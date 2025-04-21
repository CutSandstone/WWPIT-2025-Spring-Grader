#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(ll& i: a) cin >> i;
        ll ans = 0;
        vector<vector<int>> fac(n+2);
        for(int i = 1; i<=n; i++)
            for(int j = i; j<=n; j+=i)
                fac[j].push_back(i);
        vector<ll> cntPrev(n+2), cntNext(n+2);
        for(int i: a) cntNext[i]++;
        for(int i = 0; i<n; i++){
            cntNext[a[i]]--;
            for(int j: fac[a[i]])
                ans+=cntPrev[j+1]*cntNext[a[i]/j];
            cntPrev[a[i]]++;
        }
        cout << ans << "\n";
    }
}