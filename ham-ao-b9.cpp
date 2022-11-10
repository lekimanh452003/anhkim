#include <iostream.h>
#include <string.h>
using namespace std;

class NhanVien
{
	protected: 
		char ht[30];//Ten nhan vien
		float  lg; //Ma, luong
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ho ten: ";cin.getline(this->ht,30);	
		}
		virtual void xuat()
		{
			cout<<"Ten: "<<this->ht<<"		";
		}
		virtual float luong()=0;//Ham thuan ao
		virtual int kieu_nv()=0;
		virtual int get_sp()=0;
};
class QuanLy: public NhanVien
{
	protected:
		int x;//Luong co dinh
	public:
		void nhap()
		{
			NhanVien::nhap();
			cout<<"\tNhap luong co dinh: ";cin>>this->x;
		}
		float luong()
		{
			return x;
		}
		void xuat()	
		{
			NhanVien::xuat();
			cout<<"Luong co dinh: "<<this->x<<"		Luong: "<<luong()<<endl;	
		}	
		int kieu_nv()
		{
			return 1;
		}
		int get_sp()
		{
		}
};
class CongNhan1: public NhanVien
{
	protected:
		int gio, y;//gio, luong co ban
	public:
		void nhap()
		{
			NhanVien::nhap();
			cout<<"\tNhap so gio lam viec: ";cin>>this->gio;
			cout<<"\tNhap luong co ban: ";cin>>this->y;
		}	
		float luong()
		{
			if(gio>40)
			{
				lg=y + (gio-40)*1.5;
			}
			return lg;
		}
		void xuat()
		{
			NhanVien::xuat();
			cout<<"So gio lam: "<<this->gio<<"		Luong co ban: "
			<<this->y<<"		Luong: "<<luong()<<endl;
		}
		int kieu_nv()
		{
			return 2;
		}
		int get_sp()
		{
		}
};
class CongNhan2: public NhanVien
{
	protected:
		int z;//Doanh so ban hang
	public:
		void nhap()
		{
			NhanVien::nhap();
			cout<<"\tNhap doanh so ban hang: ";cin>>this->z;
		}
		float luong()
		{
			return 0.07*z;
		}
		void xuat()
		{
			NhanVien::xuat();
			cout<<"Doanh so ban hang: "<<this->z<<"		Luong: "<<luong()<<endl;
		}
		int kieu_nv()
		{
			return 3;
		}
		int get_sp()
		{
		}	
};
class CongNhan3: public NhanVien
{
	protected:
		int n, s;//So san pham n, tien moi san pham
	public:
		void nhap()
		{
			NhanVien::nhap();
			cout<<"\tNhap so san pham: ";cin>>this->n;
			cout<<"\tNhhap tien moi san pham: ";cin>>this->s;
		}
		float luong()
		{
			return n*s;
		}
		void xuat()
		{
			NhanVien::xuat();
			cout<<"So san pham: "<<this->n<<"	Tien/SP: "<<this->s
			<<"		luong: "<<luong()<<endl;
		}
		int kieu_nv()
		{
			return 4;
		}
		int get_sp()
		{
			return (this->n);
		}
	
};


int main()
{
	
	int n, i, chon;
	cout<<"\nNhap so luong nhan vien trong cong ty: ";cin>>n;
	NhanVien *nv[n];
	for(i=0; i<n;i++)
	{
		cout<<"\nNhap nhan vien thu "<<i+1<<endl;
		cout<<"\nNhap ma nhan vien: "<<endl;
		cout<<"\nQuan ly(1), Cong nhan(2), Cong nhan theo loi nhuan(3),Cong nhan theo ma san pham(4): ";
		cin>>chon;
		if(chon==1)
		{
			nv[i]=new QuanLy();
		}else if(chon==2){
			nv[i]=new CongNhan1();
		}else if(chon==3){
			nv[i]=new CongNhan2();
		}else{
			nv[i]=new CongNhan3();
		}
		nv[i]->nhap();
	}
	cout<<"\nDanh sach nhan vien: "<<endl;
	for( i=0; i<n; i++)
	{
		nv[i]->xuat();
	}
	float s1=0, s2=0, s3=0, s4=0;
	for(i=0; i<n; i++)
	{
		if(nv[i]->kieu_nv()==1) s1=s1+nv[i]-> luong();
		else if(nv[i]->kieu_nv()==2) s2=s2+nv[i]->luong();
		else if(nv[i]->kieu_nv()==3) s3=s3+nv[i]->luong();
		else if(nv[i]->kieu_nv()==4) s4=s4+nv[i]->luong();
	}
	cout<<"\ntong so tien phai tra cho quan ly: "<<s1<<endl;
	cout<<"\ntong so tien phai tra cho cong nhan: "<<s2<<endl;
	cout<<"\ntong so tien phai tra cho cong nhan theo loi nhuan: "<<s3<<endl;
	cout<<"\ntong so tien phai tra cho cong nhan theo ma san pham: "<<s4<<endl;
	cout<<"\nSap xep giam dan theo so san pham: "<<endl;

	for (int i = 0; i < n-1; i++)
	{
		if (nv[i]->kieu_nv() == 4 )
		{
			for (int j = i+1; j < n; j++)
			{
				if (nv[j]->kieu_nv() == 4)
				{
					if(nv[i]->get_sp() < nv[j]->get_sp())
					{
						swap(nv[i],nv[j]);
					}
				}
			}
		}
	}
	for(int i=0; i<n; i++)
	{
	nv[i]->xuat();
	}
	return 0;
}