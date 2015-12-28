/* 
 * File:   book.cpp
 * Author: hoaithu
 *
 * Created on December 6, 2015, 11:17 PM
 */

#include <cstdlib>
#include<iostream>
#include<string.h>
using namespace std;

/*
 * xay dung lop book
 * + thuoc tinh: ma sach, ma ten, ten tac gia, nam xuat ban, nha xuat ban;
 * + phuong thuc: ham tao, nhap, xuat, va cac ham khac
 * viet ham main thuc hien cong viec;
 * -nhap vao n dau sach
 * - tim tat ca cac sach cua mot tac gia cho truoc(nhap tu ban phim)
 */
class Book{
private:
    char nhaxb[20],ma_s[10], ma_t[10], tentg[30];// ma sach;
    int namxb;
public:
    Book(){
        strcpy(ma_s,"");
        strcpy(ma_t,"");
        strcpy(tentg,"");
        strcpy(nhaxb,"");
        int nam=1;
    }
    void Nhap(){
        cout<<"\n Nhap ma sach: ";
        cin.ignore(1);
        cin.get(ma_s, 10);
        cout<<"\n Nhap ma ten: ";
        cin.ignore(1);
        cin.get(ma_t, 10);
        cout<<"\n Nhap ten tac gia: ";
        cin.ignore(1);
        cin.get(tentg, 30);
        cout<<"\n Nhap nha xuat ban: ";
        cin.ignore(1);
        cin.get(nhaxb, 20);
        cout<<"\n Nhap nam xuat ban: ";
        cin>>namxb;
    }
    void xuat(){
        cout<<"\n"<<ma_s<<"\t"<<ma_t<<"\t"<<tentg<<"\t"<<nhaxb<<"\t"<<namxb;
    }
   char *get_tentg(){
            return tentg;
    }
};
int main(int argc, char** argv) {
    Book *b;
    int n;
    char tenTG[30];
    cout<<"\n nhap so luong sach; ";
    cin>>n;
    b=new Book[n+1];
    // nhap danh sach
    cout<<"\n Nhap danh sach: ";
    for(int i=1;i<=n;i++){
        cout<<"\n Nhap dau sach thu "<<i<<":";
        b[i].Nhap();
    }
    // in danh sach 
    for(int i=1;i<=n;i++){
        cout<<"\n dau sach thu "<<i<<":";
        b[i].xuat();
    }
    //in dau sach cua tac gia
    cout<<"\n Nhap ten tac gia; ";
    cin.ignore(1);
    cin.get(tenTG, 30);
    cout<<"\n dau sach cua tac gia thu la: ";
    for(int i=1;i<=n;i++){
        if(strcmp(tenTG,b[i].get_tentg())==0)
            b[i].xuat();
    }
    cout<<endl;

    return 0;
}

