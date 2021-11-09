#include<bits/stdc++.h>
#define ll long long
#include<queue>
using namespace std;

class liseg{
    public:
    pair<int,int> end1,end2;
    liseg() {};
    int polgno;
    liseg(pair<int,int> p1,pair<int,int> p2,int pno){
        end1=p1;
        end2=p2;
        polgno=pno;
    };
};
bool operator<(const liseg &p,const liseg &q){
    if(p.end1.first!=q.end1.first)
        return p.end1.first>q.end2.first;
    return p.end1.second>q.end2.second;
}
int main(){
    int N,ne,m,u,v=0;
    cin>>N;
    
    vector<pair<int,int>> P[N];
    
    priority_queue<liseg> qu;
    for(int i=0;i<N;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>u>>v;
            P[i].push_back(make_pair(u,v));

        }
    }
    for(int i=0;i<N;i++){
        int l=P[i].size();
        for(int j=0;j<l;j++){    
            qu.push(liseg(P[i][j],P[i][(j+1)%l],i));
            qu.push(liseg(P[i][(j+1)%l],P[i][j],i));
        }
    }
    map<int,int>::iterator j;
    int **Do=new int*[N];
    for(int i=0;i<N;i++){
        Do[i]=new int[N]{};
    }
   
    
    int l=N;
    map<int,int> s;
     for(;!qu.empty();)
     {
              
                 liseg a=qu.top();
                qu.pop();
                    if(a.end1.second>a.end2.second || (a.end1.second==a.end2.second && a.end2.first>a.end1.first)){
                        s.erase(a.end2.second);
                        continue;
                        
                    }
                    else{
                        s.insert({a.end1.second,a.polgno});
                    }
                    
                    for(  j=s.lower_bound(a.end1.second+1);j!=s.end()&&j->first<a.end2.second;j++){
                            ll  f=j->second;
                           // ll g=it->first;
                     //  cout<<f<<vec[i]->y1<<vec[i]->y2<<f<<vec[i]->pol<<pair[f][vec[i]->pol]<<"||";
                           
                            if(Do[f][a.polgno]==0  )
                            {
                                
                                if(f!=a.polgno)
                            {
                                v++;
                                Do[f][a.polgno]=1;
                                Do[a.polgno][f]=1;
                            }
                            else if(f==a.polgno )
                            {
                                l--;
                                Do[f][a.polgno]=1;
                            }
                            }
                            
                        }

                
     } 
    cout<<l<<" "<<v;
  
    

            
    
   // cout<<l<<" "<<v;
    return 0;
    cout<<qu.top().end1.first<<" "<<qu.top().end1.second<<" "<<qu.top().end2.first<<" "<<qu.top().end2.second<<" "<<qu.top().polgno;
    return 0;
}