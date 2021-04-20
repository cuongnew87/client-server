#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
class PS
  {
    private:
      int t,m;
    public:
      friend ostream &operator<<(ostream &os, PS p);
      friend istream &operator>>(istream &is, PS &p);
      friend int uscln(int a, int b);
      PS rutgon();
      friend PS operator+(PS p1, PS p2);
      PS operator-(PS p2);
      PS operator*(PS p2);
      PS operator/(PS p2);
  };
ostream &operator<<(ostream &os, PS p)
 {
  if(p.m==0) os<<"vo nghia";
  else
  if (abs(p.m)==1)
    os<<p.t* p.m;
  else
    if(p.t==0) os<<0;
    else
    os<< p.t << '/' << p.m ;
  return os;
 }

istream& operator>>(istream &is,PS &p)
 {
  cout<<"Nhap tu so va mau so:";
  is>>p.t>>p.m;
  adadad:
  {
   cout<<"Nhap lai mau:";
   is>>p.m;
   };
  if(p.m==0) goto adadad;

  return is;
 }

int uscln(int a,int b)
 {
  int x,y;
  x=abs(a); y=abs(b);
  if (x*y==0)
    return 1;
  else
    if ((x%y)==0)
      return y;
    else
      return uscln(y,x%y);
 }

PS PS::rutgon(void)
 {
  PS q;
  int x;
  x=uscln(t,m);
  q.t = t / x ;
  q.m = m / x ;
  return q;
 }

PS operator+(PS p1,PS p2)
 {
  PS q;
  q.t = p1.t*p2.m + p2.t*p1.m;
  q.m = p1.m * p2.m;
  return q.rutgon();
 }

PS PS::operator-(PS p2)
 {
  PS q;
  q.t = t*p2.m - p2.t*m;
  q.m = m*p2.m ;
  return q.rutgon();
 }

PS PS::operator*(PS p2)
 {
  PS q;
  q.t = t * p2.t ;
  q.m = m * p2.m ;
  return q.rutgon();
 }

PS PS::operator/(PS p2)
 {
  PS q;
  q.t = t * p2.m ;
  q.m = m * p2.t ;
  return q.rutgon();
 }

int main()
 {
  PS p, q, z, u, v;
  PS  s;

  //cout <<"\nNhap cac PS p, q, z, u, v:\n";
  //cin >> p >> q >> z >> u >> v;
  //s = (p - q*z) / (u + v);
  cout <<"\nNhap cac PS p, q:\n";
  cin >> p >> q;
  cout<<p<<" + "<<q<<"="<<p + q;
  cout<<endl<<p<<" - "<<q<<"="<<p - q;
  cout<<endl<<p<<" * "<<q<<"="<<p * q;
  cout<<endl<<p<<" / "<<q<<"="<<p / q;
  getch();
 }
