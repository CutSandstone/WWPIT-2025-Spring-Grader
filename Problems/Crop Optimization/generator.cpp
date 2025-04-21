#include "jngen.h"
#include <bits/stdc++.h>
using namespace std;
 
void gen(int t, int nn, int m) {
    cout << t << "\n";
    while(t--) {
        int n = rnd.next(max(3,nn-5),nn);
        cout << n << "\n";
        Array a = Array::random(n, m - 1);
        for (int i = 0; i < n; i++) {
            cout << (a[i] + 1);
            if (i != n - 1) cout << " ";
        }
        cout << "\n";
    }
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10),strtol(argv[2], &p, 10), strtol(argv[3], &p, 10));
}
