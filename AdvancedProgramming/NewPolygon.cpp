#include<bits/stdc++.h>
#define ll long long
#define x second
#define y first
using namespace std;

class cc
{
    public:
    ll x1,y1,x2,y2;
    ll hv=-1;
    ll lftr8=2;
    ll pol=-1;
    cc(){}
    cc(ll a, ll b, ll c, ll d,ll p)
    {
        x1=a; y1=b; x2=c; y2=d;pol=p;
    }
};
bool operator<(const cc &a, const cc &b) 
{ 
    if(a.x1!=b.x1) 
        return a.x1>b.x1;
    return a.y1>b.y1;
    
            
}
int main() 
{
    ll n,a,b,c,d,e,f,m;
    cin>>n;
    priority_queue<cc>vec;
    for(ll i=0; i<n ; i++){
        cin>>m;
        cin>>a>>b;
        e=a; f=b;
        for(ll j=1; j<=m; j++)
        {
            if(j==m){
                c=e;
                d=f;
            }
            else cin>>c>>d;
            //h
            if(a==c)
            {
            if(b<d ){
                    vec.push(cc(a,b,c,d,i));
                }
                else{
                    vec.push(cc(c,d,a,b,i));
                }
            }
            else
            {
                    vec.push( cc(a,b,c,d,i));
                    vec.push(cc(c,d,a,b,i));
            }
            
            
            a=c; b=d;
        }
    }
    
    set<pair<int,int>> s;
    pair<int,int> k;
    set<pair<int,int>>::iterator it;
    set<ll> pair[n];
    ll h[n]={0};
    for(ll i=0;i<n;i++)
    {
        h[f]=0;
    }
    ll l=n,v=0;
      for(;!vec.empty();)
     {
              
                 cc a=vec.top();
                 vec.pop();
                if (a.y1==a.y2)
               {
                   if(a.x1<a.x2){k.y=a.y1; k.x=a.pol; s.insert(k);}
                else  {
                        k.y=a.y2; k.x=a.pol; s.erase(k);
                           }
               }
                else
                {
                    if(a.y1>a.y2)
                    {
                        //k.y=a.y1; k.x=a.pol; s.erase(k);
                        continue;
                    }
                    for( it=s.lower_bound({a.y1+1, std::numeric_limits<int>::min()});it!=s.end() && it->first<a.y2; it++)
                    {
                             ll f=it->second;
                            ll g=it->first;
                    
                           
                             if(f!=a.pol)
                            {
                                pair[f].insert(a.pol);
                                pair[a.pol].insert(f);  
                            }
                            else if(f==a.pol && h[f]==0 )
                            {
                                l--;
                               h[f]=1;
                            }
                            
                    }
                    
                                
                }
           
     } 
    v=0;
    for(ll i=0;i<n;i++)
    {
        v+=pair[i].size();
    }  
    cout<<l<<" "<<v/2;
    return 0;
}