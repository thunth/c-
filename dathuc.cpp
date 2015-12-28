/* 
 * File:   dathuc.cpp
 * Author: hoaithu
 *
 * Created on November 28, 2015, 3:39 PM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>
using namespace std;

/*
 * 
 */
class DT{
private:
   int n;// bac cua da thuc
   int *hs; //he so cua da thuc;
public:
    DT(){
        n=0;
        hs=NULL;
    }
    DT(int n1){
        n=n1;
        hs=new int[n];
    }
    ~DT(){
        n=0;
        delete(hs);
    }
    friend istream& operator>>(istream& is, DT &d){
        cout<<"\n Nhap bac cua da thuc: ";
        is>>d.n;
        d.hs=new int[d.n+1];
        cout<<"\n Nhap he so cua da thuc: ";
        for(int i=0;i<=d.n;i++){
            cout<<"\n Nhap he so thu "<<i<<": ";
            is>>d.hs[i];   
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, DT &d){
        os<<"\n bac cua da thuc: "<<d.n;
        os<<"\n he so cua da thuc: ";
        for(int i=0;i<=d.n;i++){
            os<<d.hs[i]<<"  ";
        }
        return os;
    }
    DT operator+(DT &d){
        int nmax=(n>d.n) ? n: d.n;// bac lon nhat cua da thuc tong;
        int nmin=(n<d.n) ? n: d.n;// bac nho nhat cua da thuc tong;
        DT sum(nmax);
        for(int i=nmax;i>nmin;i--)
            sum.hs[i]= (n==nmax)?hs[i]: d.hs[i];
        for(int i=0; i<=nmin;i++){
            sum.hs[i]=hs[i]+d.hs[i];
        }
        return sum;
            
    }
     DT  operator-(DT &d) 
{ 
    int nmax = (n>d.n)?n:d.n; 
    int nmin = (n<d.n)?n:d.n; 
    DT sub(nmax); 
    for(int i=0;i<=nmin;i++)
        sub.hs[i]=hs[i]-hs[i]; 
    for(int i=nmax;i>nmin;i--) 
        sub.hs[i]=(n==nmax)?hs[i]:d.hs[i]; 
    return sub; 
} 
};
main(int argc, char** argv) {
    DT P, Q, sum, sub;
    cout<<"\n Nhap da thuc P: ";
    cin>>P;
    cout<<"\n da thuc P: "<<P;
    cout<<"\n Nhap da thuc Q: ";
    cin>>Q;
    sum=P+Q;
    cout<<" \n da thuc R= "<<sum;
    cout<<endl;
    sub = P-Q; 
    cout<<"\n\ta-b: "<<sub; 
    cout<<endl;

    return 0;
}

