#include <iostream.h>
void nhapmang(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"\nPhan tu thu "<<i+1<<endl;
		cin>>a[i];
	}
}
void xuatmang(int a[], int n)
{
	cout<<"\nXuat mang: ";
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<"	";
	}
}

void SelectionSort(int a[], int n)//SX tang dan
{
	int min;
	for(int i=0; i<n-1; i++)
	{
		min=i;
		for(int j=i+1; j<n; j++)
		{
			if(a[i]>a[j])//Sx giam dan thay dau
			{
				int temp =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void BubbleSort(int a[], int n)//SX tang dan
 {
		for(int i = 0; i < n-1; i++)
		{
			for(int j = n-1; j >i; j--)//Sx giam dan thay dau
			{
				if (a[j] < a[j-1])//S
					{
					int temp =a[j];
						a[j]=a[j-1];
						a[j-1]=temp;	
					}		
			}
					
		}
			
}
void InsertionSort(int a[], int n)
 {
	 int pos, i, x; //x luu phan tu a[i]
	 for(i=1; i < n; i++)
	 { 
			 x = a[i]; 
			 pos = i-1;				
			 while ((pos >= 0) && (a[pos] > x))
								  //Sx giam dan thay dau 
				 { //doi cho cac phan tu dung sau x
					a[pos+1] = a[pos];
				 	pos=pos-1;
				 }
			 a[pos+1] = x; //chen x vao day moi
	 }
}
void swap(int* x, int* y) 
{ 
    int t = *x; 
    *x = *y; 
    *y = t; 
} 
int partition (int a[], int low, int high) 
{ //low: chi so bat dau; hight la chi so ket thuc
    int p = a[high];    // khai bao phan tu danh dau pivot 
    int i = (low - 1);  // khoi tao chi muc cua phan tu nho hon
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (a[j] < p) //SX giam dan thi thay dau
        { 
            i++;   
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[high]); 
    return (i + 1); 
} 

void QuickSort(int a[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* index la vi tri ma noi phan tu chia thanh 2 mang con trai & phai */
        int index = partition(a, low, high); 
  		//Goi de quy sap xep 2 mang con trai, phai
        QuickSort(a, low, index - 1); 
        QuickSort(a, index + 1, high); 
    } 
} 
int main()
{
	int n;
	cout<<"\nNhap so luong phan tu: ";cin>>n;
	int a[n];
	nhapmang(a,n);
	xuatmang(a,n);
	cout<<"\nSelection Sort sap xep tang dan: ";
	SelectionSort(a,n);
	xuatmang(a,n);
	cout<<"\nPubble Sort sap xep tang dan: ";
	BubbleSort(a,n);
	xuatmang(a,n);
	cout<<"\nInsertion Sort sap xep tang dan: ";
	InsertionSort(a,n);
	xuatmang(a,n);
	int left, right;
	cout<<"\nQuick Sort sap xep tang dan: ";
	QuickSort(a,0,n-1);
	xuatmang(a,n);
	return 0;
}