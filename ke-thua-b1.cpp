#include <iostream.h>
#include <string.h>
#include <iomanip.h>
class Nguoi
{
	private:
		char ht[30];// ho ten
		int ns;	//nam sinh
	public:
		Nguoi(char *ht="", int ns=0)
		{
			strcpy(this->ht, ht);
			this->ns=ns;
		}
		void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ho ten: ";
			cin.getline(this->ht, 30);
			cout<<"\tNhap nam sinh: ";
			cin>>this->ns;
		}
		void xuat()
		{
			cout<<setw(15)<<left<<this->ht;
			cout<<setw(15)<<left<<this->ns;
		}
};
class ThiSinh : public Nguoi
{
	private:
		int sbd; //So bao danh
		float t, l, h; //Diem cac mon toan, ly, hoa
	public:
		ThiSinh(char *ht="", int ns=0, int sbd=0, float t=0, float l=0, float h=0)
		: Nguoi(ht,ns)
		{
			this->sbd=sbd;
			this->t=t;
			this->l=l;
			this->h=h;
		}	
		void nhap()
		{
			Nguoi::nhap();
			cout<<"\tNhap SBD: ";
			cin>>this->sbd;
			cout<<"\tNhap diem Toan: ";
			cin>>this->t;
			cout<<"\tNhap diem Ly: ";
			cin>>this->l;
			cout<<"\tNhap diem hoa: ";
			cin>>this->h;
			
		}
		
		void xuat()
		{
			Nguoi::xuat();
			cout<<setw(15)<<left<<this->sbd;
			cout<<setw(15)<<left<<this->t;
			cout<<setw(15)<<left<<this->l;
			cout<<setw(15)<<left<<this->h<<endl;
		}
		float tongdiem()
		{
			return (float)t+l+h;
		}
		
		friend float sap_xep(ThiSinh a[], int n);
		friend bool tim_ts(ThiSinh a[], int n);
		friend float thong_ke(ThiSinh a[], int n);
};
float sap_xep(ThiSinh a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(a[i].tongdiem()>a[j].tongdiem())
			{
				ThiSinh temp =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void tieude()
{
	cout<<setw(15)<<left<<"Ho ten";
	cout<<setw(15)<<left<<"Nam sinh";
	cout<<setw(15)<<left<<"SBD";
	cout<<setw(15)<<left<<"Toan";
	cout<<setw(15)<<left<<"Ly";
	cout<<setw(15)<<left<<"Hoa"<<endl;	
}
bool tim_ts(ThiSinh a[], int n)
{
	int x;
	cout<<"\nNhap SBD cua thi sinh can tim: ";
	cin>>x;
	tieude();
	for(int i=0; i<n; i++)
	{
		if(a[i].sbd==x)
		{
			a[i].xuat();
		}
	}
}
float thong_ke(ThiSinh a[], int n)
{
	int dem=0;
	do{
		for(int i=0; i<n; i++)
		{
			if(a[i].t>=5 && a[i].l>=5 && a[i].h>=5)
			{
				dem++;
			}
		}
	return dem;
	}while(dem<n);
}
int main()
{
	ThiSinh *a;
	int n;
	cout<<"\nNhap so luong thi sinh: ";
	cin>>n;
	a = new ThiSinh[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap thi sinh thu "<<i+1<<endl;
		a[i].nhap();
	}
	cout<<"\nDanh sach thi sinh co tong diem 3 mon tang dan: "<<endl;
	tieude();
	sap_xep(a, n);
	for(int i=0; i<n; i++)
	{
		a[i].xuat();
	}
	tim_ts(a, n);
	
	cout<<"\nPhan tram thi sinh dat yeu cau: "<<(thong_ke(a, n)/n)*100<<"%"<<endl;
	return 0;
}