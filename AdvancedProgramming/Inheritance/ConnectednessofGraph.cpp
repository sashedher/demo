#include<bits/stdc++.h>
using namespace std;


int main() {
    long long int N,M,u,v,r,ra,vi=0;
    cin>>N>>M;
    vector<bool> V(N,false);
    vector<long long int> Nde[N];
    vector<long long int> queue;
    
    for(long long int i=0;i<M;i++){
        cin>>u>>v;
        Nde[u].push_back(v);
        Nde[v].push_back(u);
    }
    long long int l=log2(N/(0.01*M));
    //cout<<"l "<<l<<endl;
    srand(time(0));
    for(long long int k=1;k<=l;k++){
        
        r=ceil(4*l*N/(pow(2,k-1)*0.01*2*M));
        
        
        for(long long int f=0;f<r;f++){
               for(long long int s=0;s<N;s++){
                   V[s]=false;
               }
            vi=0;
            queue.clear();
            ra=rand()%(N+1);
            V[ra]=true;
            queue.push_back(ra);
            while(queue.size()!=0 && vi<pow(2,k)){
                //cout<<"bfs\n";
                ra=queue[0];
                for(long unsigned int i=0;i<Nde[ra].size();i++){
                if(V[Nde[ra][i]]==false){
                    queue.push_back(Nde[ra][i]);
                    V[Nde[ra][i]]=true;
                }
            }
                
                vi++;
                queue.erase(queue.begin());
            }
            if(vi>=pow(2,k)) continue;
            else {
                cout<<"NO";
            return 0;
            }
            
        }
        

    } 
    cout<<"YES";
    return 0;
}