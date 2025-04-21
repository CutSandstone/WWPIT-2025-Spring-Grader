#include "jngen.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerGen(argc, argv);
    int t = stoi(argv[2]);
    int N = stoi(argv[3]);
    cout << t << "\n";
    while(t--){
        int n = rnd.next(max(1,N*9/10),N);
        double pw = 1/rnd.next(0.0,1.0);
        cout << n << "\n";
        vector<int> fac(n+1);
        for(int i = 1; i<=n; i++)
            for(int j = i; j<=n; j+=i)
                fac[j]++;
        vector<int> s(n);
        iota(s.begin(),s.end(),1);
        sort(s.begin(),s.end(),[&](int i,int j){return fac[i]>fac[j];});
        for(int i = 0; i<n; i++)
            cout << s[pow(rnd.next(0.0,1.0),pw)*n] << " \n"[i==n-1];
    }
}