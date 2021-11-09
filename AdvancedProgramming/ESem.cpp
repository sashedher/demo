#include<bits/stdc++.h>
using namespace std;
int x=0,d=0;
void dfs(int u,vector<long long int> Nde[],int Vis[],int nvis[],int ncycle[]){
    int c=0;
    if(Vis[u]==2)return;
    if(Vis[u]==1){
        x+=1;
        c=d;
        ncycle[c]=x;
        while (c!=u){
            c=nvis[c];
            ncycle[c]=c;
        }
        return;
    }
    nvis[u]=d;
    Vis[u]=1;
        for(unsigned int i=0;i<Nde[u].size();i++){
            if(Nde[u][i]==nvis[u]) continue;
            d=u;
            dfs(Nde[u][i],Nde,Vis,nvis,ncycle);
        }
    Vis[u]=2;

}

int main() {
    long long int n,m,u,v;
    cin>>n>>m;
    vector<long long int> Nde[n];
    int  vis[n]{},nvis[n]{},cycle[n]{};
    for(long long int i=0;i<m;i++){
        cin>>u>>v;
        Nde[u].push_back(v);
        Nde[v].push_back(u);
    }
    dfs(0,Nde,vis,nvis,cycle);
    cout<<x;
    return 0;
}
