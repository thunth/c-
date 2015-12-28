/*
1.xd lop diem:thuoc tinh:hoanh do x,tung do y;
phuong thuc:ham tao k doi,co doi,ham nhap toa do cho 1 diem
in toa do 1 diem,tinh kc tu 1 diem den goc toa do
ham main():nhap vao n diem,tim tat ca cac diem xa goc toa do nhat
*/
#include"iostream"
#include"conio.h"
#include"math.h"
using namespace std;
class DIEM{
	private:
		int x;
		int y;
	public:
	DIEM(){
		x=1;
		y=1;
	}
	DIEM(int x1,int y1){
		x=x1;
		y=y1;
	}
	void nhap(){
		cout<<"\nnhap hoanh do:";
		cin>>x;
		cout<<"\nnhap tung do:";
		cin>>y;
	}
	void in(){
		cout<<"("<<x<<","<<y<<")";
	}
	float kc(){
		return sqrt(x*x+y*y);
	}	
};
int main(){
DIEM *d;
float kc;
int n;
cout<<"\nnhap so diem:";
cin>>n;
d=new DIEM[n+1];
for(int i=1;i<=n;i++){
	cout<<"\nnhap toa do thu "<<i<<":";
	d[i].nhap();
}
for(int i=1;i<=n;i++){
	cout<<"\ntoa do diem thu "<<i<<":";
	d[i].in();
}
//tinh khoang cach
int vt;
float max=kc(d[1]);
for(int i=1;i<=n;i++){
	if(max.kc()<d[i].kc())
	max=kc();
	vt=i;
}



}