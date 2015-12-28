/* 
 * File:   hanghoa.cpp
 * Author: hoaithu
 *
 * Created on December 7, 2015, 4:44 PM
 */

#include <cstdlib>
#include <iostream>
#include<string.h>

using namespace std;

/*
 *xay dung lop mat hang
 * cac thuoc tinh: ma hang(chuoi), don gia(kieu nguyen dai)
 * phuong thuc: nhap va cac phuong thuc khac
 *xay dung lop hoa don
 * cac thuc tinh: ma hang( chuoi ), so luong (kieu nguyen), ngay ban (kieu chuoi)
 * phuong thuc: cac phuong thuc nhap va cac phuong thuc khac
 * 
 * viet ham main thuc hien chuong trinh
 * nhap m mat hang
 * nhap n hoa don
 * gia thiet moi hang cua moi hoa don deu co trong mat hang da nhap)
 * dem so hoa don co so luong trong khoang tu 5 den 10
 * tim so tien ban duoc trong ngay cho truoc. 
 */
class MatHang{
private:
    char maH[10];
    long dongia;
public:
    void nhap(){
        cout<<"\n Nhap ma hang: ";
        cin.ignore(1);
        cin.get(maH, 10);
        cout<<"\n Nhap don gia: ";
        cin>>dongia;
    }
    void xuat(){
        cout<<maH<<"\t "<<dongia<<"\t";
        cout<<endl;
    }
    int get_dongia(){
        return dongia;
    }
    char *get_maH(){
        return maH;
    }
    friend class HoaDon;
};
class HoaDon{
private:
    char maH[10], ngayban[10];
    int sl;//so luong;
public:
    void nhap(){
        cout<<"\n Nhap ma hang: ";
        cin.ignore(1);
        cin.get(maH, 10);
        cout<<"\n Nhap ngay ban: ";
        cin.ignore(1);
        cin.get(ngayban, 10);
        cout<<"\n Nhap so luong: ";
        cin>>sl;
    }
    void xuat(){
        cout<<"\t "<<maH<<"\t "<<ngayban<<"\t"<<sl<<"\t";
        cout<<endl;
    }
    int get_sl(){
        return sl;
    }
    char *get_ngayban(){
        return ngayban;
    }
    char *get_maH(){
        return maH;
    }
};
int main(int argc, char** argv) {
    int m, n;
    MatHang *a;
    HoaDon *b;
    cout<<"\n Nhap so mat hang: ";
    cin>>m;
    a=new MatHang[m+1];
    for(int i=0;i<m;i++){
        cout<<"\n Nhap mat hang ["<<i+1<<"]";
        a[i].nhap();
    }
    cout<<"\n xuat mat hang: ";
    for(int i=0;i<m;i++){
        a[i].xuat();
    }
    /// nhap hoa don
    cout<<"\n Nhap so luong hoa don: ";
    cin>>n;
    b=new HoaDon[n+1];
    for(int i=0;i<n;i++){
        cout<<"\n nhap hoa don["<<i+1<<"]";
        b[i].nhap();
    }
    cout<<"\n in hoa don: ";
    for(int i=0;i<n;i++){
        b[i].xuat();
    }
    // dem so hoa co so luong tu tu 5 den 10
    int dem=0;
    for(int i=0;i<n;i++){
        if(b[i].get_sl()>5 && b[i].get_sl()<10)
            dem++;
    }
    cout<<"\n so luong hoa don co sl tu 5 den 10 la: "<<dem;
    // tong tien cua ngay cho truoc.
    char ngay[10];
    cout<<"\n Nhap ngay can tim: ";
    cin.ignore(1);
    cin.get(ngay, 10);
    long tongtien=0;
    for(int i=0;i<n;i++){
        if(strcmp(ngay, b[i].get_ngayban())==0){
           for(int j=0;j<n;j++){
                if(strcmp(b[i].get_maH(), a[j].get_maH())==0)
                    tongtien+=a[j].get_dongia()* b[i].get_sl();
           }
        }
    }
    cout<<"\n tong tien ban duoc trong ngay do la: "<<tongtien;
    cout<<endl;
    return 0;
}

