<<<<<<< HEAD
#include "jngen.h"
#include <bits/stdc++.h>
=======
#include "bits/stdc++.h"
#define JNGEN_DISABLE_IO_OVERLOADS
#include <iomanip>
#include "jngen.h"
>>>>>>> 0d9f1dbe3507d44b3788f292a35b097846e16053
using namespace std;
using ld=long double;
using ll=long long;

void gen(int t, int nn, int qq, int mx) {
    //mx is the max that any element reaches, not the sum
    cout << t << "\n";
    while(t--) {
        int n = rnd.next(max(1,nn-5),nn);
        int q = rnd.next(max(1,qq-5),qq);
        cout << n << " " << q << "\n";
        vector<ld> p(n);
        for(int i=0;i<n;++i)p[i]=rnd.nextf();
        sort(p.begin(),p.end());
        vector<ll> a(n);
        for(int i=0;i<n;++i)a[i]=rnd.next(1,mx);
        ll sum = accumulate(a.begin(),a.end(),0LL);
        for(int i=0;i<n;++i){
            static_cast<std::ostream&>(cout)<<fixed<<setprecision(6)<<p[i]<<" \n"[i==n-1];
        }
        for(int i=0;i<n;++i){
            cout<<a[i]<<" \n"[i==n-1];
        }
        while(q--){
            cout << rnd.next(1LL,(ll)(sum*1.1)) << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv);
    char* p;
    gen(strtol(argv[1], &p, 10),strtol(argv[2], &p, 10),strtol(argv[3], &p, 10),strtol(argv[4], &p, 10));
}
