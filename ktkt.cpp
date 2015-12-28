#include<stdio.h>
//#include<conio.h>
#include<math.h>
#include<iostream>
using namespace std;
class diem{
	private:
		float x;
		float y;
	public:
         diem(float x1,float y1){
		x=x1;
		y=y1;
	}
 	     diem(){
	
	    x=0;
		y=0; 
 }
 friend istream&operator>>(istream&is,diem&d){
 	cout<<"\n nhap x:";
 	is>>d.x;
 	cout<<"\n nhap y:";
 	is>>d.y;
 	return is;
}
friend ostream&operator<<(ostream&os,diem&d){
	cout<<d.x<<"\t"<<d.y<<"\t";
	return os;
}
friend float khoangcach (diem d){
	return (sqrt(pow(d.x,2)-pow(d.y,2)));
 }
};
int main(){

	diem*d;
	int n;
	cout<<"\nnhap so diem:";
	cin>>n;
	d=new diem[n+1];
	cout<<"\nnhap danh sach diem:";
	for(int i=1;i<=n;i++)
	{
		cout<<"nhap diem thu"<<i<<":";
	    cin>>d[i];
	}
//getch();


}