#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int tt; cin >> tt;
    while(tt--){
        int n;cin>>n;
        vector<int> a(n),b(n);
        for(int&i:a)cin>>i;
        for(int&i:b)cin>>i,--i;
        vector<vector<ll>> cnt(n);
        for(int i=0;i<n;++i){
            cnt[b[i]].push_back(i);
        }
        vector<vector<int>> mn(n,vector<int>(18));
        for(int i=0;i<n;++i)mn[i][0]=a[i];
        for(int j=1;j<18;++j){
            for(int i=0;i + (1<<j) - 1 < n;++i){
                mn[i][j] = min(mn[i][j-1], mn[i+(1<<j-1)][j-1]);
            }
        }
        auto q = [&](int l, int r){
            int sz = 31-__builtin_clz(r-l+1);
            return min(mn[l][sz], mn[r-(1<<sz)+1][sz]);
        };
        ll ans = 0;
        for(int i=0;i<n;++i){
            vector<vector<ll>> stk; // cnt, mn, sum(j-i+1), last
            ll sum = 0;
            ll dsum = 0;
            for(int j=1;j<cnt[i].size();++j){
                sum += dsum * (cnt[i][j]-cnt[i][j-1]);
                int mn = q(cnt[i][j-1], cnt[i][j]);
                int cnt2 = 1;
                ll len = cnt[i][j]-cnt[i][j-1]+1;
                while(!stk.empty()&&stk.back()[1]>mn){
                    cnt2 += stk.back()[0];
                    len += stk.back()[2] + stk.back()[0] * (cnt[i][j] - stk.back()[3]);
                    sum -= stk.back()[1]*(stk.back()[2]+stk.back()[0] * (cnt[i][j] - stk.back()[3]));
                    dsum -= stk.back()[0]*stk.back()[1];
                    stk.pop_back();
                }
                dsum += (ll)mn * cnt2;
                sum += mn * len;
                stk.push_back({cnt2,mn,len,cnt[i][j]});
                ans += sum;
            }
        }
        cout<<ans<<"\n";
    }
}
