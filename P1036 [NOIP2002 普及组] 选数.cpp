#include<iostream>
using namespace std;
int count=0; 
bool is_prime(int n) 
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}
int change(int a[], int cb[], int &k, int &n, int bit=0, int index=0) {
	int sum; //k����֮��
	for(int i=index;i<n;i++) {
		cb[bit]=a[i]; //cb[bit]������index(=bit)��n-1��������
		if(bit<k-1)
			change(a,cb,k,n,bit+1,i+1); //����ִ����һbit��������һִ�е�indexҪ����i
		if(bit==k-1) { //�������ȫk����ʱ�����м���
			sum=0;
			for(int j=0;j<k;j++)
				cout<<cb[j]<<' ';cout<<endl; //������
			if(is_prime(sum)) count++;
		}
	}
}
int main()
{
	int n=0,k;cin>>n>>k;
	int a[25],cb[25]={0};
	for(int i=0;i<n;i++)cin>>a[i];
	change(a,cb,k,n);
	cout<<count;
} 
