#include <iostream.h>
#include <string.h>
struct NgayThang
{
	int dd,mm,yy;//ngay/thang/nam giao dich	
};
class GD
{
	protected:
		char ma[10];//ma giao dich
		NgayThang ng;//ngay giao dich
		float dg;//don gia
		float dt;//dien tich
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma giao dich: ";cin.getline(this->ma,10);
			cout<<"\tNhap ngay/thang/nam giao dich: ";cin>>this->ng.dd>>this->ng.mm>>this->ng.yy;
			cout<<"\tNhap don gia: ";cin>>this->dg;
			cout<<"\tNhap dien tich: ";cin>>this->dt;
		}
		virtual void xuat()
		{
			cout<<"\tMa: "<<this->ma;
			cout<<"\tNgay/thang/nam: "<<this->ng.dd
				<<"/"<<this->ng.mm<<"/"<<this->ng.yy;
			cout<<"\tDon gia: "<<this->dg;
			cout<<"\tDien tich: "<<this->dt;
		}
		virtual long double tien(){};
		virtual int loai_gd()=0;
		
		virtual int get_ng(){};
};

class GdDat: public virtual GD
{
	protected:
		char ld[3];//loai dat
	public:	
		void nhap()
		{
			GD::nhap();
			fflush(stdin);
			cout<<"\tNhap loai dat (A,B,C): ";cin.getline(this->ld,3);
			
		}
		long double tien()
		{
			if(strcmpi(ld,"A")==0)
			{
				return dt*dg*1.5;
			}else{
				return dt*dg;
			}
		}
		void xuat()
		{
			GD::xuat();
			cout<<"\tLoai dat: "<<this->ld;
			cout<<"\tThanh tien: "<<tien()<<endl;
		}
		
		int loai_gd()
		{
			return 1;
		}
		int get_ng()
		{
			if(ng.mm==9 && ng.yy==2013)
			{
				return true;
			}else{
				return false;
			}
		}
};
class GdNha:public virtual GD
{
	protected:
		char ln[10];//loai nha	
		char dc[50];//dia chi
	public:
		void nhap()
		{
			GD::nhap();
			fflush(stdin);
			cout<<"\tNhap loai nha (Cao cap, Thuong): ";cin.getline(this->ln,10);
			cout<<"\tNhap dia chi: ";cin.getline(this->dc,50);
		}
		long double tien()
		{
			if(strcmpi(ln,"cao cap")==0)
				{
					return dt*dg;
				}else{
					return dt*dg*0.9;
				}	
		}
		void xuat()
		{
			GD::xuat();
			cout<<"\tLoai nha: "<<this->ln;
			cout<<"\tDia chi: "<<this->dc;
			cout<<"\tThanh tien: "<<tien()<<endl;
		}
		
		int loai_gd()
		{
			return 2;
		}
		int get_ng()
		{
			if(ng.mm==9 && ng.yy==2013)
			{
				return true;
			}else{
				return false;
			}
		}
};
class QuanLy
{
	GD *a[100];
	int n;	
	public:
		void nhap()
		{
			int i=0;
			int chon;
			while(1)
			{
				cout<<"\nNhap loai giao dich: "<<endl;
				cout<<"\nGiao dich dat(1), Giao dich nha(2), Thoat(3): ";
				cin>>chon;
				if(chon==1)
				{
					a[i] = new GdDat();
				}
				else if(chon==2)
				{
					a[i] = new GdNha();
				}
				else{
					break;
				}
				a[i]->nhap();
				i++;
			}
			n=i;
		}
		void xuat()
		{
			cout<<"\nDanh sach giao dich: "<<endl;
			for(int i=0; i<n; i++)
			{
				a[i]->xuat();
			}
			int d1=0, d2=0;
			for(int i=0; i<n;i++)
			{
				if(a[i]->loai_gd()==1) d1++;
				if(a[i]->loai_gd()==2) d2++;
			}
			cout<<"\nSo luong giao dich dat la: "<<d1<<endl;
			cout<<"\nSo luong giao dich nha la: "<<d2<<endl;
			long double s=0;
			for(int i=0; i<n;i++)
			{
				if(a[i]->loai_gd()==1) s=s+a[i]->tien();
			}
			cout<<"\nTrung binh thanh tien cua giao dich dat: "<<s/d1<<endl;
			cout<<"\nGiao dich cua thang 9/2013: "<<endl;
			for(int i=0 ;i<n;i++)
			{
				if(a[i]->get_ng()==true)
				{
					a[i]->xuat();
				}
			}
		}
		
};
int main()
{
	QuanLy q;
	q.nhap();
	q.xuat();
	return 0;
}