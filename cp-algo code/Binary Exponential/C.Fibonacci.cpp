
//question
//https://codeforces.com/problemset/gymProblem/102644/C

//sol
//https://cp-algorithms.com/algebra/fibonacci-numbers.html#practice-problems

//codeforces 
//TC : O(log(n))
 

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

//class for matrix 
class matrix{
    public:
    vector<vector<long long>> m={{1,1},{1,0}};
    

    matrix operator*(matrix &x){
        matrix temp;
        temp.m[0][0]= (((this->m[0][0]*x.m[0][0])%mod)+((this->m[0][1]*x.m[1][0])%mod))%mod;
        temp.m[0][1]= (((this->m[0][0]*x.m[0][1])%mod)+((this->m[0][1]*x.m[1][1])%mod))%mod;
        temp.m[1][0]= (((this->m[1][0]*x.m[0][0])%mod)+((this->m[1][1]*x.m[1][0])%mod))%mod;
        temp.m[1][1]= (((this->m[1][0]*x.m[0][1])%mod)+((this->m[1][1]*x.m[1][1])%mod))%mod;
        return temp;
    }


};

 


long long logFun(long long n){
     
    matrix res,st;
    res.m={{1,0},{0,1}};
    while(n){
        if(n%2) res = res*st;
        st = st*st;
        n=n/2;
    }
    return res.m[0][1];
    
    
}

int main(){
    long long n;
    cin>>n;
     
    cout<<logFun(n);
}