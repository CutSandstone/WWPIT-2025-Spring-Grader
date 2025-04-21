#include <bits/stdc++.h>
using namespace std;
using ll=long long;

//min cost

struct Line {
	mutable ll k, m, p; //y=kx+m
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int tt; cin >> tt;
    while(tt--) {
        int n;cin>>n;
        vector<ll> val(n);
        for(ll&i:val){
            cin>>i;
            i=-i;
        }
        vector<vector<int>>edges(n);
        for(int i=1;i<n;++i){
            int a,b;cin>>a>>b;
            edges[--a].push_back(--b);
            edges[b].push_back(a);
        }
        vector<int> sz(n),dep(n),maxdep(n),maxlight(n),heavy(n,-1),heavyup(n,-1),par(n,-1);
        vector<ll> ans(n,-1e18),dist(n);
        function<void(int)> dfs=[&](int r){
            sz[r]=1;
            maxdep[r]=maxlight[r]=dep[r];
            for(int i:edges[r]){
                if(i==par[r])continue;
                par[i]=r;
                dep[i]=dep[r]+1;
                dist[i]=dist[r]+val[i];
                dfs(i);
                sz[r]+=sz[i];
                if(heavy[r]==-1||sz[i]>sz[heavy[r]]){
                    heavy[r]=i;
                }
            }
            for(int i:edges[r]){
                maxdep[r]=max(maxdep[r],maxdep[i]);
                if(i!=par[r]&&i!=heavy[r]){
                    maxlight[r]=max(maxlight[r],maxdep[i]);
                }
            }
        };
        function<void(int)>dfs1=[&](int r){
            if(par[r]!=-1){
                if(heavy[par[r]]==r)heavyup[r]=heavyup[par[r]];
                else heavyup[r]=par[r];
            }
            for(int i:edges[r])if(i!=par[r])dfs1(i);
        };
        dist[0]=val[0];
        dfs(0);
        dfs1(0);
        //inside subtree
        vector<vector<ll>> qs(n);
        function<pair<LineContainer*,ll>(int)> dfs3=[&](int r){
            ll offset=val[r];
            LineContainer* lc;
            if (heavy[r]==-1) {
                lc = new LineContainer();
            } else {
                auto pi = dfs3(heavy[r]);
                lc=pi.first,offset+=pi.second;
            }
            lc->add(val[r], val[r]*(n+1-dep[r])-offset);
            for(int i:edges[r])if(i!=par[r]&&i!=heavy[r]){
                auto pi = dfs3(i);
                for (auto line : *pi.first){
                    lc->add(line.k,line.m+pi.second-offset+val[r]);
                }
            }
            qs[r].resize(maxlight[r]-dep[r]+1);
            for (int i=0;i<maxlight[r]-dep[r]+1;++i){
                qs[r][i]=lc->query(dep[r]-i)+offset;
            }
            return pair<LineContainer*,ll>{lc,offset};
        };
        //outside subtree
        vector<vector<ll>> qs2(n);
        function<void(int,int,LineContainer*,ll)> dfs2=[&](int r, int dep2, LineContainer* lc, ll offset){
            if(lc==nullptr){
                lc = new LineContainer();
            }
            offset += val[r];
            lc->add(val[r], val[r]*(n+1-dep2)-offset);
            for(int i:edges[r])if(i!=par[r]&&i!=heavy[r]){
                auto pi = dfs3(i);
                for (auto line : *pi.first) {
                    lc->add(line.k,line.m+pi.second-offset+val[r]-(dep2-dep[r])*line.k);
                }
            }
            qs2[r].resize(maxlight[r]-dep[r]+1);
            for (int i=0;i<maxlight[r]-dep[r]+1;++i){
                qs2[r][i]=lc->query(dep2-i)+offset;
            }
            for(int i:edges[r]){
                if(i==heavy[r])dfs2(i,dep2-1,lc,offset);
                else if(i!=par[r]){
                    dfs2(i,0,nullptr,0);
                }
            }
        };
        dfs3(0);
        dfs2(0,0,nullptr,0);
        for(int i=0;i<n;++i){
            for(int j=i;j>=0;j=heavyup[j]){
                ans[i]=max(ans[i],qs2[j][dep[i]-dep[j]]+dist[i]-dist[j]);
                ans[i]=max(ans[i],qs[j][dep[i]-dep[j]]+dist[i]-dist[j]);
            }
        }
        for(auto i:ans)cout<<-i<<"\n";
    }
}