#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int b[1000]={},num=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			b[num]=a[i];num++;
		}
	}
	cout<<num<<endl;
	for(int i=0;i<num;i++) cout<<b[i]<<" ";
	return 0;
} 
