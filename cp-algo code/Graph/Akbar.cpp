//SPOJ
//https://www.spoj.com/problems/AKBAR/


#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;

        vector<vector<long long>> path(n);

        for(long long i=0;i<m;i++){
            long long x,y;
            cin>>x>>y;

            x--,y--;
            path[x].push_back(y);
            path[y].push_back(x);
        }

        vector<long long> vis(n,-1);

        bool res = true;

        for(long long i=0;i<k;i++){
            long long node, str;
            cin>>node>>str;

            long long parent=node--;
            
            if(vis[node]!=-1) {
                res = false;
                continue;
            }

            queue<pair<long long,long long>> q;
            q.push({node,str});
            vis[node]=parent;

            while(!q.empty()){
                auto p = q.front();
                long long node = p.first;
                q.pop();

                str=p.second;
                str--;

                if(str>=0){
                    for(auto &p:path[node]){
                        if(vis[p]==-1){
                            vis[p]=parent;
                            q.push({p,str});
                        }else{
                            if(vis[p]!=parent){
                                res = false;
                            }
                        }
                    }
                }
            }

        }

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                res = false;
            }
        }

        if(res){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

    }
}