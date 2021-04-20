#include "iostream"
#include "conio.h"
#include "iomanip"
#include "stdio.h"
#include "string.h"
//Xay dung lop Sach
using namespace std;

class Sach
      {
      	private:
           int maSSach;
           char tensach[50];
           char tacgia[30];
           int soluong;
        public :
              void nhap();
              void xuat();
              char* getTen(){
              	 return tensach;
              }
      };
 
 void Sach::nhap()
      {
            cout<< "Nhap Ma Sach :  "; 
            cin >>maSSach;
            cout<< "Nhap Ten Sach :  ";
            fflush(stdin);gets(tensach);
            cout<< "Nhap Tac Gia :  ";
            fflush(stdin);gets(tacgia);
            cout<<"So luong sach :  ";
            cin >>soluong; 
      }
      
 void Sach::xuat()
      {     
            cout<<setw(9)<<maSSach<<"|";
            cout<<setw(19)<<tensach<<"|";
            cout<<setw(9)<<tacgia<<"|";
            cout<<setw(9)<<soluong<<"\n";   
      }

//Xay Dung lop DSSV
class DSSach
      {
          int n;
          Sach ds[20];
        public :
              void nhap();
              void xuat();
			  void sapxep();  
      };
void DSSach::nhap()
     {
           cout<<"Nhap so Sach :  "; cin>>n;
           cout<<"\n NHAP THONG TIN TUNG QUYEN SACH \n";
           for(int i=0;i<n;i++)
                   ds[i].nhap();      
     }

void DSSach::xuat()
     {
           cout<<"\n DANH SACH SACH \n";
           cout<<setw(10)<<"Ma Sach |"<<setw(20)<<"Ten Sach           |"<<setw(10)<<"Tac gia |"<<setw(10)<<"So Luong\n";
           for(int i=0;i<n;i++)
                   ds[i].xuat();      
     }
void DSSach::sapxep()
{
	for(int i=0;i<n-1;i++)
	{
		for (int j= i+1;j<n;j++)
		{
			if(strcmp(ds[i].getTen(),ds[j].getTen())>0)
			{
				Sach temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	
}

main()
     {
      DSSach ds;
      
      ds.nhap();
      
      ds.xuat();
      cout<<"Danh sach sach sau khi sap xep la: ";
      ds.sapxep();
      
      ds.xuat();

      getch();
            
     }
