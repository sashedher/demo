#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

class Complex{
    protected:
        double real,imag;
    public:
        Complex(){}
        Complex(double treal,double timag){
            real=treal;
            imag=timag;
        }
        void add(Complex N1,Complex N2){
            Complex T;
            T.real=N1.real+N2.real;
            T.imag=N1.imag+N2.imag;
            //cout<<T.real<<" "<<T.imag<<"\n";
            cout<<fixed<<setprecision(3)<<T.real<<" "<<T.imag<<"\n";
        }
       void sub(Complex N1,Complex N2){
        Complex T;
            T.real=N1.real-N2.real;
            T.imag=N1.imag-N2.imag;    
            cout<<fixed<<setprecision(3)<<T.real<<" "<<T.imag<<"\n";
        }
        void mul(Complex N1,Complex N2){
            Complex T;
            T.real=(N1.real*N2.real)-(N1.imag*N2.imag);
            T.imag=(N1.real*N2.imag)+(N1.imag*N2.real);
            cout<<fixed<<setprecision(3)<<T.real<<" "<<T.imag<<"\n";
        }

};
class Rational:public Complex{
    protected:
        long long int num,denom;
    public:
        Rational(){}
        Rational(long long int tnum,long long int tdenom){        
            num=tnum;
            denom=tdenom;
        }
        void mul(Rational R1,Rational R2){
            Rational Te;
            Te.num=R1.num*R2.num;
            Te.denom=R1.denom*R2.denom;
            cout<<fixed<<setprecision(3)<<Te.num/Te.denom<<"\n";
        }
        void add(Rational R1,Rational R2){
            Rational Te;
            Te.num=R1.num*R2.denom+R1.denom*R2.num;
            Te.denom=(R1.denom)*(R2.denom);
            cout<<fixed<<setprecision(3)<<Te.num/Te.denom<<"\n";
        }
        void sub(Rational R1,Rational R2){
            Rational Te;
            Te.num=R1.num*R2.denom-R1.denom*R2.num;
            Te.denom=(R1.denom)*(R2.denom);
            cout<<fixed<<setprecision(3)<<Te.num/Te.denom<<"\n";
        }
        long int gcd(long long int x,long long int y){
             if(y==0)
                return x;
            else{
        
               return  gcd(y,x%y);
            }
        
             return 0;
        }
        
        void reduce(Rational R1){
            long long int g;
            if(R1.denom<0){
                R1.denom=-(R1.denom);
                g=gcd(R1.num,R1.denom);
                cout<<-(R1.num/g)<<" "<<R1.denom/g<<"\n";
            }
            else{
                g=gcd(R1.num,R1.denom);
                cout<<R1.num/g<<" "<<R1.denom/g<<"\n";
            }
        }

};
class Natural:public Rational{
    public:
     void isPrime(long long int num){
         long long int i;
         for (i=2;i<num;i++){
             if(num%i==0){
                 cout<<"0\n";
                 return;
             }
         }
         cout<<"1\n";
         return;
     }
    long long int Multinvrse(long long int x,long long int  y,long long int t1,long long int t2){
        long long int t;
        t=t1-(t2*(x/y));
        //cout<<x<<","<<y<<","<<t1<<","<<t2<<","<<t<<"\n";
        if(y==1){
                //cout<< t2;
                return t2;
            }
        else{
              return Multinvrse(y,x%y,t2,t);
        }
    }
    void InverseModulo(long long int num){
        long long int p;
        p=Multinvrse(1000000007,num,0,1);
        if(p<0){
            p=1000000007+p;
            cout<<p<<"\n";
        }
        else{
            cout<<p;
        }
    }
};




int main(){
// Rational x(4,-6);
// Rational y(2,-4);
// Rational z;
// z.reduce(x);
// Natural n;
// n.InverseModulo(396682);
    int t;
    string s1,s2;
    double x1,x2;
    long long int p,q;
    Complex c;
    Rational r;
    Natural n;
    cin>>t;
    while(t--){
        cin>>s1>>s2;       
        if(s1=="complex"){
            cin>>x1>>x2;
            Complex c1(x1,x2);
            cin>>x1>>x2;
            Complex c2(x1,x2);
            if(s2=="add") c.add(c1,c2);
            if(s2=="mul") c.mul(c1,c2);
            if(s2=="sub") c.sub(c1,c2);
        }
        if(s1=="rational"){
            if(s2=="add"){
                cin>>p>>q;
                Rational r1(p,q);
                cin>>x1>>x2;
                Rational r2(p,q);
                r.add(r1,r2);
            } 
            if(s2=="mul"){
                cin>>p>>q;
                Rational r1(p,q);
                cin>>x1>>x2;
                Rational r2(p,q);
                 r.mul(r1,r2);
            }
            if(s2=="sub") {
                cin>>p>>q;
                Rational r1(p,q);
                cin>>x1>>x2;
                Rational r2(p,q);
                r.sub(r1,r2);
            }
            if(s2=="reduce"){
                cin>>p>>q;
                Rational r1(p,q);
                 r.reduce(r1);
            }
        }
        if(s1=="natural"){
            if(s2=="isprime"){
                cin>>p;
                n.isPrime(p);
            }
            if(s2=="inverse"){
                cin>>p;
                n.InverseModulo(p);
            }

        }

            
    }

    return 0;
}








// int prime(int x){
//     int i;
//     if(x==1)
//         return 0;
//     for(i=2;i<x;i++){
//         if(x%i==0){
//             return 0;
//         }
//     }
//     return 1;
// }