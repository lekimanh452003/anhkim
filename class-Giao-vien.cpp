#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class GV
{
	private:
		char ht[30]; // Ho ten
		int t; 		// tuoi
		char bc[15]; // bang cap
		char cn[20]; //Chuyen nganh
		float bl; 	//bac luong	
	public:
		GV()
		{
			strcpy(this->ht,"Nguyen Van A");
			strcpy(this->bc, "Tien si");
			strcpy(this->cn, "Sinh hoc");
			t=45;
			bl=1.2;
		}
		GV(char *ht1, int a, char *bc1, char *cn1, int b)
		{
			strcpy(this->ht, ht1);
			t=a;
			strcpy(this->bc, bc1);
			strcpy(this->cn, cn1);
			bl=b;
		}
		void nhap()
		{
			cin.ignore();
			cout<<"\tHo ten: "; cin.getline(this->ht, 30);
			cout<<"\tTuoi: "; cin>>this->t;
			cin.ignore();
			cout<<"\tBang cap: ";cin.getline(this->bc, 15);
			cout<<"\tChuyen nganh: ";cin.getline(this->cn, 20);
			cout<<"\tBac luong: "; cin>>this->bl;
		}
		void xuat()
		{
			cout<<setw(20)<<left<<this->ht;
			cout<<setw(5)<<left<<this->t;
			cout<<setw(20)<<left<<this->bc;
			cout<<setw(20)<<left<<this->cn;
			cout<<setw(5)<<left<<this->bl<<endl;
		}
		float lcb()
		{
			return bl*610;
		}
		char* sx()
		{
			return cn;
		}
};
void tieude()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(5)<<left<<"Tuoi";
	cout<<setw(20)<<left<<"Bang cap";
	cout<<setw(20)<<left<<"chuyen nganh";
	cout<<setw(5)<<left<<"Bac luong"<<endl;
}
int main()
{
	GV *gv;
	int n;
	cout<<"\nNhap so luong giao vien: ";
	cin>>n;
	gv = new GV[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nThong tin giao vien thu "<<i+1<<endl;
		gv[i].nhap();
	}
	cout<<"\nThong tin giao vien vua nhap la: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		gv[i].xuat();
	}
	cout<<"\nDanh sach giao vien co tien luong nho hon 2000 la: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{
		if(gv[i].lcb() < 2000)
		{
			gv[i].xuat();
		}
	}
	cout<<"\nDanh sach giao vien sap xep tang dan theo chuyen nganh la: "<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n-1; j++)
		{
			if(strcmp(gv[i].sx(), gv[j].sx()) > 0)
			{
				GV temp=gv[i];
				gv[i]=gv[j];
				gv[j]=temp;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		gv[i].xuat();
	}
	return 0;
}