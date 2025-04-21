#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
using ll = long long;
struct SparseSeg {
   private:
   int n;
   vector<ll> tree;
   vector<int> left,right;
   void add(int cL, int cR, int ind, int i, ll x){
       tree[ind]+=x;
       if(cL == cR) return;
       int m = (cL+cR)>>1;
       if(i<=m){
           if(left[ind] == -1){
               left[ind] = tree.size();
               tree.push_back(0);
               left.push_back(-1);
               right.push_back(-1);
           }
           add(cL,m,left[ind],i,x);
       }else{
           if(right[ind] == -1){
               right[ind] = tree.size();
               tree.push_back(0);
               left.push_back(-1);
               right.push_back(-1);
           }
           add(m+1,cR,right[ind],i,x);
       }
   }
   ll sum(int cL, int cR, int ind, int l, int r){
       if(ind == -1) return 0;
       if(cL == l && cR == r) return tree[ind];
       int m = (cL+cR)>>1;
       if(r<=m) return sum(cL,m,left[ind],l,r);
       if(l>m) return sum(m+1,cR,right[ind],l,r);
       return sum(cL,m,left[ind],l,m)+sum(m+1,cR,right[ind],m+1,r);
   }
   public:
   SparseSeg(int N): n(N){
       tree.push_back(0);
       left.push_back(-1);
       right.push_back(-1);
   }
   void add(int ind, ll x){
       add(0,n-1,0,ind,x);
   }
   ll sum(int l, int r){
       return sum(0,n-1,0,l,r);
   }
};
int n;
ll ans;
vector<vector<int>> g;
vector<int> v;
pair<map<int,int>,pair<SparseSeg,SparseSeg>> dfs(int s, int p){
   if(s) v[s]+=v[p];
   pair<map<int,int>,pair<SparseSeg,SparseSeg>> prev{{},{SparseSeg(n<<1|1),SparseSeg(n<<1|1)}};
   prev.a[v[s]] = 1;
   prev.b.a.add(v[s]+n,1);
   prev.b.b.add(v[s]+n,v[s]);
   int add = v[s]+(s?v[p]:0);
   for(int i: g[s]) if(i != p){
       auto next = dfs(i,s);
       if(next.a.size() > prev.a.size()) swap(next,prev);
       for(auto& a: next.a){
           int k = add-a.a;
           ll cnt1 = prev.b.a.sum(0,k-1+n)-prev.b.a.sum(k+n,n<<1);
           ll cnt2 = prev.b.b.sum(k+n,n<<1)-prev.b.b.sum(0,k-1+n);
           ans+=(cnt1*k+cnt2)*a.b;
       }
       for(auto& a: next.a){
           prev.a[a.a]+=a.b;
           prev.b.a.add(a.a+n,a.b);
           prev.b.b.add(a.a+n,ll(a.b)*a.a);
       }
   }
   return prev;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> n;
   string a,b; cin >> a >> b;
   g.resize(n);
   v.resize(n);
   for(int i = 1; i<n; i++){
       int p,q; cin >> p >> q;
       g[--p].push_back(--q);
       g[q].push_back(p);
   }
   for(int i = 0; i<n; i++) v[i] = a[i]-b[i];
   int sum = 0;
   for(int i: v) sum+=abs(i);
   ans = 0;
   dfs(0,-1);
   cout << ans*2+sum << "\n";
}
