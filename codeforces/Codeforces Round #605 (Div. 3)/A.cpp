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

int a[3];

void solve(){
	sort(a,a+3);
	if(a[0]==a[2]||a[0]+1==a[2]||a[0]+1==a[2]+1){
		printf("0\n");
	}
	else{
		printf("%d\n",2*(a[2]-a[0]-2));
	}
}

int main(){
	int T;
	scanf("%d",&T);
	int iCase=1;
	while(T--){
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		solve();
	}
	return 0;
} 
