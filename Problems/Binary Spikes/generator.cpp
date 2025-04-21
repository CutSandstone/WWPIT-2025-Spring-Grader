#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
 
void gen(int n) {
    n = rnd.next(n/10)+9*n/10;
    cout << n << "\n";
    for(int i = 0; i<2; i++){
        for(int j = 0; j<n; j++) cout << rnd.next()%2;
        cout << "\n";
    }
    cout << Tree::random(n).shuffled().add1() << "\n";
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10));
    // gen(strtol(argv[1], &p, 10),strtol(argv[2], &p, 10),strtol(argv[3], &p, 10));
}