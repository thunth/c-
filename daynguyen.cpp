/* 
 * File:   daynguyen.cpp
 * Author: hoaithu
 *
 * Created on December 7, 2015, 8:23 PM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>

using namespace std;

/*
 * xay dung lop day nguyen
 * - thuoc tinh: so phan tu cua day va mot day xac dinh cac phan tu cua day
 * - phuong thuc: ham tao, ham huy, toan tu nhap, xuat
 *   + ham dem va in cac phan tu la so nguyen to cua day
 * viet chuong trinh nhap vao mot day va in day do ra man hinh 
 * dong thoi dem va in cac phan tu la so nguyen
 */
int kt(int N){
    if(N==1)
        return 0;
    if(N==2)
        return 1;
    if(N%2==0)
        return 0;
    for(int i=2;i<=sqrt(N);i++){
        if(N%i==0)
            return 0;
        else
            return 1;
    }
}
class DN{
private:
    int n; // so phan tu cua day
    int *a;// mang luu giu cac phan tu cua day
public:
    DN(){
        n=0;
        a=NULL;
    }
    ~DN(){
        n=0;
        delete a;
    }
    friend ostream& operator<<(ostream &os, DN &d){
        for(int i=0;i<d.n;i++){
            os<<d.a[i]<<"\t";
            //cout<<endl;
        }
        return os;
    }
    friend istream& operator>>(istream &is, DN &d){
        cout<<"\n Nhap so luong phan tu cua day: ";
        cin>>d.n;
        d.a=new int[d.n+1];
        for(int i=0;i<d.n;i++){
           cout<<"\n a["<<i+1<<"]=";
           cin>>d.a[i];
        }
        return is;
    }
    void NguyenTo(){
        int dem=0;
        for(int i=0;i<n;i++){
            if(kt(a[i])==1){
                cout<<"\n so nguyen to la: ";
                cout<<a[i]<<"\t";
                dem++;
            }
            
        }
        cout<<"\n co "<<dem<<" so nguyen to";
    }
};
int main(int argc, char** argv) {
    DN nt;
    cout<<"\n nhap day nguyen to.";
    cin>>nt;
    cout<<"\n xuat day nguyen to: "<<nt;
    nt.NguyenTo();
    cout<<endl;

    return 0;
}

