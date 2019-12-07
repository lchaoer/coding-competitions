#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;

int a[10];
int dp[205][205][11];


void solve(){
	memset(dp,0,sizeof(dp));
	//int sum=0;
	//for(int i=1;i<=9;i++) sum+=a[i];
	for(int i=1;i<=9;i++){
		a[i]%=22;
	}
	dp[0][0][0]=1;
	int cnt=0;
	for(int i=1;i<=9;i++){ 
		for(int j=0;j<=cnt;j++){
			
			for(int c=0;c<=a[i];c++){
				for(int k=0;k<11;k++){
					int t=((k+i*c-i*(a[i]-c))%11+11)%11;
					dp[i][j+c][t] |= dp[i-1][j][k];
					
//					dp[cnt][j+1][(k+i)%11]|=dp[cnt-1][j][k];
//					dp[cnt][j][(k-i+11)%11]|=dp[cnt-1][j][k];
				}
			}
			
		}
		cnt+=a[i];
	}
	if(dp[9][(cnt+1)/2][0]) printf("YES");
	else printf("NO");
}

int main(){
	int T;
	scanf("%d",&T);
	int iCase=1;
	while(T--){
		for(int i=1;i<=9;i++) scanf("%d",&a[i]);
		printf("Case #%d: ",iCase);
		solve();
		printf("\n");
		iCase++;
	}
	return 0;
} 

