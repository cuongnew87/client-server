#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
class MT;
class VT;
class MT
 {
  private:
    double a[20][20]; // Mang chua cac phan tu ma tran
    int n ; // Cap ma tran
  public:
    friend class VT;
    friend ostream& operator<< (ostream& os, const MT& x);
    friend istream& operator>> (istream& is, MT& x);
    friend MT operator*(const MT& x1, const MT& x2);
    VT operator*(const VT& v);
 };

class VT
 {
  private:
    double b[20]; // Mang chua cac phan tu cua vec to
    int n ; // Cap vec to
  public:
    friend class MT;
    friend ostream& operator<< (ostream& os, const VT& v);
    friend istream& operator>> (istream& is, VT &v);
    VT operator*(const MT& v);
    friend double operator*(const VT& v1, const VT& v2);
 };

ostream& operator<< (ostream& os, const MT& x)
 {
  os << setprecision(2) << setiosflags(ios::showpoint);
  for (int i=1 ; i<= x.n ; ++i)
   {
    for (int j=1; j<=x.n; ++j)
      os << setw(6) << x.a[i][j];
    os << "\n" ;
   }
  return os;
 }

ostream& operator<< (ostream& os, const VT& v)
 {
  os << setprecision(2) << setiosflags(ios::showpoint);
  for (int i=1 ; i<= v.n ; ++i)
    os << setw(6) << v.b[i] ;
  os << "\n" ;
  return os;
 }

istream& operator>> (istream&  is, MT& x)
 {
  cout << " - Cap ma tran: ";
  is >> x.n;
  cout << "Nhap cac phan tu :\n";
  int j;
  for (int i=1 ; i<= x.n ; ++i)
    for (j=1; j<=x.n; ++j)
     {
      cout << "Ptu[" << i << "," << j << "]= ";
      is >> x.a[i][j];
     }
  return is;
 }

istream& operator>> (istream&  is, VT& v)
 {
  cout << " - Cap vec to: ";
  is >> v.n;
  cout << "Nhap cac phan tu :\n";
  for (int i=1 ; i<= v.n ; ++i)
   {
    cout << "Ptu[" << i <<  "]= ";
    is >> v.b[i];
   }
  return is;
 }

MT operator*(const MT& x1, const MT& x2)
 {
  if (x1.n!=x2.n)
   {
    cout << "\nKhong thuc hien duoc phep nhan vi 2 MT khong cung cap";
    getch();
    return x1;
   }
  else
   {
    MT x;
    int n, i, j,k;
    n = x.n = x1.n;
    for (i=1; i<=n; ++i)
      for (j=1; j<=n ;++j)
       {
	x.a[i][j] = 0.0 ;
	for (k=1 ; k<=n; ++k)
	  x.a[i][j] += x1.a[i][k]*x2.a[k][j] ;
       }
    return x;
   }
 }

VT MT::operator*(const VT& v)
 {
  if (n!=v.n)
   {
    cout << "\n Cap ma tran khac cap vec to, phep nhan vo nghia";
    getch();
    return v;
   }
  else
   {
    VT u; int  n;
    n = u.n = v.n ;
    for (int i=1; i <=n ; ++i)
     {
      u.b[i] = 0;
      for (int j=1; j<=n; ++j)
	u.b[i] += a[i][j]*v.b[j];
     }
    return u;
   }
 }

VT VT::operator*(const MT& v)
 {
  VT z;
  int i,j;
  for (j=1; j<=n; ++j)
   {
    z.b[j] = 0.0 ;
    for (i=1; i<=n; ++i)
      z.b[j] += v.a[i][j]*b[i];
   }
  z.n = n;
  return z;
 }

double operator*(const VT& v1, const VT& v2)
 {
  if (v1.n!=v2.n)
   {
    cout << "\nKhong thuc hien duoc phep nhan vi 2 VT khong cung cap";
    getch();
    return 0;
   }
  double tg=0.0;
  for (int i=1; i<=v2.n; ++i)
    tg += v1.b[i]*v2.b[i];
  return tg;
 }

int main()
 {
  MT x,y;
  VT u,v;
  cout <<"\nNhap ma tran X " ; cin >> x;
  cout <<"\nNhap ma tran Y " ; cin >> y;
  cout <<"\nNhap vec to u " ; cin >> u;
  cout <<"\nNhap vec to v " ; cin >> v ;

  cout <<"\nMa tran x:\n"<< x ;
  cout <<"\nMa tran y:\n"<< y ;
  cout <<"\nVec to u:\n"<< u ;
  cout <<"\nVec to v:\n"<< v ;
  cout <<"\nMa tran x*y:\n"<<x*y ;
  cout <<"\nVec to x*u:\n"<<x*u ;
  cout <<"\nVec to u*x:\n"<<u*x ;
  cout <<"\nSo u*v:\n"<<u*v ;
  getch();
 }
