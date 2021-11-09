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
        cout<<"______________________ite-"<<i<<"_______________________\n";
        g=G[i];
        flag=0;
        S.clear();
        sort(T.begin(),T.end());
        for(j=0;j<T.size();j++){
            if(g+T[j]>=800 && g+T[j]<=1000){
                S.push_back(T[j]);
                cout<<"creating set S\n";
            }
        }
        cout<<i<<" "<<S.size()<<" "<<T.size()<<"\n"<<"set S :";

        for(auto &i:S){
                cout<<i<<" ";
            }
            cout<<endl;
        if(S.size()!=0){
             cout<<"checking set S\n";
            sort(S.begin(),S.end());
            d=S[0];
            sc=sc-S[0]-g;
            it=lower_bound(T.begin(),T.end(),d);
            T.erase(it);
        }
        else if(T.size()!=0){
            cout<<"checking set T   \n";
            for(j=T.size()-1;j>=0;j--){
                if(T[j]+g<=1000){
                    T[j]=T[j]+g;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                sc=sc-g;
            }
        }
        else break;
        cout<<"set T :";
        for(auto &i:T){
                cout<<i<<" ";
            }
        cout<<endl;
        cout<<"present scrap weight : "<<sc<<"\n";
    }  
    cout<<"final scrap weight :"<<sc<<"\n";
 
 
 
    return 0;
}