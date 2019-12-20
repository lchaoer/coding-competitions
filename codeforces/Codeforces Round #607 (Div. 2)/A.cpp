#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#include<vector>
#include<queue> 
#define ll long long
#define mod 1000000007
using namespace std;
int gcd(int a,int b){ 
	if(b==0) return a;
	return gcd(b,a%b);
}



const int maxn=100000+5;
int n;


int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		n=s.length();
		if(s.substr(n-2)=="po"){
			cout<<"FILIPINO"<<endl;
		}
		else if(s.substr(n-4)=="desu"||s.substr(n-4)=="masu"){
			cout<<"JAPANESE"<<endl;
		}
		else{
			cout<<"KOREAN"<<endl;
		}
	}
	return 0;
} 
