#include<bits/stdc++.h>
using namespace std;
int main(){
    int dist[5][5]{},k;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>dist[i][j];
        }
    }
    for(k=0;k<5;k++){
        cout<<"\ndist---"<<k<<endl;
        for(int p=0;p<5;p++){
            for(int q=0;q<5;q++){
                cout<<dist[p][q]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
        
    }
    cout<<"\ndist---"<<k<<endl;
        for(int p=0;p<5;p++){
            for(int q=0;q<5;q++){
                cout<<dist[p][q]<<" ";
            }
            cout<<endl;
        }
    return 0;
}
