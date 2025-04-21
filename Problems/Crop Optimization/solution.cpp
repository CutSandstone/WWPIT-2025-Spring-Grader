#include <bits/stdc++.h>
#define ll long long
#define v vector
using namespace std;
 
void solve() {
    int n; cin >> n;
    v<int> a(n);
    for (int &i : a) cin >> i;
    multiset<int> sums;
    for (int i = 0; i < n - 1; i++) {
        sums.insert(a[i] + a[i + 1]);
    }
 
    int ans = 2e9;
    for (int i = 1; i < n - 1; i++) {
        int s1 = a[i - 1] + a[i];
        int s2 = a[i] + a[i + 1];
        sums.erase(sums.find(s1));
        sums.erase(sums.find(s2));
        int val = a[i - 1] + a[i + 1];
        if (!sums.empty()) val = max(val, *(--sums.end()));
        ans = min(ans, val);
        sums.insert(s1);
        sums.insert(s2);
    }
 
 
    sums.erase(sums.find(a[0] + a[1]));
    ans = min(ans, *(--sums.end()));
    sums.insert(a[0] + a[1]);
    sums.erase(sums.find(a[n - 2] + a[n - 1]));
    ans = min(ans, *(--sums.end()));
 
    cout << ans << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}
