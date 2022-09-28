#include <iostream.h>
class PhanSo
{
	private:
		int t; //Tu so
		int m; // Mau so
	public:
		PhanSo(int a=1, int  b=1)
		{
			this->t=a;
			this->m=b;
		}	
		~PhanSo(){};
		void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap tu so = "; cin>>this->t;
			cout<<"\tNhap mau so = "; cin>>this->m;
		}
		void xuat()
		{
			cout<<this->t<<"/"<<this->m<<"		";
		}
		float tong(PhanSo ps1, PhanSo ps2) 
		{
			PhanSo kq;
				kq.t=ps1.t*ps2.m + ps1.m*ps2.t;
				kq.m=ps1.m*ps2.m;
				
			return (float)kq.t/kq.m;	
		}
		float hieu(PhanSo ps1, PhanSo ps2) 
		{
			PhanSo kq;
				kq.t=ps1.t*ps2.m - ps1.m*ps2.t;
				kq.m=ps1.m*ps2.m;
				
			return (float)kq.t/kq.m;	
		}
		float tich(PhanSo ps1, PhanSo ps2)
		{
			PhanSo kq;
				kq.t=ps1.t*ps2.t;
				kq.m=ps1.m*ps2.m;
				
			return (float)kq.t/kq.m;	
		}
		float thuong(PhanSo ps1, PhanSo ps2)
		{
			PhanSo kq;
				kq.t=ps1.t*ps2.m ;
				kq.m=ps1.m*ps2.t;
				
			return (float)kq.t/kq.m;	
		}
};

int main()
{
	PhanSo ps1, ps2;
	cout<<"\nNhap phan so thu 1:  "<<endl;
	ps1.nhap();
	cout<<"\nNhap phan so thu 2:"<<endl;
	ps2.nhap();
	cout<<"\n2 phan so vua nhap la: "<<endl;
	ps1.xuat();
	ps2.xuat();
	PhanSo ps;
	cout<<"\nTong 2 phan so la: "<<ps.tong(ps1, ps2)<<endl;
	cout<<"\nHieu 2 phan so la: "<<ps.hieu(ps1, ps2)<<endl;
	cout<<"\nTich 2 phan so la: "<<ps.tich(ps1, ps2)<<endl;
	cout<<"\nThuong 2 phan so la: "<<ps.thuong(ps1, ps2)<<endl;
	return 0;
}