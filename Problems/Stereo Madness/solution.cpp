#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int mn = INT_MAX, mx = INT_MIN;
    while(n--){
        int x; cin >> x;
        mn = min(mn,x);
        mx = max(mx,x);
    }
    cout << fixed << setprecision(6) << mx/(double)mn << "\n";
}
