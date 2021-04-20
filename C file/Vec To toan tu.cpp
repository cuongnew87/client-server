#include <iostream.h>
#include <conio.h>
#include <assert.h>
class vecto{
      public:
             vecto(int n=100);// constructor tao mot vecto co do dai n
             vecto( const vecto &);//copy constructor 
             ~vecto(); //destructor
             friend vecto  operator+ ( const vecto &, const vecto &);
             friend vecto  operator- ( const vecto &, const vecto &);
             friend vecto  operator* ( const vecto &, const int &);
              vecto  &operator=(const vecto &);
             friend istream &operator >>( istream &, vecto &);
             friend ostream &operator <<(ostream &, const vecto &);
             int &operator []( int );
             int get_num();
      private:
              int num,*p;             
      };
      vecto::vecto(int n)
      {
             num=n;
             p=new int[num];
             for ( int i=0; i<n; i++) p[i]=0;
      }
      vecto::vecto(const vecto &a)
      {
           num=a.num;
           p= new int[num];
           assert(p!=0);
           for( int i=0; i<num; i++) p[i]=a.p[i];  
      }
      vecto::~vecto()
      {
             delete [] p;
      }
      int vecto::get_num()
      {
             return num;
      }
      vecto  operator+(const vecto &a, const vecto &b)
      {
             vecto result;
             result.num= (a.num > b.num) ? a.num :b.num;
             delete [] result.p;
             result.p= new int[result.num];
             assert(result.p!=0);
             for(int i=0; i< result.num ; i++) result.p[i]=a.p[i]+b.p[i];
             return result;
      }
       vecto  operator-( const vecto &a, const vecto &b)
       {
             vecto result;
             result.num= (a.num > b.num) ? a.num :b.num;
             delete [] result.p;
             result.p= new int[result.num];
             assert(result.p!=0);
             for(int i=0; i< result.num ; i++) result.p[i]=a.p[i]-b.p[i];
             return result;
       }
       vecto  operator*( const vecto &a,const int &n) // nhan vecto a voi mot so nguyen
       {
              vecto result(a);// saochep 
              for( int i=0; i<a.num; i++) result.p[i]=a.p[i]*n;
              return result;
       }
        vecto& vecto::operator=(const vecto &a)
        {
               num= a.num;
               delete [] p;
               p= new int [num];
               assert(p!=0);
               for( int i=0 ; i<num; i++) p[i] = a.p[i];
               return *this;
        }
        istream &operator>>( istream &in, vecto &a)
        {
                cout<<"Nhap so phan tu:"<<endl;
                in>>a.num;
                cout<<"Nhap cac gia tri cho cac phan tu: "<<endl;
                for ( int i=0; i<a.num; i++) {
                    cout<<"a.p["<<i<<"]: "<<endl;
                    in>> a.p[i];
                }
                return in;
        }
        ostream &operator <<(ostream &out, const vecto &a)
        {
               for ( int i=0; i<a.num; i++)
                    out <<"\t"<<a.p[i];       
               return out;
        }
       int & vecto::operator []( int n )
       {
                assert ( n>=0 && n< num);
                return p[n];
       }
       int main ()
       {
           vecto vt1,vt2,vt3;
           cout<< "Vecto 1: " <<endl;
           cin >> vt1;
           cout <<"vecto 1:" <<vt1 <<endl;
           cout<<" Vecto 2: " <<endl;
           cin >>vt2;// >>
           cout <<"vecto 2: "<<vt2 <<endl<<endl; // xuat
           vt3=vt1+vt2;// phep cong
           cout <<"vecto 1:" <<vt1 <<endl;
           cout <<"vecto 2: "<<vt2 <<endl;
           cout <<"vt3=vt1 + vt2:"<< vt3<<endl;
           vt3=vt1-vt2;// phep tru
           cout <<"vt3=vt1 - vt2:"<<vt3 <<endl;
           vt3=vt1*5; // phep nhan
           cout << "vt3=vt1 * (int):"<<vt3<<endl;
           int n=vt1.get_num();
           vt1[n-1]=-1; // toan tu truy cap 
           cout <<"vt1: "<<vt1<<endl;
           getch();
           return 0;
       }  
