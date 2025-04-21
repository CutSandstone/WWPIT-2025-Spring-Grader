#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n,m,q;cin>>n>>m>>q;
    vector works(min(n,m)+1,vector(n,vector<int>(m)));
    for(auto&vi:works[0])for(int&i:vi)cin>>i;
    for(int k=1;k<=min(n,m);++k){
        for(int i=0;i<n-k;++i){
            for(int j=0;j<m-k;++j){
                works[k][i][j]=works[k-1][i][j]==works[k-1][i+1][j]&&works[k-1][i][j]==works[k-1][i][j+1]&&works[k-1][i][j]==works[k-1][i+1][j+1]&&works[k-1][i][j]>0;
            }
        }
    }
    vector pre(min(n,m)+1,vector(n,vector<int>(m)));
    for(int k=1;k<=min(n,m);++k){
        for (int i=0;i<n-k;++i){
            for(int j=0;j<m-k;++j){
                pre[k][i][j]=works[k][i][j]+(i>0?pre[k][i-1][j]:0)+(j>0?pre[k][i][j-1]:0)-(i>0&&j>0?pre[k][i-1][j-1]:0);
            }
        }
    }
    while(q--){
        int x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        --x1;--y1;--x2;--y2;
        cout<<(pre[k][x2-k][y2-k]-(x1>0?pre[k][x1-1][y2-k]:0)-(y1>0?pre[k][x2-k][y1-1]:0)+(x1>0&&y1>0?pre[k][x1-1][y1-1]:0))<<'\n';
    }
}
