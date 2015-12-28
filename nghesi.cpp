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
    void nhap();
    void xuat();
    int get_catxe();
};
void NS :: nhap(){
    cout<<"\n Nhap ten nghe si: ";
    cin.ignore(1);
    cin.get(TenNS, 30);
    cout<<"\n Nhap so dien thoai: ";
    cin.ignore(1);
    cin.get(sdt, 15);
    cout<<"\n catxe: ";
    cin>>catxe;
    cout<<endl;
}
void NS :: xuat(){
    cout<<"\n Ten nghe si: "<<TenNS;
    cout<<"\n So dien thoai: "<<sdt;
    cout<<"\n catxe: "<<catxe;
    cout<<endl;
}
int NS ::get_catxe(){
    return catxe;
}
int main(int argc, char** argv) {
    NS *ns,tg;
    int n, tong=0;
    cout<<"\n Nhap so nghe si: ";
    cin>>n;
    ns= new NS[n+1];
    // nhap danh sach nghe si
    for(int i=1;i<=n;i++){
        cout<<"\n Nhap nghe si thu "<<i<<": ";
        ns[i].nhap();
    }
    //sap xep nghe si theo thu tu giam dan catxe
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(ns[i].get_catxe()<ns[j].get_catxe()){
                tg=ns[i];
                ns[i]=ns[j];
                ns[j]=tg;
            }
        }
    // in danh sach nghe si da sap xep.
    for(int i=1;i<=n;i++)
        ns[i].xuat();
    // tinh tong so catxe cua nghe si;
    for(int i=1;i<=n;i++){
        tong+=ns[i].get_catxe();
    }
    cout<<"\n tong catxe cua nghe si la: "<<tong;
    cout<<endl;
    return 0;
}

