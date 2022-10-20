#include <iostream.h>
#include <math.h>
class VecTor3
{
	private:
		int a, b, c;// toa do vecto
	public:
		VecTor3(int a=0, int b=0, int c=0)
		{
			this->a=a;
			this->b=b;
			this->c=c;
		}
		~VecTor3(){};
		void nhap()
		{
			cout<<"\nNhap toa do a, b, c: ";
			cin>>this->a>>this->b>>this->c;
		}
		void xuat()
		{
			cout<<"("<<this->a<<","<<this->b<<","<<this->c<<")"<<"		";
		}
		friend VecTor3 operator + (VecTor3 &A, VecTor3 &B)
		{
			VecTor3 kq;
			kq.a=A.a+B.a;
			kq.b=A.b+B.b;
			kq.c=A.c+B.c;
			return kq;
		}
		friend VecTor3 operator - (VecTor3 &A, VecTor3 &B)
		{
			VecTor3 kq;
			kq.a=A.a-B.a;
			kq.b=A.b-B.b;
			kq.c=A.c-B.c;
			return kq;
		}
};
int main()
{
	VecTor3 A, B; 
	cout<<"\nVec-to A: ";
	A.nhap();
	cout<<"\nVec-to B: ";
	B.nhap();
	
	cout<<"A=";
	A.xuat();
	cout<<"B=";
	B.xuat();
	
	VecTor3 C;
	C=A+B;
	cout<<"A+B=";
	C.xuat();
	
	C=A-B;
	cout<<"A-B=";
	C.xuat();
	return 0;
}
