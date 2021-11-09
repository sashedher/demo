#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<limits>
using namespace std;
#define  LL long long

int main() {
    LL int i,j,n,W,H,wi,hi,inf,Ar=0,c,k;
    inf=10000009;
    cin>>n>>W>>H;
    vector<pair<int,int>> A;
    int **M= new int*[n+1];
    for(i=0;i<=W;i++){
        M[i]=new int[W+1]{0};
    }
    for (i=0;i<n;i++){
        cin>>wi>>hi;
        Ar+=wi*hi;
        A.push_back(make_pair(wi,hi));
    }
    sort(A.begin(),A.end(),greater<>());
    cout<<endl;
    M[0][0]=0;
    for(i=1;i<=W;i++){M[0][i]=inf;}
    for(i=0;i<=n;i++){M[i][0]=0;}
    
    for(i=1;i<=n;i++){
        for(j=1;j<=W;j++){
            if(j-A[i-1].first<0){
                M[i][j]=M[i-1][j];
            }
            else{
                M[i][j]=min((M[i-1][j-A[i-1].first]+(A[i-1].first*A[i-1].second)),M[i-1][j]);
            }
        }
    }
    c=inf+1;
    for(k=0;k<=W;k++)
   {
       if(M[n][k]== inf||c<=M[n][k]) continue;
       for(i=n,j=k;(i>=0 && j>=0);){
                    
                    if(i==0){
                        if(c>M[n][k])
                        c=M[n][k];
                        break;
                    }
                    else if (j==0)
                    {
                        
                                        if(A[i-1].first<=(W-k))
                                        {
                                            //cout<<M[n][k]<<"  \n";
                                            break;
                                        }
                                        else
                                        {
                                        if(c>M[n][k])
                                            c=M[n][k];
                                            break;
                                        }
                        
                    
                        }            
        else if(M[i-1][j]>M[i-1][j-A[i-1].first]+(A[i-1].first*A[i-1].second)){
            i--;
            j=j-A[i-1].first;
        }
        else {
            if(A[i-1].first<=(W-k))
            {
                break;
            }
            else
            {
               if(c>M[n][k])
                c=M[n][k];
                break;
            }
            
           
            }
        }
    


   }
   cout<<Ar-c<<endl;
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"_____________________\n";
    for (int i=0; i<n; i++) { 
        cout << A[i].first << " "<< A[i].second << endl; 
    }
    for(i=0;i<=W;i++){
        delete[] M[i];
    }
    delete[] M;
    return 0;
}
