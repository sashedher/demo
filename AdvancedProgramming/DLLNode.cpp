#include<iostream>
using namespace std;

class DNode{
    private:
        int data;
        DNode *next;
        DNode* prev;
    public:
        int getdata(){return data;}
        void setdata(int d){data=d;}
        DNode* getNext(){return next;}
        DNode* getPrev(){return prev;}
        node(int d,DNode* n,DNode* p){
            data=d;
            next=n;
            prev=p;
        }
        
};



class list{
 private:
        DNode::DNode* n;
        DNode::DNode* head;
        DNode::DNode* tail;
 
 public:

        list::list(){
            n=NULL
        }
        int InsertNode(int t){
            node* temp=new node(t,NULL,NULL)
            if(temp==NULL){ return -1;}
            if(n==NULL){
                 n=temp;
                return 0;
            }
            else{
                temp.prev=tail;
               temp.next=head;
               head.prev=temp;
               tail.next=temp;
               head=temp;
                return 0;
            }
        }
        void printList(list* head){
            list* temp;
            while(temp!=tail){
                cout<<temp;
            }
        }






        list::~list{

        }


};
int main(){
     int t,q,c,x,sl;
     char o;
    string a;
    list N;
    cin>>a;
    sl=a.length();  
            for(int i=0;i<sl;i++){
                N.InsertNode(sl[i]);
            }
 returnn 0;
}


















    //  cin>>t;
    //  while(t--){
    //      cin>>a;
    //      cin>>q;
    //      while(q--){
    //          cin>>o>>c>>x;
    //         sl=o.strlen();  
    //         for(int i=0;i<sl;i++){
    //             N.InsertNode(sl[i]);
    //         }


    //          if(o=='a'){
    //              //addition
    //          }
    //          else{
    //              //multiplication
    //          }
    //      }
    //      //cout<<result;
    //  }
   