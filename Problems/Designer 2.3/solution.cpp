#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> check(int n, int m, vector<int> nums){
    int dy = nums[1]-nums[0];
    if((nums[n*m-1]-dy*(m-1)-nums[0])%(n-1))return {};
    int dx = (nums[n*m-1]-dy*(m-1)-nums[0])/(n-1);
    multiset<int> s;
    for(int i:nums)s.insert(i);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            s.extract(dy*j+dx*i+nums[0]);
        }
    }
    if(!s.empty())return {};
    vector grid(n,vector<int>(m));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)grid[i][j]=nums[0]+i*dx+j*dy;
    return grid;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        int n,m; cin >> n >> m;
        vector<int> nums(n*m);
        for(int&i:nums)cin>>i;
        sort(nums.begin(),nums.end());
        auto one = check(n,m,nums);
        if (one.empty()) {
            one = check(m,n,nums);
            vector<vector<int>> two(n,vector<int>(m));
            for(int i=0;i<n;++i)for(int j=0;j<m;++j)two[i][j]=one[j][i];
            swap(one,two);
        }
        for(auto vi:one){
            for(int i:vi)cout<<i<<" ";
            cout<<"\n";
        }
    }
}