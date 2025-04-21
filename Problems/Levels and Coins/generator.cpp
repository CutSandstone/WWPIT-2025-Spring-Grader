#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
 
void gen(int t, int n, int k) {
    cout << t << "\n";
    for(int i=0;i<t;++i){
        cout << n << "\n" << Array::random(n, 1, k) << "\n";
    }
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10), strtol(argv[2], &p, 10), strtol(argv[3], &p, 10));
}