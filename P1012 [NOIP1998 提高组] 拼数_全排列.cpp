#include<iostream>
using namespace std;
void swapd(string a[], int i, int j){
	string temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void perm(string a[], int p, int q, string &max){
	if(p==q){
		string now="";
		for(int k=0;k<q;k++) now+=a[k];
		if(now>=max) max=now;
	}else{
		for(int i=p;i<q;i++){//����ȫ���з�Χ��ÿ��Ԫ��
			swapd(a,i,p);//ʹ�õ�һ��Ԫ�أ��±�Ϊp���ֱ�������е�ÿ��Ԫ�ؽ���λ�û���
         	perm(a,p+1,q,max);//����һ���Ļ����ϣ�������Ԫ�ؽ���ȫ���У����Ĵ�����Ҫ��⣩
         	swapd(a,i,p);//���ݹ��̣�����20���������е�Ԫ�طֱ����±�Ϊp�ĵ�Ԫ�ؽ�����λ�ã�����Ҫ��λ��
        }
	}
}
int main(){
	int num;cin>>num;
	const int n=num;
	string a[n],max="0";
	for(int i=0;i<n;i++) cin>>a[i];
	perm(a,0,n,max);
	cout<<max;
} 
