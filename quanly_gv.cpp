/* 
 * File:   quanly_gv.cpp
 * Author: hoaithu
 *
 * Created on November 28, 2015, 12:30 AM
 */

#include <cstdlib>
#include<iostream>
using namespace std;

/*Trong một trường đại học cần quản lí cán bộ và giảng viên,  cán bộ gồm các thông 
 *tin: Mã cán bộ, mã đơn vị, mã năm sinh, hệ số lương, phụ cấp ăn ca và bảo hiểm
 * giang viên cần bổ sung thêm các thông tin: Phụ cấp đứng lớp= 25% lương cơ bản, 
 * và phụ cấp độc hại (nếu có) = 10% lương cơ bản.
 * Hãy lập chương trình quản lý cán bộ giảng viên sao cho kế thừa các dữ liệu dùng chhung 
 * thực hiện tính lương cho cán bộ giảng viên tương ứng, in ra danh sách cán bộ giảng viên
 * phải đóng thuế thu nhập ( lương thực lĩnh >5000000)
 * 
 */
float luongcb_cb;// luong co ban cua can bo;
float luongcb_gv; // luong co ban cua giang vien;
// lop can bo;
class CanBo{
private:
    char macb[10], madv[10], bh[20];// ma can bo, ma don vi, bao hiem;
    int ns;
protected:
    float hsl, pc_anca;//hsl= he so luong, pc_anca=phu cap an ca; 
public:
    void Nhap(){
        cout<<"\n Nhap ma can bo: "; 
        cin.ignore(1);
        cin.get(macb, 10);
        cout<<"\n Nhap ma don vi: ";
        cin.ignore(1);
        cin.get(madv, 10);
        cout<<"\n Nhap nam sinh: ";
        cin>>ns;
        cout<<"\n Nhap he so luong: "; cin>>hsl;
        cout<<"\n Nhap phu cap an ca: "; cin>>pc_anca;
        cout<<"\n Nhap bao hiem: ";
        cin.ignore(1);
        cin.get(bh, 20);
    }
    void Xuat(){
        cout<<"\n Ma can bo: "<<macb;
        cout<<"\n Ma don vi: "<<madv;
        cout<<"\n Nam sinh: "<<ns;
        cout<<"\n He so luong: "<<hsl;
        cout<<"\n Phu cap an ca: "<<pc_anca;
        cout<<"\n Bao hiem: "<<bh;
    }
    float luongcb(){
        float luong_cb;
        luong_cb=hsl*luongcb_cb+pc_anca;
        return luong_cb;
    }
};
class GiangVien :public CanBo{
private:
    bool choice;
    float pc_lop,pc_dochai;// phu cap lop, phu cap doc hai;
public:
    void Nhap(){
        CanBo::Nhap();
        cout<<"\n Co phu cap doc hai khong? ";
        cin>>choice;// 1 - co, 0- khong;
        cout<<endl;
    }
    void Xuat(){
        CanBo::Xuat();
        pc_lop=0.25*luongcb_gv;
        cout<<"\n Phu cap dung lop: "<<pc_lop;
        if(choice==1){
            pc_dochai=0.1*luongcb_gv;
            cout<<"\n Tien phu cap doc hai: "<<pc_dochai;
            cout<<endl;
        }         
    }
    float luong_gv(){
        float luong_gv;
        pc_lop=0.25*luongcb_gv;
        luong_gv=(luongcb_gv*hsl)+ pc_anca + pc_lop + pc_dochai;
        return luong_gv;
    }
};
int main(int argc, char** argv) {
    CanBo *cb;
    GiangVien *gv;
    int m, n;
    // nhap luong cb_gv va luongcb_cb
    cout<<"\n Nhap luong co ban cua can bo: "; cin>>luongcb_cb;
    cout<<"\n Nhap luong co ban cua giang vien: "; cin>>luongcb_gv;
    
    // nhap so can bo va nhap danh sach can bo;
    cout<<"\n Nhap so can bo: ";cin>>m;
    cb=new CanBo[m+1];
    cout<<"\n --------------------------------------\n";
    cout<<"\n Nhap danh sach can bo";
    for(int i=0;i<m;i++){
        cout<<"\n Nhap can bo thu "<<i+1<<": ";
        cb[i].Nhap();
    }
    cout<<endl;
    
    // nhap so giang vien va nhap danh sach giang vien;
    cout<<"\n Nhap so giang vien: "; cin>>n;
    gv= new GiangVien[n+1];
    cout<<"\n -------------------------------------\n";
    cout<<"\n Nhap danh sach giang vien";
    for(int i=0;i<n;i++){
        cout<<"\n Nhap giang vien thu "<<i+1<<": ";
        gv[i].Nhap();
    }
    // in danh sach thong tin can bo giang vien
    cout<<"\n ------------------------------------\n";
    cout<<"\n In danh sach thong tin can bo va giang vien";
    for(int i=0;i<m;i++){
        
        cb[i].Xuat();
        cout<<"\n Luong can bo thu "<<i+1<<": "<<cb[i].luongcb();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        gv[i].Xuat();
        cout<<"\n Luong giang vien thu: "<<i+1<<": "<<gv[i].luong_gv();
    }
    cout<<endl;
    // danh sach can bo nhan vien phai dong thue
    cout<<"\n Danh sach can bo nhan vien phai dong thue.";
    for(int i=0;i<m;i++){
        if(cb[i].luongcb()>5000){
            cb[i].Xuat();
            cout<<endl;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(gv[i].luong_gv()>5000){
            gv[i].Xuat();
            cout<<endl;
        }
    }
    cout<<endl;
    return 0;
}

