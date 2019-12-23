#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#include<vector>
#include<queue> 
#include<string>
#define ll long long
#define mod 1000000007
using namespace std;
int gcd(int a,int b){ 
	if(b==0) return a;
	return gcd(b,a%b);
}

const int maxn=3e5+10;
ll n;
ll a[maxn];


void solve(){
	ll ans=0;
	ll k1=0,k2=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]/2;
		if(a[i]&1){
			if(i&1) k1++;
			else k2++; 
		}
	}

	printf("%lld",ans+min(k1,k2));
}

int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	solve();
	return 0;
} 
