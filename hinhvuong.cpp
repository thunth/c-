/* 
 * File:   hinhvuong.cpp
 * Author: hoaithu
 *
 * Created on December 6, 2015, 2:51 PM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>
using namespace std;

/*
 *xay dung lop hinh vuong
 * - thuoc tinh kich thuoc hinh vuong
 * - phuong thuc:
 * + ham tao co doi
 * + ham tao khong doi
 * + ham nhap, ham in, ham tinh dien tich
 * viet ham main
 * - in day hinh vuong vua nhap
 * - tinh dien tich chu vi cua moi hinh. 
 */
class HinhVuong{
private:
    float a;// a kich thuoc cac canh cua hinh vuong
public:
    HinhVuong(){
        a=1;
    }
    HinhVuong(float a1){
        a=a1;
    }
    friend ostream& operator<<(ostream& os, HinhVuong &hv){
        os<<hv.a;
        return os;
    }
    friend istream& operator>>(istream& is, HinhVuong &hv){
        cout<<"\n a= ";
        is>>hv.a;
    }
     float DienTich(){
        return pow(a, 2); 
    }
     float ChuVi(){
        return 4*a;
    }
    
};
int main(int argc, char** argv) {
    HinhVuong *hv;
    int n;
    float dt, cv;
    cout<<"\n nhap so luong hinh vuong; ";
    cin>>n;
    hv= new HinhVuong[n+1];
    /// nhap danh sach hinh vuong
    cout<<"\n---------------------------\n";
    for(int i=1;i<=n;i++){
        cout<<"\n Nhap hinh vuong thu "<<i<<": ";
        cin>>hv[i];
    }
    // in danh sach cac hinh vuong
    cout<<"\n danh sach cac hinh ";
    for(int i=1;i<=n;i++){
        cout<<"\n hinh vuong thu "<<i<<":\t";
        cout<<hv[i];
    }
    //dt=DienTich(hv);
    for(int i=1;i<=n;i++){
        cout<<"\n dien tich hinh vuogn thu "<<i<<":\t";
        cout<<hv[i].DienTich();
        cout<<"\n chu vi cua hinh vuong thu "<<i<<":\t";
        cout<<hv[i].ChuVi();
    }
    cout<<endl;

    return 0;
}

