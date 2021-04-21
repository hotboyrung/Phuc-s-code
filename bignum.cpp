#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
#define modd 1000000007
using namespace std;
void chuanhoa(string &a,string &b)
{
	while(a.length()>b.length())
	{
		b="0"+b;	
	}
	while(a.length()<b.length())
	{
		a="0"+a;	
	}
}
int ss(string a,string b)
{
	for(int i=0;i<a.length();i++)
	{
		if(b[i]>a[i])
		{
			return -1;
		}
		else 
		{
			if(b[i]<a[i]) return 1;
		}
	}
	return 0;
}
string hieu(string a,string b)
{
	string res="";
	int check=0;
	chuanhoa(a,b);
	if(ss(a,b)==0) 
	{
		res="0"; return res;
	}
	else
	{
		if(ss(a,b)==-1) 
		{
			swap(a,b);
			check=1;
		}
	}
	while(res.length()!=a.length())
	{
		res+="0";
	}
	int k=0;
	for(int i=res.length()-1;i>=0;i--)
	{
		int tam=10+(a[i]-48)-(b[i]-48);
		if(k==1)
		{
			tam--; k=0;
		}
		if(tam<10)
		{
			k=1;
		}
		res[i]=(tam%10)+48;
	}
	while(res[0]=='0')
	{
		res.erase(res.begin());
	}
	if(check==1)
	{
		return "-"+res;
	}
	else return res;
}
string tong(string a,string b)
{
	chuanhoa(a,b);
	string res=""; //res=0a
	while(res.length()!=a.length())
	{
		res+="0";
	}
	int k=0;
	for(int i=res.length()-1;i>=0;i--)
	{
		int tam=a[i]+b[i]-96;
		if(k==1) //co nho
		{
			k=0;
			tam++;
		}
		if(tam>=10) 
		{
			k=1;
			tam=tam-10;
		}
		res[i]=tam+48;
	}
	if(k==1) return	"1"+res;
	else return res;
}
string tichnho(string a,int b)
{
	int k=0;
	string res="";
	while(res.length()<a.length())
	{
		res+="0";
	}
	for(int i=res.length()-1;i>=0;i--)
	{
		int tam=(a[i]-48)*b+k;
		k=tam/10;
		res[i]=tam%10+48;
	}
	if(k!=0)
	{
		int tam=k+48;
		return char(tam)+res;
	}
	else return res;
}
string tich(string a,string b)
{
	string res="";
	if(a=="0"||b=="0") return "0";
	chuanhoa(a,b);
	while(res.length()<2*max(a.length(),b.length()))
	{
		res+="0";
	}
	string tam;
	for(int i=b.length()-1;i>=0;i--)
	{
		tam=tichnho(a,b[i]-48);
		int k=b.length()-i-1;
		while(k--)
		{
			tam=tam+"0";
		}
		res=tong(res,tam);
	}
	while(res[0]=='0')
	{
		res.erase(res.begin());
	}
	return res;
}
int main() 
{
	string a,b;
	cin>>a>>b;
	cout<<tong(a,b)<<"\n"<<hieu(a,b)<<"\n"<<tich(a,b);
//	cout<<tichnho(a,9);
	return 0;
} 
