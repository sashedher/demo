#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class LandBuying_BruteForce
{
private:
     int x,y;
public:
    void intiali(int p,int q){
        x=p;
        y=q;
    }
    void sort(LandBuying_BruteForce *A,int s){
        LandBuying_BruteForce t;
        int i,j;
        for(i=0;i<s;i++){
            for(j=i+1;j<s;j++){
                 if(A[i].x>A[j].x){
                        t=A[i];
                        A[i]=A[j];
                        A[j]=t;
                       
                 }
                 else if(A[i].x == A[j].x && A[i].y>A[j].y){
                        t=A[i];
                        A[i]=A[j];
                        A[j]=t;
                        
                }   
            }
        }
    }
    
    int isSquare(LandBuying_BruteForce a,LandBuying_BruteForce b , LandBuying_BruteForce c,LandBuying_BruteForce d){
        int d1,d2,d3,d4,dg1,dg2;
        d1=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        d2=(a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y);
        d3=(b.x-d.x)*(b.x-d.x)+(b.y-d.y)*(b.y-d.y);
        d4=(c.x-d.x)*(c.x-d.x)+(c.y-d.y)*(c.y-d.y);
        dg1=(a.x-d.x)*(a.x-d.x)+(a.y-d.y)*(a.y-d.y);
        dg2=(b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y);
        if(d1==d2 && d2==d3 && d3==d4 && dg1==dg2){
            if(dg1==(2*d1) && dg2==(2*d3)){
                return d1;
            }
        }
        return 0;
    }
    
};



int main() {
    int n,i,x,y,j,k,l,c=0,a=0;
    LandBuying_BruteForce s;
    cin>>n;
    LandBuying_BruteForce *L=new LandBuying_BruteForce[n];
    for(i=0;i<n;i++){
        cin>>x>>y;
        L[i].intiali(x,y);
    }
    s.sort(L,n);
    for(i=0;i<n-3;i++){
        for(j=i+1;j<n-2;j++){
            for(k=j+1;k<n-1;k++){
                for(l=k+1;l<n;l++){
                    c=s.isSquare(L[i],L[j],L[k],L[l]);
                    if(a<c)
                        a=c;
                    
                }
            }
        }
    }
    cout<<a;
    delete[] L;

    return 0;
}
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class LandBuying
{
private:
     int x,y;
public:
    void intiali(int p,int q){
        x=p;
        y=q;
    }
    
    void sort(LandBuying *A,int s){
        LandBuying t;
        int i,j;
        for(i=0;i<s;i++){
            for(j=i+1;j<s;j++){
                 if(A[i].x>A[j].x){
                        t=A[i];
                        A[i]=A[j];
                        A[j]=t;
                       
                 }
                 else if(A[i].x == A[j].x && A[i].y>A[j].y){
                        t=A[i];
                        A[i]=A[j];
                        A[j]=t;
                        
                }   
            }
        }
    }
    
    int checkSquare(LandBuying a,LandBuying c,LandBuying *l,int s){
        int i,q=0,d1;
        LandBuying b,d;
         b.x=(a.x+c.x-c.y+a.y)/2;        b.y=(c.x-a.x+a.y+c.y)/2;
        d.x=(a.x+c.x+c.y-a.y)/2;        d.y=(a.x-c.x+a.y+c.y)/2;
        for(i=0;i<s;i++){
            if(b.x ==l[i].x && b.y==l[i].y )
               q=q+1; 
            if(d.x == l[i].x && d.y==l[i].y )
                q+=1;
        }
        d1=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        if(q==2)
            return d1;
        return 0;
    }
    
};



int main() {
    int n,i,x,y,j,c=0,a=0;
    LandBuying s;
    cin>>n;
    LandBuying *L=new LandBuying[n];
    for(i=0;i<n;i++){
        cin>>x>>y;
        L[i].intiali(x,y);
    }
    s.sort(L,n);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            c=s.checkSquare(L[i],L[j],L,n);
            if(a<c && c>0)
                a=c;
                  
        }
    }
    //for(i=0,j=n-1;i<j;i++,j--){
      //      c=s.checkSquare(L[i],L[j],L,n);
        //    if(a<c && c>0)
          //      a=c;
                  
    //}
    if(a>0)
        cout<<a;
    else
        cout<<"NO";
    delete[] L;

    return 0;
}*/





