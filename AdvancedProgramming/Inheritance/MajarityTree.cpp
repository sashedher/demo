#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,l,i,j,s=0,c=0;
    cin>>n;
    l=pow(3,n);
    int **A=new int*[n+1];
    for(i=0;i<=n;i++){
        A[i]=new int[l]{};
        l=l/3;
    }
    l=pow(3,n);
    for(j=0;j<l;j++){
        cin>>A[0][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<l;j++){
            s=s+A[i][j];
            if((j%3==2)){
                if(s>=2){A[i+1][j/3]=1;}
                else {A[i+1][j/3]=0;}
                s=0;
            }
        }
        l=l/3;
    }
    cout<<A[n][0]<<"\n";
    s=0,c=0;
    for(i=n-1,j=0;i>=0;i--,j++){
        c=c*3+j%3;
        s=s+A[i][c];
    }
    cout<<s+A[n][0]<<endl;
    return 0;
}