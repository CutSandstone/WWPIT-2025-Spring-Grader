#include <bits/stdc++.h>
#define v vector
#define ll long long
using namespace std;
 
ll m[2];
 
void solve() {
    int n; ll x; cin >> n >> x;
    v<ll> a(n);
 
    for (ll &i : a) cin >> i;
    sort(a.begin(), a.end());
 
    m[0] = a[n - 2], m[1] = a[n - 1];
    int ans = 0;
    while (m[1] < x) {
        ll sum = m[0] + m[1];
        m[0] = m[1], m[1] = sum;
        ans++;
    }
 
    cout << ans << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}
