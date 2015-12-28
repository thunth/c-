/* 
 * File:   ngay thang.cpp
 * Author: hoaithu
 *
 * Created on December 6, 2015, 9:38 AM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>
#include<string.h>

/*xay dung lop ngay thang date:
 *  - thuoc tinh kieu nguyen: ngay thang nam
 *  - ham tao co doi
 *  - ham nhap ngay thang 
 *  - ham in ngay, thang
 *  - so sanh ngay thang d1 co lon hon ngay thang d2 hay khong?
 * xay dung lop sinh vien
 * - thuoc tinh ho ten kieu chuoi, ngay sinh kieu date
 * - phuong thuc: ham tao, nhap tinh tuoi
 * viet chuong trinh nhap vao hai sinh vien
 * cho biet sinh vien nao co tuoi nho hon
 * 
 */

using namespace std;
class date{
    int ngay;
    int thang;
    int nam;
public:
    date(){
        ngay=2;
        thang=2;
        nam=2012;
        
    }
    date(int ngay,int thang,int nam){
        ngay=1;
        thang=4;
        nam=2015;
        
    }
    void nhap(){
        cout<<"\nnhap ngay:\n";
        cin>>ngay;
        cout<<"\nnhap thang:\n";
        cin>>thang;
        cout<<"\nnhap nam:\n";
        cin>>nam;
    }
    void xuat(){
        cout<<ngay<<"\t"<<thang<<"\t"<<nam;
    }
    date sosanh(date a){
        int ngaya;
        int ngayb;
        ngaya=a.nam*10000+a.thang*100+a.ngay;
        ngayb=nam*10000+thang*100+ngay;
        if(ngaya>ngayb)
            return a;
        else
            return *this;
    }
    int get_nam(){
        return nam;
    }
    
};
class sinhvien:public date{
private:
    char hoten[20];
    date ngaysinh;
public:
    sinhvien(){
        strcpy(hoten,"");
//        date=(int 2,int 3,int 2015);
        
        
    }
    void nhap(){
        cout<<"\nnhap ho ten sinh vien:";
        cin.ignore(1);
        cin.get(hoten,20);
        cout<<"\nnhap ngay thang nam sinh:\n";
        date::nhap();
        
    }
    void xuat(){  
        cout<<hoten<<"\t";
        date::xuat();
        cout<<endl;
    }
    int tinh_tuoi(){ 
        int tuoi;
        tuoi= 2015-get_nam();
        return tuoi;
       //cout<<"\nnhap nam hien tai:";
//        return(2015-get_nam());
    }
   
};


/*
 * 
 */
int main(int argc, char** argv) {
    date d1, d2;
    sinhvien sv;
    d1.nhap();
    d2.nhap();
    d1.xuat();
    cout<<endl;
    d2.xuat();
    date max;
    cout<<"\nso sanh ngay a va b: ";
    max=d1.sosanh(d2);
    max.xuat();
    cout<<endl;
    sv.nhap();
    cout<<"\n thong tin sinh vien la: ";
    sv.xuat();
    cout<<"\n tuoi cua sinh vien la: ";
    cout<<sv.tinh_tuoi();
    cout<<endl;
    

    return 0;
}

