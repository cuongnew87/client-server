#include <iostream.h>
#include <conio.h>
#include <stdio.h>
int ngay[13]={0,31,28,31,30,31,30,31,30,31,30,31,30};
class Date
{
      int d,m,y;
public:
  friend istream& operator>>(istream &in,Date &x);
  friend ostream& operator<<(ostream &out,Date x);
  operator int();
  };
 istream & operator>>(istream &in,Date &x)
  {
 cout<<"Nhap ngay:";   in>>x.d;
 cout<<"Nhap thang:";  in>>x.m;
  cout<<"Nhap nam:";  in>>x.y;
  return in;
     }
 ostream& operator <<(ostream &out ,Date x)
 {
    out<<x.d<<"/"<<x.m<<"/"<<x.y;
                                          
 return out;
     }
 Date::operator int()
 {
   int songay;
   songay=d;
   for(int i=1;i<=m-1;i++)
   {
      songay= songay+ ngay[i];
      if(i==2&&(y%4==0&&y%100!=0)||(y%400==0))
      songay=songay+1;

   }
   songay=songay +365*(y-1900);
   songay=songay+ (y-1900)/4;
 /*
   for((i%4==0&&i%100!=0)||(i%400==0))
   songay=songay+1;
 */
 return songay;

               }
               int main()
               {
                 Date x,y  ;

                int khoangcach;
                 cin>>x;
                 cin>>y;
                 khoangcach= int(x)-int(y);
                 cout<<"khoang cach tu ngay"<<x<<"den ngay "<<y<<"la:"<<khoangcach;
                 getch();

               }








































