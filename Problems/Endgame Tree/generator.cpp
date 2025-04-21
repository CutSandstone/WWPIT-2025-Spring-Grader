#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;

void gen1(int n){
    int t = n/14;
    cout << t << "\n";
    while(t--){
        cout << "7 7\n";
        for(int i = 0; i<7; i++) cout << rnd.next()%2 << " \n"[i==6];
        Tree tr = Tree::random(7).shuffled();
        cout << tr.add1() << "\n";
        for(int i = 0; i<7; i++) cout << rnd.next()%7+1 << "\n";
    }
}

void gen2(int n){
    n /= 20;
    int sqr = max(1, int(sqrt(n)/2));
    cout << "10\n";
    for(int t = 10; t--;){
        cout << n << " " << n << "\n";
        Tree tr = Tree::random(n).shuffled();
        vector<vector<int>> g(n);
        for(auto& a: tr.edges()){
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        vector<bool> val(n);
        function<void(int,int)> dfs = [&](int s,int p){
            if(p != -1) val[s] = !val[p];
            for(int i: g[s]) if(i != p)
                dfs(i,s);
        };
        dfs(0,-1);
        for(int i = 0; i<n; i++) cout << val[i] << " \n"[i==n-1];
        cout << tr.add1() << "\n";
        set<int> cur;
        bool removing = false;
        for(int x = n; x--;){
            if(removing){
                if(cur.empty()){
                    removing = false;
                    int v = rnd.next()%n + 1;
                    cur.insert(v);
                    cout << v << "\n";
                } else {
                    int v = *cur.begin();
                    cur.erase(v);
                    cout << v << "\n";
                }
            } else {
                int v = -1;
                do { v = rnd.next()%n + 1; } while(cur.count(v));
                cur.insert(v);
                cout << v << "\n";
                if(rnd.next()%sqr == 0) removing = true;
            }
        }
    }
}


void gen3(int n) {
    n /= 15;
    int sqr = max(1, int(sqrt(n/2)/2));
    cout << "10\n";
    for(int t = 10; t--;){
        cout << n << " " << n/2 << "\n";
        for(int i = 0; i<n; i++) cout << 0 << " \n"[i==n-1];
        Tree tr = Tree::random(n).shuffled();
        cout << tr.add1() << "\n";
        set<int> cur;
        bool removing = false;
        for(int x = n/2; x--;){
            if(removing){
                if(cur.empty()){
                    removing = false;
                    int v = rnd.next()%n + 1;
                    cur.insert(v);
                    cout << v << "\n";
                } else {
                    int v = *cur.begin();
                    cur.erase(v);
                    cout << v << "\n";
                }
            } else {
                int v = -1;
                do { v = rnd.next()%n + 1; } while(cur.count(v));
                cur.insert(v);
                cout << v << "\n";
                if(rnd.next()%sqr == 0) removing = true;
            }
        }
    }
}

void gen4(int n) {
    n /= 20;
    int sqr = max(1, int(sqrt(n)/2));
    cout << "10\n";
    for(int t = 10; t--;){
        cout << n << " " << n << "\n";
        Tree tr = Tree::randomPrim(n,-20).shuffled();
        vector<vector<int>> g(n);
        for(auto& a: tr.edges()){
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        vector<bool> val(n);
        function<void(int,int)> dfs = [&](int s,int p){
            if(p != -1) val[s] = !val[p];
            for(int i: g[s]) if(i != p)
                dfs(i,s);
        };
        dfs(0,-1);
        for(int i = 0; i<n; i++) cout << val[i] << " \n"[i==n-1];
        // print the tree edges
        cout << tr.add1() << "\n";
        vector<int> degs(n);
        for(int i = 0; i<n; i++) degs[i] = g[i].size();
        sort(degs.begin(),degs.end());
        int t5 = degs[degs.size()-5];
        set<int> canRm;
        for(int i = 0; i<n; i++){
            if(g[i].size() >= t5) canRm.insert(i);
            for(int j: g[i]) if(g[j].size() >= t5)
                canRm.insert(i);
        }
        vector<int> canRmV(canRm.begin(),canRm.end());
        set<int> cur;
        bool removing = false;
        for(int x = n; x--;){
            if(removing){
                if(cur.empty()){
                    removing = false;
                    int v = canRmV[rnd.next()%canRmV.size()]+1;
                    cur.insert(v);
                    cout << v << "\n";
                } else {
                    int v = *cur.begin();
                    cur.erase(v);
                    cout << v << "\n";
                }
            } else {
                int v = -1;
                do { v = canRmV[rnd.next()%canRmV.size()]+1; } while(cur.count(v));
                cur.insert(v);
                cout << v << "\n";
                if(rnd.next()%sqr == 0 || cur.size() >= canRmV.size()/2) removing = true;
            }
        }
    }
}

void gen5(int n) {
    n /= 30;
    cout << "10\n";
    for(int t = 10; t--;){
        cout << n << " " << n*2 << "\n";
        int root = rnd.next()%n;
        for(int i = 0; i<n; i++) cout << (i == root) << " \n"[i==n-1];
        Tree tr = Tree::randomPrim(n,-1).shuffled();
        cout << tr.add1() << "\n";
        vector<vector<int>> g(n);
        for(auto& a: tr.edges()){
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        vector<vector<int>> dep;
        function<void(int,int,int)> dfs = [&](int s, int p, int d){
            if(dep.size() == d) dep.push_back({});
            dep[d].push_back(s);
            for(int i: g[s]) if(i != p) dfs(i,s,d+1);
        };
        dfs(0,-1,0);
        int mx = 0;
        for(int i = 1; i<dep.size(); i++) if(dep[i].size() > dep[mx].size())
            mx = i;
        for(int x = 2*n; x--;)
            if(rnd.next()%10 == 0)
                cout << root+1 << "\n";
            else cout << dep[mx][rnd.next()%dep[mx].size()]+1 << "\n";
    }
}

int main(int argc, char** argv){
    registerGen(argc, argv);
    int which = stoi(argv[1]);
    int n = stoi(argv[2]);
    switch(which){
        case 1: gen1(n); break;
        case 2: gen2(n); break;
        case 3: gen3(n); break;
        case 4: gen4(n); break;
        case 5: gen5(n); break;
    }
}
