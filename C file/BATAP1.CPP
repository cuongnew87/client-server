#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
class PS
{
 private: int t,m;
 public:
 friend ostream &operator>> (ostream &os,PS p);
 friend istream &operator>>(ostream &is,PS &p);
 friend int uscln(int a,int b);
 PS rutgon(void);
 friend PS operator+(PS p1,PS p2);
	PS operator-(PS p2);
	PS operator*(PS p2);
	PS operator/(PS p2);
};

ostream &operator<<(ostream &os, PS p)
{
 if(abs(p.m==1))
 os<<p.t*p.m;
 else
    if(p.t==0) os<<0;
    else
    os<<p.t<<'/'<<p.m;
 return os;
}

istream &operator>>(istream &is,PS &p)
{
cout<<"Nhap tu:";
is>>p.t;
cout<<"\nNhap mau(#0):";
is>>p.m ;
return is;
}
int uscln(int a,int b)
{
 int x,y;
 x=abs(a);
 y=abs(b);
 if(x*y==0) return 1;
 else
     if(x%y==0) return y;
     else return uscln(x,x%y);
}
PS PS::rutgon(void)
{
 PS q;
 int x;
 x=uscln(t,m);
 q.t=t/x;
 q.m=m/x;
 return q;
}

PS operator+(PS p1,PS p2)
{
 PS q;
 q.t=p1.t*p2.m+p1.m*p2.t;
 q.m=p1.m*p2.m;
 if(q.t==0) return q;
 else
   return q.rutgon();
}
PS PS::operator-(PS p2)
{
 PS q;
 q.t=t*p2.m-m*p2.t;
 q.m=m*p2.m;
 if(q.t==0) return q;
 else
 return q.rutgon();
}
PS PS::operator*(PS p2)
{
 PS q;
 q.t=t*p2.t;
 q.m=m*p2.m;
 if(q.t==0) return q;
 else
 return q.rutgon();
}
PS PS::operator/(PS p2)
{
 PS q;
 q.t=t*p2.m;
 q.m=m*p2.t;
 if(q.t==0) return q;
 else
 return q.rutgon();
}

int main()
{
PS p,q,z,u,v;
PS s;
  
  cout <<"\nNhap cac PS p, q:\n";
  cin >> p >> q;
  cout<<p<<" + "<<q<<"="<<p + q;
  cout<<endl<<p<<" - "<<q<<"="<<p - q;
  cout<<endl<<p<<" * "<<q<<"="<<p * q;
  cout<<endl<<p<<" / "<<q<<"="<<p / q;
  getch();
 }





































