#include<iostream>

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
        int count=0;
        Node **T;
public:
        void creatArray(int s){
            T=new Node*[s];
            
        }
        void insertNode(int x){
            T[count]=new Node(x,NULL,NULL);
            count++;
            if(root==NULL){
                root=T[0];
            }
        }
        
        void preorder(Node *root){
            if(root){
                cout<<root->getData()<<" ";
                preorder(root->getLeft());
                preorder(root->getRight());
                
            }
        }
        void print(){
            int i;
            for(i=0;i<count;i++){
                cout<<T[i]->getData()<<" ";
            }
        }
        int Primecheck(int x){
            int i,c=0;
            for(i=2;i<x;i++){
                if(x%i==0){
                    c++;
                }
            }
            if(c==0){
                return 1;
            }
            else{return 0;} 
        }
        // int palindrome(int x){

        // }

        ~Binary(){
            for( int i=0;i<count;i++){
                delete T[i];
            }
            delete[] T;
        }

        
};





int main(){
    int n,m=0,i;
    //char o;
    Binary* B= new Binary;
    cin>>m;
    int *Ar=new int[m];                
    for(i=0;i<m;i++){
        cin>>Ar[i];
    }
    B->creatArray(m);
    for(i=0;i<m;i++){
        B->insertNode(Ar[i]);
        
    }

   B->print();
    delete[] Ar;
    return 0;
}










// while(n--){
//         cin>>o;
//         switch (o)
//         {
//         case 'i':   cin>>m;
//                     int *Ar=new int[m];
                    
//                     for(i=0;i<m;i++){
//                         cin>>Ar[i];
//                     }
//                     B->insertNode(Ar,m);                    
                    
                    

//             break;
//         case 'a':
//             break;
//         case 'b':
//             break;
//         case 'c':
//             break;
//         default:
//             break;
//         }

//     }