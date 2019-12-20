#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#include<vector>
#include<string>
#include<queue> 
#define ll long long
#define mod 1000000007
using namespace std;
int gcd(int a,int b){ 
	if(b==0) return a;
	return gcd(b,a%b);
}



const int maxn=100000+5;
int n,k;
map<char,int> m;
string s;

void solve(){
	int cnt=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(m.count(s[i])==1){
			cnt++;
		}
		else{
			ans+=1ll*cnt*(cnt+1)/2;
			cnt=0;
		}
	}
	ans+=1ll*cnt*(cnt+1)/2;
	printf("%lld",ans);
}

int main(){
	scanf("%d%d",&n,&k);
	cin>>s;
	for(int i=0;i<k;i++){
		char x;
		cin>>x;
		m[x]=1;
	}
	solve();
	return 0;
} 
