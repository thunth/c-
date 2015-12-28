/* 
 * File:   kt_dathuc.cpp
 * Author: hoaithu
 *
 * Created on December 7, 2015, 10:30 AM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>

using namespace std;

/*
 *xay dung lop da thuc
 * + thuoc tinh gom bac cua da thuc, he so cua da thuc
 * + phuong thuc gom: ham tao khong doi, ham huy, nhap da thuc phuong thuc toan tu
 *  in da thuc, ham ban tinh gia tri cua da thuc tai x0
 *viet ham main thhuc hien cong viec 
 * + nhap mot da thuc, in da thuc do
 * + nhap vao d1 va d2 roi tinh bieu thuc s=sqrt(p(d1)-p(d2))
 * 
 * 
 */
class DT{
private:
    int n;
    float *a;
public:
    DT(){
        n=0;
        a=NULL;
    }
    ~DT(){
     n=0;
     delete a;
    }
    friend ostream& operator<<(ostream& os, DT &d){
        for(int i=0; i<=d.n;i++){
            os<<"\t"<<d.a[i]<<"^x"<<i;
            if(i!=d.n){
                os<<" + ";
            }
        }
        return os;
    }
    friend istream& operator>>(istream& is, DT &d){
        cout<<"\n Nhap bac cua da thuc: ";
        is>>d.n;
        d.a=new float[d.n+1];
        for(int i=0;i<=d.n;i++){
            cout<<"\n a["<<i<<"]=";
            is>>d.a[i];
        }
        return is;
    }
    friend float tinh_gt(DT &d, float m){
        float sum=0;
        for(int i=0;i<=d.n;i++){
            sum+=d.a[i]*pow(m,i);
        }
        return sum;
    }
};

int main(int argc, char** argv) {
    DT P;
    float sum1, sum2, d1, d2;
    cout<<"\n Nhap da thuc P: ";
    cin>>P;
    cout<<"\n Xuat da thuc P: "<<P;
    cout<<"\n Nhap so thuc d1= ";
    cin>>d1;
    cout<<"\n Nhap d2= ";
    cin>>d2;
    sum1=tinh_gt(P, d1);
    sum2=tinh_gt(P, d2);
    if(sum1-sum2>=0)
        cout<<"\n bieu thuc= "<<sqrt(sum1-sum2);
    else
        cout<<"\n Bieu thuc vo nghia.";
//    cout<<"\n gia tri cua da thuc la: "<<sum;
    cout<<endl;
    return 0;
}

