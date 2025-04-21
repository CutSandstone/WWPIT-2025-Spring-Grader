#include "../../lib/jngen.h"
#include "../../lib/stdc++.h"
using namespace std;
void gen(int n){
    cout << n << "\n";
    cout << Array::random(n, 1, int(1e9)) << "\n";
}
int main(int argc, char** argv){
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10));
}