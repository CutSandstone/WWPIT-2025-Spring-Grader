#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerTestlibCmd(argc, argv);
    int tt = inf.readInt(1, 200000, "number of testcases");
    for(int t = 1; t<=tt; t++){
        int n = inf.readInt(1, 200000, "length of array");
        vector<int> a(n),b(n);
        int sa = 0, sb = 0;
        for(int i = 0; i<n; i++) a[i] = inf.readInt(1, int(1e9), "i'th index in array a");
        for(int i = 0; i<n; i++) b[i] = inf.readInt(1, int(1e9), "i'th index in array b");
        int ops = ouf.readInt(0, 60*n, "number of operations");
        for(int i = 0; i<ops; i++){
            int op = ouf.readInt(1, 2, "operation");
            if(op == 1){
                char c = ' ';
                while(isspace(c)) c = ouf.readChar();
                int k = ouf.readInt(1, n-1, "shift");
                if(c == 'A') sa = (sa-k+n)%n;
                else if(c == 'B') sb = (sb-k+n)%n;
                else quitf(_pe, "invalid operation. operation 1 must be on either array A or B");
            }else{
                int ind = ouf.readInt(1, n, "index")-1;
                swap(a[(ind+sa)%n], b[(ind+sb)%n]);
            }
        }
        for(int i = 0; i<n-1; i++){
            if(a[(i+sa)%n] > a[(i+1+sa)%n]) quitf(_wa, "array a is not sorted in T = %d", t);
            if(b[(i+sb)%n] > b[(i+1+sb)%n]) quitf(_wa, "array b is not sorted in T = %d", t);
        }
    }
    quitf(_ok, "accepted");
}
