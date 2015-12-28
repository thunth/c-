/* 
 * File:   sanpham.cpp
 * Author: hoaithu
 *
 * Created on November 27, 2015, 10:29 PM
 */

#include <cstdlib>
#include<iostream>
using namespace std;

/*viet chuong trinh thuc hien cong viec sau:
 *- xay dung lop co so bao gom:
 * +thuoc tinh: ten san pham, nam san xuat, gia thanh.
 * + phuong thuc nhap, xuat thong tin.
 * - xay dung lop hoa don ban san pham ke thua tu lop san pham co them:
 * + thuoc tinh: so luong ban, gia ban;
 * + phuong thuc nhap, xuat thong tin, tinh thanh tien(=so luong* gia ban)
 *  tinh thue(=10% thanh tien), tinh lai(chenh lech gia * so luong ban)
 * - Chuong trinh thuc hien: 
 * + Nhap danh sach N hoa don ban san pham;
 * + sap xep danh sach theo tien lai giam dan;
 * + hien ra man hinh danh sach gom: thu tu, ten sam pham, gia thanh, so luong ban
 *  gia ban, thanh tien, thue va tien lai. 
 * + tinh tong tien cua cac hoa don ban san pham.
 * + cho biet thong tin cua hoa don co tien thue cao nhat.
 */
// lop co so: lop san pham;
class SanPham{
private:
    char tensp[30];
    int namsx;
    float gt;//gt=gia thanh;
public:
    void nhap(){
        cout<<"\n Nhap ten san pham: ";
        cin.ignore(1);
        cin.get(tensp, 30);
        cout<<"\n Nhap nam san xuat: "; cin>>namsx;
        cout<<"\n Nhap gia thanh san pham: "; cin>>gt;
    }
    void in(){
        cout<<"\n Ten san pham: "<<tensp;
        cout<<"\n Nam san xuat: "<<namsx;
        cout<<"\n gia thanh san pham: "<<gt;
    }
    float get_gt(){
        return gt;
    }
};
//lop dan xuat: lop hoa don;
class HoaDon: public SanPham{
private:
    int sl, gb;// sl= so luong, gb= gia ban;
public:
    void nhap(){
        SanPham::nhap();
        cout<<"\n Nhap so luong ban: "; cin>>sl;
        cout<<"\n Nhap gia ban: "; cin>>gb;
    }
    void in(){
         SanPham::in();
        cout<<"\n So luong ban: "<<sl;
        cout<<"\n gia ban: "<<gb;
    }
    int get_gb(){
        return gb;
    }
    float Tinh_ChenhLech(){
        return (get_gb()-get_gt());
    }
    float Tinh_ThanhTien(){
        return (sl*gb);
    }
    float Tinh_Thue(){
        return 0.1*Tinh_ThanhTien();
    }
    float Tinh_Lai(){
        return sl*Tinh_ChenhLech();
    }
    friend void sapxep(int &n, HoaDon *hd){
        HoaDon tg;
       for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(hd[i].Tinh_Lai()<hd[j].Tinh_Lai()){
               tg=hd[i];
               hd[i]=hd[j];
               hd[j]=tg;
            }
        }
    // danh sach da duoc sap xep la:
     cout<<"\n danh saxh duoc;";
    for(int i=1;i<=n;i++){
        hd[i].in();
        }
    }
    // danh sach chi tiet
    friend void in_ChiTiet(int &n, HoaDon *hd){
        for(int i=1;i<=n;i++){
        cout<<"\n STT: "<<i<<": ";
        hd[i].in();
        cout<<"\n Thanh tien: "<<hd[i].Tinh_ThanhTien();
        cout<<"\n Lai: "<<hd[i].Tinh_Lai();
        cout<<"\n Thue: "<<hd[i].Tinh_Thue();
        }
    }
    friend float TongTien(int &n,HoaDon *hd){
        float tongtien=0;
        for(int i=1;i<=n;i++){
            tongtien+=hd[i].Tinh_ThanhTien();
        }
        return tongtien;
    }
    friend void hoadon_max(int &n, HoaDon *hd){
        int vt;
        float thue_max= hd[0].Tinh_Thue();
        for(int i=1;i<=n;i++){
            if(hd[i].Tinh_Thue()>thue_max){
                thue_max=hd[i].Tinh_Thue();
                vt=i;
        }
    }
    cout<<"\n hoa don co thue cao nhat.";
    hd[vt].in();
    cout<<"\n Thanh tien:"<<hd[vt].Tinh_ThanhTien();
    cout<<"\n Lai: "<<hd[vt].Tinh_Lai();
    cout<<"\n Thue: "<<hd[vt].Tinh_Thue();
    }
        
    
};
int main(int argc, char** argv) {
    HoaDon *hd, tg;
    int n;
    float tong_tien;
    cout<<"\n Nhap so luong hoa don: "; cin>>n;
    hd=new HoaDon[n+1];
    // nhap danh sach hoa don;
    for(int i=1;i<=n;i++){
        cout<<"\n Hoa don thu "<<i<<": ";
        hd[i].nhap();
    }
    cout<<endl;
    // sap xep hoa don theo tien lai
    cout<<"------------------------------------"
    sapxep(n, hd);
    // in danh sach hoa don chi tiet
    cout<<"\n ---In danh sach hoa don chi tiet.----";
    in_ChiTiet(n, hd);
    tong_tien=TongTien(n, hd);
    cout<<"\n -----tong tien cac hoa don la: "<<tong_tien;
    // in ra hoa don co tien thue cao nhat.
    hoadon_max(n, hd);  
    cout<<endl;
    return 0;
}

