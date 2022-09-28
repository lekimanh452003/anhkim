#include <iostream.h>
#include <iomanip.h>
#include <string.h>
struct ngaysinh
{
	int dd, mm, yyyy;
};
class KH
{
	private:
	char ht[30];
	char cmt[10];
	char k[50];
	ngaysinh ns;
	public:
	KH()
	{
		strcpy(this->ht,"Nguyen Van A");
		strcpy(this->cmt,"12345678");
		strcpy(this->k,"to 1");
		ns.dd=4;
		ns.mm=5;
		ns.yyyy=2001;
	}
	KH(char *ht1, char *cmt1,char *k1, int a, int b, int c)
	{
		strcpy(this->ht,ht1);
		strcpy(this->cmt,cmt1);
		strcpy(this->k,k1);
		ns.dd=a;
		ns.mm=b;
		ns.yyyy=c;
	}
	void nhap()
	{
		cin.ignore();
		cout<<"\nHo ten: ";cin.getline(this->ht,30);
		cout<<"\nChung minh thu: ";cin.getline(this->cmt,10);
		cout<<"\nHo khau: ";cin.getline(this->k,50);
		cout<<"\nNgay sinh: ";cin>>this->ns.dd;
		cout<<"\nThang sinh: ";cin>>this->ns.mm;
		cout<<"\nNam sinh: ";cin>>this->ns.yyyy;
	}
	void xuat()
	{
		cout<<setw(20)<<left<<this->ht;
		cout<<setw(20)<<left<<this->cmt;
		cout<<setw(20)<<left<<this->k;
		cout<<setw(5)<<right<<this->ns.dd<<"/"<<this->ns.mm<<"/"<<this->ns.yyyy<<endl;
		
	}
	bool th12()
	{
		if(ns.mm==12)
			return true;
		else
			return false;
	}
	char* sx()
	{
		return ht;
	}

};
void tieude()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(20)<<left<<"Chung minh thu";
	cout<<setw(20)<<left<<"Ho khau";
	cout<<setw(20)<<right<<"Ngay/thang/nam sinh"<<endl;
}
int main()
{
	KH *kh;
	int n;
	cout<<"\nNhap so luong khach hang: ";
	cin>>n;
	kh = new KH[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nThong tin khach hang thu "<< i+1<<endl;
		kh[i].nhap();
	}
	
	cout<<"\nThong tin khach hang vua nhap la: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		kh[i].xuat();
	}
	
	
	cout<<"\nThong tin khach hang sinh thang 12 la: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	if(kh[i].th12()==true)
	{
		kh[i].xuat();
	}
	
	cout<<"\nThong tin khach hang sap xep tang dan theo ho ten: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(strcmp(kh[i].sx(), kh[j].sx()) > 0)
			{
				KH temp=kh[i];
				kh[i]=kh[j];
				kh[j]=temp;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		kh[i].xuat();
	}
	return 0;
}