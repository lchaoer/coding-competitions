#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#include<cstring>
#define ll long long
using namespace std;

const int maxn=100000+5;
int n;
int a[maxn];
int sum[maxn];

void solve(){
	memset(sum,0,sizeof(sum));
	int k=0,cnt=0;
	for(int i=0;i<n;i++){
		sum[a[i]]++;
		if(a[i]>k) cnt++;
		if(cnt>k){
			k++;
			cnt-=sum[k];
		}
		printf(" %d",k);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	int iCase=1;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		printf("Case #%d:",iCase);
		solve();
		printf("\n");
		iCase++;
	}
	return 0;
} 
