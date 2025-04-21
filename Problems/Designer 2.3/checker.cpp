#include "bits/stdc++.h"
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc==4);
    ifstream inp,sub;
    inp.open(argv[1]);
    sub.open(argv[2]);
    assert(inp.is_open());
    assert(sub.is_open());
    int tt; inp >> tt;
    while(tt--) {
        multiset<int> nums1;
        int n,m; inp >> n >> m;
        for(int i=0;i<n*m;++i){
            int a; inp >> a;
            nums1.insert(a);
        }
        vector<vector<int>> nums2(n,vector<int>(m));
        for(int i=0;i<n;++i)for(int j=0;j<m;++j){
            assert(sub>>nums2[i][j]);
            auto it = nums1.lower_bound(nums2[i][j]);
            assert(it != nums1.end());
            nums1.erase(it);
        }
        assert(nums1.empty());
        int diff = nums2[0][1]-nums2[0][0];
        for(int i=0;i<n;++i){
            for(int j=1;j<m;++j){
                assert(nums2[i][j]-nums2[i][j-1] == diff);
            }
        }
        diff = nums2[1][0]-nums2[0][0];
        for(int j=0;j<m;++j){
            for(int i=1;i<n;++i){
                assert(nums2[i][j]-nums2[i-1][j] == diff);
            }
        }
    }
    inp.close();
    sub.close();
}
