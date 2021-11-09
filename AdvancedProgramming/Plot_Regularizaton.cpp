#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class plot_Regularization{
    private: int x1,y1,x2,y2;
    public: 
    void Intiali(int p,int q,int r,int s){
        x1=p;
        y1=q;
        x2=r;
        y2=s;
    }
    int check(plot_Regularization a,plot_Regularization b){
        
        if(a.x2<=b.x1 || b.x2<=a.x1)
            return 0;
        if(a.y2<=b.y1 || b.y2<=a.y1)
            return 0;

        return 1;        
        
    }



};

int main() {
    int t,n,i,j,p,q,r,s,c,k=0;
    cin>>t;
    plot_Regularization cp;
    while(t--){
        c=0;
        k=0;
        cin>>n;
        plot_Regularization *R=new plot_Regularization[n];
        int *A=new int[n]{};
        for(i=0;i<n;i++){
            cin>>p>>q>>r>>s;
            R[i].Intiali(p,q,r,s);
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(i<j){
                    c=cp.check(R[i],R[j]);
                }
                if(c==1){
                    A[i]=1;
                    A[j]=1;
                }
            }
        }
        for(i=0;i<n;i++){
            k+=A[i];
        }
        cout<<k<<"\n";
        delete[] R;
        delete[] A;

    }
    return 0;
}
