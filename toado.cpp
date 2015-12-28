/* 
 * File:   toado.cpp
 * Author: hoaithu
 *
 * Created on December 5, 2015, 3:05 PM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>
using namespace std;

/*xay dung lop diem
 * + thuoc tinh: hoanh do va tung do
 * + phuong thuc:
 * - ham tao co doi
 * - ham tao khong doi
 * - ham nhap toa do mot diem
 * - ham in toa do mot diem
 * - ham ban tinh khoang cach tu mot diem den goc toa do
 * viet ham main thuc hien cong viec:
 * - nhap n diem
 * - tim tat ca cac diem xa goc toa do nhat
 * 
 */
class Diem{
private:
    float x, y;
public:
    // ham tao co doi
    Diem(float x1, float y1){
        x=x1;
        y=y1;
    }
    //ham toa khogn doi
    Diem(){
        x=0;
        y=0;
    }
    void xuat(){
        cout<<"("<<x<<","<<y<<")";
//      ;
    }
    friend istream& operator>>(istream& is, Diem &d){
        cout<<"\n Nhap x= ";
        is>>d.x;
        cout<<"\n Nhap y= ";
        is>>d.y;
        return is;
    }
    friend float TinhKhoangCach(Diem d){
        return sqrt(pow(d.x,2)+pow(d.y,2));
    }
};
int main(int argc, char** argv) {
    Diem *d;
    float kc;
    int n;
    cout<<"\n Nhap so diem: ";
    cin>>n;
    d=new Diem[n+1];
    cout<<"\n Nhap danh sach diem ";
    for(int i=1;i<=n;i++){
        cout<<"\n Diem thu "<<i<<": ";
        cin>>d[i];
    }
    // danh sach toa do diem
    cout<<"\n danh sach toa do.";
    for(int i=1;i<=n;i++){
        d[i].xuat();
        
    }
    // tinh khoang cach
    
//    kc=KhoangCach
    
    int vt;
    float max=TinhKhoangCach(d[1]);
    for(int i=1;i<=n;i++){
        if(max<TinhKhoangCach(d[i])){
            max=TinhKhoangCach(d[i]);
            vt=i;
        }
    }
    cout<<"\n diem cach xa toa do nhat la: ";
    d[vt].xuat();
    //in cac diem co toa do xa nha
    cout<<endl;
    return 0;
}

