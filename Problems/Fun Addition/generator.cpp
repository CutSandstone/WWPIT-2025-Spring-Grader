#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
void gen(int t, int n, int m, int mx) {
    cout << t << "\n";
    while(t--) {
        cout << n << "\n";
        cout << Array::random(n, 1, m) << "\n";
        cout << Array::random(n, 1, mx) << "\n";
    }
}
int main(int argc, char** argv){
    registerGen(argc, argv);
    gen(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]),stoi(argv[4]));
}
