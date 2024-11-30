#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define ll long long

/**
 * input:
 * 
 * 7 9
1 2 1
2 3 4
3 4 4
4 5 2
5 1 1
1 6 1
6 7 2
7 4 7
5 3 1
 * 
 * 
output:

0 1 2 3 1 1 3 
1 0 3 4 2 2 4 
2 3 0 3 1 3 5 
3 4 3 0 2 4 6 
1 2 1 2 0 2 4 
1 2 3 4 2 0 2 
3 4 5 6 4 2 0 
8 //length of weights used
1 2
1 5
1 6
3 5
4 5
6 7

 * 
 */


vector<vector<int>>floydWarshall(vector<vector<int>>mat,int n){

    for(int i=1;i<=n;i++){
        mat[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mat[i][k]!=1e9 || mat[k][j]!=1e9)
               
                    mat[i][j] =min(mat[i][j], mat[i][k] + mat[k][j]);
                
            }
        }
    }
return mat;
}


int main(){
 freopen("./input.txt","r",stdin);
    freopen("./output.txt","w",stdout);

    int n,m;

    cin>>n>>m;

    int u,v,wt;

    int totWt=0;
    vector<vector<int>>mat(n+1,vector<int>(n+1,1e9));
    vector<pair<int,pair<int,int>>>edges;
    while(m--){
        cin>>u>>v>>wt;
        totWt+=wt;
        mat[u][v] =wt;
        mat[v][u] = wt;
        edges.push_back({u,{v,wt}});
    }

    mat = floydWarshall(mat,n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    set<pair<int,int>>true_edge;
int req_wt=0;

    for(auto edge:edges){
        bool found =false;
        u = edge.first;
        v = edge.second.first;
        wt = edge.second.second;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                  if (mat[i][j] == mat[i][u] + wt + mat[v][j] || mat[i][j] == mat[i][v] + wt + mat[u][j]) {
                    
                    true_edge.insert({u,v});
                    req_wt+=wt;
                    found=true;
                    break;
                 }
                
                }
                 if(found)break;   
            }
       
            
        
    }

    cout<<req_wt<<endl;

    for(auto edg:true_edge){
        cout<<edg.first<<" "<<edg.second<<endl;
    }

}