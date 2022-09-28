#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class HCN
{
	private:
	float d,r;//thuoc tinh, bien thanh vien
	char ma[20];
	public:


	HCN()//ham tao khong tham so
	{
		d=0;r=0;
		strcpy(ma,"");
	}
	HCN(float a)
	{
		d=a;r=a;
	}
	HCN(float dai,float r,char *ma="")
	{
		d=dai;this->r=r;strcpy(this->ma,ma);
	}
	HCN(const HCN &h)//ham tao sao chep
	{
		this->d=h.d;
		this->r=h.r;
	}
	void nhap()
	{
		cout<<"Moi nhap chieu dai:";cin>>this->d;
		cout<<"Moi nhap chieu rong:";cin>>this->r;
		cout<<"moi nhap ma";
		fflush(stdin);
		cin.getline(ma,20);
	}
	void xuat()
	{
		cout<<"("<<d
			<<","<<r<<")"<<endl;
	}
	float chuvi()
	{
		return 2*(d+r);
	}
	float dientich()
	{
		return d*r;
	}
	HCN cong(HCN h)
	{
		HCN T;
		if (this->d==h.d) //if (h1.d==h2.d)
		{
			T.d=h.d;		//T.d=h2.d;
			T.r=h.r+this->r;//T.r=h2.r+h1.r;
		}
		else if (this->r==h.r)
		{
			T.r=h.r;
			T.d=h.d+this->d;
		}
		else
		{
			T.d=0;T.r=0;
			
		}
		return T;
	}
};
int main(){
	HCN h;//goi ham tao ko ts
	h.xuat();
	HCN h1(5);
	h1.xuat();
	HCN h2(4,3);
	h2.xuat();
	HCN h3(h2);
	h3.xuat();
	
}
