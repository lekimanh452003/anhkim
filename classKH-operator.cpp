#include <iostream.h>
#include <iomanip.h>
#include <string.h>
struct NS
{
	int dd, mm, yyyy; // Ngay, thang, nam	
};
class KH
{
	private:
		char ht[30];
		NS ns;
		char cmt[10];
		char k[50];
	public:
		friend istream& operator >> (istream &is, KH &kh)
		{
			fflush(stdin);
			cout<<"\tNhap ho ten: ";
		 	cin.getline(kh.ht, 30);
			cout<<"\tNhap ngay/ thang/ nam sinh: "; 
			cin>>kh.ns.dd>>kh.ns.mm>>kh.ns.yyyy;
			fflush(stdin);
			cout<<"\tNhap chung minh thu: ";
			cin.getline(kh.cmt, 10);
			cout<<"\tNhap ho khau: ";
			cin.getline(kh.k, 50);
		}	
		friend ostream& operator << (ostream &os, KH &kh)
		{
			cout<<setw(20)<<left<<kh.ht;
			cout<<setw(15)<<right<<kh.ns.dd<<"/"<<kh.ns.mm<<"/"<<kh.ns.yyyy;
			cout<<setw(15)<<right<<kh.cmt;
			cout<<setw(20)<<right<<kh.k<<endl;
		}
		friend bool operator > (KH &kh1, KH &kh2)
		{
			return (kh1.ns.yyyy > kh2.ns.yyyy);
		}
		bool hokhau()
		{
			return (strcmp(this->k, "Ha Noi")==0);
		}
};
void tieude()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(20)<<right<<"Ngay sinh";
	cout<<setw(15)<<right<<"CMT";
	cout<<setw(20)<<right<<"Ho khau"<<endl;
}
int main()
{
	KH *kh;
	int n;
	cout<<"\nNhap so luong khach hang: ";
	cin>>n;
	kh = new KH[n];
	cout<<"\nNhap thong tin khach hang: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\nNhap thong tin khach hang thu "<<i+1<<endl;
		cin>>kh[i];
	}
	KH kh1;
	cout<<"\nXuat thong tin khach hang: "<<endl;
	tieude();
	for(int i=0; i< n; i++)
	{
		cout<<kh[i];
	}
	
	cout<<"\nXuat thong tin khach hang co dia chi Ha Noi: "<<endl;
	tieude();
	for(int i=0; i< n; i++)
	{
		if(kh[i].hokhau())
		{
			cout<<kh[i];
		}
	}
	cout<<"\nXuat thong tin khach hang theo thu tu giam dan cua tuoi: "<<endl;
	for(int i=0; i< n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(operator >(kh[i],kh[j]))
			{
				KH temp =kh[i];
				kh[i]=kh[j];
				kh[j]= temp;
			}		
		}
	}
	tieude();
	for(int i=0; i< n; i++)
	{
		cout<<kh[i];
	}
	return 0;
}