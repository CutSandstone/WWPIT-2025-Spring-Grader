#include "jngen.h"
#include <bits/stdc++.h>
using namespace std;
void gen(int t, int N){
    cout << t << "\n";
    while(t--){
        int n = rnd.next(max(1,N*9/10),N);
        cout << n << "\n";
        vector<int> perm(n);
        iota(perm.begin(),perm.end(),1);
        if(n&1){
            jngen::shuffle(perm.begin(),perm.end());
        }else{
            if(rnd.next(0,9)){
                jngen::shuffle(perm.begin(),perm.begin()+n/2);
                for(int i = 0; i<n/2; i++){
                    perm[n-i-1] = n+1-perm[i];
                    if(rnd.next(0,1)) swap(perm[n-1-i],perm[i]);
                }
            }else jngen::shuffle(perm.begin(),perm.end());
        }
        for(int i = 0; i<n; i++) cout << perm[i] << " \n"[i==n-1];
    }
}
int main(int argc, char** argv){
    registerGen(argc, argv);
    gen(stoi(argv[1]),stoi(argv[2]));
}
