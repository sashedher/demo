#include<iostream>
using namespace std;
void Hmirror(int* B,long long int n,long long int m){
    long long int i=0,t,k,w;
    for(i=0;i<m/2;i++){
        for(k=0;k<n;k++){
            t=B[(m-i-1)*n+k];
            B[(m-i-1)*n+k]=B[k+i*n];
            B[k+i*n]=t;
        }
    } 

}
void Vmirror(int* B,long long int n,long long m){
    long long int i=0,t,k,w;
    for(i=0;i<m;i++){
        for(k=0;k<n/2;k++){
            t=B[n*i+k];
            B[n*i+k]=B[(i+1)*n-k-1];
            B[(i+1)*n-k-1]=t;
        }
    } 
}
int  main(){
    long long int m,n,i,j,s=0;
    cin>>m>>n;
    int *A=new int[m*n];
    for(i=0;i<m*n;i++){
        cin>>A[i];
    }
    
    
    Vmirror(A,n,m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<A[j+i*m]<<" ";
        }
        cout<<"\n";
    }

    return 0;

}
// t=B[n*k+i];
//             B[n*k+i]=B[n*(n-1-k)-i];
//             B[n*(n-1-k)-i]=t;