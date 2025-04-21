#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<int>p(n);
        for(int&i:p)cin>>i,--i;
        ll ans=0;
        for(int i=0;i<n;++i){
            ans+=min(abs(p[i]-i),n-abs(p[i]-i));
        }
        ll ans2 = ans;
        for(int i=0;i<n;++i){
            vector<int> ddx(n);
            ll x=0,dx=0;
            for(int j=0;j<n;++j){
                int a=p[j],b=j;
                for(int _=0;_<2;_++) {
                    int orig = min(abs(a-b),n-abs(a-b));
                    int da = min(abs(a-i),n-abs(a-i));
                    if(da<orig){
                        ddx[(b-(orig-da)+1+n)%n]++;
                        ddx[(b+1)%n]-=2;
                        ddx[(b+(orig-da)+1)%n]++;
                        x += max(0,orig-(da+min(b,n-b)));
                        if((b+1+n)/n > (b-(orig-da)+1+n)/n) dx++;
                        if((b+(orig-da)+1)/n > (b+1)/n) dx--;
                    }
                    swap(a,b);
                }
            }
            for(int j=0;j<n;++j){
                dx+=ddx[j];
                if(j)x+=dx;
                ans2=min(ans2,ans-x);
            }
        }
        cout<<ans2<<"\n";
    }
}