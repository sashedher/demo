#include<bits/stdc++.h>
using namespace std;

int main(){
    int C,m,N,q,u,v,x;
    int INF=100000009;
    vector<pair<int,int>> CurCol;
    cin>>C;
    cin>>m;
    int **cGrh= new int*[C];
    for(int i=0;i<=C;i++){
        cGrh[i]=new int[C]{0};
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        cGrh[u][v]=1;
        cGrh[v][u]=1;
    }
    for(int i=0;i<C;i++){
        cGrh[i][i]=1;
    }
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>u;
        CurCol.push_back(make_pair(i,u));
    }
    float forex[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                cin>>forex[i][j];
        }
    }
    cout<<"colour map ------\n";
    for(int i=0;i<C;i++){
        for(int j=0;j<C;j++){
            cout<<cGrh[i][j]<<" ";
        }
        cout<<endl;   
    }
    cout<<"-------------------\n";
    for(int i=0;i<N;i++){
        cout<<CurCol[i].first<<" "<<CurCol[i].second<<endl;
    }
    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j && cGrh[CurCol[i].second][CurCol[j].second]==0){
                    forex[i][j]=-1;
                }
                
            }
    }    
    cout<<"---------------\n";
    cout<<setprecision(3);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<forex[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j)
                    forex[i][j]=max(forex[i][k]*forex[k][j],forex[i][j]);
                else forex[i][j]=0;
            }
        }
    }
    cout<<"---------------\n";
    cout<<setprecision(3);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<forex[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j)
                   if(forex[i][j]< (max(forex[i][k]*forex[k][j],forex[i][j]))){
                        forex[i][j]=INF;
                 }
            }
        }
    }
    cout<<"---------------\n";
    cout<<setprecision(3);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<forex[i][j]<<" ";
        }
        cout<<endl;
    }




    // cin>>q;
    // while (q--){
    //     cin>>u>>v>>x;
    //     maxCurrencyrate();
    // }
    
    return 0;
}
