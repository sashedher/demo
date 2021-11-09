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
    void intiali(int u,int v){
        x=u;
        y=v;
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
    int sqcheck(LandBuying *p,int s){
        int lx,ly,i,j,n,dis,ar=0,t1,t2,t3,t4;
        cout<<"one\n";
        LandBuying a,b,c,d;
        n=abs(p[s-1].y)+1;
        //cout<<n<<"=n\n";
        lx=p[0].x;
        ly=p[0].y;
        //cout<<lx<<" "<<ly<<endl;
        int **m=new int*[n];
        for(i=0;i<n;i++){
            m[i]=new int[n];
        }
        for(i=0;i<s;i++){
            t1=p[i].x-lx;
            t2=p[i].y-ly;
            m[t1][t2]=1;
            cout<<t1<<" "<<t2<<"\n";
        }
       // cout<<"two";
        for(i=0;i<s-1;i++){
            a=p[i];
            for(j=i+1;j<s;j++){
                c=p[j];
                b.x=(a.x+c.x-c.y+a.y)/2;        b.y=(c.x-a.x+a.y+c.y)/2;
                d.x=(a.x+c.x+c.y-a.y)/2;        d.y=(a.x-c.x+a.y+c.y)/2;
                t1=abs(b.x-lx);t2=(b.y-ly);t3=abs(d.x-lx);t4=(d.x-ly);
                
                if(t1>=0 && t2>=0 && t3>=0 && t4>=0 && t1<=n && t2<=n && t3<=n && t4<=n){
                    if((m[t1][t2] == 1)  &&  (m[t3][t4] == 1)){
                        dis=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
                    }
                }
                
                else{
                    dis=0;
                }
                 if(dis>=ar){
                    ar=dis;
                }
            }
           
        }
        // for(i=0;i<s;i++){
        //     for(j=0;j<s;j++){
        //         cout<<m[i][j]<<" ";
        //     }
        // cout<<"\n";
        // }

        // for(int i = 0; i < n; ++i) 
        //     delete[] m[i];   
        // delete[] m;
        return ar;
    }

    void pri(){
        cout<<x<<" "<<y<<"\n";
    }


};

int main() {
    int n,x,y,i,ar;
    LandBuying s;
    cin>>n;
    LandBuying *L=new LandBuying[n];
    for(i=0;i<n;i++){
        cin>>x>>y;
        L[i].intiali(x,y);
    }
    s.sort(L,n);
    // cout<<"-----------------------------------\n";
    // for(i=0;i<n;i++){
    //     L[i].pri();
    // }
    ar=s.sqcheck(L,n);
    cout<<ar;
    delete[] L;
    return 0;
}