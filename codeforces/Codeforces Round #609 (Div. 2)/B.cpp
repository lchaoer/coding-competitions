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
const int maxn=2000+5;
int n,m;
int a[maxn],b[maxn];


void solve(){
	sort(a,a+n);
	sort(b,b+n);
	int ans=1<<30;
	for(int i=0;i<n;i++){
		int x=(m+b[i]-a[0])%m;
		bool flag=true;
		for(int j=1;j<n;j++){
			if((a[j]+x)%m != b[(i+j)%n]){
				flag=false;break;
			}
		}
		if(flag) ans=min(ans,x);
	}
	cout<<ans;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	solve();
	return 0;
} 
