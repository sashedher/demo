#include<bits/stdc++.h>
using namespace std;
int countZeroes(int arr[], int n) {
        int l=0,h=n-1,m;
        if(n==1){
        if(arr[0]==0) return 1;
        else return 0;
    }
   
    while(l<=h){
         m=(l+h)/2;
        if(arr[m]==1 && arr[m+1]==0) return n-m-1;
        else if(arr[m]==1) l=m+1;
        else if(arr[m]==0) h=m-1;
        
    }
    return n-m;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    cout<<countZeroes(a,n);
    return 0;
}
