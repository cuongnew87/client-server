#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class Oxy
{
	protected:
	float x,y;
	public:
		Oxy()
		{
			x = 0;
			y = 0;
		}
		Oxy(float x,float y)
		{
			x = x;
			y = y;
		}
		friend istream &operator >>(istream &is,Oxy &a)
		{
			cout<<"Nhap x,y:";
			is>>a.x>>a.y;
			return is;
		}
		friend ostream &operator <<(ostream &os,Oxy &a)
		{
			os<<"("<<a.x<<";"<<a.y<<")";
			return os;
		}
		~Oxy()
		{
		}
		friend float KC(Oxy a,Oxy b)
		{
			return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
		}
};
class DanhSach
{
	Oxy *ds;
	int size;
	public:
		DanhSach()
		{			size = 0;
			ds = new Oxy[size];
		}
		friend istream &operator >>(istream &is,DanhSach &a)
		{
			cout<<"Nhap so diem:";
			is>>a.size;	
			a.ds = new Oxy[a.size];	
			for(int i=0;i<a.size;i++)
			{		
				is>>a.ds[i];
			}
			return is;
		}
		friend ostream &operator <<(ostream &os,DanhSach a)
		{
			cout<<"Danh sach diem:"<<endl;
				for(int i=0;i<a.size;i++)
			{
				os<<a.ds[i]<<endl;
			}
			return os;
		}
		~DanhSach()
		{
		}
		void check()
		{
		for(int i=0;i<size;i++)
		{
			if(size==3&&KC(ds[i],ds[i+1])+KC(ds[i+1],ds[i+2])>KC(ds[i+2],ds[i])&&KC(ds[i+1],ds[i+2])+KC(ds[i+2],ds[i])>KC(ds[i],ds[i+1])&&KC(ds[i+2],ds[i])+KC(ds[i],ds[i+1])>KC(ds[i+1],ds[i+2]))
			{
			cout<<"Day la tam giac"<<endl;
			break;
		}
			else
			{ 
			cout<<"Khong phai la tam giac"<<endl;
			break;
		}
		}
			}	
};
int main()
{
	DanhSach a;
	cin>>a;
	cout<<a<<endl;
	a.check();
}
