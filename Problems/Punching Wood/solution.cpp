#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << min(36, (x + 63) / 64) << "\n";
    }
}
