//codeforces
//https://codeforces.com/problemset/problem/199/A

 
#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

void fun(){
    dp.push_back(0);
    dp.push_back(1);
    while(dp[dp.size()-1]<=1e9){
        dp.push_back(dp[dp.size()-1]+dp[dp.size()-2]);
    }
}

vector<int> sum(int i ,int n){
    if(i>=4) return{dp[i-1],dp[i-3],dp[i-4]};
    if(i==3) return{1,1,0};
    if(i==2||i==1) return{1,0,0};
    return {0,0,0};
}

int main(){
    fun();
    int n;
    cin>>n;
    
     
    auto it = find(dp.begin(),dp.end(),n);
    
    auto res = sum(it-dp.begin(),n);

    for(auto &r:res){
        cout<<r<<" ";
    }


}