/* 
 * File:   thuatoansx.cpp
 * Author: hoaithu
 *
 * Created on December 2, 2015, 8:24 AM
 */

#include <cstdlib>
#include<iostream>
#include<stdio.h>
using namespace std;
template<class T>
void Nhap(T *a,int n, char c){
    
    for(int i=1;i<=n;i++){
        cout<<c<<"["<<i<<"]=";
        cin>>a[i];
        cout<<endl;
    }
    
}
template <class T>
void xuat(T *a, int n){
    //cout<<"\n day phan tu cua mang.";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<"\t";
    }
}
//template<class T>
//void swap(T &a, T &b){
//    T tg;
//    tg=a;
//    a=b;
//    b=tg;
//}
template<class T>
void BubbleSort(T *a, int n){
    int i, j;
    for(i=1;i<=n;i++)
        for(j=n;j>i;j--)
            if(a[j]<a[j-1]){
                swap(a[j], a[j-1]);
                xuat(a,n);
                cout<<endl;
            }
                
}
template<class T>
void SelectionSort(T *a, int n){
    int i,j, min;
    for(i=1;i<n;i++){
        min=i;
        for(j=i+1;j<=n;j++){
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i)
            swap(a[i], a[min]);
        xuat(a,n);
        cout<<endl;
    }
}

template<class T>
void InsertSort(T *a, int n){
    T x;
    int i,j;
    for(i=1;i<=n-1;i++){
        j=i-1;
        x=a[i];
        while(a[j]>x && j>=0){
            a[i+1]=a[j];
            j--;
        }
        a[j+1]=x;
        xuat(a, n);
        cout<<endl;
    }
}
//template<class T>
//void    
//template <class T>
template <class T>
void quick(T *a,int L,int R)
{
if(L>=R)
    return ;
T x=a[L];
int i=L,j=R;
while(i<j)
{
while(i<=R && a[i]<x) 
    i++;
while(j>=L && a[j]>x) 
    j--;
if(i<j)
    swap(a[i],a[j]);
    i++;
    j--;

}
quick(a,L,j);
quick(a,i,R);
}
template <class T>
void Vundong(T *a,int n,int k)
{
if(2*k>n) 
    return ;
if(2*k==n)
{
    if(a[n]>a[k]) swap(a[n],a[k]);
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
template<class T>
void MergeSort( T *a, int L, int R, bool tang=true){
    if(L>=R) return ;
int k=(L+R)/2;
MergeSort(a,L,k,tang);
MergeSort(a,k+1,R,tang);
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
int main(int argc, char** argv) {
    int n;
    int *a, *b;
    cout<<"\n Nhap n: ";
    cin>>n;
    a= new int[n+1];
    b= new int[n+1];
    cout<<"\n Nhap day: ";
    Nhap(a, n, 'a');
    cout<<endl;
    cout<<"\n day vua nhap: ";
    xuat(a,n);
    cout<<endl;
    // BubbelSort;
    // SelectionSotr);
    cout<<"\n cac buoc sap xep theo BubbleSort:\n ";
    BubbleSort(a, n);
    cout<<"\n day so duoc sap xep: \n ";
    xuat(a,n);
    cout<<endl;
    cout<<"\n cac buoc sap xep SelectionSort:\n ";
    SelectionSort(a, n);
    cout<<"\n day so duoc sap xep : \n ";
    xuat(a,n);
    cout<<endl;
    cout<<"\n cac buoc sap xep theo Insertort:\n ";
    InsertSort(a, n);
    cout<<"\n day so duoc sap xep: \n ";
    xuat(a,n);
    cout<<endl;
//    cout<<"\n cac buoc sap xep theo QuickSort:\n ";
    quick(a,1, n);
      cout<<"\n day so duoc sap xep quicsort: \n ";
    xuat(a,n);
    cout<<endl;
    Heap(a,n);
    cout<<"\nDay sau khi sap Heap \n";
    xuat(a,n);
    
    MergeSort(a,1, n, false);
    cout<<"\n day sau khi sx MergeSort:\n ";
    xuat(a, n);
    cout<<endl;
    return 0;
}

