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
int x;
string s;


void solve(){
	ll len=s.length();
	for(int i=1;i<=x;i++){
		len=(len-1)*(s[i-1]-'0')%mod;
		
		if(s.length()<=x){
			int t=s[i-1]-'0';
			string st=s.substr(i);
			for(int j=2;j<=t;j++){
				if(s.length()<=x) s+=st;
			}
		}
	}
	printf("%lld\n",(1ll*x+len)%mod);
}

int main(){
	int T;
	scanf("%d",&T);

	while(T--){
		cin>>x>>s;
		solve();
	}
	return 0;
} 
