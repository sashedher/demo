#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class LandBuying1
{
private:
     int x,y;
public:
    void intiali(int p,int q){
        x=p;
        y=q;
    }
    void sort(LandBuying1 *A,int s){
        LandBuying1 t;
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

    int Binsearch(LandBuying1 a,LandBuying1 c,LandBuying1 *l,int s){
        int x,r,m,co=0,d1;
        x=0,r=s-1;
        
        LandBuying1 b,d;
        b.x=(a.x+c.x-c.y+a.y)/2;        b.y=(c.x-a.x+a.y+c.y)/2;
        d.x=(a.x+c.x+c.y-a.y)/2;        d.y=(a.x-c.x+a.y+c.y)/2;
        do{
            m=(x+r)/2;
            if(b.x ==l[m].x){
                if(b.y==l[m].y){
                    co+=1;
                    break;
                }
                else if(b.y>l[m].y){
                    x=m;
                    continue;
                }
                
            }
            else if(b.x>l[m].x)
                x=m+1;
            else
                r=m-1;
        }while(x>r);
        x=0,r=s-1;
        do{
            m=(x+r)/2;
            if(d.x ==l[m].x){
                if(d.y==l[m].y){
                    co+=1;
                    break;
                }
                else if(d.y>l[m].y){
                    x=m;
                    continue;
                }
                
            }
            else if(d.x>l[m].x)
                x=m+1;
            else
                r=m-1;
        }while(x>r);
        if(co==2){
            d1=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
            return d1;
        }

        return 0;

    }
    
};



int main() {
    int n,i,x,y,j,c=0,a=0,q=0;
    LandBuying1 s,b,d;
    cin>>n;
    LandBuying1 *L=new LandBuying1[n];
    for(i=0;i<n;i++){
        cin>>x>>y;
        L[i].intiali(x,y);
    }
    s.sort(L,n);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            c=s.Binsearch(L[i],L[j],L,n);
                if(a<c)
                    a=c;
                   
        }
    }
    
    cout<<a;
    delete[] L;

    return 0;
}
/*for(i=0,j=n-1;i<j;i++,j--){
            c=s.Binsearch(L[i],L[j],L,n);
            if(a<c && c>0)
                a=c;

    }*/
/*
void prin(){
        cout<<x<<" "<<y<<"\n";
    }

cout<<"===========================\n";
    for(i=0;i<n;i++){
        L[i].prin();
    }
    cout<<"===========================\n";


     int isSquare(LandBuying a, LandBuying c){
        int d1,d2,d3,d4,dg1,dg2;
        LandBuying b,d;
        b.x=(a.x+c.x-c.y+a.y)/2;        b.y=(c.x-a.x+a.y+c.y)/2;
        d.x=(a.x+c.x+c.y-a.y)/2;        d.y=(a.x-c.x+a.y+c.y)/2;
        d1=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        dg1=(a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y);
        dg2=(b.x-d.x)*(b.x-d.x)+(b.y-d.y)*(b.y-d.y);
        d3=(c.x-d.x)*(c.x-d.x)+(c.y-d.y)*(c.y-d.y);
        d4=(a.x-d.x)*(a.x-d.x)+(a.y-d.y)*(a.y-d.y);
        d2=(b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y);
        if(d1==d2 && d2==d3 && d3==d4 && dg1==dg2){
            if(dg1==(2*d1) && dg2==(2*d3)){
                return d1;
            }
        }
        
        return 0;
    }
    */
   /*
      /* int checkSquare(LandBuying a,LandBuying c,LandBuying *l,int s){
        int i,j,q=0,d1;
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
    }*/
    

   
