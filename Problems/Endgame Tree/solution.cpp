#include <bits/stdc++.h>
using namespace std;
 
struct D {
    int sm, mx;
};
 
D comb(D a, D b) {
    D c;
    c.sm = a.sm + b.sm;
    c.mx = max(a.mx, a.sm + b.mx);
    return c;
}
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while(t--){
        int n,q; cin >> n >> q;
        vector<bool> v(n);
        vector<int> oneChild(n);
        for(int i = 0; i<n; i++){
            string s; cin >> s;
            v[i] = s == "1";
        }
        int lg = 0;
        while((1 << lg) <= n) lg++;
        vector<D> segt(1 << (lg + 1));
        vector<vector<int>> jmp(n,vector<int>(lg+1,-1));
        vector<int> st(n),en(n);
        int adj1 = 0;
        set<int> one;
        for(int i = 0; i<n; i++) if(v[i]) one.insert(i);
        vector<vector<int>> g(n);
        for(int i = 1; i<n; i++){
            int a,b; cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
            if(v[a] && v[b]) adj1++;
        }
        vector<int> cnts(n);
        int t = 0;
        vector<int> dep(n);
        auto bel = [&](int a, int b) {
            for(int i = lg; i >= 0; i--) {
                if(dep[jmp[b][i]] > dep[a]) {
                    b = jmp[b][i];
                }
            }
            return b;
        };
        auto add = [&](int k, int v) {
            if(k >= n) return;
            k += (1 << lg);
            segt[k].sm += v;
            segt[k].mx = max(0, segt[k].sm);
            while(k > 1) {
                k /= 2;
                segt[k] = comb(segt[2 * k], segt[2 * k + 1]);
            }
        };
        set<pair<int,int>> ones2;
        auto toggle = [&](int s) {
            add(st[s], (!v[s]) - v[s]);
            add(en[s], v[s] - (!v[s]));
            if(!v[s]) {
                ones2.insert({dep[s], s});
            } else {
                ones2.erase(ones2.find({dep[s], s}));
            }
        };
        auto edit = [&](int k){
            bool b = false;
            toggle(k);
            if(ones2.size() >= 3) {
                auto f = ones2.begin();
                int fi = (*f).second;
                int se = (*(++f)).second;
                add(st[fi], -1);
                add(en[fi], 1);
                bool flag = false;
                if(segt[1].mx >= 2) b = true;
                else {
                    if(st[fi] <= st[se] && en[se] <= en[fi]) {
                        add(st[se], -1);
                        add(en[se], 1);
                        int be = bel(fi, se);
                        add(st[be], -1);
                        add(en[be], 1);
                        
                        if(segt[1].mx >= 1) b = true;
 
                        add(st[be], 1);
                        add(en[be], -1);
                        
                        add(st[se], 1);
                        add(en[se], -1);
                    } else {
                        flag = true;
                    }
                }
                add(st[fi], 1);
                add(en[fi], -1);
 
                if(flag) {
                    add(st[se], -1);
                    add(en[se], 1);
                    if(segt[1].mx >= 2) b = true;
                    add(st[se], 1);
                    add(en[se], -1);
                }
            }
            return b;
        };
        function<void(int,int)> dfs = [&](int s, int p){
            dep[s] = (p == -1) ? 0 : (dep[p] + 1);
            jmp[s][0] = p;
            for(int i = 0; i < lg; i++)
                jmp[s][i + 1] = jmp[s][i] == -1 ? -1:jmp[jmp[s][i]][i];
            st[s] = t++;
            if(p != -1 && v[s]) oneChild[p]++;
            for(int i: g[s]) if(i != p)
                dfs(i,s);
            en[s] = t;
        };
        dfs(0,-1);
        for(int i = 0; i<n; i++) if(v[i]){
            v[i] = 0;
            toggle(i);
            v[i] = 1;
        }
        edit(0);
        v[0] = !v[0];
        bool no3path = edit(0);
        v[0] = !v[0];
        function<int()> solve = [&](){
            if(adj1 != 0) return 0; // Case 1
            if(one.size() == 0) return 0; // Case 2
            if(one.size() == 1) return int(g[*one.begin()].size()); // Case 3
            if(!no3path) return 1; // Case 4
            return 0; // Case 5
        };
        cout << solve() << "\n";
        while(q--){
            int x; cin >> x; x--;
            if(v[x]){
                one.erase(x);
                adj1-=oneChild[x];
                if(jmp[x][0] != -1){
                    if(v[jmp[x][0]]) adj1--;
                    oneChild[jmp[x][0]]--;
                }
            }else{
                one.insert(x);
                adj1+=oneChild[x];
                if(jmp[x][0] != -1){
                    if(v[jmp[x][0]]) adj1++;
                    oneChild[jmp[x][0]]++;
                }
            }
            no3path = edit(x);
            v[x] = !v[x];
            cout << solve() << "\n";
        }
    }
}