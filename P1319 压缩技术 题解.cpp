#include <iostream>//c++��׼��
using namespace std;
int main(){
	int a,n,t=0,i=0,b,s=0;//t�ж���û�лس���i�ж����ʲô��s�ж���û������
	cin>>n;
	while(s<n*n){
		cin>>a;//ѭ������a��
		i++;
		for(b=a;b>=1;b--){
			if(t==n){cout<<endl;t=0;}//�ж��Ƿ���Ҫ�س����س���tҪ����
			if(i%2==1)cout<<0;
            else cout<<1;//�ж��Ƿ�i����2���������0���������1��ע�ⲻҪ�س�
			t++;
			s++;//t��s��һ
			}
		}
	cout<<endl;
	return 0;
}
