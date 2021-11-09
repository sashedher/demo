#include<iostream>
#include<cmath>
 
using namespace std;
class Node {
      private:
         int data;
         Node *left,*right;
    public:
        Node(int d,Node* n,Node* p){
            data=d;
            left=n;
            right=p;
        }
 
        Node* getLeft(){return left;}
        Node* getRight(){return right;}
        void setRight(Node* n){right=n;}
        void setLeft(Node* p){left=p;}
        int getData(){return data;}
};
 
class Binary{
private:
        Node * root=NULL;
        int count=0,primsum=0,rsum=0,lsum=0,palinsum=0,power=1;
        Node **T;
public:
        void creatArray(int s){
           
            if(count==0){
            T=new Node*[s];
            }
            else{
            s=count+s;
            Node** It=new Node*[s];
            for(int i=0;i<count;i++){
                It[i]=T[i];
            }
            T=It;
            It=NULL;
            }
        }
        void insertNode(int *B,int x){
            int i;
                 if(count==0){
                     for(i=0;i<x;i++){
                         T[count]=new Node(B[i],NULL,NULL);
                         count++;
                     }
                 }
            else{
                for(i=0;i<x;i++){
                    T[count]=new Node(B[i],NULL,NULL);
                    count++;
                }
            }   
            
            root=T[0];
            for(i=0;i<=((count-1)/2);i++){
                if(2*i<count-1){
                    T[i]->setLeft(T[2*(i+1)-1]);
                }
                if((2*i+1)<count-1){
                    T[i]->setRight(T[2*(i+1)]);            
                }
            }
            cout<<"\n"<<root->getData()<<"=root\n";
        }
        
        int Primenumcheck(int x){
            int i,c=0;
            for(i=1;i<=x;i++){
                if(x%i==0){
                    c++;
                }
            }
            if(c==2){
                return 1;
            }
            else{return 0;} 
        }
        
        void call(){
            primsum=0;
            primeGrandrec(T[0]);
            cout<<"primsum="<<primsum;
        }
       
        void primeGrandrec(Node *xx){
            if(xx!=NULL){
                primeGrand(xx);
                cout<<xx->getData()<<" ";
                primeGrandrec(xx->getLeft());
                primeGrandrec(xx->getRight()); 
            }
        }
        
        void primeGrand(Node *temp){
            if(temp!=NULL){
                if(Primenumcheck(temp->getData())){
                    if(temp->getLeft()!=NULL && temp->getLeft()->getLeft()!=NULL){
                        primsum=primsum+(temp->getLeft()->getLeft()->getData());
                    }
                        if(temp->getLeft()!=NULL && temp->getLeft()->getRight()!=NULL){
                        primsum=primsum+(temp->getLeft()->getRight()->getData());
                        }
                        if(temp->getRight()!=NULL && temp->getRight()->getLeft()!=NULL){
                        primsum=primsum+(temp->getRight()->getLeft()->getData());
                    }
                        if(temp->getRight()!=NULL && temp->getRight()->getRight()!=NULL){
                        primsum=primsum+(temp->getRight()->getRight()->getData());
                        }
                }
            }
            
        }
        void callz(){
            lsum=0,rsum=0;
            ziglf(root->getLeft());
            rsum=lsum;
            lsum=0;
            zagri(root->getRight());
            if(lsum>=rsum){
                cout<<lsum+(root->getData());
            }
            else
            {
                cout<<rsum+(root->getData());
            }
            
        }
        void ziglf(Node *p){
            if(p){
                lsum+=p->getData();
                zagri(p->getRight());

            }
        }
        void zagri(Node * q){
            if(q){
                lsum+=q->getData();
                ziglf(q->getLeft());
            }
        }
        void calllv(){
            int j;
            lvltree(root,2);
            cout<<palinsum<<" =ssssssssss";
           j= palincheck(palinsum);
            if(j==1){
                cout<<palinsum;
            }
            else{

            }

        }
        void lvltree(Node * q,int l){
            if(l==0 && q){
                cout<< q->getData()<<" ";
                palindrome(q->getData());
                
            }
            else{
                lvltree(q->getLeft(),l-1);
                 lvltree(q->getRight(),l-1);
            }

        }
        void palindrome(int xy){
            
            if(palinsum==0){
                palinsum=xy;
            }
            else{
                palinsum=palinsum*10+xy;
            }
        }
        int palincheck(int nu){
            int te,r;
            te=nu;
            while(nu){
                r=r*10+nu%10;
                nu/=10;
            }
            if(r==te){
                return 1;
            }
            else{return 0;}
        }
       
    
    
    
    
        void print(){
            int i;
            cout<<"\n";
            for(i=0;i<count;i++){
                cout<<T[i]->getData()<<" ";
            }
            cout<<"count="<<count<<"\n";
        }
         ~Binary(){
            for( int i=0;i<count;i++){
                delete T[i];
            }
            delete[] T;
        }
 
};
 
int main(){
    int n,m=0,i,p=0;
    //char o;
    Binary *Bin=new Binary;
    // Binary *Bin2=new Binary;
    cin>>m;
    int *Ar=new int[m];                
    for(i=0;i<m;i++){
        cin>>Ar[i];
    }
   
    
    Bin->creatArray(m);
    Bin->insertNode(Ar,m);
    Bin->print();
 
    Bin->creatArray(m);
    Bin->insertNode(Ar,m);
    Bin->print();
    cout<<"okkkkkkkkkkk";
    cout<<"prime sum="<<p;
    cout<<"______________________________\n";
    //Bin->call();
    //Bin->callz();
    Bin->calllv();
    delete[] Ar;
    return 0;
}
