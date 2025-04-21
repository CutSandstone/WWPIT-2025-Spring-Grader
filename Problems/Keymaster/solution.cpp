#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(2);
    int tt; cin >> tt; while (tt--) {
        int n,q; cin >> n >> q;
        vector<ld> nums(n);
        for(ld&i:nums)cin>>i;
        vector<ll> cnt(n);
        for(ll&i:cnt)cin>>i;
        nums.push_back(0);
        cnt.push_back(1e17);
        vector<ld> pre(n);
        for(int i=0;i<n;++i){
            pre[i]=(i==0?0.L:pre[i-1])+nums[i]*cnt[i];
        }
        partial_sum(cnt.begin(),cnt.end(),cnt.begin());
        while(q--){
            ll x; cin >> x;
            int i = lower_bound(cnt.begin(),cnt.end(),x)-cnt.begin();
            cout << (i==0?0.L:pre[i-1]) + nums[i] * (x-(i==0?0:cnt[i-1])) << "\n";
        }
    }
}