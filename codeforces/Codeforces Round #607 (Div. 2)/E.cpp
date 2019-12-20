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
ll G,B;
int k;
vector<pair<int,int> > g[maxn];
int cnt[maxn];

void dfs(int u,int p){
	cnt[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].first,w=g[u][i].second;
		if(v==p) continue;
		
		dfs(v,u);
		if(cnt[v]&1) G+=1ll*w;
		B+=1ll*min(cnt[v],2*k-cnt[v])*w;
		cnt[u]+=cnt[v];	
	}
}



int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&k);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=2*k;i++) g[i].clear();
		for(int i=1;i<=2*k-1;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
		}
		G=0;B=0;
		dfs(1,0);
		printf("%lld %lld\n",G,B);
	}
	return 0;
} 
