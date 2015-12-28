/* 
 * File:   phanso.cpp
 * Author: hoaithu
 *
 * Created on November 28, 2015, 9:25 AM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>
using namespace std;

/*
 *Xay dung lop phan so:
 *Thuoc tinh: tu so va mau so
 * phuong thuc:
 * + ham tao khong doi va ham tao co doi;
 * + ham nhap, xuat phan so
 * + ham toan tu * de nhan hai phan so;
 * + toan tu bang de in mot ps ra man hinh duoi dang tuso/mauso;
 * (yeu cau phan so in ra dang toi gian)
 */
class PS{
private:
    int ts, ms;// tu so va mau so;
public:
    // ham tao 
    PS(int ts1=0, int ms1=1){
        ts=ts1;
        ms=ms1;
    }
    // ham nhap
    friend istream& operator>>(istream& is, PS &ps ){
        cout<<"\n Nhap tu so: "; is>>ps.ts;
        cout<<"\n Nhap mau so: "; is>>ps.ms;
        return rutgon(ps);
        return is;
    }
    //ham tim uoc chung lon nhat;
    int UCLN(int a, int b){
        int x,y;
        x=abs(a);
        y=abs(b);
        if(x*y==0)
            return 1;
        while(x!=y){
            if(x>y)
                x=x-y;
            else
                y=y-x;
        }
        return x;
    }
    PS rutgon(PS ps){
        PS q;
        int x;
        x=UCLN(ps.ts, ps.ms);
        q.ts=q.ts/x;
        q.ms=q.ms/x;
        return q;
    }
    friend ostream& operator<<(ostream& os, PS ps){
        os<<ps.ts<<"/"<<ps.ms;
        return os;
    }
};
int main(int argc, char** argv) {
    PS a;
    cout<<"\n Nhap phan so: ";
    cin>>a;
    cout<<"\n in phan so:";
    cout<<a;
//    ps.xuat();
    cout<<endl;

    return 0;
}

