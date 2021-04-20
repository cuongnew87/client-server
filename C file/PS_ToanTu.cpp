#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
 //mo ta lop PS
 class PS
 {
 	int t,m;
 public:
       // void nhap();      
       // void xuat();
        PS cong(PS y);  //PS cong(PS'this,PSy)
        //PS tru(PS y);
        
        friend PS chia(PS x,PS y);
        friend ostream &operator <<(ostream &os, PS a)
        {
			os<<a.t<<"/"<<a.m;  
			return  os;
		}
		friend istream &operator >>(istream &is, PS &a)
        {
			cout<<"nhap tu so"; is>>a.t;    
 			cout<<"nhap mau so"; is>>a.m; 
			return  is;
		}
		PS operator+(PS y)
		{
			PS kq;
 			kq.t=t*y.m+y.t*m;
 			kq.m=m*y.m;
 			return kq;
		}
		friend PS operator-(PS x, PS y)
		{
			PS kq;
 			kq.t=x.t*y.m-y.t*x.m;
 			kq.m=x.m*y.m;
 			return kq;
		}
        
 };



 
PS chia(PS x,PS y)
{
 PS kq;
 kq.t=x.t*y.m;
 kq.m=x.m*y.t;
 return kq;               
} 

int main()
{
 PS a,b,kq;
 cout<<"\nnhap ps a:\n";
 cin>>a; 
 cout<<"\nnhap ps b:\n";
 cin>>b;
 
 kq=a.operator+(b);
 kq = b.cong(b);
 kq = a + b;
 cout<<"\ntong 2ps:"<<kq;
 
 kq = a - b;
 cout<<"\nhieu 2ps:"<<kq;
 
 //kq=nhan(a,b);
 ///cout<<"\ntich 2ps:"<<kq;
  
 //kq=chia(a,b);
 //cout<<"\nthuong 2ps:"<<kq;
  
 getch();
}
 
 
 
 
 
 
 
 
 
 
 
 
