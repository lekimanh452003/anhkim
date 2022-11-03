#include <iostream.h>
#include <string.h>
#include <iomanip.h>
#include <stdio.h>
class MayIn
{
	protected:
		char sh[10];
		int sl; //Thuoc tinh so hieu va so luong
	public:
		MayIn(){}	
		MayIn::MayIn(char* s): sl(0)
		{
			strcpy(sh, s);
		}
		MayIn(char *sh, int sl)
		{
			strcpy(sh,sh);
			sl=sl;
		}
		void nhapkho(int q)
		{
		
			sl=sl+q;
		}
		void xuatkho(int q)
		{
			sl=(sl>q)? sl-q: 0;
		}
		void in()
		{
			cout<<"\nMay in "<<sh<<" con so luong "<<sl<<" chiec"<<endl;
		}	
};
class Laser: public virtual MayIn
{
	protected:
		int DPI;
		
	public:
		Laser (int dpi):DPI(dpi){}
		Laser (char* s, int dpi):MayIn(s),DPI(dpi)
		{
			dpi=dpi;
		}
		void in()
		{
			cout<<"\nMay in Laser "<<sh<<" DPI "<<DPI
				<<" con so luong "<<sl<<" chiec"<<endl;
		}			
};
class InMau: public virtual MayIn
{
	protected:
		int bm;
	public:
		InMau(int m):bm(m){}
		InMau(char *s, int m):MayIn(s),bm(m)
		{
			m=m;
		}
		void in()
		{
			cout<<"\nMay in Mau "<<sh<<" bang mau "<<bm
				<<" con so luong "<<sl<<" chiec"<<endl;
		}		
};
class LaserMau: public Laser, public InMau
{	protected:
	public:
		LaserMau(char *s, int DPI, int bm):MayIn(s), Laser(s,DPI),InMau(s,bm)
		{
			
		}
		void in()
		{
			cout<<"\nMay in Laser Mau "<<sh<<" DPI "<<DPI<<" bang mau "<<bm
				<<" con so luong "<<sl<<" chiec"<<endl;
		}
};
int main()
{
	fflush(stdin);
	MayIn a1("X");
	Laser a2("Y", 1200);
	InMau a3("Z",4);
	LaserMau a4("T", 900, 4);
	a1.nhapkho(7);
	a2.nhapkho(5);
	a3.nhapkho(6);
	a4.nhapkho(3);
	a1.xuatkho(3);
	a2.xuatkho(3);
	a3.xuatkho(4);
	a4.xuatkho(2);
	a1.in();
	a2.in();
	a3.in();
	a4.in();
	cout<<endl;
	return 0;
}