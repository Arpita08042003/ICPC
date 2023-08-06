//SPOJ
//https://www.spoj.com/problems/NAKANJ/

//NAKANJ - Minimum Knight moves !!!
//BFS;


#include<bits/stdc++.h>
using namespace std;

//define moves('L' shape)
vector<vector<int>> moves={
    {2,1},{1,2},{-2,1},{1,-2},
    {2,-1},{-1,2},{-2,-1},{-1,-2}
};
 
bool isValid(int &x,int &y){
    if(x<0||y<0||x>=8||y>=8) return false;
    return true;
}

int fun(pair<int,int> str,pair<int,int> dst,vector<vector<int>> &vis){
    queue<pair<pair<int,int>,int>> q;
    q.push({str,0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        int level = p.second;
        auto node = p.first;

        if(node==dst) return level;
        if(vis[node.first][node.second]!=-1) continue;
        vis[node.first][node.second]=level;
        level++;

        for(auto &m:moves){
            int x=m[0]+node.first,y=m[1]+node.second;
            if(!isValid(x,y)) continue;
            if(vis[x][y]!=-1) continue;
            q.push({{x,y},level});
        }
    }

}


int main(){
    //
    int t;
    cin>>t;

    while(t--){
        vector<vector<int>> vis(8,vector<int>(8,-1));
        vector<pair<int,int>> v;

        for(int i=0;i<2;i++){
            string s;
            cin>>s;
            v.push_back({s[0]-'a',s[1]-'1'});
        }

        cout<<fun(v[0],v[1],vis)<<endl;
    }
}