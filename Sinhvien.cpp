/* 
 * File:   Sinhvien.cpp
 * Author: hoaithu
 *
 * Created on December 6, 2015, 8:48 AM
 */

#include <cstdlib>
#include<iostream>
using namespace std;

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
class Date{
private:
    int ngay, thang, nam;
public:
    Date(){
        ngay=1;
        thang=1;
        nam=-1;
    }
public:
    void Nhap(){
        cout<<"\n Nhap ngay, thang, nam: ";
        cin>>ngay>>thang>>nam;
    }
    void xuat(){
        cout<<ngay<<"/"<<thang<<"/"<<nam;
    }
    friend class sinhvien;
};
class sinhvien{
private:
    Date ngaysinh;
    char hoten[20];
public:
    void nhap(){
        cout<<"\n Ho ten: ";
        cin.ignore(1);
        cin.get(hoten, 20);
        cout<<"\n Nhap ngay sinh:";
        cout<<ngaysinh;
    }
};
int main(int argc, char** argv) {

    return 0;
}

