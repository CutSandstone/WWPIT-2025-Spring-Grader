#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerTestlibCmd(argc, argv);
    int tt = inf.readInt(1,200000,"number of test cases");
    for(int t = 1; t<=tt; t++){
        int n = inf.readInt(1,200000,"length of permutation");
        vector<int> perm(n);
        for(int i = 0; i<n; i++) perm[i] = inf.readInt(1,n,"i'th element of permutation");
        int realOps = ans.readInt(-1,2*n,"number of operations");
        int contOps = ouf.readInt(-1,2*n,"number of operations");
        if(realOps == -1 && contOps != -1)
            quitf(_wa,"expected impossible, contestant got possible");
        if(realOps != -1 && contOps == -1)
            quitf(_wa,"expected possible, contestant got impossible");
        if(realOps != -1){
            while(realOps--){
                ans.readInt(1,n,"i");
                ans.readInt(1,n,"j");
            }
            while(contOps--){
                int i = ouf.readInt(1,n,"i");
                int j = ouf.readInt(1,n,"j");
                swap(perm[i-1],perm[j-1]);
                swap(perm[n-i],perm[n-j]);
            }
            for(int i = 1; i<n; i++) if(perm[i]<perm[i-1])
                quitf(_wa,("not sorted on case "+to_string(t)).c_str());
        }
    }
    quitf(_ok,"all possible permutations are sorted");
}
