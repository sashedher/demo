#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int k,n,i,cp=1000,sum=0,sc=0;
    cin>>k>>n;
    int *A=new int[n];
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A, A + n, greater<int>());
    i=0;
    while(k){
        cp=1000;
        for(;i<n;i++){
            if(A[i]<=cp)
                cp-=A[i];
            else {
                //i--;
                break;
            }
        }
        k--;
    }
    for(;i<n;i++){
        sc+=A[i];
    }
    cout<<sc<<"\n";
    return 0;
}
