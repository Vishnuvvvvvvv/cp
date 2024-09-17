#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr,int n){
    //check whether every i+1 is +1 or -1 to teh ith elemtn
    map<int,int>mp;
    mp[arr[0]]=1;
    //create a map, check if any adj element is visited ,then its fine
    for(int i=1;i<n;i++){
        int el = arr[i];
        mp[el]=1;
        if(( mp[el-1]!=1) && (mp[el+1]!=1) ){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){

    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);

    int t;
    cin>>t;
    int n;

    while(t--){
        cin>>n;
        vector<int>arr(n,0);

        for(int i=0;i<n;i++)
            cin>>arr[i];

        solve(arr,n);

    }

}