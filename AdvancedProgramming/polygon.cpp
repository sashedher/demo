#include<bits/stdc++.h>
using namespace std;
bool simplePolygon(vector<pair<long long int,long long int>> x){
    long long int up,down,left,right;
    long long int l=x.size();
    for(long long int i=l-1;i>1;i++){
        for(long long int j=i-1;j>0;j--){
            up=(x[i].first-x[(j-1)%l].first)*(x[(i-1)%l].second-x[(j-1)%l].second)-(x[(i-1)%l].first-x[(j-1)%l].first)*(x[i].second-x[(j-1)%l].second);
            down=(x[i].first-x[(j-2)%l].first)*(x[(i-1)%l].second-x[(j-2)%l].second)-(x[(i-1)%l].first-x[(j-2)%l].first)*(x[i].second-x[(j-2)%l].second);
            left=(x[(j-1)%l].first-x[i].first)*(x[(j-2)%l].second-x[i].second)-(x[(j-2)%l].first-x[i].first)*(x[(j-1)%l].second-x[i].second);
            right=(x[(j-1)%l].first-x[(i-1)%l].first)*(x[(j-2)%l].second-x[(i-1)%l].second)-(x[(j-2)%l].first-x[(i-1)%l].first)*(x[(j-1)%l].second-x[(i-1)%l].second);
            if( ((up>0 && down <0) || (up<0 && down>0)) && ((left>0 && right<0) || (left<0 && right>0))) return false;
        }
    }
    return  true;
}
bool intersectPolygon(vector<pair<long long int,long long int>> p,vector<pair<long long int,long long int>> q){
    long long int up,down,left,right,l1,l2;
    l1=p.size();
    l2=q.size();
    for(long long int i=0;i<l1;i++){
        for(long long int j=0;j<l2;j++){
            up=(p[i].first-q[j].first)*(p[(i+1)%l1].second-q[j].second)-(p[(i+1)%l1].first-q[j].first)*(p[i].second-q[j].second);
            down=(p[i].first-q[(j+1)%l2].first)*(p[(i+1)%l1].second-q[(j+1)%l2].second)-(p[(i+1)%l1].first-q[(j+1)%l2].first)*(p[i].second-q[(j+1)%l2].second);
            left=(q[j].first-p[i].first)*(q[(j+1)%l2].second-p[i].second)-(q[(j+1)%l2].first-p[i].first)*(q[j].second-p[i].second);
            right=(q[j].first-p[(i+1)%l1].first)*(q[(j+1)%l2].second-p[(i+1)%l1].second)-(q[(j+1)%l2].first-p[(i+1)%l1].first)*(q[j].second-p[(i+1)%l1].second);
            if( ((up>0 && down <0) || (up<0 && down>0)) && ((left>0 && right<0) || (left<0 && right>0))){ 
                
                return true;
            }
        }
    }
    return false;
}
int main(){
    long long int N,m,x,y,simpx=0,interxn=0;
    cin>>N;
    vector<pair<long long int,long long int>> plog[N];
    for(long long int i=0;i<N;i++){
        cin>>m;
        for(long long int j=0;j<m;j++){
            cin>>x>>y;
            plog[i].push_back(make_pair(x,y));
        }
    }
    for(long long int i=0;i<N;i++){
        if(simplePolygon(plog[i])){
            simpx++;            
        }
    }

    for(long long int i=0;i<N-1;i++){
        for(long long int j=i+1;j<N;j++){
            if(intersectPolygon(plog[i],plog[j])){
                interxn++;
            }
        }
    }
    cout<<simpx<<" "<<interxn;
    return 0;
}