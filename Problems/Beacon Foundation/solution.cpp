#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6;
const int LG = 20;
int fac[MX+1];
int jp[MX+1][LG];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[1] = 2;
    fill(jp[1],jp[1]+LG,1);
    for(int i = 2; i<=MX; i++) if(fac[i] == 0)
        for(int j = i; j<=MX; j+=i) if(fac[j] == 0) fac[j] = i;
    for(int i = 2; i<=MX; i++){
        jp[i][0] = jp[i/fac[i]][0]+1;
        for(int j = 1; j<LG; j++)
            jp[i][j] = max(jp[i][j-1],i>(1<<(j-1))?jp[i-(1<<(j-1))][j-1]:0);
    }
    int t; cin >> t; while(t--){
        int n,k; cin >> n >> k;
        for(int i = LG-1; i>=0 && n>0; i--) if(jp[n][i] < k)
            n-=1<<i;
        if(n<=0){
            cout << "-1\n";
            continue;
        }
        while(n && k--){
            cout << n << " ";
            n/=fac[n];
        }
        cout << "\n";
    }
}
