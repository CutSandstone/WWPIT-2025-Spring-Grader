#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t; while(t--){
        int n; cin >> n;
        vector<int> a(n),p(n);
        for(int i = 0; i<n; i++){
            int x; cin >> x;
            a[p[i] = x-1] = i;
        }
        vector<pair<int,int>> ops;
        function<void(int,int)> doSwap = [&](int i, int j){
            if(i == j) return;
            swap(p[i],p[j]);
            swap(a[p[i]],a[p[j]]);
            swap(p[n-1-i],p[n-1-j]);
            swap(a[p[n-1-i]],a[p[n-1-j]]);
            ops.push_back({i+1,j+1});
        };
        int m = n/2;
        if(n&1){
            vector<bool> vis(n);
            int c = 0;
            for(int i = 0; i<n; i++)
                if (!vis[i]) {
                    c++;
                    for (int j = i; !vis[j]; j = p[j])
                        vis[j] = 1;
                }
            if(((n-c)&1) != 0){
                cout << "-1\n";
                continue;
            }
            for(int i = 0; i<m; i++){
                if(a[i] == m){
                    doSwap(m,a[n-i-1]);
                }else if(a[n-i-1] == m){
                    doSwap(m,a[i]);
                }
                if(a[i] == i && a[n-i-1] == n-i-1) continue;
                if(a[i] == n-i-1 && a[n-i-1] == i){
                    doSwap(i,i+1);
                    doSwap(i,n-i-2);
                }else if(a[i] == i){
                    doSwap(n-a[i]-1,m);
                    doSwap(m,a[n-i-1]);
                    doSwap(i,a[i]);
                }else{
                    doSwap(n-a[n-i-1]-1,m);
                    doSwap(m,a[i]);
                    doSwap(i,a[i]);
                }
            }
            cout << ops.size() << "\n";
            for(auto& a: ops) cout << a.first << " " << a.second << "\n";
        }else{
            bool w = 1;
            for(int i = 0; i<m; i++){
                if(a[i] == i && a[n-i-1] == n-i-1) continue;
                if(a[i]+a[n-i-1] != n-1){
                    w = 0;
                    break;
                }
                if(a[i] == n-i-1){
                    if(i == m-1){
                        w = 0;
                        break;
                    }
                    doSwap(i,i+1);
                    doSwap(i,n-i-2);
                    continue;
                }
                doSwap(i,a[i]);
            }
            if(w){
                cout << ops.size() << "\n";
                for(auto& a: ops) cout << a.first << " " << a.second << "\n";
            }else cout << "-1\n";
        }
    }
}
