#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
class MT
 {
  private:
    double a[20][20]; // Mang chua cac phan tu ma tran
    int n ; // Cap ma tran
  public:
    friend ostream& operator<< (ostream& os, const MT& x);
    friend istream& operator>>(istream& is, MT& x);
    friend MT operator+(const MT& x1, const MT& x2);
    friend MT operator-(const MT& x1, const MT& x2);
    friend MT operator*(const MT& x1, const MT& x2);
    friend MT operator!(MT x); // Tinh ma tran nghich dao
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


istream&  operator>> (istream&  is, MT& x)
 {
  cout << " - Cap ma tran: ";
  is >> x.n;
  cout << "Nhap cac phan tu :\n";
  int j;
  for (int i=1 ; i<= x.n ; ++i)
    for (j=1; j<=x.n; ++j)
     {
      cout << "PT[" << i << "," << j << "]= ";
      is >> x.a[i][j];
     }
  return is;
 }


MT operator+(const MT& x1, const MT& x2)
 {
  if (x1.n!=x2.n)
   {
    cout << "\nKhong thuc hien duoc phep cong vi 2 MT khong cung cap";
    getch();
    return x1;
   }
  else
   {
    MT x;
    int i, j, n;
    n = x.n = x1.n;
    for (i=1; i<=n; ++i)
      for (j=1; j<=n ;++j)
	x.a[i][j] = x1.a[i][j] + x2.a[i][j];
    return x;
   }
 }


MT operator-(const MT& x1, const MT& x2)
 {
  if (x1.n!=x2.n)
   {
    cout << "\nKhong thuc hien duoc phep tru vi 2 MT khong cung cap";
    getch();
    return x1;
   }
  else
   {
    MT x;
    int i, j, n;
    n = x.n = x1.n;
    for (i=1; i<=n; ++i)
      for (j=1; j<=n ;++j)
	x.a[i][j] = x1.a[i][j] - x2.a[i][j] ;
    return x;
   }
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


MT operator!(MT x)
 {
  MT y;
  int i,j,k,r,n;
  MT tg;
  n = y.n = x.n ;
  for (i=1 ; i<=n ; ++i)
    for (j=1 ; j<=n ; ++j)
      if (i==j)
	y.a[i][j] = 1;
      else
	y.a[i][j] = 0;
  for (k=1; k<=n; ++k)
   {
    r=k;
    for (i=k+1; i<=n; ++i)
      if (abs(x.a[i][k]) > abs(x.a[r][k]) )
	r = i;
      if (abs(x.a[r][k]) < 1.0E-8)
       {
	cout << "\n Ma tran suy bien, khong co nghich dao" ;
	getch();
	return x;
       }
    /* Hoan vi hang r va hang k */
    for (j=1 ; j<=n ; ++j)
     {
      tg = x.a[k][j];
      x.a[k][j] = x.a[r][j];
      x.a[r][j] = tg;
      tg = y.a[k][j];
      y.a[k][j] = y.a[r][j];
      y.a[r][j] = tg;
     }
    /* Chia hang k cho a[k,k] */
    tg = x.a[k][k] ;
    for (j=1 ; j<=n ; ++j)
     {
      x.a[k][j] /= tg;
      y.a[k][j] /= tg;
     }
    /* Khu cot k : lam cho a[i,k] = 0 voi i != k */
    for (int i=1; i<= n ; ++i)
      if (i != k)
       {
	tg = x.a[i][k] ;
	for (j=1 ; j<=n ; ++j)
	 {
	  x.a[i][j] -= tg*x.a[k][j] ;
	  y.a[i][j] -= tg*y.a[k][j] ;
	 }
       }
   }
  return y;
 }

int main()
 {
  MT x,y,r,s;

  cout <<"\nNhap ma tran X " ; cin >> x;
  //cout <<"\nNhap ma tran Y " ; cin >> y;
  //cout <<"\nNhap ma tran R " ; cin >> r;
  //cout <<"\nNhap ma tran S " ; cin >> s;
  //v = !((x+y)*(r-s))*u ;
  cout << "\nx:\n" <<x;
  cout << "\n!x:\n"<<!x;
  //cout << "\nx+y:\n" <<x+y;
  //cout << "\nx*y:\n" <<x*y;
  getch();
 }
