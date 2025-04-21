#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
void gen(int n){
    cout << n << " ";
    Tree t2 = Tree::randomPrim(n/2+1,-10);
    vector<int> cnt(n/2+1);
    for(auto& a: t2.edges()){
        cnt[a.first]++;
        cnt[a.second]++;
    }
    cout << cnt.size() << "\n";
    Tree tr = Tree::random(n);
    vector<vector<int>> g(n);
    for(auto& a: tr.edges()){
        g[a.first].push_back(a.second);
        g[a.second].push_back(a.first);
    }
    vector<int> up(n);
    function<void(int,int)> dfs = [&](int s,int p){
        up[s] = p;
        for(int i: g[s]) if(i != p)
            dfs(i,s);
    };
    for(int i = 1; i<n; i++) cout << up[i]+1 << " \n"[i==n-1];
    int mod = 1e9+7;
    for(int i = 1; i<n; i++) cout << rnd.next()%mod << " \n"[i==n-1];
    for(int i = 1; i<n; i++) cout << rnd.next()%mod << " \n"[i==n-1];
    for(int i: cnt){
        cout << i << " ";
        cout << rnd.next()%mod << " ";
        set<int> cur;
        while(cur.size()<i) cur.insert(rnd.next(1,n));
        Array v(cur.begin(),cur.end());
        v.shuffle();
        for(int j = 0; j<i; j++) cout << v[j] << " \n"[j==i-1];
    }
}
int main(int argc, char** argv){
    registerGen(argc, argv);
    gen(stoi(argv[1]));
}
