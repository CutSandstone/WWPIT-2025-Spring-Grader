#include "../../lib/jngen.h"
#include <bits/stdc++.h>
using namespace std;
void gen(int n, int m, int q, int k, int cnt, int qSize) {
    //cnt = expected number of unique numbers in the grid
    //qSize = number of times to reroll query bounds (higher = larger query size)
    Random r;
    r.seed(n^m^q^k^cnt^qSize);
    cout << n << " " << m << " " << q << "\n";
    vector grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(r.next(n*m/cnt)==0){
                grid[i][j] = r.next(1, k);
            } else {
                int dx=0,dy=-1;
                if(r.next(2)==0)swap(dx, dy);
                int nx=i+dx, ny=j+dy;
                if(min(nx,ny)>=0){
                    grid[i][j]=grid[nx][ny];
                } else {
                    swap(dx,dy);
                    nx=i+dx,ny=j+dy;
                    if(min(nx,ny)>=0){
                        grid[i][j]=grid[nx][ny];
                    } else grid[i][j]=r.next(1,k);
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)cout<<grid[i][j]<<" \n"[j==m-1];
    }
    for(int i = 0; i < q; i++) {
        pair<int,int> one = r.nextp(1,n,odpair);
        pair<int,int> two = r.nextp(1,m,odpair);
        for(int j=0;j<qSize;++j){
            pair<int,int> one1=r.nextp(1,n,odpair);
            pair<int,int> two1=r.nextp(1,m,odpair);
            one={min(one.first,one1.first),max(one.second,one1.second)};
            two={min(two.first,two1.first),max(two.second,two1.second)};
        }
        cout << one.first << " " << two.first << " " << one.second << " " << two.second << " " << r.next(1, min(one.second-one.first, two.second-two.first)) << "\n";
    }
}
int main(int argc, char** argv){
    registerGen(argc, argv);
    gen(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]),stoi(argv[4]),stoi(argv[5]),stoi(argv[6]));
}
