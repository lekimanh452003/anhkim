#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class STUDENT
{
	private:
		char ma[10]; //Ma sinh vien
		char ht[30]; //Ho ten	
		char gt[4]; // Gioi tinh
	public:
		STUDENT(){
			
		}
		STUDENT(char *ma, char *ht, char *gt)
		{
			strcpy(this->ma,ma);
			strcpy(this->ht,ht);
			strcpy(this->gt, gt);
		}
		friend istream& operator >>(istream& is, STUDENT &a)
		{
			fflush(stdin);
			cout<<"\tNhap ma sinh vien: "; is.getline(a.ma, 10);
			cout<<"\tNhap ho ten sinh vien: "; is.getline(a.ht, 30);
			cout<<"\tNhap gioi tinh: "; is.getline(a.gt, 4);
			return is;
		}
		friend ostream& operator <<(ostream &os, STUDENT &a)
		{
			cout<<setw(20)<<right<<a.ma;
			cout<<setw(20)<<right<<a.ht;
			cout<<setw(20)<<right<<a.gt;
			return os;
		}
		~STUDENT(){};
		bool get_GT()
		{
			if(strcmp(gt, "nam")==0)
			{
				return true;
			}else{
				return false;
			}
		}
		char* get_ht()
		{
			return ht;
		}
};
class MONHOC
{
	private:
		char m[10];
		char ten[30];
	public:
		MONHOC(){
			
		}
		MONHOC(char *m, char *ten)
		{
			strcpy(this->m, "");
			strcpy(this->ten, "");
		}	
		~MONHOC(){};
		friend istream& operator >> (istream &is, MONHOC &a)
		{
			cout<<"\tNhap ma mon hoc: "; is.getline(a.m, 10);
			cout<<"\tNhap ten mon hoc: "; is.getline(a.ten, 30);
			return is;
		}
		friend ostream& operator << (ostream &os, MONHOC &a)
		{
			cout<<setw(20)<<right<<a.m;
			cout<<setw(20)<<right<<a.ten;
			return os;
		}
		char* get_ten_mh()
		{
			return ten;
		}
};
class DIEMMH :  public STUDENT, public MONHOC
{
	private:
		float dt;
	public:
		DIEMMH(){
			
		}
		DIEMMH(char *ma, char *ht, char *gt,char *m, char *ten, float dt)
		:STUDENT(ma, ht, gt),MONHOC(m, ten)
		{
			this->dt=dt;
		}
		friend istream& operator >>(istream &is, DIEMMH &a)
		{
			is>>(STUDENT&)a;
			is>>(MONHOC&)a;
			cout<<"\tNhap diem thi: ";is>>a.dt;
			return is;
		}
		friend ostream& operator << (ostream &os, DIEMMH &a)
		{
			os<<(STUDENT&)a;
			os<<(MONHOC&)a;
			cout<<setw(20)<<a.dt;
			return os;
		}
		float get_dt()
		{
			return dt;
		}
		friend bool operator < (DIEMMH &a1, DIEMMH &a2)
		{
			return (a1.dt < a2.dt);
		}
		friend float tong_diem(DIEMMH a[], int n);
		friend float tim_diem_toan_min(DIEMMH a[], int n); 
			
};
float tong_diem(DIEMMH a[], int n)
{
	float s=0;
	for(int i=0; i<n; i++)
	{
		s=s+a[i].dt;
	}
	return s;
}
void tim_sv(DIEMMH a[], int n)
{
	char x[30];
	fflush(stdin);
	cout<<"\nNhap sinh vien X can tim: "; cin.getline(x,30);
	for(int i=0; i<n; i++)
	{
		if(strcmp(x,a[i].get_ht())==0)
		{
			cout<<a[i];
		}
	}
}

float tim_diem_toan_min(DIEMMH a[], int n)
{
	
	for(int i=0; i<n; i++)
	{
		if(strcmp(a[i].get_ten_mh(), "Toan")==0)
			{
				float min=a[0].dt;
				for(int j=0; j<n; j++)
				{
					
					if(a[j].dt < min)
					{
						min=a[j].dt;
					}
					
				}
				cout<< min;
				break;
			}
	}
}
void sap_xep(DIEMMH a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(operator<(a[i],a[j]))
			{
				DIEMMH temp=a[i];
					a[i]=a[j];
					a[j]=temp;
			}
		}
	}
}
int main()
{
	STUDENT st;
	cout<<"\nNhap thong tin 1 sinh vien: "<<endl;
	cin>>st;
	cout<<"\nThong tin sinh vien: "<<endl;
	cout<<st;
	DIEMMH *a;
	int n;
	cout<<"\nNhap so luong sinh vien: "<<endl;
	cin>>n;
	a = new DIEMMH[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap sinh vien thu "<< i+1<<endl;
		cin>>a[i];
	}
	for(int i=0; i<n; i++)
	{
		cout<<a[i];
	}
	cout<<"\nSinh vien co gioi tinh la nam trong danh sach: "<<endl;	
	for(int i=0; i<n; i++)
	{
		if(a[i].get_GT()==true)
		{
			cout<<a[i];
		}
	}
	cout<<"\nDiem trung binh cac mon hoc cua danh sach diem: "<<tong_diem(a,n)/n<<endl;
	cout<<"\nTim sinh vien X. "<<endl;
	tim_sv(a,n);
	cout<<"\nTim diem toan nho nhat. "<<endl;
	tim_diem_toan_min(a,n);
	cout<<"\nSap xep theo chieu giam dan cua diem thi: "<<endl;
	sap_xep(a, n);
	for(int i=0; i<n; i++)
	{
		cout<<a[i];
	}
	
	return 0;
}