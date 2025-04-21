#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
 
void gen(int t, int maxn=1000000) {
    cout << t << "\n";
    while(t--){
        int n = rnd.next(1, maxn);
        bool works = rnd.wnext(0, 1, 5);
        cout << n << " " << (works ? rnd.next(1, 31-countl_zero((unsigned int)n)) : rnd.next(1, min(n,(31-countl_zero((unsigned int)n))*2))) << "\n";
    }
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    if(argc == 2) gen(stoi(argv[1]));
    else gen(stoi(argv[1]),stoi(argv[2]));
}
