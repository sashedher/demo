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
        double add(double a,double b){return a+b;}
        double sub(double a,double b){return a-b;}
        double mul(double a,double b){return a*b;}
        void cadd(Complex N1,Complex N2){
            cout<<fixed<<setprecision(3)<<add(N1.real,N2.real)<<" "<<add(N1.imag,N2.imag)<<"\n";
        }
       void csub(Complex N1,Complex N2){  
            cout<<fixed<<setprecision(3)<<sub(N1.real,N2.real)<<" "<<sub(N1.imag,N2.imag)<<"\n";
        }
        void cmul(Complex N1,Complex N2){
            cout<<fixed<<setprecision(3)<<sub(mul(N1.real,N2.real),mul(N1.imag,N2.imag))<<" "<<add(mul(N1.real,N2.imag),mul(N1.imag,N2.real))<<"\n";
        }
    ~Complex(){}
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
       void Rmul(Rational R1,Rational R2){
            cout<<fixed<<setprecision(3)<<Complex::mul(R1.num,R2.num)/Complex::mul(R1.denom,R2.denom)<<"\n";
        }
        void Radd(Rational R1,Rational R2){
             cout<<fixed<<setprecision(3)<<Complex::add(Complex::mul(R1.num,R2.denom),Complex::mul(R1.denom,R2.num))/Complex::mul(R1.denom,R2.denom)<<"\n";
        }
        void Rsub(Rational R1,Rational R2){
            cout<<fixed<<setprecision(3)<<Complex::sub(Complex::mul(R1.num,R2.denom),Complex::mul(R1.denom,R2.num))/Complex::mul(R1.denom,R2.denom)<<"\n";
        }
        long long int gcd(long long int x,long long int y){
             if(y==0)
                return x;
            else{
        
               return  gcd(y,x%y);
            }
        
             return 0;
        }
        void reduce(Rational R1){
            long long int g,r1,r2;
            r1=R1.num>R1.denom?R1.num:R1.denom;
            r2=R1.num<R1.denom?R1.num:R1.denom;
            g=gcd(r1,r2);
            if((R1.denom/g)<0){
                cout<<-(R1.num/g)<<" "<<-(R1.denom/g)<<"\n";
            }
            else{
                cout<<(R1.num/g)<<" "<<(R1.denom/g)<<"\n";
            }
        }
    ~Rational(){}

};
class Natural:public Rational{
    public:
     void isPrime(long long int num){
         long long int i;
         if(num<2){
             cout<<"0\n";
             return;
         }
         if(num==2 || num==3){
             cout<<"1\n";
             return;
         }
         for (i=2;i<sqrt(num);i++){
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
        if(y==1){
                  return t2;
            }
        else{
              return Multinvrse(y,x%y,t2,t);
        }
    }
    void InverseModulo(long long int num){
        long long int p,r1,r2;
            r1=num>1000000007?num:1000000007;
            r2=num<1000000007?num:1000000007;
        p=Multinvrse(r1,r2,0,1);
        if(p<0){
            p=1000000007+p;
            cout<<p<<"\n";
        }
        else{
            cout<<p;
        }
    }
    ~Natural(){}
};




int main(){
    int t;
    string s1,s2;
    double x1,x2;
    long long int p,q;
    Complex c,*a[2];
    Rational r;
    Natural n;
    // a[0]=&r;
    // a[1]=&n;
    cin>>t;
    while(t--){
        cin>>s1>>s2;       
        if(s1=="complex"){
            cin>>x1>>x2;
            Complex c1(x1,x2);
            cin>>x1>>x2;
            Complex c2(x1,x2);
            if(s2=="add") c.cadd(c1,c2);
            else if(s2=="mult") c.cmul(c1,c2);
            else if(s2=="sub") c.csub(c1,c2);
        }
        else if(s1=="rational"){
            if(s2=="add"){
                cin>>p>>q;
                Rational r1(p,q);
                cin>>p>>q;
                Rational r2(p,q);
                r.Radd(r1,r2);
            } 
            else if(s2=="mult"){
                cin>>p>>q;
                Rational r1(p,q);
                cin>>p>>q;
                Rational r2(p,q);
                 r.Rmul(r1,r2);
            }
            else if(s2=="sub") {
                cin>>p>>q;
                Rational r1(p,q);
                cin>>p>>q;
                Rational r2(p,q);
                r.Rsub(r1,r2);
            }
            else if(s2=="reduce"){
                cin>>p>>q;
                Rational r1(p,q);
                 r.reduce(r1);
            }
        }
         else if(s1=="natural"){
            if(s2=="isprime"){
                cin>>p;
                n.isPrime(p);
            }
             else if(s2=="inverse"){
                cin>>p;
                n.InverseModulo(p);
            }
        }

            
    }

    return 0;
}
