#include<bits/stdc++.h>

using namespace std;


int solve(int a,int b){

    int mini = INT_MAX;
    for(int c=a;c<=b;c++){
        mini = min (mini, (c-a) + (b-c));
    }   
    return mini;
}
int main(){


    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);

    int t;
    cin>>t;
    int a,b;
    while(t--){
            cin>>a>>b;
            cout<<solve(a,b)<<endl;
    }
} 