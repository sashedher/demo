#include<iostream>
using namespace std;
class Node
{
    private:
        int data;
        Node* prev, *next;
    public:
    Node()
    {
        // Implement Constructor
    }
    Node(int d)
    {
        // Implement Constructor
        prev=NULL;
        next=NULL;
        data=d;
    }
    Node* getNext() { return next;}
    Node* getPrev() { return prev;}
    void setNext(Node *ptr) { next = ptr;}
    void setPrev(Node *ptr) {prev = ptr;}
    int getdata(){return data;}
    
};

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        //int mini,pusum=0,posum=0;
    public:
    LinkedList()
    {
        // Implement Constructor
        head=NULL;
        tail=NULL;
    
    }
    Node* cempty(){
        return head;
    }
    void insert(int x)
    {  

        Node* temp=new Node(x);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            temp->setPrev(tail);
            tail->setNext(temp);
            tail=tail->getNext();
        }
       
    }
    void remove()
    { 
        if(head==NULL){
            cout<<"Empty stack\n";
            return;
            }
        else{
            Node * temp;
            temp=tail;
            tail=tail->getPrev();
            delete temp;
        }
    }
    Node* getTop(){
        if(head==NULL) return NULL;
        return tail;
    }
    int mini(){
        Node* temp;
        int i=0;
        for(temp=tail;temp!=NULL;temp=temp->getPrev()){
                if(temp->getdata()<=i) i=temp->getdata();
        }
        return i;
    }
    int sums(){
        Node* temp;
        int i=0;
        for(temp=tail;temp!=NULL;temp=temp->getPrev()){
                 i+=temp->getdata();
        }
        return i;
    }
};

class Stack
{
    private:
        LinkedList list_obj;
    
    public:
    Node* temp;
    int i;
    void push(int d){
        list_obj.insert(d);

    }
    int pop(){
        int i=0;
        if(list_obj.cempty()){
           i=getTop();
           return i;
        }
    }
    int getTop(){
        
        temp=list_obj.getTop();
        if(list_obj.cempty()){
            cout<<"stack empty\n";
            return 0;
        }
        return temp->getdata();
        
    }
    int getMin(){
        if(list_obj.cempty()) cout<<"stack empty\n";
     return list_obj.mini();  
    }
    int getSum(){
        if(list_obj.cempty()) return 0;
       return  list_obj.sums();
    }
};
int main(){
    long long int i,j,q,n;
    Stack s;
    cin>>n;
    while (n--){
        cin>>q;
        switch (q)
        {
        case 0:
                cin>>i;
                s.push(i);
            break;
        case 1:
                
               j=s.pop();
               if(j!=0){
                cout<<j<<"\n";
               }
            break;
        case 2:
                j=s.getTop();
                if(j!=0){
                    cout<<j<<"\n";
                }
            break;
        case 3:
               j=s.getMin();
               if(j!=0)
                cout<<j;
            break;
        case 4:
                j=s.getSum();
                if(j==0) cout<<"0";
                else cout<<j<<"\n";
            break;

        default:
            break;
        }
        
    }
    
    return 0;
}