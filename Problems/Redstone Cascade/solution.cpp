#include <bits/stdc++.h>
#define a first
#define b second
using namespace std;
using ll = long long;
const int mod = 1e9+7;
int main() {
    int n, q; cin >> n >> q;
    auto currentTimeMillis = []() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); };
    vector<vector<int>> g(n);
    for(int i = 1; i<n; i++){
        int x; cin >> x;
        g[x-1].push_back(i);
    }
 
    int lg = 0;
    while((1<<lg) <= n) lg++;
    vector<vector<int>> up(n,vector<int>(lg,-1));
    vector<int> depth(n);
    vector<int> st(n);
    int timer = 0;
    function<void(int,int)> dfs = [&](int s, int p){
        st[s] = timer++;
        depth[s] = s?depth[p]+1:0;
        up[s][0] = p;
        for(int i: g[s])
            dfs(i,s);
    };
    dfs(0,-1);
    function<ll(ll)> inv = [&](ll s){
        int p = mod-2;
        ll a = 1;
        while(p){
            if(p&1) a = a*s%mod;
            s = s*s%mod;
            p>>=1;
        }
        return a;
    };
    vector<vector<pair<ll,ll>>> jp(n,vector<pair<ll,ll>>(lg));
    for(int i = 1; i<n; i++)
        cin >> jp[i][0].a;
    for(int i = 1; i<n; i++)
        cin >> jp[i][0].b;
    auto comb = [](pair<ll,ll> a, pair<ll,ll> b){
        return pair<ll,ll>{(a.a*b.a+a.b*(1-b.a+mod)%mod)%mod,(a.a*b.b+a.b*(1-b.b+mod)%mod)%mod};
    };
    for(int i = 1; i<lg; i++)
        for(int j = 0; j<n; j++){
            up[j][i] = up[j][i-1] == -1 ? -1:up[up[j][i-1]][i-1];
            if(up[j][i] != -1)
                jp[j][i] = comb(jp[j][i-1],jp[up[j][i-1]][i-1]);
        }
    auto lca = [&](int a, int b){
        if(depth[a] > depth[b]) swap(a,b);
        int d = depth[b]-depth[a];
        for(int i = 0; i<lg; i++) if((d>>i)&1)
            b = up[b][i];
        if(a == b) return a;
        for(int i = lg-1; i>=0; i--) if(up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
        return up[a][0];
    };
    auto upProb = [&](int a, int d){
        pair<ll,ll> cur = {1,0};
        for(int i = 0; i<lg; i++) if((d>>i)&1){
            cur = comb(cur,jp[a][i]);
            a = up[a][i];
        }
        return cur;
    };
    while(q--){
        int l; cin >> l;
        vector<int> c(l);
        ll p; cin >> p;
        set<int> need;
        for(int& i: c) cin >> i, need.insert(--i);
        if(l == 0){
            cout << "1\n";
            continue;
        }
        auto cmp = [&](const int& a, const int& b){return st[a]>st[b];};
        map<int,int,decltype(cmp)> mp(cmp);
        for(int i: c) mp[i] = 0;
        mp[0] = -1;
        for(int val = mp.begin()->a; val;){
            int next = mp.upper_bound(val)->a;
            int l = lca(val,next);
            if(l != val && depth[l] > depth[mp[val]])
                mp[val] = l;
            if(next && l != next && depth[l] > depth[mp[next]])
                mp[next] = l;
            if(mp.find(l) == mp.end()) mp[l] = 0;
            val = next;
        }
        map<int,vector<int>> down;
        for(auto& a: mp) if(a.b != -1)
            down[a.b].push_back(a.a);
        function<pair<ll,ll>(int)> dfs2 = [&](int s){
            if(down.find(s) == down.end()) return pair<ll,ll>{1,0};
            pair<ll,ll> ans = {1,need.count(s) ? 0:1};
            for(int i: down[s]){
                auto cur = comb(dfs2(i),upProb(i,depth[i]-depth[s]));
                ans.a = ans.a*cur.a%mod;
                ans.b = ans.b*cur.b%mod;
            }
            return ans;
        };
        auto ans = dfs2(0);
        cout << (ans.a*p+ans.b*(1-p+mod)%mod)%mod << "\n";
    }
}
