#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
class hdon
 {
  private:
    char tenhang[20];
    float dongia,soluong,thanhtien;
  public:
    int nhap(int i);
    void in(int);
    friend fstream& operator<<(fstream& fs,const hdon &hd);
    friend fstream& operator>>(fstream& fs,hdon &hd);
    float getttien()
     {
      return thanhtien;
     }
 };
int hdn=sizeof(hdon);

fstream& operator>>(fstream& fs,hdon &hd)
 {
  fs.read((char*)(&hd), hdn);
  return fs;
 }

fstream& operator<<(fstream& fs,const hdon &hd)
 {
  fs.write( (char*)(&hd),hdn);
  return fs;
 }

void hdon::in(int i)
 {
  cout<<endl<<setw(5)<<i<<"    "<<setiosflags(ios::left)<<setw(15)<<tenhang<<setiosflags(ios::right)
      <<setw(10)<<soluong<<setw(12)<<dongia<<setw(12)<<thanhtien;
 }

int hdon::nhap(int i)
 {
  cout << "\nNhap mat hang thu "<<i<<". Neu khong muon nhap thi khong nhap ten hang:";
  cout << "\nTen hang: "; cin.get(tenhang,20);
  if (tenhang[0]==0)
   return 0;
  cout << "So luong: " ; cin >> soluong ;
  cout << "Don gia: " ;  cin >> dongia ;
  thanhtien=soluong*dongia;
  cin.ignore();
  return 1;
 }
  
int main() {

  fstream f("solieu.cpp",ios::binary | ios::out|ios::in);
  hdon hd;
  int i=0;
  float tongtien=0;
  while (hd.nhap(++i))
    f<<hd;
  f.seekg(0,ios::beg);
  i=0;

  cout<<"                    SO LIEU BAN HANG";
  cout<<"\n   STT       TEN HANG        SO LUONG    DON GIA    THANH TIEN";
  while (f>>hd,!f.eof())
   {
    hd.in(++i);
    tongtien+=hd.getttien();
   }
  cout<<setw(68)<<" Tong tien"<<setw(12)<<tongtien;
  f.close();
  getch();
}
