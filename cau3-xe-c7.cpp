#include <iostream.h>
#include <string.h>
class Xe
{
	protected:
		char ma[10];//ma so chuyen
		char ten[30];//ho ten tai xe
		int sxe;//So xe
		long int dt;//Doanh thu
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma so chuyen: ";cin.getline(this->ma,10);
			cout<<"\tNhap ho ten tai xe: ";cin.getline(this->ten,30);
			cout<<"\tNhap so xe: ";cin>>this->sxe;
			cout<<"\tNhap doanh thu: ";cin>>this->dt;
		}
		virtual void xuat()
		{
			cout<<"Ma so chuyen: "<<this->ma;
			cout<<"		Ho ten tai xe: "<<this->ten;
			cout<<"		So xe: "<<this->sxe;
			cout<<"		Doanh thu: "<<this->dt;
		}
		virtual long int doanh_thu(){};
		virtual int loai_xe()=0;
};
class NoiThanh: public Xe
{
	protected:
		float km; // So km di duoc
		int st;//So tuyen
	public:
		void nhap()
		{
			Xe::nhap();
			cout<<"\tNhap so Km di duoc: ";cin>>this->km;
			cout<<"\tNhap so tuyen: ";cin>>this->st;
		}
		void xuat()
		{
			Xe::xuat();
			cout<<"		So Km: "<<this->km;
			cout<<"		So tuyen: "<<this->st<<endl;
		}
		long int doanh_thu()
		{
			return dt;
		}
		int loai_xe()
		{
			return 1;
		}
		
};
class NgoaiThanh: public Xe
{
	protected:
		char noi[30];//Noi den
		float sn;//So ngay di duoc
	public:
		void nhap()
		{
			Xe::nhap();
			fflush(stdin);
			cout<<"\tNhap noi den: ";cin.getline(this->noi,30);
			cout<<"\tNhap so ngay di duoc: ";cin>>this->sn;
		}
		void xuat()
		{
			Xe::xuat();
			cout<<"		Noi den: "<<this->noi;
			cout<<"		So ngay: "<<this->sn<<endl;
		}
		long int doanh_thu()
		{
			return dt;
		}
		int loai_xe()
		{
			return 2;
		}
	
};
class QuanLy
{
	Xe *a[50];
	int n;
	public:
		void nhap()
		{
			int i=0;
			int chon;
			while(1)
			{
				cout<<"\nNhap thong tin chuyen xe: "<<endl;
				cout<<"\nXe noi thanh(1), Xe ngoai thanh(2), Thoat(3): ";cin>>chon;
				if(chon==1)
				{
					a[i]=new NoiThanh();	
				}else if(chon==2)
				{
					a[i]=new NgoaiThanh();
				}else{
					break;
				}
				a[i]->nhap();
				i++;
			}
			n=i;
		}
		void xuat()
		{
			cout<<"\nDanh sach cac chuyen xe; "<<endl;
			for(int i=0; i<n;i++)
			{
				a[i]->xuat();
			}	
		}
		long int tong()
		{
			long int s1=0, s2=0;
			for(int i=0; i<n; i++)
			{
				if(a[i]->loai_xe()==1) s1=s1+a[i]->doanh_thu();
				if(a[i]->loai_xe()==2) s2=s2+a[i]->doanh_thu();
			}
			cout<<"\nTong doanh thu xe Noi thanh: "<<s1<<endl;
			cout<<"\nTong doanh thu xe Ngoai thanh: "<<s2<<endl;
		}
			
};
int main()
{
	QuanLy q;
	q.nhap();
	q.xuat();
	q.tong();
	return 0;
}