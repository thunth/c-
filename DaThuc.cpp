                            /* 
 * File:   DaThuc.cpp
 * Author: hoaithu
 *
 * Created on December 7, 2015, 8:03 AM
 */

#include <cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

/*
 *xay dung lop da thuc
 *  thuoc tinh gom: ham tao khong doi, ham huy, phuong thuc toan tu nhap xuat
 *  phuong thuc toan tu cong hai da thuc
 * viet ham main thuc hien cong viec:
 * - nhap hai da thuc:P, Q
 *  - tim da thuc tong R= P+ Q
 *  - in da thuc P, Q, R ra man hinh
 */
class dathuc{
private:
    int n;// bac cua da thuc
    float *a; // he so cua da thuc
public:
    // ham tao
    dathuc(){
        n=2;
        a=NULL;
    }
    dathuc(int n1){
        n=n1;
        a=new float[n];
    }
    ~dathuc(){
        n=0;
        delete a;
    }
    friend ostream& operator<<(ostream& os, dathuc &d){
//        os<<"\n bac:"<<d.n;
        cout<<endl;
        for(int i=0;i<=d.n;i++){
            os<<d.a[i]<<"^x"<<i;
            if(i!=d.n)
                os<<" + ";
        }
        cout<<endl;
        return os;
    }
    friend istream& operator>>(istream& is, dathuc &d){
        cout<<"\n NHap bac cua da thuc: ";
        cin>>d.n;
        d.a=new float[d.n+1];
        for(int i=0;i<=d.n;i++){
            cout<<"\na["<<i<<"]=";
            is>>d.a[i];
        }
        return is;
    }
    dathuc operator+(dathuc &d){
        int i, min;
        dathuc s(n);
        min=n<d.n ? n: d.n;//bac nho nhat cua fa thuc tong
        s.n=n>d.n ? n: d.n;
//        s.a=new float[s.n+1];
        for(i=0;i<=min;i++ ){
            s.a[i]=a[i]+d.a[i];
        }
        for(i=min+1;i<=s.n;i++){
            if(s.n==d.n)
                s.a[i]=d.a[i];
            else
                s.a[i]=a[i];
        }
        return s;
    }
    dathuc operator-(dathuc &d){
        int i,min;
        dathuc h(n);
        min=n<d.n ? n: d.n;
        h.n=n>d.n ? n: d.n;
        for(i=0;i<=min;i++){
            h.a[i]=a[i]-d.a[i];
        }
        
        for(i=min+1;i<=h.n;i++){
            if(h.n==d.n && n>d.n)
            h.a[i]=d.a[i];
            else
                h.a[i]=-d.a[i];
        }
        return h;
        
    }
};
int main(int argc, char** argv) {
    dathuc P,Q;
    cout<<"\n Nhap da thuc P";
    cin>>P;
    cout<<"\n Nhap da thuc Q";
    cin>>Q;
    cout<<" \n P "<<P;
    cout<<" \n Q"<<Q;
    dathuc R=P + Q;
    cout<<"R=P+Q"<<R;
    cout<<endl;
    dathuc d= P- Q;
    cout<<"d=P-Q"<<d;
    cout<<endl;
    

    return 0;
}

