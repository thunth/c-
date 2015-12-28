/* 
 * File:   newmain.cpp
 * Author: hoaithu
 *
 * Created on December 7, 2015, 9:32 PM
 */

#include <cstdlib>
#include<iostream>
#include<string.h>
using namespace std;

/*
 * xay dung lop mon hoc
 * - thuoc tinh: ma mon hoc, ten mon hoc, so tin chi
 * - phuong thuc: ham tao, ham nhap xuat va mot so ham neu can
 * xay dung lop quan li mon hoc
 * - thuoc tinh:ma ki hoc, so mon hoc cua ki hoc
 * - phuong thuc: danh sach cac mon hoc cua tung ki, va mot so ham neu can.
 * viet ham main thuc hien cong viec: 
 * - nhap thong tin cho n doi tuong cua lop quan li mat hang
 * - tinh tong so tin chi cua tung ki
 * - cho ki nao sinh vien dang ki nhieu tin chi nhat.
 */
class MonHoc{
private:
    char maMH[30], tenMH[30];
    int tc;//tin chi
public:
    MonHoc(){
       strcpy(maMH, 30);
       strcpy(tenMH, 30);
       tc=0;
       
    }
    void nhap(){
        cout<<"\n Nhap ma mon hoc: ";
        cin.ignore(1);
        cin.get(maMH, 30);
        cout<<"\n Nhap ten mon hoc: ";
        cin.ignore(1);
        cin.get(tenMH, 30);
        cout<<"\n Nhap so tin chi: ";
        cin>>tc;
    }
    void xuat(){
        cout<<maMH<<"\t"<<tenMH<<"\t"<<tc;
    }
    friend class qlmh;
};
class qlmh{
private:
    char maHK[10];
    int soMH;
public:
    void nhap(){
        cout<<"\n Nhap ma hoc ki: ";
        cin.ignore(1);
        cin.get(maHK, 10);
        cout<<"\n Nhap so mon hoc: ";
        cin>>soMH;
        MonHoc *a;
        a= new MonHoc[soMH+1];
        for(int i=1;i<=soMH;i++){
            cout<<"\n Nhap mon thu ["<<i<<"}:";
            a[i].nhap();
        }
    }
    void xuat(){
        cout<<"\t"<<maHK<<"\t soMH";
        for(int i=1; i<=soMH;i++)
            
    }
};
int main(int argc, char** argv) {

    return 0;
}

