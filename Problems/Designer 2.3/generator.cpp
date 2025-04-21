#include "jngen.h"
#include "bits/stdc++.h"
using namespace std;

void gen(int t, int n, int m, int mx) {
    cout<<t<<"\n";
    while(t--) {
        int nn = rnd.next(max(1,n-2), n);
        int mm = rnd.next(max(1,m-2), m);
        cout << nn << " " << mm << "\n";
        int dx = rnd.next(1, mx/2/nn);
        int dy = rnd.next(1, mx/2/mm);
        int st = rnd.next(1, mx-dx*(nn-1)-dy*(mm-1));
        vector<int> nums(nn*mm);
        for(int i=0;i<nn;++i)for(int j=0;j<mm;++j){
            nums[i*mm+j]=st+dx*i+dy*j;
        }
        jngen::shuffle(nums.begin(), nums.end());
        for(int i=0;i<nn*mm;i++){
            cout<<nums[i]<<" \n"[i==nn*mm-1];
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10), strtol(argv[2], &p, 10), strtol(argv[3], &p, 10), strtol(argv[4], &p, 10));
}