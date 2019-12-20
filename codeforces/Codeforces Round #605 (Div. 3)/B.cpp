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
string s;

void solve(){
	int a[4]={0};
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='U') a[0]++;
		if(s[i]=='R') a[1]++;
		if(s[i]=='D') a[2]++;
		if(s[i]=='L') a[3]++;
	}
	a[0]=a[2]=min(a[0],a[2]);
	a[1]=a[3]=min(a[1],a[3]);
	int ans=a[0]+a[1]+a[2]+a[3];
	if(ans==0) printf("0\n");
	else{
		if(a[0]==0||a[1]==0){
			printf("2\n");
			if(!a[0]) printf("LR");
			else printf("UD");
		}
		else{
			printf("%d\n",ans);
			for(int i=0;i<a[0];i++) printf("U");
			for(int i=0;i<a[1];i++) printf("R");
			for(int i=0;i<a[2];i++) printf("D");
			for(int i=0;i<a[3];i++) printf("L");
		}
		
	}
	printf("\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>s;
		solve();
	}
	return 0;
} 
