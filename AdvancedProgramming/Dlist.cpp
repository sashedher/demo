#include<iostream>

using namespace std;
class Node {
      private:
         int data;
         Node *next,*prev;
    public:
        Node(int d,Node* n,Node* p){
            data=d;
            next=n;
            prev=p;
        }
        Node* getPrev(){return prev;}
        Node* getNext(){return next;}
        void setNext(Node* n){next=n;}
        void setPrev(Node* p){prev=p;}
        int getData(){return data;}
        void setData(int x){data=x;}
};

class Dlist{
private:
    Node* head=NULL,*tail=NULL;
public:
    int count=0;
    Dlist(){
        head=NULL;
        tail=NULL;
    }
    void insertNode(int d){
        count++;
        Node* temp=new Node(d,NULL,NULL);
        if(temp==NULL){return ;}
        if(head==NULL){ 
            head=temp;
            tail=head;
            return;

        }
        else{
            temp->setNext(head);
            head->setPrev(temp);
            head=temp;
            head->setPrev(NULL);
        }
        return;
    }
    void insertTail(int z){
        count++;
         Node* temp=new Node(z,NULL,NULL);
         if(temp==NULL){return ;}
         if(tail==NULL){
             head=temp;
             tail=head;
             return;
         }
        else{
            temp->setPrev(tail);
         tail->setNext(temp);
         tail=tail->getNext();
        tail=temp;
        }
        return;         
    }

    void prinDnode(){
        Node *t;
        t=head;
        while(((t->getData())==0) && t!=NULL){
            t=t->getNext();
        }
        for(;t!=NULL;t=t->getNext()){
            cout<<t->getData();
        }
        cout<<"\n";
    }
    Dlist* lisAdd(Dlist* x,int c,int p){
        p+=1;
        Dlist *ad=new Dlist();
        Node *temp;
        temp=tail;
        while(p--){
            if(temp!=NULL){
            ad->insertNode(temp->getData());
            temp=temp->getPrev();
            }
            else if(p>0){
                ad->insertNode(0);
            }
            else{
                ad->insertNode(c);
            }
        }
        return ad;
    }
    Dlist* lisAddv2(Dlist* x,int p,int c){
        int sum=0,carry=0;
        Dlist *ad= new Dlist();
        Node *temp;
        temp=tail;
        while(p--){
            ad->insertNode(temp->getData());
            temp=temp->getPrev();
           
        }
        carry=c;         
        while(carry!=0) {
            sum=(temp->getData()+carry)%10;
            carry=(temp->getData()+carry)/10;
            temp->setData(sum);
            ad->insertNode(sum);
            temp=temp->getPrev();
                if(!temp) break;
        }
        if (carry!=0)
            ad->insertNode(carry);
        while(temp!=NULL){
            ad->insertNode(temp->getData());
            temp=temp->getPrev();
        }
        return ad;

    }
    Dlist* lisMul(Dlist* x,int c,int p){
        int sum=0,carry=0;
        Dlist *R=new Dlist();
        Node *temp;
        temp=tail;
        while(temp!=NULL){
            sum=((c*(temp->getData()))+carry)%10;
            carry=((c*(temp->getData()))+carry)/10;
            R->insertNode(sum);
            temp=temp->getPrev();
        }
        if(carry)
            R->insertNode(carry);
        while (p--)
        {
            R->insertTail(0);
        }
        return R;
        
    }


    ~Dlist(){
        Node* x= head;
         while ( x!= NULL) {
          Node *temp = x;
          x = x->getNext();
          delete temp; 
      }
    }
};
int main(){
    string num;
    int t,q,c,p,i,sl,tem;
    char o;
    cin>>t;
    while(t--){
        cin>>num;
        cin>>q;    
        Dlist *A=new Dlist();
        sl=num.length();    
        for(i=sl;i>0;i--){
            tem=int(num[i-1])-48;
            A->insertNode(tem);
        }
        while(q--){
        cin>>o>>c>>p;
        
           if(o=='a'){
               sl=A->count;
               if(p>=sl){
                    A=A->lisAdd(A,c,p);
                }
                else{
                    A=A->lisAddv2(A,p,c);
                }

           }
           if(o=='m'){
                A=A->lisMul(A,c,p);
           }
        }
        
     A->prinDnode();
     A=NULL;
    }
    return 0;
}
