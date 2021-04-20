#include <iostream>
#include <conio.h>
#include <assert.h>
class matrix
{
     private:
             int row, col;
             float *a;
     public:
            matrix(int n=3, int m=3); // constructor
            matrix( const matrix &);// copy constructor 
            ~matrix();// descontructor
            void set_matrix(int , int); // khai tao ma tran
            friend matrix operator+(const matrix&, const matrix & ); // cong hai ma tran
            friend matrix operator-(const matrix&, const matrix & ); // tru hai ma tran
            friend matrix operator*(const matrix&, const matrix & ); // nhan hai ma tran
            friend matrix operator* ( const matrix &, const float &); // nhan ma tra voi mot so
            friend ostream  operator << ( ostream &,const matrix&); // xuat
            friend istream  operator>>( istream &, matrix &); // chen
            friend bool operator==( const matrix &, const matrix &); // bang nhau
            friend bool operator!=( const matrix &, const matrix &);  // khac nhau
            friend matrix operator !( const matrix &); // chuyen vi ma tran          
            matrix & operator=( const matrix &); // gan
            float & operator()( int , int ); // toan tu goi ham
 }; 
 matrix::matrix(int n, int m)
 {
      row=n;
      col=m;
      a=new float [n*m];      
      for ( int i=0; i<n; i++)
          for ( int j=0; j<m; j++)               
              *(a+i*m+j)=0;              
 }
matrix::matrix( const matrix &b)
{
        row=b.row;
        col=b.col;
        a=new float[row*col];
        for( int i=0; i<row; i++)
        for ( int j=0; j<col; j++)
            a[i*col+j]=b.a[i*col+j];
}
 matrix::~matrix()
 {
       delete[] a;
 }
  matrix operator+(const matrix& n, const matrix &m )
  {
        assert(n.row==m.row && n.col==m.col); // phai la hai ma tran cung cap
        matrix  result(n);
        delete[] result.a;
        result.a=new float[result.row * result.col];
        for( int i=0; i<n.row; i++)
             for( int j=0; j<n.col; j++)
                  result.a[i*n.col+j]=n.a[i*n.col+j]+m.a[i*n.col+j];
        return result;
  }
  matrix operator-( const matrix &n, const matrix &m)
  {
         assert (n.row==m.row && n.col==m.col);
         matrix result(n);
         delete[] result.a;
         result.a=new float[result.row * result.col];
         for ( int i=0; i<n.row; i++)
             for( int j=0; j<n.col; j++)
                  result.a[i*n.col+j]=n.a[i*n.col+j]-m.a[i*n.col+j];
        return result;
  }
  matrix operator* ( const matrix &n, const float &c)
  {
         matrix result(n);
         delete[] result.a;
         result.a=new float[result.row * result.col];
         for ( int i=0; i<n.row; i++)
             for( int j=0; j<n.col; j++)
                  result.a[i*n.col+j]=n.a[i*n.col+j]*c;
        return result;
  }
  matrix operator*( const matrix &n, const matrix &m)
  {
         assert(n.col==m.row);
         matrix result(n.row,m.col);  
         delete[] result.a;
         result.a=new float[result.row * result.col];       
         for( int i=0; i<n.row; i++)
              for( int j=0; j<m.col; j++)
                  for ( int k=0; k<m.row; k++)
                      result.a[i*m.col+j]+= n.a[i*n.col+k]* m.a[k*m.col+j] ;
         return result;
  }
  ostream & operator <<( ostream & out, const matrix &n)
  {
          for( int i=0; i<n.row; i++)
          {
               out<<endl;
               for( int j=0; j<n.col; j++)
                    out<<" \t "<<n.a[i*n.col+j];
          }
          return out;
  }
  istream &operator >>( istream &in,  matrix &n)
  {
          cout <<"So hang: "; in>>n.row;
          cout <<"SO cot: " ; in>>n.col;
          for( int i=0; i<n.row; i++)          
               for( int j=0; j<n.col; j++) {
                        cout<<"a["<<i<<"]"<<"["<<j<<"] = ";
                        in>>n.a[i*n.col+j];              
                     }
          return in;
  }
  matrix& matrix::operator =( const matrix &n)
  {
          row=n.row;
          col=n.col;
          delete [] a;
          a =new float[row*col];
          assert(a!=0);
          for( int i=0; i<row; i++)          
               for( int j=0; j<col; j++)
                    a[i*col+j]=n.a[i*col+j];
               return *this;
  }
  bool operator==( const matrix &n, const matrix &m)
  {
       if ( n.row==m.row && n.col==m.col)
       {
            for( int i=0; i<n.row; i++)
                 for( int j=0; j<n.col; j++)
                      if ( n.a[i*n.col+j]!=m.a[i*n.col+j]) return 0;
        }else return 0;        
        return 1;
   }
   bool operator!=( const matrix &n, const matrix &m)
   {
        return !(n==m);
    }
    
    matrix operator !( const matrix &n)// ma tran chuyen vi
    {
           matrix result(n.col,n.row);
           for(int i=0; i<result.row; i++)
                   for( int j=0; j<result.col; j++)
                        result.a[i*result.col+j]=n.a[j*result.row+i];
                        return result;
    }
     float & matrix::operator()( int n, int m)
     {
           assert(n>=0 && n< row && m>=0 && m < col);
           return a[n*col+m];
     }
 int main ()
 {
     matrix T,M, N,B,L;
     cout << "Nhap hai ma tran M va T co cung so hang va so cot, thuc hien +/- ma tran:" <<endl
          << "Chu y: M va T la hai ma tran cung cap."<<endl;
     cout<<"\nMa tran M: "<<endl;
     cin>>T;
     cout<<T;
     cout<<"\nMa tran T" <<endl;
     cin>>M;
     cout<<M;
     N=T+M;
     cout<<"\nMa tran N=M+T: "<<endl <<N;
     N=M-T;
     cout<<"\n Ma tran N=M-T: "<<endl <<N;
     B=N;
     cout<<"\n gan hai ma tran B=N" <<endl<<B;
     cout << "Nhap ma tran L, thuc hien nhan hai ma tran B va L ( chu y: B.cot=L.row)" <<endl;
     cout << "Ma tran L:"<<endl;
     cin>>L;
     N=B*L;
     cout<<"\n Nhan hai ma tran N=B*L" <<endl<<N; getch();
     cout<<"\n Nhan ma tran B voi mot hang so c bat ki: " <<endl;
     N=B*3.4; 
     cout<<"\n Nhan hai ma tran N=B*3.4: " <<endl<<N; getch();
     cout<<"\n Kiem tra hai ma tran khac nhau?"<<endl;
     if ( M!=N) cout<<"Ma tran M va N la khac nhau"<<endl;
     else cout<< "Ma tran M va N la bang nhau." <<endl;
     getch();
     N=B;// thu lenh gan dong thoi kiem tra toan tu bang nhau
     cout<<"Kiem tra hai ma tran co khac nhau?"<<endl;
     if ( B==N) cout<<"Hai ma tran B va N la bang nhau"<<endl;
     else cout<< "Hai ma tran B va N la khong bang nhau." <<endl;
     getch();
     cout<<"Chuyen vi ma tran B:"<<endl;
     cout<<"Truoc khi chuyen vi ma tran:"<<endl <<B;
     cout<<"\nSau khi chuyen vi ma tran: "<<endl <<!B;
     getch();
     cout << "Toan tu goi ham de truy xuat mot phan tu cua ma tran: " <<endl;
     float value=M(0,1);
     cout<< "value: " << value <<endl;
     getch();
     return 0;
 }  
