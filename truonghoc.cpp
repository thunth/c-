/* 
 * File:   truonghoc.cpp
 * Author: hoaithu
 *
 * Created on December 6, 2015, 4:33 PM
 */

#include <cstdlib>
#include<iostream>
#include<string.h>
#include<stdio.h>
//s#include <cstdio>

using namespace std;

/*
 *xay dung lop nguoi 
 * - thuoc tinh ho te, truong (a,b,c)
 * - phuong thuc tao, nhap, xuat
 * xay dung lop test ke thua tu lop nguoi nhu sau:
 *  class test: public nguoi{
 * ptivate: float diem;
 * public:nhap, xuat, lay diem;
 * viet ham main thuc hien: 
 * nhap vao n nguoi tham gia kiem tra test
 * tinh tong diem cua moi truogn va cho biet truogn nao co diem cao nhat 
 */
class Nguoi{
private:
    char hoten[20];
    char truong[2];
public:
    Nguoi(){
        strcpy(hoten,"");
        strcpy(truong,"");
    }
    void nhap(){
        cout<<"\n Nhap ho ten: ";
        cin.ignore(1);
        cin.get(hoten, 20);
        cout<<"\n Nhap truong: ";
        cin.ignore(1);
        cin.get(truong, 2);
    }
    void xuat(){
        cout<<hoten<<"\t"<<truong;
    }
    int get_truong(){
        if(strcmp(truong,"A")==0)
            return 1;
        if(strcmp(truong, "B")==0)
            return 2;
        if(strcmp(truong, "C")==0)
            return 3;
    }
    
    
};
class Test:public Nguoi{
private:
    float diem;
public:
    void nhap(){
        Nguoi::nhap();
        cout<<"\n Nhap diem: ";
        cin>>diem;
    }
    void xuat(){
        Nguoi::xuat();
        cout<<"\t "<<diem;
    }
    float get_diem(){
        return diem;
    }
};
int main(int argc, char** argv) {
    Test *t;
    int n;
    cout<<"\n Nhap n= ";
    cin>>n;
    t= new Test[n+1];
    // nhap danh sach
    cout<<"\n nhap danh sach";
    for(int i=1;i<=n;i++){
        cout<<"\n Nhap nguoi thu "<<i<<":";
        t[i].nhap();
    }
    // in danh sach 
    cout<<"\n danh sach ";
    for(int i=1;i<=n;i++){
        cout<<"\n Nguoi thu "<<i<<":";
        t[i].xuat();
    }
    // tinh tong diem
    float tong1=0, tong2=0, tong3=0;
    for(int i=1;i<=n;i++){
        if(t[i].get_truong()==1)
            tong1+=t[i].get_diem();
        if(t[i].get_truong()==2)
            tong2+=t[i].get_diem();
        if(t[i].get_truong()==3)
            tong3+=t[i].get_diem();
    }
    cout<<"\n tong diem";
    cout<<"\n truong A ="<<tong1;
    cout<<"\n truong B ="<<tong2;
    cout<<"\n truong C ="<<tong3;
//    float max=tong1;
//    if(max<tong2)
//        max=tong2;
//    if(max<tong3)
//        max=tong3;
//    cout<<"\n truong "<<<<" co diem lon nhat la: "<<max;
//    cout<<"\n tong diem cua truogn a la: "<<tong1;
    if(tong1>tong2 && tong1>tong3)
        cout<<"\n truong A co diem cao nhat la: "<<tong1;
    if(tong2>tong1 && tong2>tong3)
        cout<<"\n truong B co diem cao nhat la: "<<tong2;
    if(tong3>tong1 && tong3>tong2)
        cout<<"\n truong C co diem cao nhat la: "<<tong3;
    cout<<endl;
    return 0;
}

