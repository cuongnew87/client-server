#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;
class DT
 {
  private:
    double a[20]; // Mang chua cac he so da thuc a0, a1,...
    int n ; // Bac da thuc
  public:
    friend ostream& operator<<(ostream& os, DT &d);
    friend istream& operator>>(istream& is,DT &d);
    friend DT operator-(const DT &d);
    friend DT operator+(DT d1, DT d2);
    friend DT operator-(DT d1, DT d2);
    friend DT operator*(DT d1, DT d2);
    friend DT operator/(DT d1, DT d2);
    friend DT operator%(DT d1, DT d2);
    friend double operator^(DT d, double x); // Tinh gia tri da thuc
 };

ostream& operator<< (ostream& os, DT &d)
 {
  	if (d.n==0 && d.a[0]==0)
    	os<<0;
  	for (int i=d.n ; i>=0 ; i--)
   	{
    	if (d.a[i]>0 && i<d.n)
      		os<<"+";
    	if (d.a[i]!=0)
     	{
      		if (d.a[i]!=1 || i==0)
				if (d.a[i]!=-1 || i==0)
	  				os<<d.a[i];
				else
	  				os<<"-";
      		if (i>0)
			{
	 			os<<"x";
	 			if (i>1)
	   				os<<i;
			}
     	}
   	}
  	return os;
}

istream& operator>> (istream& is, DT &d)
 {
  cout << " - Bac da thuc: " ;
  is >> d.n;
  cout << "Nhap cac he so da thuc:\n" ;
  for (int i=d.n ; i>= 0 ; --i)
   {
    cout << "a["<< i << "]="  ;
    is >> d.a[i] ;
   }
  return is;
 }

DT operator-(const DT& d)
 {
  DT p;
  p.n = d.n;
  for (int i=0 ; i<=d.n ; ++i)
  p.a[i] = -d.a[i];
  return p;
 }

DT operator+(DT d1, DT d2)
 {
  DT d;
  int k,i;
  k = d1.n > d2.n ? d1.n : d2.n ;
  for (i=0; i<=k ; ++i)
  if (i<=d1.n && i<=d2.n)
    d.a[i] = d1.a[i] + d2.a[i];
  else
    if (i<=d1.n)
      d.a[i] = d1.a[i];
    else
      d.a[i] = d2.a[i];
  i=k;
  while (i>0 && d.a[i]==0.0) --i;
  d.n = i;
  return d;
 }

DT operator-(DT d1, DT d2)
 {
  return (d1 + (-d2));
 }

DT operator*(DT d1, DT d2)
 {
  DT d;
  int k, i, j;
  k = d.n = d1.n + d2.n ;
  for (i=0; i<=k; ++i) d.a[i] = 0;
    for (i=0 ; i<= d1.n ; ++i)
      for (j=0 ; j<= d2.n ; ++j)
	d.a[i+j] += d1.a[i]*d2.a[j] ;
  return d;
 }

DT operator/(DT d1, DT d2)
 {
  DT d,tg;
  int k, i;
  float h;
  d.n=0;
  d.a[0]=0;
  if (d1.n<d2.n)
    return d;
  k = d.n = d1.n - d2.n;
  do
   {
    if (d1.a[d1.n]!=0)
      {
	d.a[k]=h=d1.a[d1.n]/d2.a[d2.n];
	tg.n=d2.n+k;
	for (i=tg.n; i>=0; i--)
	  tg.a[i]=0;
	for (i=d2.n; i>=0; i--)
	 {
	  tg.a[i+k]=h*d2.a[i];
	 }
	d1=d1-tg;
      }
    else
      d.a[k]=0;
    k--;
   }
  while (d1.n>=d2.n);
  for (i=k-1; i>=0; i--)
    d.a[i]=0;
  return d;
 }

DT operator%(DT d1, DT d2)
 {
  DT d,tg;
  int k, i;
  float h;
  if (d1.n<d2.n)
    return d1;
  k = d.n = d1.n - d2.n;
  do
   {
    if (d1.a[d1.n]!=0)
      {
	d.a[k]=h=d1.a[d1.n]/d2.a[d2.n];
	tg.n=d2.n+k;
	for (i=tg.n; i>=0; i--)
	  tg.a[i]=0;
	for (i=d2.n; i>=0; i--)
	 {
	  tg.a[i+k]=h*d2.a[i];
	 }
	d1=d1-tg;
      }
    else
      d.a[k]=0;
    k--;
   }
  while (d1.n>=d2.n);
  return d1;
 }

double operator^(DT d, double x)
 {
  double s=0.0 , t=1.0;
  for (int i=0 ; i<= d.n ; ++i)
   {
    s+= d.a[i]*t;
    t*= x;
   }
  return s;
 }

int main()
 {
  DT p,q,r,s;
  double x,g;

  cout <<"\nNhap da thuc P " ; cin >> p;
  cout <<"\nNhap da thuc Q " ; cin >> q;
  cout << "\nDa thuc p=" << p ;
  cout << "\nDa thuc q=" << q ;
  r = p+q;
  cout << "\nDa thuc p+q="<<r;
  //cout << "\nDa thuc p-q=" <<p-q;
  //cout << "\nDa thuc p*q=" <<p*q;
  //cout << "\nDa thuc p/q=" <<p/q;
  //cout << "\nDa thuc p%q=" <<p%q;
  getch();
 }
