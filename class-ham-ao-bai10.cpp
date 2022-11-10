#include <iostream.h>
#include <string.h>
using namespace std;
class KhachSan
{
	protected:
		char mhd[10],mkh[10], ten[30];//Ma hoa don, ma khach hang, Ten khach hang
		int dg;// don gia
		long t;
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma hoa don: ";cin.getline(this->mhd,10);
			cout<<"\tNhap ma khach hang: ";cin.getline(this->mkh,10);
			cout<<"\tNhap ten: ";cin.getline(this->ten,30);

		}
		virtual void xuat()
		{
			cout<<"Ma hoa don: "<<this->mhd<<"	Ma khach hang: "<<this->mkh
				<<"	Ten: "<<this->ten<<endl;
		}
		virtual long tien(){};
		virtual int loai_dv()=0;
		virtual bool tim()=0;
};
class GiatLa: public virtual KhachSan
{
	protected:
		float kg,dg, dvt;
	public:
		void nhap()
	 	{
	 		KhachSan::nhap();	
 			cout<<"\tNhap khoi luong quan ao(Kg): ";cin>>this->kg;
		 	cout<<"\tNhap don gia: ";cin>>this->dg;
		 	cout<<"\tNhap tien dich vu them(voi loai quan ao dac biet: vest, ao lua,..): ";cin>>this->dvt;	
 		}
 		
		 long tien()
		 {
 			if(kg>5)
		 	{
			 	return kg*dg+dvt-0.05*(kg*dg+dvt);
		 	}else
		 	{
 				return kg*dg+dvt;
 			}
 		}
		 void xuat()
 		{
		 	KhachSan::xuat();
			cout<<"Khoi luong: "<<this->kg<<"	Don gia: "<<this->dg
				<<"	Dich vu them: "<<this->dvt<<endl;
			cout<<"Tien dich vu giat la: "<<tien()<<endl;		
	 	}
		 int loai_dv()
	 	{
 			return 1;
 		}
 		bool tim()
 		{
			 if(tien()>10000000)
		 	{
	 			return true;
			}else{
				return false;
			}	
	 	}
		
};
class ThueXe:public virtual KhachSan
{
	protected:
		float gio;
	public:
	void nhap()
	 	{
	 		KhachSan::nhap();
 			cout<<"\tNhap so gio thue: ";cin>>this->gio;
 			cout<<"\tNhap don gia: ";cin>>this->dg;
 		}
 		long tien()
 		{
		 	if(gio>10)
		 	{
 				return gio*dg-0.1*(gio*dg);		
			}else{
				return gio*dg;
			}	
 		}
 		void xuat()
 		{
		 	KhachSan::xuat();
			cout<<"So gio: "<<this->gio<<"	Don gia: "<<this->dg<<endl;	
			cout<<"Tien dich vu thue xe: "<<tien()<<endl;	
	 	}	
		 int loai_dv()
	 	{
 			return 2;
 		}
		 bool tim(){};
};
void menu()
{
	cout<<"\t\t=====================MENU======================="<<endl;
	cout<<"\t\t1.Nhap hoa don."<<endl;
	cout<<"\t\t2.Nhap in don va tinh tien."<<endl;
	cout<<"\t\t3.Tong tien khach san nhan duoc."<<endl;
	cout<<"\t\t4.Dich vu giat la co tien dich vu tren 10 trieu."<<endl;
	cout<<"\t\t=====================END========================"<<endl;
}

class QuanLy
{
	
	KhachSan *a[50];
	int n;
	public:
	void nhap()
	{
		int i=0; long t=0;
		int chon;
		while(1)
		{
			cout<<"\nNhap dich vu "<<endl;
			cout<<"\nGiat la(1), Thue xe(2), Thoat(3): ";
			cin>>chon;
			if(chon==1){
				a[i]=new GiatLa();
			}	
			else if(chon==2){
				a[i]=new ThueXe();
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
		cout<<"\t\tHOA DON"<<endl;
		cout<<"\nSo dich vu da su dung: "<<n<<endl;
		for(int i=0; i<n; i++)
		{
			a[i]->xuat();
		}
		int s1=0, s2=0;
		for(int i=0; i<n; i++)
		{
			if(a[i]->loai_dv()==1) s1=s1+a[i]->tien();
			if(a[i]->loai_dv()==2) s2=s2+a[i]->tien();
		}
		cout<<"\nTong tien dich vu giat la: "<<s1<<endl;
		cout<<"\nTong tien dich vu thue xe: "<<s2<<endl;
		cout<<"\n"<<endl;	
	}
	void doanh_thu()
	{
		int s1=0, s2=0;
		for(int i=0; i<n; i++)
		{
			if(a[i]->loai_dv()==1) s1=s1+a[i]->tien();
			if(a[i]->loai_dv()==2) s2=s2+a[i]->tien();
		}
		cout<<"\nTong doanh thu: "<<s1+s2<<endl;
		cout<<"\n"<<endl;		
	}
	void timkiem()
	{
		for(int i=0; i<n; i++)
		{
			if(a[i]->tim()==true) 
			{
				a[i]->xuat();
			}
		}
	}

};
int main()
{
	QuanLy q;
	int yc;
	do{
		menu();	
		cout<<"\nNhap yeu cau: ";cin>>yc;
		if(yc==1)
		{
			q.nhap();
		}
		else if(yc==2)
		{
			q.xuat();
		}
		else if(yc==3)
		{
			q.doanh_thu();
		}else{
			q.timkiem();
			q.xuat();
		}
	}while(yc>=1 || yc<=5);
}