#include <iostream.h>
#include <conio.h>
class date{
      private:
              int day, month, year;
              
      public:
             date(int d=0, int m=0, int y=0);
             ~date();
             void set_date(int d, int m, int y);
             date get_date();
             int maxday( int m, int y);
             friend date operator ++(date &d);
             friend date operator --(date &d);
             friend date operator +=(date &d1, int n);
             friend date operator -=(date &d1, int n);
             friend ostream &operator <<(ostream &, date d);
             friend istream &operator >>(istream &, date &d);
      };
      date::date(int d, int m, int y)
      {
             set_date(d,m,y);
      }
      date::~date()
      {
      }
      int date::maxday(int m, int y)
      {
          int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
          if( ((y%4==0)&&(y%100!=0))||y%400==0) mon[2]=29;
          return (mon[m]);
      }
      void date::set_date(int d, int m, int y)
      {           
               day = (d <= maxday(m,y))?d:0;
               month=(m <=12 && m>0) ?m:0;
               year= y;
       }
       date date::get_date()
       {
            cout<<"date: "<< day<<"/" <<month<< "/"<<year<<endl ;
        }
        date operator ++ (date &d)
        {
             if (d.day < d.maxday(d.month, d.year))d.day++;
             else if(d.month<12){d.day=1; d.month++; }
             else {d.year++;d.day=1; d.month=1;}
             return d;
         }
         date operator --(date &d)
         {
              if( d.day>1) d.day--;
              else if( d.month>1) {d.day= d.maxday(d.month, d.year); d.month--; }
              else d.year--;
              return d;
          }
          ostream &operator << ( ostream &out, date d)
          {
              out<<d.day <<"/" <<d.month<<"/" <<d.year<<endl;   
              return out;
          }
          istream &operator >>( istream &in, date &d)
          {
                  cout<<"Day: " <<endl; in>>d.day;
                  cout<<"Month: "<<endl;in>>d.month;
                  cout<<"Year: "<<endl; in>>d.year;
                  return in;
          }
          date operator +=( date &d1, int n)
          {
               for ( int i=1; i<=n; i++) ++d1;
               return d1;
           }
           date operator -=( date &d1, int n)
           {
                for ( int i=1; i<=n; i++) --d1;
                return d1;
            }
          int main ()
          {
              date d,d1;
              int n,m;
              d.get_date();
              d.set_date(29,9,1988);
              d.get_date();
              ++d;
              d.get_date();
              --d;
              d.get_date();
              cout<< "Nhap d1:" <<endl;
              cin >>d1;
              cout << "nhap n:"; cin>>n;
              d1+= n;
              cout<<d1;
              cout << "nhap m:"; cin>>m;
              d1-=m;
              cout<<d1;;
              getch();
              return 0;
          }  
