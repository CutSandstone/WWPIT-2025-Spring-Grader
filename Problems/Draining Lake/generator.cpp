#include "jngen.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerGen(argc, argv);
    int t = stoi(argv[1]);
    int n = stoi(argv[2]);
    cout << n << "\n";
    while(t--){
        int x = rnd.next(1,n);
        int y = rnd.next(1,n);
        cout << x << " " << y << "\n";
    }
}
