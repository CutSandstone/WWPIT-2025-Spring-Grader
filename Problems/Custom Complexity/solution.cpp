#include "bits/stdc++.h"
using namespace std;
using ll=long long;
const ll mod = 1e9+7;
const ll inv6 = 166666668;
const ll inv12 = 83333334;
const ll inv24 = 41666667;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int tt; cin >> tt; while(tt--){
        ll n,m,x,y,t; cin>>n>>m>>x>>y>>t;
        ll ans = 0;
        ans = (t*t%mod*t%mod*t+t*t%mod*t*2+t*t*2+t)%mod*inv6%mod;
        for(ll e:{t-x,t-y,t-(n-x+1),t-(m-y+1)}){
            if(e>0)
                ans -= (e*e%mod*e%mod*e+e*e%mod*e*4+e*e*5+e*2)%mod*inv12%mod;
        }
        for(ll c:{t-x-y,t-(n-x+1)-y,t-x-(m-y+1),t-(n-x+1)-(m-y+1)}){
            if (c>0)
                ans += (c*c%mod*c%mod*c+c*c%mod*c*6+c*c%mod*11+c*6)%mod*inv24%mod;
        }
        cout << (ans%mod+mod)%mod << "\n";
    }
}