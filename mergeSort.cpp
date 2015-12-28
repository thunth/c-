/* 
 * File:   mergeSort.cpp
 * Author: hoaithu
 *
 * Created on December 2, 2015, 8:32 PM
 */

#include <cstdlib>
#include<iostream>
#include<stdio.h>

using namespace std;

/*
 * 
 */
template<class T>
void Nhap(T *a, int n, char c){
    for(int i=1;i<=n;i++){
        cout<<c<<"["<<i<<"]=";
        cin>>a[i];
    }
}
template<class T>
void xuat(T *a, int n){
    for(int i=1;i<=n;i++)
    cout<<a[i]<<"\t";
}
template<class T>
void Merge (T *a, int i, int j, int k){
    int left=i;
    int right=k+1;
    int t=i;
    T b[100];
    while(left<=k && right<=j){
        if(a[left]<a[right]){
            b[t]=a[left];
            left++;
            t++;
        }
        else{
            b[t]=a[right];
            right++;
            t++;
        }
    }
    if(left<k){
        for(int r=right; r<=j; j++){
            b[t]=a[r];
            t++;
        }
    }
    else{
        for(int r=left;r<=k;r++){
            b[t]=a[r];
            t++;
        }
    }
    for(int r=i; r<=j;r++){
        a[r]= b[r];
    }
}
template<class T>
void MergeSort(T *a, int i, int j){
    if(i<j){
        int k=(i+j)/2;
        MergeSort(a, i, k);
        MergeSort(a, k+1, j);
        Merge(a, i, j, k);
    }
} 
int main(int argc, char** argv) {
    int n;
    int a[100];
    cout<<"\n nhap n=";
    cin>>n;
    //a= new int[n+1];
//    b= new int[n+1];
    cout<<"\n Nhap day:";
    Nhap(a, n, 'a');
    cout<<"\n xuat day: ";
    xuat(a, n);
    cout<<endl;
    cout<<"\n sap theo thuat toan mergesotr: ";
    cout<<"\n";
    MergeSort(a,1,n);
    cout<<"\nDay sau khi sap Merge \n";
    xuat(a,n);
    cout<<endl;
    
    

    return 0;
}

