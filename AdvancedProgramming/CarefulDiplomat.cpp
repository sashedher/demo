#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    long long int k,n,i,flag=0,sc=0,g,d=0;
    long unsigned int j;
    cin>>k>>n;
    //int *A=new int[n];
    vector<int> G;
    vector<pair<int,int>> S,T;
    for(i=0;i<n;i++){
        cin>>g;
        sc+=g;
        G.push_back(g);
    }
    sort(G.begin(), G.end(), greater<int>());
    // for(i=0;i<n;i++){
    //     cout<<G[i]<<" ";
    // }
    for(i=0;i<k;i++){
        T.push_back(make_pair(0,i));
    }
    for(i=0;i<n;i++){
        flag=0;
        g=G[i];
        for(j=T.size()-1;j>=0;j--){
            if(g+T[j].first>=800 && g+T[j].first<=1000){
               sc=sc-g-T[j].first;
               T.erase(T.begin()+j);                     //segmentation fault may arise
                // S.push_back(make_pair(T[j].first,T[j].second));
                break;
                cout<<"finding set S";
                flag=1;
            }
        }
        cout<<i<<" "<<" "<<T.size()<<"\n";
        if(T.size()!=0 && flag==0){
            cout<<"checking set T   \n";
            for(j=T.size()-1;j>=0;j--){
                if(T[j].first+g<=1000){
                    T[j].first=T[j].first+g;
                    break;
                }
            }         
            
          
        }
        else sc=sc-g;
        sort(T.begin(),T.end());
        for(auto &i:T){
            cout<<i.first<<"  "<<i.second<<"\n";
        }
    }  
    // for(;i<n;i++){
    //     sc=sc+G[i];
    // }
    // for(auto &i:T){
    //     sc+=i.first;
    // }
    cout<<sc<<"\n";
    


    return 0;
}







/*while(l<h){
        //cout<<"_11111111111_ ";
        m=(l+h)/2;
        if(A[m]>=pow(2,p-1)){
            h=m;
        }
        else{
            l=m+1;
        }
    }*/