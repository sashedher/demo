#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int a,b;
long long int DCZombiee(long long int *Z,long long int *fr,long long int l,long long int h,int p,long long int of){
    long long int i,pos=l-1,len,nz=0,dc=0,sc1=0,sc2=0;
    if(l>h) return a;
    len=1<<p;
 
    for(i=l;i<=h;i++) {nz+=fr[i];}
    dc=nz*b*len;
    if(len==h-l+1){ return nz*b;}
    for(i=l;i<=h;i++){
        if(Z[i]<=(len/2)+of) pos=i;
        else break;
    }
   
        sc1=DCZombiee(Z,fr,l,pos,p-1,of);
        sc2=DCZombiee(Z,fr,pos+1,h,p-1,of+(len/2));
    
    
    
        if(sc1+sc2<=dc) return sc1+sc2;
    else return dc;
}




int main(){
    int t,n;
    cin>>t;
    while(t--){
        long long int k,i,c=0,f=0,j=0;
        cin>>n>>k>>a>>b;
        long long int* A=new long long int[k]; 
        for(i=0;i<k;i++) cin>>A[i];
        sort(A,A+k);
        for(i=0;i<k;i++){
            if( A[i]!=A[i-1]) c++;
        }
        long long int *city=new long long int[c];
        long long int* freq=new long long int[c];
        for(int i=0;i<k;i++){
                f=1;
                while (A[i]==A[i+1] && i<k-1){
                    f++;i++;
                }
            city[j]=A[i];
            freq[j]=f;
            j++;
        }
        cout<<DCZombiee(city,freq,0,c-1,n,0)<<endl;
        delete[] city;
        delete[] freq;
        delete [] A;
     }
    
    
    return 0;
}