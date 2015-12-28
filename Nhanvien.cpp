/*xay dung lop nha vien: manv, hoten, nam sinh
phuong thuc: tao, nhap, xuat, doc tuoi
xay dung lop hop dong dh ke thua lop nhan vien nhu sau:
class hd: public nhanvien{
long tien conng;
int ngay cong;
public:
void nhap;
void xuat;
float tinh luong;
biet rang tinhluong= tiencong*ngay cong;
}
viet main thuc hien nhap vao n nguoi hop dong
tim nguoi co tuoi cao nhat
tim nguoi co luong thap nhat
tinh luong trung binh cua nhung nguoi hop dong
*/
#include<iostream>
#include<stdio.h>
//#include<conio.h>
using namespace std;
class NhanVien{
	private:
		char manv[10], hoten[25];
		int ns;// nam sinh 
	public:
		void nhap(){
			cout<<"\n Nhap ma nhan vien: ";
			cin.ignore(1);
			cin.get(manv, 10);
			cout<<"\n Nhap ho ten: ";
			cin.ignore(1);
			cin.get(hoten, 25);
			cout<<"\n Nhap nam sinh: ";
			cin>>ns;
		}
		void xuat(){
			cout<<manv<<"\t"<<hoten<<"\t"<<ns;
		}
		int get_tuoi(){
			return (2015- ns);
		}
//                char get_manv(){
//                    
//                }
};
class HD: public NhanVien{
	private: 
		long tiencong;
		int ngaycong;
	public:
		void nhap(){
			NhanVien::nhap();
			cout<<"\n Nhap tien cong: ";
			cin>>tiencong;
			cout<<"\n Nhap ngay cong: ";
			cin>>ngaycong; 
		}
		void xuat(){
			NhanVien::xuat();
			cout<<"\t "<<tiencong<<"\t"<<ngaycong;
			cout<<endl;
		}
		float tinh_luong(){
			return (tiencong*ngaycong);
		}
                
        
};
int main(){
	HD *hd;
	//NhanVien *nv;
	int n;
	cout<<"\n Nhap so nhan vien: ";
	cin>>n;
	hd= new HD[n+1];
	//nv=new NhanVien[n+1];
	cout<<"\n Nhap danh sach nhan vien: ";
	for(int i=0;i<n;i++){
		cout<<"\n Nhan vien thu "<<i<<":";
	    hd[i].nhap();
	}
        // xuat dsa sv
        cout<<"\n danh sach nv:\n";
        for(int i=0;i<n;i++){
            hd[i].xuat();
            cout<<endl;
        }
	// tim nguoi co tuoi cao nhat
	HD max_Tuoi=hd[0];
//	int vt=0;
	for(int i=0;i<n;i++){
		if(max_Tuoi.get_tuoi()<hd[i].get_tuoi())
                    max_Tuoi=hd[i];
//                    vt=i;	
	}
	cout<<"\n Nguoi co tuoi cao nhat: ";
//        <<max_Tuoi;
//        cout<<endl;
//        hd[vt].xuat();
	 //tim nguoi luong thap nhat
        max_Tuoi.xuat();
//        int VT    ;
	HD min_luong=hd[0];
	for(int i=0;i<n;i++){
		if(min_luong.tinh_luong()>hd[i].tinh_luong())
		    min_luong=hd[i];  
//                    VT=i;	
	}
        cout<<endl;
	cout<<"\n nguoi co luong thap nhat: ";
        cout<<endl;
        min_luong.xuat();
	// tinh luog trung binh
//	int dem=0;
	float tong_luong=0;
	for(int i=0;i<n;i++){
		tong_luong+=hd[i].tinh_luong();
//		dem++;
	}
        
//	if(dem==0)
//	   cout<<"\n khogn tinh duoc luong tb.";
//	else
//        { 
            float luong_tb=tong_luong/n;
        
	   cout<<"\n luong tb= "<<luong_tb;
//        }
        cout<<"\n tong luong: "<<tong_luong;
        cout<<endl;
	return 0;
}