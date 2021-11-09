#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *p,int* q){
    int t;
    t=*p;*p=*q;*q=t;
}

void sortBub(long int *B,int n){
    int flag,i,j;
    flag=0;
    for(i=n;i>0;i--){
        for(j=0;j<i-1;j++){
            if(B[j]>B[j+1]){
                swap(B[j],B[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
        
    }
}

int main() {
      
    long int t,n,m,x,i,j,s;
    cin>>t;
    while(t--){
        s=0;
        cin>>n>>m>>x;
        long int *M=new long int[m];
        for(i=0;i<m;i++){
            cin>>M[i];
        }
        sortBub(M ,m);
        s+=m;
        if((M[0]-x)>0){
            s=s+x;
        }   
        else{
            s=s+M[0]-1;
        }
        for(i=1;i<m;i++){
            if((M[i-1]+x)>=(M[i]-x)){
                s+=M[i]-M[i-1]-1;
            }
            else{
                s+=2*x;
            }
            
        }
        if((M[m-1]+x)<=n){
            s=s+x;
        }
        else{
            s=s+n-M[m-1];
        }        
        cout<<"\n"<<n-s<<"\n";
        delete[] M;
    }
    return 0;
}