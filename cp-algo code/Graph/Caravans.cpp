//WA at test case 4;

//https://acm.timus.ru/problem.aspx?space=1&num=2034


#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        --x,--y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int s,f,r;
    cin>>s>>f>>r;
    --s,--f,--r;

    vector<int> dis(n,INT_MAX);

    queue<pair<int,int>> q;
    q.push({0,r});

    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int node = p.second;
        int w = p.first;

        for(auto &child:graph[node]){
            if(dis[child]<=w+1) continue;
            dis[child]=w+1;
            q.push({w+1,child});
        }
    }

    // now find the path from scr to dst;
    // for(auto &D:dis){
    //     cout<<D<<" ";
    // }

    vector<int> rec(n,-1);

    q.push({0,s});
    rec[s]=dis[s];
    int path = INT_MAX;
    int res=-1;

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int node = p.second;
        int w=p.first;
        if(node==f){
            if(w<path){
                res = rec[node];
                path=w;
            } 
            break;
        }
        for(auto &child:graph[node]){
            if(rec[child]!=-1) {
                rec[child]=max(rec[child],rec[node]);
                continue;}
            rec[child]=min(dis[child],rec[node]);
            q.push({w+1,child});
        }
    }

    cout<<res;



}