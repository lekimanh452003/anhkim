#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class Nguoi
{
	private:
		char ht[30];//ho ten
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ho va ten: ";cin.getline(this->ht,30);
		}
		virtual void xuat()
		{
			cout<<setw(15)<<left<<this->ht;
		}
		virtual int phan_loai()=0;
		virtual int thuong(){};
};
class SinhVien: public Nguoi
{
	private:
		float dt;//diem thi	
	public:
		void nhap()
		{
			Nguoi::nhap();
			cout<<"\tNhap diem thi: ";cin>>this->dt;
		}
		void xuat()
		{	Nguoi::xuat();
			cout<<setw(15)<<left<<this->dt<<endl;
		}
		int phan_loai()
		{
			return 1;
		}
		int thuong()
		{
			if(dt>8){
				return true;
			}else{
				return false;
			}
		}
};
class GiangVien: public Nguoi
{
	private:
		int sbb;//so bai bao
	public:
		void nhap()
		{
			Nguoi::nhap();
			cout<<"\tNhap so bai bao: ";cin>>this->sbb;
		}
		void xuat()
		{	Nguoi::xuat();
			cout<<setw(15)<<left<<"x";
			cout<<setw(15)<<left<<this->sbb<<endl;
		}
		int phan_loai()
		{
			return 2;
		}
		int thuong()
		{
			if(sbb>5){
				return true;
			}else{
				return false;
			}
		}	
		
};
void tieude()
{
	cout<<setw(15)<<left<<"Ho ten";
	cout<<setw(15)<<left<<"Diem";
	cout<<setw(15)<<left<<"So bai bao"<<endl;
}
class Quanly
{
	Nguoi *a[100];
	int n;
	public:
		void nhap()
		{
			int i=0;
			int chon;
			cout<<"\NHAP THONG TIN."<<endl;
			while(1)
			{
				cout<<"\nSinh vien(1), Giang vien(2),Dung(3): ";cin>>chon;
				if(chon==1) a[i] = new SinhVien();
				else if(chon==2) a[i] = new GiangVien();
				else break;
				a[i]->nhap();
				i++;
				n=i;	
			};
		}
		void xuat()
		{
			tieude();
			for(int i=0; i<n;i++)
			{
				a[i]->xuat();
			}
		}	
		void tim()
		{
			cout<<"\nDoi tuong duoc thuong"<<endl;
			tieude();
			for(int i=0; i<n; i++)
			{
				if(a[i]->thuong()==true)
				{
					a[i]->xuat();
				}
			}
		}
};
int main()
{
	Quanly q;
	q.nhap();
	q.xuat();
	q.tim();
	return 0;
}