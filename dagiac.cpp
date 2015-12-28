/* 
 * File:   dagiac.cpp
 * Author: hoaithu
 *
 * Created on December 7, 2015, 5:43 PM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>
using namespace std;

/*
 *xay dung lop diem:
 * thuoc tinh:hoanh do, tung do
 * phuong thuc:
 * nhap, xuat, tinh do dai doan thang di qua hai diem
 *xay dung lop da giac: 
 * thuoc tinh gom so dinh, day diem chua toa do cac dinh,
 * cac phuong thuc nhap xuat tinh chu vi da giac;
 *viet ham main thuc hien chuong trinh
 * nhap m da giac, tim chu vi cua moi da giac vua nhap
 * tim da giac co chu vi lon nhat
 * in toa do cac dinh cua da giac tim duoc
 *  
 */
class Diem{
private:
    float x, y; // hoanh do, tung do 
public:
    void nhap(){
        cout<<"\n Nhap x, y: ";
        cin>>x>>y;
        
    }
    void xuat(){
        cout<<"("<<x<<","<<y<<")"<<"\t";
    }
    float KC(Diem d2){
        return sqrt(pow(x - d2.x,2)+pow(y - d2.y,2));
    }
    friend class DaGiac;
};
class DaGiac{
private:
    int n;// so dinh cua da giac
    Diem *a;
public:
    void nhap(){
        cout<<"\n Nhap so dinh cau da giac: ";
        cin>>n;
        a= new Diem[n+1];
        for(int i=1;i<=n;i++){
            cout<<"\n Nhap diem thu: "<<i<<":";
            a[i].nhap();
        }
    }
    void xuat(){
        for(int i=1;i<=n;i++){
            a[i].xuat();
        }
    }
    float ChuVi(){
        float cv=0;
        float s1=0; // do dai diem dau den diem cuoi
        s1=a[n].KC(a[1]);
        for(int i=1;i<=n;i++){
            cv+=a[i].KC(a[i+1]);
        }
        cv+=a[n].KC(a[1]);
        return cv;
    }
    
};
int main(int argc, char** argv) {
    DaGiac *d;
    int m;
    cout<<"\n Nhap so luong da giac";
    cin>>m;
    d= new DaGiac[m+1];
    cout<<"\n Nhap da giac";
    for(int i=1;i<=m;i++){
        cout<<"\n Nhap da giac thu "<<i<<":";
        d[i].nhap();
    }
    cout<<"\n in cac da giac: ";
    for(int i=1;i<=m;i++){
        cout<<"\n cac dinh cua da giac thu "<<i<<":";
        d[i].xuat();
    }
    // tinh chu vi cac da giac
//    float chuvi=0;
    for(int i=1;i<=m;i++){
        cout<<"\n chu vi cua da giac thu "<<i<<" la: ";
        cout<<d[i].ChuVi();  
    }
    int vt=0;
    float cv_max=d[1].ChuVi();
    for(int i=1;i<=m;i++){
        if(cv_max<d[i].ChuVi())
            cv_max=d[i].ChuVi();
    }
    for(int i=1;i<=m;i++){
        if(cv_max==d[i].ChuVi()){
            cout<<"\n da giac co chu vi max la da giac thu"<<i<<":";
            d[i].xuat();
        }    
    }
    
    cout<<"\n da giac co chu vi lon nhat la: "<<cv_max;
    
    cout<<endl;

    return 0;
}

