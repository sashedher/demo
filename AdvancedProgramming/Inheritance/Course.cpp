#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bitset>
#include<algorithm>
#include<bits\stdc++.h>
using namespace std;

// don't modify this class
// use this as a base class for different types of courses
class Course {
    public:
    int required_time;
    int forget_time;
    int start;
    int end;
    int id;
    Course(){};
    Course(int tid,int tstart,int tend ,int trequired_time,int tforget_time){
        id=tid;
        start=tstart;
        end=tend;
        required_time=trequired_time;
        forget_time=tforget_time;
    }
    // this method will return the binary representation of course id
    string binary() {
    	string str = bitset<64>(id).to_string();
        return str;
    } 
    // this will check if course id is prime
    bool is_prime() {
        if(id <= 1) return false;
        for(int i = 2; i <= sqrt(id); i++) {
            if(id%i == 0) return false;
        }
        return true;
    }
};

class OnlineCourse : public Course{
    public:
        int type;
        OnlineCourse(){};
        OnlineCourse(int tid,
        int ttype,int tstart,int tend ,int trequired_time,int tforget_time) : Course(tid,tstart,tend,trequired_time,tforget_time ){
            type=ttype;
        }
        void sorttt(vector<pair<int,int>> &V){
         sort(V.begin(),V.end());   
        }
        void prin(){
                cout<<id<<" "<<type<<" "<<start<<" "<<end<<" "<<required_time<<" "<<forget_time<<"\n"; 
        }
        int rangeFirst(vector<pair<int ,int>> V ,int x){
            int l,m,h;
            l=0;
            h=V.size()-1;
            while(l<=h){
                m=(l+h)/2;
                if(V[m].first< x){
                    l=m+1;
                }
                else{
                    h=m-1;
                }

            }
            return m;
        }
        int rangeSecond(vector<pair<int ,int>> V ,int x){
            int l,m,h;
            l=0;
            h=V.size()-1;
            while(l<=h){
                m=(l+h)/2;
                if(V[m].second< x){
                    l=m+1;
                }
                else{
                    h=m-1;
                }

            }
            return m;
        }
        int coursecheck(vector<pair<int ,int>> v,  int s,int e){
            int i,xi;
            xi=required_time;
            for(i=s;i<=e;i++){
                if((v[i].second-v[i].first)>xi){
                    return 1;
                }
                else if(i==s){
                    if(xi!=0) xi=xi-(v[i].second-start);
                    else 
                }
                else if(v[i+1].first-v[i].second>=forget_time){
                    i++;
                    //forgot time more than gap start over from next interval
                    xi=required_time;
                }
                else{
                    if(i==s) xi=xi-v[i].second-start;
                    else  xi=xi-v[i].second-v[i].first;
                }
            }
        }

};


// derive classes for different course types using the above base class



int main() {
	// take input from std input
  	// print to std output
    int n,i,m,n1,n2,m1,m2,m3,m4,m5,m6;
    int s,e,t;
    OnlineCourse o;
    cin>>n>>m;
    OnlineCourse *M=new OnlineCourse[m];
    vector<pair<int,int>> N;
    for(i=0;i<n;i++){
        cin>>n1>>n2;
        N.push_back(make_pair(n1,n2));
    }
    o.sorttt(N);
    
    for(i=0;i<m;i++){
        cin>>m1>>m2>>m3>>m4>>m5>>m6;
          M[i]=OnlineCourse(m1,m2,m3,m4,m5,m6);
    }
    for(i=0;i<m;i++){
            s=o.rangeFirst(N,M[i].start);
            e=o.rangeSecond(N,M[i].end);
            t=M[i].coursecheck(N,s,e);
            if(t==1){
                //course completed;
            }
    }
    
    cout<<"exites\n";
    delete[] M;
    return 0;
}

//driver code
// int **N=new int*[n];
    // int **M=new int*[m];
    // for(i=0;i<n;i++){
    //     N[i]=new int[2];
    //     cin>>N[i][0]>>N[i][1];
    // }
    // for(i=0;i<m;i++){
    //     M[i]=new int[6];
    //     cin>>M[i][0]>>M[i][1]>>M[i][2]>>M[i][3]>>M[i][4]>>M[i][5];
    // }
    // for(i=0;i<n;i++){  
    //     cout<<N[i][0]<<" "<<N[i][1]<<"\n";
    // }
    // for(i=0;i<m;i++){
    //     cout<<M[i][0]<<" "<<M[i][1]<<" "<<M[i][2]<<" "<<M[i][3]<<" "<<M[i][4]<<" "<<M[i][5]<<"\n";
    // }
    // for(i=0;i<n;i++){
    //     delete N[i];
    // }
    // for(i=0;i<m;i++){
    //     delete M[i];
    // }
    // delete[] N;
    // delete[] M;

//for(i=0;i<N.size();i++){
    //     cout<<" hi  "<<N[i].first<<" "<<N[i].second<<"\n";
    // }
    // cout<<o.rane(N,37);
    // // for(i=0;i<m;i++){
    // //     n1=o.rane(N,M[i].start);
    // // cout<<n1<<" "<<M[i].start<<"\n";
    // // }
    // // cout<<"________________________\n";
    // // for(i=0;i<m;i++){
    // //     n1=o.rane(N,M[i].end);
    // // cout<<n1<<" "<<M[i].end<<"\n";
    // // }