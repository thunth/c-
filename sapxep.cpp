//Sap xep
//
#include<cstdlib>
#include<iostream>
#include<stdio.h>
//s#include<conio.h>
using namespace std;
template <class T>
T *Nhap(int &n)
{
cout<<"\nNhap so phan tu cua day : ";
cin>>n;
T *a=new T[n+1];
for(int i=1;i<=n;i++)
{
cout<<"a["<<i<<"] = ";
cin>>a[i];
}
return a;
}
template <class T>
void Xuat(T *a,int n)
{
cout<<endl;
for(int i=1;i<=n;i++)
cout<<a[i]<<"\t";
}
template <class T>
void Bubble(T *a,int n,bool tang=true) //noi bot
{
for(int i=1;i<n;i++)
{
for(int j=n;j>i;j--)
if(a[j-1]>a[j]==tang) swap(a[j-1],a[j]);
Xuat(a,n);
}
}
template <class T>
void Select(T *a,int n,bool tang=true) //chon
{
for(int i=1;i<n;i++)
{
int p=i;
for(int j=i+1;j<=n;j++)
if(a[p]>a[j]==tang) p=j;
swap(a[p],a[i]);
Xuat(a,n);
}
}
template <class T>
void Insert(T *a,int n,bool tang=true) //chen
{
for(int i=2;i<=n;i++)
{
int j;
T x=a[i];
for(j=i-1;j>=1 && a[j]>x==tang;j--) a[j+1]=a[j];
a[j+1]=x;
Xuat(a,n);
}
}
template <class T>
void Merge(T *a,int L,int R,bool tang=true) //chon
{
if(L>=R) return ;
int k=(L+R)/2;
Merge(a,L,k,tang);
Merge(a,k+1,R,tang);
T*x = new T[R+2];
T*y = new T[R+2];
int i,j,v;
for(i=L;i<=k;i++)
    x[i]=a[i];
for(j=k+1;j<=R;j++)
    y[j]=a[j];
x[k+1]=y[R+1]=((x[k]>y[R]==tang)?x[k]:y[R])+(tang?1:-1);
for(i=L,j=k+1,v=L;v<=R;v++)
a[v]=(x[i]<y[j]==tang)?x[i++]:y[j++];
}
template <class T>
void quick(T *a,int L,int R)
{
if(L>=R) return ;
T x=a[(L+R)/2];
int i=L,j=R;
while(i<j)
{
while(i<=R && a[i]<x) i++;
while(j>=L && a[j]>x) j--;
if(i<j) swap(a[i],a[j]);
i++;
j--;
}
quick(a,L,j);
quick(a,i,R);
}
//tim kiem tuan tu
template <class T>
int find(T *a,int n,T x)
{
for(int i=1;i<=n;i++)
if(a[i]==x) return i;
return -1;
}
//tim kiem nhi phan de quy
template <class T>
int Search(T *a,int L,int R,T x)
{
if(L>R)return -1;
int k=(L+R)/2;
if(a[k]==x) return k;
if(a[k]>x) return Search(a,L,k-1,x);
return Search(a,k+1,R,x);
}
//tim kiem nhi phan khu de quy
template <class T>
int TKNP(T *a,int n,T x)
{
int L=1,R=n;
while(L<=R)
{
int k=(L+R)/2;
if(a[k]==x)
    return k;
if(a[k]>x)
    R=k-1;
else 
    L=k+1;
}
return -1;
}
template <class T>
void Vundong(T *a,int n,int k)
{
if(2*k>n)
    return ;
if(2*k==n)
{
if(a[n]>a[k]) 
    swap(a[n],a[k]);
return;
}
int p=(a[2*k]>a[2*k+1])?2*k:2*k+1;
if(a[k]>=a[p]) 
    return ;
swap(a[k],a[p]);
Vundong(a,n,p);
}
template <class T>
void Heap(T *a,int n)
{
for(int i=n/2;i>=1;i--)
    Vundong(a,n,i); //tao dong
for(int i=n;i>1;i--)
{
swap(a[1],a[i]);
Vundong(a,i-1,1);
}
}
int main()
{
int n;
float *a=Nhap<float>(n);
cout<<"\nDay vua nhap\n";
Xuat(a,n);
cout<<"\nCac buoc sap xep\n";
 Bubble(a,n,false);
 cout<<"\nDay sau khi sap bubble \n";
 Xuat(a,n);
 Select(a,n,false);
 cout<<"\nDay sau khi sap select \n";
 Xuat(a,n);
 Insert(a,n,true);
 cout<<"\nDay sau khi sap insert \n";
 Xuat(a,n);
 Merge(a,1,n,false);
    cout<<"\nDay sau khi sap Merge \n";
    Xuat(a,n);
 quick(a,1,n);
    cout<<"\nDay sau khi sap Quick \n";
 Xuat(a,n);
Heap(a,n);
cout<<"\nDay sau khi sap Heap \n";
Xuat(a,n);
float x;
cout<<"\nNhap phan tu muon tim x =";
cin>>x;
int p=Search(a,1,n,x);
if(p==-1) cout<<"\nKhong co phan tu muon tim";
else cout<<"\nPhan tu muon tim tai a"<<p;
//getch();
cout<<endl;
}