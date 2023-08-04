#include <bits/stdc++.h>
using namespace std;


// Binary Exponentiation

// -Also known as exponentiation by squaring 
// -Calculating a^n;
// -TimeComplextity of log(n)

//alway try to avoid recursion, although both have same time complexity, but in recursive function there is overhead of recursive cell called


//recursion 

long long mod = 1e9+7;

long long Fun(long long a,long long b){
    if(b==0) return 1;
    long long res = Fun(a,b/2);
    if(b&1) res = (((res*res )%mod)*a )%mod;
    else res=(res*res )%mod;
    return res;
}

//
long long recFun(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1){
            res = (res*a )%mod;}
            a=(a*a )%mod;
            b=b>>1;
        
    }
    return res;
}




int main(){
    long long a,b;
    cin>>a>>b;
    cout<<recFun(a,b)<<endl;
    cout<<Fun(a,b);
}