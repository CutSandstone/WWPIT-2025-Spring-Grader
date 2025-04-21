#include "jngen.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void gen(int t, int nn, ll mm) {
    cout << t << "\n";
    while(t--) {
        int n = rnd.next(max(3,nn-5),nn);
        ll x = rnd.next(max(1LL,mm-5),mm);
        cout << n << " " << x << "\n";
        Array64 a = Array64::random(n, mm - 1);
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
    gen(strtol(argv[1], &p, 10),strtol(argv[2], &p, 10), strtoll(argv[3], &p, 10));
}
