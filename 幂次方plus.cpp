#include<bits/stdc++.h>
using namespace std;
string run(int x,int i=0,string s=string("")){
	if(x==0)return string("0");
	do
	{
		if(x&1)
		{
			s=(i==1?"2":"2("+run(i)+")")+(s==""?"":"+")+s;//ƴ���ַ�����Ӧ���⣬Ҫ�ѵʹη����ں���
		} 
	} 
	while(++i,x>>=1);//ÿ��������λ
	return s;
}
int main(){
	int x;cin>>x;
	cout<<run(x)<<endl;
}
