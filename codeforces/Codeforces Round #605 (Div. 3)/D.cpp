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



const int maxn=2e5+5;
int n;
int a[maxn];
int f[maxn][2];

void solve(){
	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++) f[i][0]=1 ;
	int ans=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]){ 
			f[i][0]=f[i-1][0]+1;
			f[i][1]=f[i-1][1]+1;
		}
	
		if(i>=2 && a[i]>a[i-2]) f[i][1]=max(f[i-2][0]+1,f[i][1]); // delete pre
		
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	cout<<ans;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	solve();
	return 0;
} 
