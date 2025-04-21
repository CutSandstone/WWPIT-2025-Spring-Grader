#include "jngen.h"
#include <bits/stdc++.h>
using namespace std;
 
void gen(int t, int n, int k, int elongation) {
    //elongation: see https://github.com/ifsmirnov/jngen/blob/master/doc/tree.md
    cout << t << "\n";
    for(int i=0;i<t;++i){
        Tree g = Tree::randomPrim(n, (long long)elongation*(i+1)/t).shuffled();
        Array a = Array::random(n, 1, k);
 
        cout << n << "\n";
        cout << a << "\n";
        cout << g.add1() << "\n";
    }
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10), strtol(argv[2], &p, 10), strtol(argv[3], &p, 10), strtol(argv[4], &p, 10));
}
