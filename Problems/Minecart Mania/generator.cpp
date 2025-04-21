#include "../../lib/jngen.h"
#include "bits/stdc++.h"
using namespace std;
void allcases(int l, int r) {
    int cur = 1;
    for(int i=1;i<l;++i){
        cur*=i;
    }
    int cnt=0;
    for(int i=l;i<=r;++i){
        cur*=i;
        cnt+=cur;
    }
    cout<<cnt<<"\n";
    for(int n=l;n<=r;++n){
        vector<int> p(n);
        iota(p.begin(),p.end(),1);
        do {
            cout<<n<<"\n";
            for(int i=0;i<n;++i){
                cout<<p[i]<<" \n"[i==n-1];
            }
        } while (next_permutation(p.begin(),p.end()));
    }
}
void gen(int t, int nn) {
    cout << t << "\n";
    while(t--) {
        int n = rnd.next(max(1,nn-5),nn);
        cout << n << "\n";
        Array p = Array::id(n,1).shuffled();
        cout << p << "\n";
    }
}
void circle(int t, int nn) {
    cout << t << "\n";
    while(t--) {
        int n = nn;
        cout << n << "\n";
        Array p = Array::id(n,1);
        int offset = rnd.next(n);
        if (rnd.next(2)) p = p.reverse();
        for(int i=0;i<n;++i){
            cout<<p[(i+offset)%n]<<" \n"[i==n-1];
        }
    }
}
int main(int argc, char** argv){
    registerGen(argc, argv);
    switch(stoi(argv[1])){
        case 1: allcases(stoi(argv[2]),stoi(argv[3])); break;
        case 2: gen(stoi(argv[2]),stoi(argv[3])); break;
        case 3: circle(stoi(argv[2]),stoi(argv[3])); break;
    }
}