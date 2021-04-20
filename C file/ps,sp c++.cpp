#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;
class PS
{
	private:
		int tu,mau;
	public:
		PS()
		{
			tu=0;
			mau=1;
			
		}
		~PS()
		{
		}		
		friend istream& operator>>(istream& is,PS &a)
		{
			cout<<"nhap tu so: ";
			is>>a.tu;
			cout<<"nhap mau so: ";
			is>>a.mau;
			return is;
		}
		friend ostream& operator<<(ostream& os,PS &a)
		{
			os<<a.tu<<"/"<<a.mau<<endl;
			
			return os;
		}
		PS operator+(PS a)
		{
			PS b;
			b.tu=tu*a.mau+mau*a.tu;
			b.mau=mau*a.mau;
			return b;
		}
		
};
class SP
{
	private: 
		int thuc,ao;
	public:
		SP()
		{
			thuc=0;
			ao=0;
		}
		~SP()
		{
		}
		void nhap()
		{
			cout<<"nhap phan thuc: ";
			cin>>thuc;
			cout<<"nhap phan ao: ";
			cin>>ao;
			
		}
		friend istream& operator>>(istream& is,SP &a)
		{
			a.nhap();
			return is;
		}
		friend ostream& operator<<(ostream& os,SP &a)
		{
			os<<a.thuc<<"+"<<a.ao<<"i"<<endl;
			return os;
		}
		SP operator+(SP a)
		{
			SP b;
			b.thuc=thuc+a.thuc;
			b.ao=ao+a.ao;
			return b;
		}
		
};
template<class T>
class DS
{
	private: 
		T *a;
		int size;
	public:
		DS()
		{
			size = 0;
			a = new T[size];			
		}
		DS(int size)
		{
			size = size;
			a = new T[size];			
		}
		~DS()
		{
		}
		void nhap()
		{
			cout<<"nhap so luong phan tu: ";
			cin>>size;
			a = new T[size];
			for(int i=0;i<size;i++)
			{
				cin>>a[i];
			}
		}
		void xuat()
		{
			for(int i=0;i<size;i++)
			{
				cout<<a[i];
			}
		}
		T tinhtong()
		{
			T tong;
			for(int i=0;i<size;i++)
			{
				tong=tong+a[i];
			}
			return tong;
		}		
};
int main()
 {
	DS<SP> a;
	a.nhap();
	a.xuat();
	SP tongsp=a.tinhtong();
	cout<<"tong cac SP vua nhap la: "<<tongsp<<endl;
	DS<PS> b;
	b.nhap();
	b.xuat();
	PS tongps=b.tinhtong();
	cout<<"tong cac PS vua nhap la: "<<tongps<<endl;	
	return 0;
}
