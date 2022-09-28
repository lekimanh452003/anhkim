#include <iostream.h>
class DaThuc3
{
	private:
		int a, b, c, d; // Cac he so cua da thuc bac 3
	public:
		DaThuc3() // Ham khoi tao khong tham so
		{
			this->a=0;
			this->b=0;
			this->c=0;
			this->d=0;
		}
		DaThuc3(int a1) //Ham tao 1 tham so
		{
			this->a=a1;
		}
		DaThuc3(int a1, int b1) //Ham tao 2 tham so
		{
			this->a=a1;
			this->b=b1;
		}	
		DaThuc3(int a1, int b1, int c1) //Ham tao 2 tham so
		{
			this->a=a1;
			this->b=b1;
			this->c=c1;
		}
		DaThuc3(int a1, int b1, int c1, int d1) //Ham tao 2 tham so
		{
			this->a=a1;
			this->b=b1;
			this->c=c1;
			this->d=d1;
		}
		void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap he so a: "; cin>>this->a;
			cout<<"\tNhap he so b: "; cin>>this->b;
			cout<<"\tNhap he so c: "; cin>>this->c;
			cout<<"\tNhap he so d: "; cin>>this->d;	
		}	
		void xuat()
		{
			cout<<"("<<this->a<<"X^3 + "
				<<this->b<<"X^2 + "
				<<this->c<<"X + "
				<<this->d<<")"<<endl;
		}
		int getA()
		{
			return a;
		}
			int getB()
		{
			return b;
		}
			int getC()
		{
			return c;
		}
			int getD()
		{
			return d;
		}
		~DaThuc3(){};	
};
int main()
{
	DaThuc3 dt[2];
	for(int i = 0; i < 2; i++)
	{
		cout<<"\nNhap da thuc thu "<<i+1<<endl;
		dt[i].nhap();
	}
	cout<<"\nTong 2 da thuc la: "<<endl;
	cout<<"("<<dt[0].getA()+dt[1].getA()
	<<"X^3 + "<<dt[0].getB()+dt[1].getB()
	<<"X^2 + "<<dt[0].getC()+dt[1].getC()
	<<"X + "<<dt[0].getD()+dt[1].getD()<<")"<<endl;
	return 0;
}