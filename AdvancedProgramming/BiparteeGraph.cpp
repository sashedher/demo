#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include<bits/stdc++.h>
using namespace std;


int main() {
    long long int N,M,u,v,c=1,f=0;
    cin>>N>>M;
    vector<int> Vis(N,2);
    vector<long long int> Nde[N];
    vector<long long int> queue;
    
    for(int i=0;i<M;i++){
        cin>>u>>v;
        Nde[u].push_back(v);
        Nde[v].push_back(u);
    }
    srand(time(0));
    int L,K;
    L=rand()%N;
    K=rand()%N;
    for(int j=0;j<K;j++){
        c=1;
        f=1;
        v=rand()%N;
        int p=0;
        while(p<L){
            Vis[v]=c++;
            while(queue.size()!=0){
                u=rand()%(Nde[v].size());
                if(Nde[v].size()!=0 && Vis[u]==2){
                    queue.push_back(v);
                    v=u;
                    f=1;
                    break;
                }
                else if(f==0){
                    v=queue[queue.size()-1];
                    queue.erase(queue.end());
                }
            }
            p++;
            
            
            if(Vis[u]!=2 && Vis[u]==j%2)
            L++;
        }
        
    }














    
    return 0;
}