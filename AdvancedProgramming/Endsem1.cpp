#include<bits/stdc++.h>
using namespace std;


int main() {
    long long int n,m,u,v,count=0,x=0;
    cin>>n>>m;
    vector<long long int> Nde[n];
    vector<long long int> q;
    stack<int> s;
    int  vis[n]{},nvis[n]{},cycle[n]{};

    
    for(long long int i=0;i<m;i++){
        cin>>u>>v;
        Nde[u].push_back(v);
        Nde[v].push_back(u);
    }
    s.push(0);
    int c;
    while(!s.empty()){
        u;
        u=s.top();
        s.pop();
        if(vis[u]==2){
            continue;
        }
        if(vis[u]==1){
            count++;
            c=x;
            cycle[c]=count;
            while(c!=u){
                c=nvis[c];
                cycle[c]=count;
            }
            continue;
        }
        nvis[u]=x;
        vis[u]=1;
        for(int i=0;i<Nde[u].size();i++){
            if(nvis[u]!=Nde[u][i]){
                s.push(Nde[u][i]);
            }
            
            
        }
        vis[u]=2;
        x=u;
    }

    cout<<count<<endl;
    return 0;
}