#include <bits/stdc++.h>
#define v vector
#define ll long long
using namespace std;
 
void solve() {
    int n; cin >> n;
    v<ll> arr(n);
    for (ll &i : arr) cin >> i;
    
    v<ll> cost(n, 1e18);
 
    ll mx = arr[0];
    for (int i = 1; i < n; i++) {
        cost[i] = (arr[i] + mx) / mx;
        mx = max(mx, arr[i]);
    }
 
    sort(cost.begin(), cost.end());
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += cost[i];
        cout << ans << " ";
    }
    cout << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}