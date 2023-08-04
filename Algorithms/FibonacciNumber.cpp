//Fibonacci no --> o(n);
//--> log(n);

#include<bits/stdc++.h>
using namespace std;

class matrix{
    public:
    vector<vector<int>> m={{1,1},{1,0}};
     

    matrix operator*(matrix &x){
        matrix temp;
        temp.m[0][0]= (this->m[0][0]*x.m[0][0])+(this->m[0][1]*x.m[1][0]);
        temp.m[0][1]= (this->m[0][0]*x.m[0][1])+(this->m[0][1]*x.m[1][1]);
        temp.m[1][0]= (this->m[1][0]*x.m[0][0])+(this->m[1][1]*x.m[1][0]);
        temp.m[1][1]= (this->m[1][0]*x.m[1][0])+(this->m[1][1]*x.m[1][1]);
        return temp;
    }


};

int OFun(int n){
    //
    if(n==1||n==2) return 1;
    return OFun(n-1)+OFun(n-2);
}

//creating class for matrix;


int logFun(int n){
    // for log(n) complexity we have to use matrix 
    //{                   
    //   1(=fn+1) 1(=fn)
    //   1(=fn)   0(=fn-1)   
    //} matrix power of(n)
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
    int n;
    cin>>n;
    cout<<OFun(n)<<endl;
    cout<<logFun(n);
}