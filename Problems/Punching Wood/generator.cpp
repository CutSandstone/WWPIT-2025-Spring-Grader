#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
 
void gen(int t, int nn) {
    cout << t << "\n";
    while(t--) {
        int n = rnd.next(nn / 2, nn);
        cout << n << "\n";
    }
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10), strtol(argv[2], &p, 10));
}
