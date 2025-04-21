#include <bits/stdc++.h>
#define v vector
#define ll long long
using namespace std;
 
const ll mod = (ll) 1e9 + 7;
const ll maxn = (ll) 5e3;
 
ll invFact[2 * maxn + 1];
ll fact[2 * maxn + 1];
 
ll exp(ll num, ll x) {
	if (x == 0) return 1;
	ll res = exp(num, x / 2);
	ll prod = (res * res) % mod;
	if (x & 1) return (prod * num) % mod;
	else return prod;
}
 
ll inv(ll x) {
	return exp(x, mod - 2);
}
 
ll choose(ll n, ll k) {
	if (n < k) return 0;
	return ((fact[n] * invFact[k]) % mod * invFact[n - k]) % mod;
}
 
void solve() {
    int n; cin >> n;
    v<int> p(n);
    for (int &i : p) cin >> i;
 
    int ones = 0;
    v<int> exist(n + 1);
    v<int> leq(n + 1);
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) exist[p[i]]++;
        else ones++;
    }
 
    for (int i = 1; i <= n; i++) {
        leq[i] = leq[i - 1] + (1 - exist[i]);
    }
 
    v<v<ll>> suff(n + 1, v<ll>(n + 2));
    for (int k = 1; k <= n; k++ ) {
        for (int i = n; i >= 0; i--) {
            suff[k][i] = suff[k][i + 1];
            if (exist[i] || i == 0) continue;
            suff[k][i] += (i * choose(leq[i - 1], k - 1)) % mod;
            suff[k][i] %= mod;
        }
    }
 
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        int k = 0;
        int mx = -1;
        
        for (int j = i; j < n; j++) {
            if (p[j] == -1) k++;
            mx = max(mx, p[j]);
 
            ll tot = suff[k][mx + 1];
            if (mx != -1) {
                tot += (mx * choose(leq[mx], k)) % mod;
                tot %= mod;
            }
 
            tot = (tot * fact[k]) % mod;
            tot = (tot * fact[ones - k]) % mod;
            ans = (ans + tot) % mod;
        }
    }
 
    cout << ans << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
 
    fact[0] = 1;
	for (int i = 1; i <= 2 * maxn; i++) {
		fact[i] = ((fact[i - 1] * i) % mod);
	}
 
	for (int i = 0; i <= 2 * maxn; i++) {
		invFact[i] = inv(fact[i]);
	}
 
    int t; cin >> t;
    while (t--) solve();
}
