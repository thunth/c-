/* 
 * File:   dt.cpp
 * Author: hoaithu
 *
 * Created on December 7, 2015, 3:17 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
class dt{
private:
    int n;//bac cua da thuc;
    float *a;
public:
    dt(){
        n=0;
        a=NULL;
        
    }
    dt(int n1){
        n=n1;
        a=new float[n];
        
    }
    ~dt(){
        n=0;
        delete a;
    }
    friend istream &operator>>(istream &is,dt&d)
    {
        cout<<"\n nhap bac cua da thuc:\n";
        is>>d.n;
        cout<<"\nnhap he so cua da thuc:";  
        d.a=new float[d.n+1];
        for(int i=1;i<=d.n;i++)
        {
            cout<<"\na["<<i<<"]=";
            is>>d.a[i];
            
            
        }
        return is;
          
        }
    friend
};

/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}

