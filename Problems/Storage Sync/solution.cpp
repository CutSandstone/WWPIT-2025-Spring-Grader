#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while(t--){
        int n; cin >> n;
        vector<int> a(n),b(n);
        for(int& i: a) cin >> i;
        for(int& i: b) cin >> i;
        vector<string> ops;
        function<void(int,int,bool)> swapOps = [&](int i, int j, bool arr){
            string other = arr ? "A" : "B";
            ops.push_back("2 " + to_string(i+1));
            ops.push_back("1 "+other+" "+to_string((j-i+n)%n));
            ops.push_back("2 " + to_string(j+1));
            ops.push_back("1 "+other+" "+to_string((i-j+n)%n));
            ops.push_back("2 " + to_string(i+1));
            if(arr) swap(b[i],b[j]);
            else swap(a[i],a[j]);
        };
        map<int,set<int>> mp;
        for(int i = 0; i<n; i++) mp[a[i]].insert(i);
        for(int i = 0; i<n; i++){
            int ind = *mp.begin()->second.begin();
            mp.begin()->second.erase(ind);
            if(mp.begin()->second.size() == 0) mp.erase(mp.begin()->first);
            if(ind == i) continue;
            mp[a[i]].erase(i);
            mp[a[i]].insert(ind);
            swapOps(i,ind,0);
        }
        for(int i = 0; i<n; i++) mp[b[i]].insert(i);
        for(int i = 0; i<n; i++){
            int ind = *mp.begin()->second.begin();
            mp.begin()->second.erase(ind);
            if(mp.begin()->second.size() == 0) mp.erase(mp.begin()->first);
            if(ind == i) continue;
            mp[b[i]].erase(i);
            mp[b[i]].insert(ind);
            swapOps(i,ind,1);
        }
        cout << ops.size() << "\n";
        for(auto& a: ops) cout << a << "\n";
    }
}
