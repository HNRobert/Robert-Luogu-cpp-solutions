#include<iostream>
#include<cmath>
using namespace std;

void change(int a[], int cb[], int &k, int &n, int bit=0, int index=0) {
/*
 *����˵����
  ����a[]��������������
  ����cb[]��cb��ʾ����ϡ������а���k������������a[]��ѡȡ3�������±��С��������
  bit��λ��k������k��λ�ã�Ҳ������cb[]���±꡾��������k��������ϡ�
  index��ָ�꣬��������cb[]�ڵ�����Ӧ��a[]���±��Ǵ�С�������еģ�index��cb[]�е�x�����ķ�ΧΪindex~n-1
  �����ȿ��·���ͼ
  
  k��n����k��n
*/
	int sum; //k����֮��
	for(int i=index;i<n;i++) {
		cb[bit]=a[i]; //cb[bit]������index(=bit)��n-1��������
		if(bit<k-1)
			change(a,cb,k,n,bit+1,i+1); //����ִ����һbit��������һִ�е�indexҪ����i
		if(bit==k-1) { //�������ȫk����ʱ�����м���
			sum=0;
			for(int j=0;j<k;j++)
				cout<<cb[j]<<" "; //������ 
			cout<<endl;
		}
	}
	
}
int main()
{
	int n,k;cin>>n>>k;
	int a[20+5],cb[20+5]={};
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<endl;
	change(a,cb,k,n);
	return 0;
} 
