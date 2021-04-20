#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;
class PS
{
private:
 int t,m;
public:
 friend ostream &operator<<(ostream &os, PS p);
 friend istream &operator>>(istream &is, PS &p);
 friend int uscln(int a,int b);
 PS rutgon(void);
 friend PS operator+(PS p1,PS p2);
	PS operator-(PS P2);
	PS operator*(PS p2);
	PS operator/(PS p2);
 };
 ostream &operator<<(ostream &os,PS p)
{
 if (abs(p.m)==1)
    os<<p.t*p.m;
 else
    os<<p.t<<"/"<<p.m;
 return os;
}
istream &operator>>(istream &is,PS &p)
{
  cout<<"Nhap tu va mau:";
  is>>p.t>>p.m;
  return is;
}
int uscln(int a,int b)
{
  int x,y;
  x=abs(a);
  y=abs(b);
  if(x*y==0)
    return 1;
else if((x%y)==1) return y;
     else
     return uscln(y,x%y);
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
q.t=p1.t*p2.m+p2.t*p1.m;
q.m=p1.m*p2.m;
return q.rutgon();
}

int main()
{
PS p,q,z,u,v;
PS s;
cout<<"\nNhap cac PS p,q:\n";
cin>>p>>q;
cout<<p<<"+"<<q<<"="<<p+q;
getch();
}
