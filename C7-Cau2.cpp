#include <iostream.h>
#include <iomanip.h>
#include <string.h>
struct NgayThang
{
	int dd,mm,yy;	
};
class HD
{
	protected:
		char mhd[10];//Ma hoa don
		NgayThang nt;//ngay thang
		char ten[30];//Ten khach hang
		char mp[10];//Ma phong
		double dg;//don gia
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma hoa don: ";cin.getline(this->mhd, 10);
			cout<<"\tNhap ngay/thang/nam: ";cin>>this->nt.dd>>this->nt.mm>>this->nt.yy;
			fflush(stdin);
			cout<<"\tNhap ten khach hang: ";cin.getline(this->ten,30);
			cout<<"\tNhap ma phong: ";cin.getline(this->mp, 10);
			cout<<"\tNhap don gia: ";cin>>this->dg;
		}
		virtual void xuat()
		{
			cout<<"	Ma hoa don: "<<this->mhd;
			cout<<"		Ngay: "<<this->nt.dd<<"/"<<this->nt.mm<<"/"<<this->nt.yy;
			cout<<"		Ten: "<<this->ten;
			cout<<"		Ma phong: "<<this->mp;
			cout<<"		Don gia: "<<this->dg;
		}	
		virtual long double tien(){};
		virtual int loai_hd()=0;
		int get_thang()
		{
			return nt.mm;
		}
		int get_nam()
		{
			return nt.yy;
		}
};

class HDTG:public HD
{
	protected:
		float gio;//so gio thue
	public:
		void nhap()
		{
			HD::nhap();
			cout<<"\tNhap so gio thue: ";cin>>this->gio;
		}
		long double tien()
		{
			if(gio >24 && gio <30)
			{
				return 24*dg;
			}else if(gio >=1 && gio <=24){
				return gio*dg;
			}else{
				return 0;
			}
		}
		void xuat()
		{
			HD::xuat();
			cout<<"		So gio thue: "<<this->gio;
			cout<<"		Thanh tien: "<<tien()<<endl;
		}
		int loai_hd()
		{
			return 1;
		}
	
};
class HDTN: public HD
{
	protected: 
		int snt;//so ngay thue
	public:
		void nhap()
		{
			HD::nhap();
			cout<<"\tNhap so ngay thue: ";cin>>snt;
		}
		long double tien()
		{
			if(snt > 7)
			{
				return snt*dg*0.8;
			}else{
				return snt*dg;
			}
		}
		void xuat()
		{
			HD::xuat();
			cout<<"		So ngay thue: "<<snt;
			cout<<"		Thanh tien: "<<tien()<<endl;
		}
		int loai_hd()
		{
			return 2;
		}
		
};

class QuanLy
{
	HD *a[100];
	int	n;
	public:
		void nhap()
		{
			int i=0;
			int chon;
			while(1)
			{
				cout<<"\nNhap danh sach hoa don thue phong: "<<endl;
				cout<<"\nHoa don theo gio(1), Hoa don theo ngay(2), Thoat(3): ";cin>>chon;
				if(chon==1) a[i]=new HDTG();
				else if(chon==2) a[i]=new HDTN();
				else break;
				a[i]->nhap();
				i++;
			}
			n=i;
		
		}
		void xuat()
		{
			cout<<"\nSo luong hoa don: "<<n<<endl;
			cout<<"\nDanh sach hoa don: "<<endl;
			for(int i=0;i<n;i++)
			{
				a[i]->xuat();
			}
			int d1=0, d2=0;
			for(int i=0; i<n;i++)
			{
				if(a[i]->loai_hd()==1) d1++;
				if(a[i]->loai_hd()==2) d2++;
			}
			cout<<"\nSo luong hoa don theo gio: "<<d1<<endl;
			cout<<"\nSo luong hoa don theo ngay: "<<d2<<endl;
		}
		
		long double tb_tien()
		{
			long double s1=0,s2=0;
			int d1=0, d2=0;
			for(int i=0; i<n; i++)
			{
				if(a[i]->get_thang()==9 && a[i]->get_nam()==2013)
				{
					if(a[i]->loai_hd()==1)
					{
						s1=s1+a[i]->tien();
					 	d1++;
					}
					if(a[i]->loai_hd()==2) 
					{
						s2=s2+a[i]->tien();
						d2++;
					}
				}	
			}
			cout<<"TB thanh tien: "<<(s1+s2)/(d1+d2)<<endl;;
		}
};
int main()
{
	QuanLy q;
	q.nhap();
	q.xuat();
	q.tb_tien();
	return 0;
}