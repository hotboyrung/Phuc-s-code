#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
void khoitao(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	cout<<"\n";
}
int vitri(int a[],int n,int value,int start)
{
	int min =1000,k=start;
	for(int i=start;i<n;i++)
	{
		if(a[i]-value<min&&a[i]-value>0)
		{
			min=a[i]-value;
			k=i;
		}
	}
	return k;
}
void spawn(int a[],int n)
{
	print(a,n);
	int i=n-1,k,dem=0;
	while(i>=2)
	{
		if(a[i-1]> a[i])
		{
			i--;
		}
		if(a[i-1]<a[i])
		{
			sort(a+i,a+n);
			k=vitri(a,n,a[i-1],i);	
			swap(a[k],a[i-1]);
			print(a,n);
			i=n-1;
			dem++;
		}
		
	}
	cout<<dem+1;
}
int main() 
{
	int n;
	cin >> n;
	khoitao(a,n);
	spawn(a,n);
		return 0;
}
