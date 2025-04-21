#include"bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> nums(n);
        for(int&i:nums)cin>>i;
        sort(nums.begin(),nums.end());
        vector<ll> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;++i)pre[i]=pre[i-1]+nums[i];
        ll rsum = nums[n-1];
        int a = 0;
        ll lsum=0;
        ll last=0;
        ll ans = 0;
        for(int i=n-2;i>=0;--i){
            while(a<=i){
                ll nxt=lsum+(nums[a]-last)*(i-a+1);
                if(nums[a]<(nxt+rsum+n-1)/n) {
                    lsum=nxt;
                    last=nums[a];
                    a++;
                } else break;
            }
            if (a<=i){
                //every time to add 1 to non capped elements:
                //max element * n += n
                //average * n += i-a+1
                //task is find max dx such that
                //max element * n + (n * dx) < sum + ((i-a+1) * dx)
                //((n-i+a-1)*dx)<sum - max element * n
                // dx < ceil(sum - max element * n) / (n - i + a - 1))
                //where dx = number of times to add 1 to non capped elements
                ll dx = (lsum + rsum - last * n - 1) / (n-i+a-1);
                lsum += dx * (i-a+1);
                last += dx;
            }
            while(a>i) {
                a--;
                lsum=pre[a];
                last=nums[a];
            }
            ans=max(ans,lsum);
            rsum += nums[i];
            lsum -= last;
        }
        cout<<ans<<"\n";
    }
}