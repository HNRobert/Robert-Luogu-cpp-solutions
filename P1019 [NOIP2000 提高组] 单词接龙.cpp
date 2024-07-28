#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

char stc;
int n,recordlen=0;
struct dragon{
	string word;
	int ustime;
}dg[21];
string connected(string a,string b){
	int lent=a.length(),alen=a.length(),blen=b.length();
	if(blen<alen) lent=blen;
	string hisa="",hisb="";
	for(int i=0;i<lent-1;i++){
		hisa=a[alen-i-1]+hisa;
		hisb+=b[i];
		if(hisa==hisb){
			for(int j=hisa.length();j<blen;j++) a+=b[j];
			return a;
		}
	}
	return "0";
}
int connect(string currents){
	int i=0;
	for(i;i<n;i++){
		if(connected(currents,dg[i].word)!="0"&&dg[i].ustime<2){
			string aftconnect=connected(currents,dg[i].word);
			dg[i].ustime++;
			connect(aftconnect);
			dg[i].ustime--;
		}
	}
	if(i==n&&currents.length()>recordlen) recordlen=currents.length(); 
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){cin>>dg[i].word;dg[i].ustime=0;}
	cin>>stc;
	for(int i=0;i<n;i++){
		if(dg[i].word[0]==stc) {dg[i].ustime++;connect(dg[i].word);dg[i].ustime--;}
	}
	cout<<recordlen;
} 
