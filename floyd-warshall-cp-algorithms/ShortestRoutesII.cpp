#include<bits/stdc++.h>
using namespace std;
#define ll long long
// https://cses.fi/problemset/task/1672/



vector<vector<ll>> solve(vector<vector<ll>>&mat,ll n){
for(ll i=1;i<=n;i++){
    mat[i][i] =0;
}
for(ll k=1;k<=n;k++)
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(mat[i][k]<1e18 &&mat[k][j]<1e18)
            mat[i][j] = min(mat[i][k] + mat[k][j] ,mat[i][j]);
        }
        }

return mat;
}

int main(){
    


    // freopen("./input.txt","r",stdin);
    // freopen("./output.txt","w",stdout);


    ll n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>>mat(n+1,vector<ll>(n+1,1e18));

ll a,b,c;
    while(m--){
        
        cin>>a>>b>>c;
        mat[a][b] = min(c,mat[a][b]);
        mat[b][a] = min(c,mat[b][a]);

    }

   vector<vector<ll>>ans=solve(mat,n);

 ll s,d;
    while(q--){
       
        cin>>s>>d;
        ans[s][d]==1e18?cout<<-1<<endl:cout<<ans[s][d]<<endl;
    }

}
