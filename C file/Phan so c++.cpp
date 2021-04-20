#include<iostream>
#include<iomanip>
using namespace std;
class phanso
{
	private: //Chua thanh phan cua lop
		int ts,ms;
	public: 
		void nhap();
		void tong(phanso b);
		void hieu(phanso b);
		void nhan(phanso b);
		void chia(phanso b);
		void rutgon();
		void xuat();
};
void phanso ::chia(phanso b)
{
	ts= ts*b.ms;
	ms= ms*b.ts;
}
void phanso ::nhan(phanso b)
{
    ts= ts*b.ts;
	ms= ms*b.ms;	
}
void phanso ::nhap()
{
	cout<<"Nhap tu so:";
	cin>>ts;
	cout<<"Nhap mau so:";
	cin>>ms;
}
void phanso ::tong(phanso b)
{
	ts= ts*b.ms+b.ts*ms;
	ms= ms*b.ms;
}
void phanso ::hieu(phanso b)
{
	ts= ts*b.ms-b.ts*ms;
	ms= ms*b.ms;
}
void phanso ::xuat()
{
	
	cout<<ts<<"/"<<ms<<endl;
}
void phanso ::rutgon()
{
	for(int i=1;i<=ts*ms;i++)
	{
		if(ts%i==0 && ms%i==0)
		{
			ts = ts/i;
			ms = ms/i;
		}
	}
}
int main()
{
	phanso a,b,c;
	a.nhap();
	a.rutgon();
	b.nhap();
	b.rutgon();
	cout<<"Phan so vua nhap la:"<<endl;
	a.xuat();
	b.xuat();
	c = a;
	c.tong(b);
	c.rutgon();
	cout<<"Tong 2 phan so vua nhap la:";
	c.xuat();
	c = a;
	c.hieu(b);
	c.rutgon();
	cout<<"Hieu 2 phan so vua nhap la:";
	c.xuat();
	c = a;
	c.nhan(b);
	c.rutgon();
	cout<<"Tich 2 phan so vua nhap la:";
	c.xuat();
	c = a;
	c.chia(b);
	c.rutgon();
	cout<<"Thuong 2 phan so vua nhap la:";
	c.xuat();
	
}
