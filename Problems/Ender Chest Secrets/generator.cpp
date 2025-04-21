#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
void allcases(int l, int r) {
    unordered_set<string> tcs;
    for(int n=l;n<=r;++n){
        vector<int> p(n);
        iota(p.begin(),p.end(),1);
        do {
            for(int mask=0;mask<1<<n;++mask) {
                string s = to_string(n)+"\n";
                for(int i=0;i<n;++i){
                    s += to_string((mask>>i&1?p[i]:-1)) + " \n"[i==n-1];
                }
                tcs.insert(s);
            }
        } while (next_permutation(p.begin(),p.end()));
    }
    cout<<tcs.size()<<"\n";
    for(string s: tcs)cout<<s;
}
void gen(int t, int nn, int wt) {
    //wt: high value => more ones, low value => less ones
    cout << t << "\n";
    while(t--) {
        int n = rnd.next(max(1,nn-5),nn);
        cout << n << "\n";
        Array p = Array::id(n,1).shuffled();
        Array hide = Array::randomUnique(rnd.wnext(n,wt), n);
        vector<bool> h(n,1);
        for(int i:hide)h[i]=0;
        for(int i=0;i<n;++i){
            if(h[i]) cout<<p[i];
            else cout<<"-1";
            cout<<" \n"[i==n-1];
        }
    }
}
int main(int argc, char** argv){
    registerGen(argc, argv);
    if(stoi(argv[1]) == 1) allcases(stoi(argv[2]),stoi(argv[3]));
    else gen(stoi(argv[2]),stoi(argv[3]),stoi(argv[4]));
}
