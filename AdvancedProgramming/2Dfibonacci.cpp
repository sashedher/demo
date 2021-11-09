#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,b,c,m,n,i,j;
    cin>>a>>b>>c;
    cin>>m>>n;
    vector<int> v;
    int **A= new int*[m+1];
    for(i=0;i<=m;i++){
        A[i]=new int[n+1];
    }
    A[0][0]=a;
    for(i=1;i<=n;i++){
        A[0][i]=b;
    }
    for(i=1;i<=m;i++){
        A[i][0]=c;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            
            A[i][j]=A[i-1][j-1]+max(A[i-1][j],A[i][j-1]);
        }
    }
    cout<<A[m][n]<<"\n";
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(i=m,j=n;(i>=0 && j>=0);){
        if(i==0  && j==0){
            v.push_back(A[i][j]);
            break;
        }
        else{
            v.push_back(A[i][j]);
        }
        if(A[i-1][j]>=A[i][j-1]){
            i--;
        }
        else j--;
    }
    
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    for(i=0;i<=m;i++){
        delete[] A[i];
    }
    delete[] A;
    return 0;
}
