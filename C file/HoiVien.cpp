#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
using namespace std;
class date{
	public:
	int ngay , thang, nam;
	public:
		int getngay()
		{
			return ngay;
		}
		int getthang()
		{
			return thang;
		}
		int getnam()
		{
			return nam;
		}
		void nhap()
		{
			cout<<"nhap vao ngay -thang -nam:";
			cin>>ngay>>thang>>nam;
			
		}
		void xuat()
		{
			cout<<"ngay"<<ngay<<"thang"<<thang<<"nam"<<nam;
		}
};
class HV{
	public:
		char hoten[20];
		char diachi[20];
		date ns;
	public:
		HV()
		{
		
		}
		virtual void nhap()
		{ 
		    ns.nhap();
			cout<<"nhap vao ho ten hoi vien:";
			fflush(stdin);
			gets(hoten);
			cout<<"nhap vao dia chi hoi vien:";
			fflush(stdin);
			gets(diachi);
		}
		virtual void xuat()
		{
			ns.xuat();
			cout<<"ho ten"<<hoten<<"diachi"<<diachi<<endl;
			
		}
};
class GD:public HV{
	public:
		char tenvo[10];
	public :
		GD()
		{
		
		}
		 void nhap ()
		{
			HV::nhap();
			cout<< "nhap vao ten vo:";
			fflush(stdin);
			gets(tenvo);
		}
		 void xuat()
		{ 
		    HV::xuat();
			cout<<"ten vo:"<<tenvo;
		}
};
class NY:public HV{
	private :
		int sdt;
	public:
		NY()
		{
		
		}
		void nhap()
		{
			HV::nhap();
			cout<<"nhap vao sdt :";
			cin>>sdt;
		}
		void xuat()
		{
			HV::xuat();
			cout<<"sdt"<<sdt;
		}
		
};
int main()
{
	int n;
	HV *a[100];

			cout<<"nhap vao danh sach hoi vien:"<<endl;
			cin>>n;
			
		
			for(int i=0;i<n;i++)
			{
				int choice;
				cout<<"Moi ban lua chon:";
				cout<<"0. Ban chua co nguoi yeu"<<endl;
				cout<<"1. Ban co nguoi yeu"<<endl;
				cout<<"2. Ban co gia dinh"<<endl;
				cin>>choice;
				if(choice == 0)
				{
					a[i] = new HV();
					a[i]->nhap();
				}
				else if(choice == 1)
				{
					a[i] = new NY();
					a[i]->nhap();
				}
				else if(choice == 2)
				{
					a[i] = new GD();
					a[i]->nhap();
				}
			}
	
			for(int i=0;i<n;i++)
			{
				a[i]->xuat();
				//cout<<endl;
			}
	
		
}

