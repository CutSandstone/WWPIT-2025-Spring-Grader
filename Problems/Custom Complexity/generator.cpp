#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
 
void gen(int q, int n, int m, int t) {
    cout << q << "\n";
    for (int i = 0; i < q; i++) {
        int nn = rnd.wnext(1, n, 2);
        int mm = rnd.wnext(1, m, 2);
        cout << nn << " " << mm << " " << rnd.next(1, nn) << " " << rnd.next(1, mm) << " " << rnd.next(1, t) << "\n";
    }
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    gen(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]),stoi(argv[4]));
}
