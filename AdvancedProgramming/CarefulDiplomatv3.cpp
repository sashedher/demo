#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    long long int k,n,i,flag=0,sc=0,g,d=0,ss=0;
    long unsigned int j;
    cin>>k>>n;
    vector<int> G,S,T;
    vector<int>::iterator it;
    for(i=0;i<n;i++){
        cin>>g;
        sc+=g;
        G.push_back(g);
    }
    sort(G.begin(), G.end(), greater<int>());
    for(i=0;i<k;i++){
        T.push_back(0);
    }
    for(i=0;i<n;i++){
        g=G[i];
        flag=0;
        ss=0;
        sort(T.begin(),T.end());
        if(T.size()){
            for(j=0;j<T.size();j++){
                if(g+T[j]>=800 && g+T[j]<=1000){
                    sc=sc-(g+T[j]);
                    it=lower_bound(T.begin(),T.end(),T[j]);
                    T.erase(it);
                    ss=1;
                    break;
                }
            }
        }
        cout<<i<<" "<<T.size()<<"\n";

        if(ss==0 && T.size()!=0){
            it=lower_bound(T.begin(),T.end(),(800-g));
                if(*it+g<=800){
                    *it=*it+g;
                    flag=1;
                    break;
                }
            
            if(flag==0){
                sc=sc-g;
            }
        }
        else if(T.size()==0) break;
        cout<<"set T :";
        for(auto &i:T){
                cout<<i<<" ";
            }
        cout<<endl;
        cout<<"present scrap weight : "<<sc<<"\n";
    }  
    cout<<sc<<"\n";
 
 
 
    return 0;
}