//Spoj
//https://www.spoj.com/problems/MICEMAZE/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e,t,m;
    cin>>n>>e>>t>>m;

    vector<vector<pair<int,int>>> graph(n);

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        y--,x--;
        graph[y].push_back({w,x});
    }

    vector<int> vis(n);

    set<pair<int,int>> q;
    q.insert({0,--e});
     
    int res=0;
    
    while(!q.empty()){
       auto P = q.begin();
       auto p=*P;
       q.erase(P);
       int w = p.first;
       int node = p.second;
       vis[node]=1;
        res++;
        
        for(auto &child:graph[node]){
            if(vis[child.second]) continue;
            if(w+child.first<=t){
                q.insert({w+child.first,child.second});
                vis[child.second]=1;
            }
        }

    }

    cout<<res;

}
 