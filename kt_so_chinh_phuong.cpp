#include <iostream.h>
#include <math.h>
bool kt_SCP(int n)//la so nguyen duong co can bac 2 la 1 so nguyen
{
	int a=sqrt(n);
	if(a*a==n)
	{
		return true;
	}else{
		return false;
	}
}
int main()
{
	int n;
	cout<<"\nn= ";cin>>n;
	kt_SCP(n);
	if(kt_SCP(n)==true)
	{
		cout<<"\nLa so chinh phuong."<<endl;
	}else{
		cout<<"\nko phai so chinh phuong"<<endl;
	}
	return 0;
}
