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
		char ma[10];//Ma khach hang
		char ht[30];//Ho ten
		NgayThang nt;//Ngay ra hoa don
		int sl;//So luong
		double dg;//don gia
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma khach hang: ";cin.getline(this->ma, 10);
			cout<<"\tNhap ho ten: ";cin.getline(this->ht,30);
			cout<<"\tNhap ngay/thang/nam: ";cin>>this->nt.dd>>this->nt.mm>>this->nt.yy;
			fflush(stdin);
			cout<<"\tNhap so luong: ";cin>>this->sl;
			cout<<"\tNhap don gia: ";cin>>this->dg;
		}
		virtual void xuat()
		{
			cout<<"\t\t\tHOA DON"<<endl;
			cout<<"	Ma Khach hang: "<<this->ma;
			cout<<"		Ten: "<<this->ht;
			cout<<"		Ngay: "<<this->nt.dd<<"/"<<this->nt.mm<<"/"<<this->nt.yy<<endl;
			cout<<" 	So luong (KW): "<<this->sl;
			cout<<"		Don gia: "<<this->dg<<endl;
			
		}	
		virtual long double tien(){};
		virtual int loai_hd()=0;
		virtual int get_ng(){};
};

class HDVN:public HD
{
	protected:
		char dt[15];//Doi tuong khach hang
		int dm;//Dinh muc
		
	public:
		void nhap()
		{
			HD::nhap();
			fflush(stdin);
			cout<<"\tNhap doi tuong(Sinh hoat, Kinh doanh, San xuat): ";cin.getline(this->dt,15);
			cout<<"\tNhap dinh muc: ";cin>>this->dm;
		}
		long double tien()
		{
			if(sl<=dm){
				return sl*dg;
			}else{
				return sl*dg*dm+dg*2.5*(sl-dm);
			}
		}
		void xuat()
		{
			HD::xuat();
			cout<<"	Doi tuong: "<<this->dt;
			cout<<"		Dinh muc: "<<this->dm;
			cout<<"		Thanh tien: "<<tien()<<endl;
			cout<<"\n___________________________________________________________________________"<<endl;
		}
		int loai_hd()
		{
			return 1;
		}
		int get_ng()
		{
			if(nt.mm==9 && nt.yy==2013)
			{
				return true;
			}else{
				return false;
			}
		}
	
};
class HDNN: public HD
{
	protected: 
		char qt[30];//Quoc tich
	public:
		void nhap()
		{
			HD::nhap();
			fflush(stdin);
			cout<<"\tNhap quoc tich: ";cin.getline(this->qt,30);
		}
		long double tien()
		{
			return sl*dg;
		}
		void xuat()
		{
			HD::xuat();
			cout<<"	Quoc tich: "<<this->qt;
			cout<<"		Thanh tien: "<<tien()<<endl;
			cout<<"\n___________________________________________________________________________"<<endl;
		}
		int loai_hd()
		{
			return 2;
		}
		int get_ng()
		{
			if(nt.mm==9 && nt.yy==2013)
			{
				return true;
			}else{
				return false;
			}
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
				cout<<"\nSTT: "<<i+1<<endl;
				cout<<"\nKhach hang Viet Nam(1), Khach hang nuoc ngoai(2), Thoat(3): ";cin>>chon;
				if(chon==1) a[i]=new HDVN();
				else if(chon==2) a[i]=new HDNN();
				else break;
				a[i]->nhap();
				i++;
			}
			n=i;
		
		}
		void xuat()
		{
			cout<<"\nSo luong hoa don: "<<n<<endl;
			cout<<"\nDanh sach tat ca hoa don: "<<endl;
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
			cout<<"\nSo luong hoa don khach Viet Nam: "<<d1<<endl;
			cout<<"\nSo luong hoa don khach nuoc ngoai: "<<d2<<endl;
		}
		
		long double tb_tien()
		{
			long double s1=0;
			int d1=0;
			for(int i=0; i<n; i++)
			{
				if(a[i]->loai_hd()==2) 
				{
					s1=s1+a[i]->tien();
					d1++;
				}	
			}
			cout<<"TB thanh tien cua khach nuoc ngoai: "<<s1/d1<<endl;;
		}
		void tim()
		{
			cout<<"\nGiao dich cua thang 9/2013: "<<endl;
			for(int i=0; i<n; i++)
			{
				if(a[i]->get_ng()==true){
					a[i]->xuat();
				}
			}
		}
};
void menu()
{
	cout << "MENU" << endl;
    cout << "Hay chon menu sau:" << endl;
    cout << "1: Nhap danh sach hoa don" << endl;
    cout << "2: Xuat danh sach hoa don" << endl;
    cout << "3: Tinh TB thanh tien cua khach nuoc ngoai" << endl;
    cout << "4: Tim giao dich cua thang 9/2013" << endl;
    cout << "0: Thoat khoi chuong trinh" << endl;
}
int main()
{
	QuanLy q;
    int control;
 	do{
 		menu();
 		cout<<"\nNhap yeu cau: ";cin>>control;
	  switch (control){
        case 1:
            q.nhap();
            break;
        case 2:
            	q.xuat();
            break;
        case 3:
            q.tb_tien();
            break;
        case 4:
            q.tim();
            break;
        default :
            cout<<"\nKet thuc. "<<endl;	
            break;
    	}
		
	 }while(control>=1 || control<=4);
	return 0;
}