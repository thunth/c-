/* 
 * File:   nghesi.cpp
 * Author: hoaithu
 *
 * Created on November 26, 2015, 8:23 AM
 */

#include <cstdlib>
#include<iostream>
using namespace std;

/*Xay dung lop va chuong trinh de:
 * 1. nhap danh sach n nghe si, moi nghe si gom: ten nghe si, so dien thoai, catxe.
 * 2.sap xep nghe si theo thu tu catxe giam dan 
 * 3. tinh tong catxe cua cac nghe si
 * 
 */
class NS{
private:
    char TenNS[30], sdt[15];
    int catxe;
public:
    friend istream& operator>>(istream& is, NS &ns);
    friend ostream& operator<<(ostream& os, NS ns);
    int get_catxe();
    //friend int tong(NS *ns );
};
istream& operator>>(istream& is, NS &ns){
    cout<<"\n nhap ten nghe si: ";
    is>>ns.TenNS;
    cout<<"\n nhap so dien thoai: ";
    is>>ns.sdt;
    cout<<"\n catxe: ";
    is>>ns.catxe;
    return is;
}
ostream& operator<<(ostream& os, NS ns){
    os<<"\n ten nghe si: "<<ns.TenNS;
    os<<"\n so dien thoai: "<<ns.sdt;
    os<<"\n catxe: "<<ns.catxe;
}

int NS::get_catxe(){
    return catxe;
}

int main(int argc, char** argv) {
    NS *ns, tg;
    int n;
    int tong=0;
    cout<<"\n nhap n= "; cin>>n;
    ns=new NS[n+1];
    // nha danh sach nghe si;
    cout<<"\n Nhap danh sach nghe si";
    for(int i=1;i<=n;i++){
       cout<<"\n nhap nghe si thu: "<<i<<": ";
       cin>>ns[i];
    }
    // sap xep danh sach nghe si theo thu tu catxe giam dan;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(ns[i].get_catxe()<ns[j].get_catxe()){
                tg=ns[i];
                ns[i]=ns[j];
                ns[j]=tg;
            }
        }
    // danh sach nghe si da sap xep;
    for(int i=1;i<=n;i++)
        cout<<ns[i];
    // tong catxe cua cac nghe si la:
    for(int i=1;i<=n;i++){
        tong+= ns[i].get_catxe();
    }
    cout<<"\n tong catxe cua cac nghe si: "<<tong;
    cout<<endl;
    return 0;
}

