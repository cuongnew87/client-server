#include<iostream>
#include<math.h>
using namespace std;
class CPoint
{
	int x,y;
	public:
		CPoint()
		{
			x = 0;
			y = 0;
		}
		void nhap()
		{
			cout<<"Nhap x,y:";
			cin>>x>>y;
		}
		void xuat()
		{
			cout<<"("<<x<<";"<<y<<")"<<endl;
		}
		void dichphai()
		{
			x = x+1;
			y = y;
		}
	float   kc(CPoint b)
		{
			return  sqrt(pow(x-b.x,2)+pow(y-b.y,2));
		}
		void kiemtra(CPoint a,CPoint b,CPoint c)
		{
			float ab = a.kc(b);
			float bc = b.kc(c);
			float ac = a.kc(c);
			if(ab + ac == bc || ac + bc == ab || ab + bc == ac)
			cout<<"3 diem thang hang";
			else 
			cout<<"3 diem khong thang hang";
		}
};
int main()
{
	CPoint p1,p2,p3;
	p2.nhap();
	cout<<"Cac diem vua nhap la:"<<endl;
	p1.xuat();
	p2.xuat();
	float khoangcach = p1.kc(p2);
	cout<<"Khoang cach:"<<khoangcach<<endl;
    p2.dichphai();
	cout<<"Diem p2 sau khi dich phai:"<<endl;
	p2.xuat();
	p3.nhap();
	p3.xuat();
	CPoint p4;
	p4.kiemtra(p1,p2,p3);
	
	
}
