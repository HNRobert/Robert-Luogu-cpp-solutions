#include<iostream>
#include<algorithm>
using namespace std;
int harvest[30],price[30],f[50000];//w����Ϊ��Ҫ�ȣ�v����Ϊmoney��f������dp������
int n,money;//n������Ʒ������m����Ǯ��
int main(){
    cin>>money>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>price[i]>>harvest[i];
        harvest[i]*=price[i];
    }
    for(int i=1;i<=n;i++) for(int j=money;j>=price[i];j--){
        if(j>=price[i]){
            f[j]=max(f[j],f[j-price[i]]+harvest[i]);//dp
        }
    }
    cout<<f[money]<<endl;//������СΪmʱ���ֵ
    return 0;
} 
