#include<bits/stdc++.h>
using namespace std;

void solve(string num){
    //2 digit positive integer n 
   int sum = (num[0] - '0') + (num[1] - '0');
    cout << sum << endl;
   
    
    }

int main(){

    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cout<<"hy"<<endl;
     int t;
    cin >> t;
    while (t--) {
        string num;
        cin >> num;
        solve(num);  // Call the solve function for each test case
    }

   
}