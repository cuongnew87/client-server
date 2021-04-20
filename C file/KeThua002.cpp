#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <iomanip>
using namespace std;
class DIEM
{
	private:
		int x;
		int y;
	public:
		DIEM( int xx, int yy);
		void nhap( );
		void in( );
};
	
DIEM::DIEM( int xx, int yy)
{
x = xx;
y = yy;
}

