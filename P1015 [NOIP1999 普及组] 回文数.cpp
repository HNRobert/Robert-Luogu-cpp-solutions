#include<iostream>
#include<cstring>
using namespace std;
string circleplus(string x,int p){
	string y="";
	for(int i=x.length()-1;i>=0;i--) y+=x[i];
    const int lenx=x.length()+1;
    int a[lenx],b[lenx];
	memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
	for(int j=0;j<lenx-1;j++) if('0'<=x[j]&&x[j]<='9') a[lenx-j-2]=x[j]-'0'; else a[lenx-j-2]=x[j]-'A'+10;      //����x����a����
	for(int j=0;j<lenx-1;j++) if('0'<=y[j]&&y[j]<='9') b[lenx-j-2]=y[j]-'0'; else b[lenx-j-2]=y[j]-'A'+10;      //����y����b����
	int c[lenx],m=0;memset(c,0,sizeof(c));
    for(int i=0;i<lenx;i++){
		c[i]=a[i]+b[i]+m;    	//��iλ��Ӳ����ϴεĽ�λ
		m=c[i]/p;	             //���λ��λ
		c[i]%=p;                      //�洢��iλ��ֵ
	}
	string z="";
	int i=lenx-1;
	for(i;i>=0;i--) if(c[i]) break;
	for(i;i>=0;i--) if(c[i]<10) z+=(char)(c[i]+'0');else z+=(char)(c[i]+'A'-10);
	return z;
}
int iscircle(string num){
	string fnum="";
	for(int i=num.length()-1;i>=0;i--) fnum+=num[i];
	return fnum==num;
}
int main(){
	int p,step=0;cin>>p;
	string num;cin>>num;
	while(step<=30&&!iscircle(num)){
		step++;
		num=circleplus(num,p);
	}
	if(step<=30) cout<<"STEP="<<step;
	else cout<<"Impossible!";
	return 0;
} 
