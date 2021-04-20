#include "iostream.h"
#include "stdio.h"
#include "conio.h"
 //mo ta lop PS
 class PS
 {
 int t,m;
 public:
        void nhap();      
        void xuat();
        PS cong(PS y);  //PS cong(PS'this,PSy)
        PS tru(PS y);
        friend PS nhan(PS x,PS y); 
        friend PS chia(PS x,PS y);
 };
 
 void PS::nhap()
 {
 cout<<"nhap tu so"; cin>>t;    
 cout<<"nhap mau so"; cin>>m;
 }
 
 void PS::xuat()
 {
 cout<<t<<"/"<<m;     
 }
 
PS PS::cong(PS y)
 {
 PS kq;
 kq.t=t*y.m+y.t*m;
 kq.m=m*y.m;
 return kq;               
 }
 
PS PS::tru(PS y)
 {
 PS kq;
 kq.t=t*y.m-y.t*m;
 kq.m=m*y.m;
 return kq;               
 }

PS nhan(PS x,PS y)
{
 PS kq;
 kq.t=x.t*y.t;
 kq.m=x.m*y.m;
 return kq;               
} 
 
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
 a.nhap(); 
 cout<<"\nnhap ps b:\n";
 b.nhap(); 
 
 kq=a.cong(b);
 cout<<"\ntong 2ps:"; kq.xuat();
 
 kq=a.tru(b);
 cout<<"\nhieu 2ps:"; kq.xuat();
 
 kq=nhan(a,b);
 cout<<"\ntich 2ps:"; kq.xuat();
  
 kq=chia(a,b);
 cout<<"\nthuong 2ps:"; kq.xuat();  
 getch();
}
 
 
 
 
 
 
 
 
 
 
 
 
