#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
void gen(int t, int nn, int m) {
    cout << t << "\n";
    while(t--) {
        int n = rnd.next(max(1,nn-5),nn);
        cout << n << "\n";
        Array a = Array::random(n, m - 1);
        Array b = Array::random(n, m - 1);
        for (int i = 0; i < n; i++) {
            cout << (a[i] + 1);
            if (i != n - 1) cout << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << (b[i] + 1);
            if (i != n - 1) cout << " ";
        }
        cout << "\n";
    }
}
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    gen(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]));
}
