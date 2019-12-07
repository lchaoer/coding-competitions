#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn=7000+10;
const int maxm=200000+10;
int n;
ll a[maxn];
ll num[maxm];

ll bf(){
	int i,j,k;
	ll ans=0;
	for(i=0;i<n-2;i++){
		for(j=i+1;j<n-1;j++){
			for(k=j+1;k<n;k++){
				if( (a[i]*a[j]==a[k])||(a[j]*a[k]==a[i])||(a[i]*a[k]==a[j])    )
					ans++;
			}
		}
	}
	return ans;
}

ll solve(){
	ll ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==0||a[j]==0||a[i]==1||a[j]==1) continue;
			
			if((a[i]*a[j])>200000) continue;
			
			ans+= num[a[i]*a[j]];
		}
	}
	ans+=num[0]*(num[0]-1)*(num[0]-2)/6;     //  0 0 0
	ans+=num[0]*(num[0]-1)/2 * (n-num[0]);   //  0 0
	
	ans+=num[1]*(num[1]-1)*(num[1]-2)/6;
	for(int i=2;i<=200000;i++){
		ans+=num[1]*  num[i]*(num[i]-1)/2;
	}
	
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	int t=1;
	while(T--){
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			num[a[i]]++;
		}
		printf("Case #%d: %lld\n",t,solve());
		t++;
	}
	return 0;
} 
