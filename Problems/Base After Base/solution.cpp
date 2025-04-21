#include"bits/stdc++.h"
using namespace std;
int main(){
    cin.tie(NULL);
    int tt;cin>>tt;
    while(tt--){
        int n; cin >> n;
        vector<int> nums(n+2);
        for(int i=2;i<=n+1;++i)cin>>nums[i];
        int mx1=0,mx2=0,a=0,b=1;
        for(int i=2;i<=n+1;++i){
            if(nums[i]>mx1){
                swap(mx1,mx2);
                swap(a,b);
                mx1=nums[i],a=i;
            }
            else if (nums[i]>mx2){
                mx2=nums[i],b=i;
            }
        }
        cout<<a-1<<" "<<b-1<<"\n";
    }
}