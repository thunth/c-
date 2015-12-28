#include <cstdlib> 
#include <stdio.h> 
#include <iostream>
using namespace std;
class DT 
{ 
private: 
    int n;//bac cua da thuc 
    int *a;//mang chua he so da thuc 
public: 
    DT(){n=0;a=NULL;} 
    DT(int n1){n=n1;a = new int [n];} 
    ~DT(){n=0;delete a;} 
    friend ostream& operator<<(ostream&,DT &); 
    friend istream& operator>>(istream&,DT &); 
    DT operator+(DT &); 
    DT operator-(DT &); 
}; 
istream &operator>>(istream &is, DT &d) 
{ 
    cout<<"\nBac da thuc n= "; 
    cin>>d.n; 
    d.a = new int[d.n+1]; 
    cout<<"\nNhap cac he so cua da thuc: "; 
    for(int i=0;i<=d.n;i++) 
    { 
        cout<<"a["<<i<<"]= "; 
        is>>d.a[i]; 
    } 
    return is; 
} 
ostream &operator<<(ostream &os, DT &d) 
{ 
    //os<<"- Da thuc: "; 
//    for(int i=0;i<=d.n;i++) 
//    { 
//        os<<d.a[i]<<"x^"<<i;
//        if(i!=d.n) 
//            cout<<" + "; 
//    } 
//    return os;
    os<<"\n bac:"<<d.n;
        os<<"\n he so: ";
        for(int i=0;i<=d.n;i++){
            os<<d.a[i]<<"\t";
        }
        cout<<endl;
        return os;
} 
DT DT::operator+(DT &d) 
{ 
    int nmax = (n>d.n)?n:d.n; 
    int nmin = (n<d.n)?n:d.n; 
    DT sum(nmax); 
    for(int i=nmax;i>nmin;i--) 
        sum.a[i]=(n==nmax)?a[i]:d.a[i]; 
    for(int i=0;i<=nmin;i++)    
        sum.a[i]=a[i]+d.a[i]; 
    return sum; 
} 
DT DT::operator-(DT &d) 
{ 
    int nmax = (n>d.n)?n:d.n; 
    int nmin = (n<d.n)?n:d.n; 
    DT sub(nmax); 
    for(int i=0;i<=nmin;i++)
        sub.a[i]=a[i]-d.a[i]; 
    for(int i=nmax;i>nmin;i--) 
        sub.a[i]=(n==nmax)?a[i]:d.a[i]; 
    return sub; 
} 
int main() 
{ 
//    clrscr(); 
    DT a,b; 
// DT c(3); 
    cout<<"\nNhap da thuc a: "; cin>>a; 
    cout<<"\nNhap da thuc b: "; cin>>b; 
    cout<<"\n\t  a: "<<a; 
    cout<<"\n\t  b: "<<b; 
    DT sum = a+b; 
    cout<<"\n\ta+b: "<<sum; 
    DT sub = a-b; 
    cout<<"\n\ta-b: "<<sub; 
    cout<<endl;
//    getch(); 
}  