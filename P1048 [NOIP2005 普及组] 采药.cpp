#include<iostream>
using namespace std;
int value=0,time;
/*
int A(int m,int n){
	int r=1;for(int i=0;i<n;i++)r*=m--;return r;
}
int C(int m,int n){
	return A(m,n)/A(n,n);
}
*/
void swapd(int **a,int i,int j){ //������������Ԫ��λ��
    int temp[2];
	for(int l=0;l<2;l++) temp[l]=a[i][l];
    for(int l=0;l<2;l++) a[i][l]=a[j][l];
    for(int l=0;l<2;l++) a[j][l]=temp[l];
}
void perm(int **a,int p,int q){//ȫ�ź�������������a���±�p���±�q��Ԫ�ؽ���ȫ����
	if(p==q){//��ֹ����������һ��Ԫ�ؽ���ȫ��ʱ��ӡ���
		//for(int i=0;i<q;i++)cout<<a[i][0]<<' '<<a[i][1]<<' ';cout<<endl;
		int sum=0,tm=time;
		for(int j=0;j<q&&tm>=a[j][0];j++) {sum+=a[j][1];tm-=a[j][0];}
		if(sum>value) value=sum;
    }else{//ȫ���к��Ĵ���
    	for(int i=p;i<q;i++){//����ȫ���з�Χ��ÿ��Ԫ��
			swapd(a,i,p);//ʹ�õ�һ��Ԫ�أ��±�Ϊp���ֱ�������е�ÿ��Ԫ�ؽ���λ�û���
         	perm(a,p+1,q);//����һ���Ļ����ϣ�������Ԫ�ؽ���ȫ���У����Ĵ�����Ҫ��⣩
         	swapd(a,i,p);//���ݹ��̣�����20���������е�Ԫ�طֱ����±�Ϊp�ĵ�Ԫ�ؽ�����λ�ã�����Ҫ��λ��
        }
    }
}
/*
int change(int **a, int cb[][2], int &k, int &n, int bit=0, int index=0){
	//a: all items; cb: all changes; k:nums to pick; n:total number;
	int sum,tm=time; //k����֮��
	for(int i=index;i<n;i++){
		for(int g=0;g<2;g++) cb[bit][g]=a[i][g]; //cb[bit]������index(=bit)��n-1��������
		if(bit<k-1) change(a,cb,k,n,bit+1,i+1); //����ִ����һbit��������һִ�е�indexҪ����i
		if(bit==k-1){ //�������ȫk����ʱ�����м���
			sum=0;cout<<'g'<<endl;
			for(int j=0;j<k&&tm>cb[j][0];j++) {sum+=cb[j][1];tm-=cb[j][0];}
			if(sum>value) value=sum;
		}
	}
}
*/
int main(){
	int m;cin>>time>>m;
	int **c= new int*[m];
	for(int i=0;i<m;i++) c[i]=new int[2];
	for(int i=0;i<m;i++) cin>>c[i][0]>>c[i][1];
	perm(c,0,m);
	cout<<value;
	for(int i=0;i<m;i++) delete[] c[i];
	delete[] c;
	return 0;
}
