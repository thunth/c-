/* 
 * File:   sinhvien.cpp
 * Author: hoaithu
 *
 * Created on November 26, 2015, 7:37 AM
 */

#include <cstdlib>
#include<iostream>
using namespace std;

/*xay dung lop de thuc hien chuong trinh sau:
 * 1. nhap n sinh vien, moi sinh vien gom: ma sinh vien, tuoi, diem trung binh
 * 2. in ra danh sach 5 sinh vien co diem cao nhat
 * 3. nhap tuoi t, tinh diem trung binh cua cac sinh vien co tuoi t.
 * 
 * 
 */
class SinhVien{
private:
    char MaSV[10];
    int tuoi;
    float dtb;// diem trung binh
public:
    void nhap(){
        cout<<"\n nhap ma sinh vien: ";
        cin.ignore(1);
        cin.get(MaSV, 10);
        cout<<"\n Nhap tuoi cua sinh vien: "; cin>>tuoi;
        cout<<"\n Nhap diem trung binh cua sinh vien: "; cin>>dtb;
        cout<<endl;
        
    }
    void xuat(){
        cout<<" \n Ma sinh vien: "<<MaSV;
        cout<<"\n Tuoi: "<<tuoi;
        cout<<"\n Diem trung binh: "<<dtb;
        cout<<endl;
    }
    float get_dtb(){
        return dtb;
    }
    int get_tuoi(){
        return tuoi;
    }
};
int main(int argc, char** argv) {
    SinhVien *sv, tg;
    int n, t, dem=0;
    float tong=0, DTB;
    do{
    cout<<"\n Nhap so sinh vien: ";
    cin>>n;
    }while(n<5);
    sv=new SinhVien[n+1];
    //nhap danh sach sinh vien
    cout<<"\n nhap danh sach sinh vien ";
    for(int i=1; i<=n;i++){
        cout<<"\n nhap sinh vien thu "<<i<<":";
        sv[i].nhap();
    }
    // sap xep sinh vien tang dan ve so diem
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(sv[i].get_dtb()<sv[j].get_dtb()){
                tg=sv[i];
                sv[i]=sv[j];
                sv[j]=tg;
            }
        }
    // in ra danh sach 5 sinh vien co diem cao nhat
    cout<<"\n Danh sach 5 sinh vien co diem cao nhat.";
    for(int i=1;i<=5;i++){
        sv[i].xuat();
    }
    // nhap tuoi tu ban phim 
    
    cout<<"\n Nhap tuoi tu ban phim: ";
    cin>>t;
    // tinh diem trung binh sinh vien co tuoi t
    for(int i=1;i<=n;i++){
        if(sv[i].get_tuoi()==t){
            dem++;
            tong+=sv[i].get_dtb();
        }
    }
    if(dem==0)
        cout<<"\n Khong co sinh vien co tuoi t.";
    else{
        DTB=tong/dem;
        cout<<"\n Diemm trung binh cua cac sinh vien co tuoi t la: "<<DTB;
        
    }
    cout<<endl;
    return 0;
}

