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


const int maxn=2e5+5;
int n;
int a[maxn];
int d[maxn];
vector<int> fg[maxn];

int main(){
	scanf("%d",&n);
	queue<int> q;
	memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++){
		if(i-a[i]>=1){
			fg[i-a[i]].push_back(i);
			if(a[i]%2 != a[i-a[i]]%2) d[i]=1;
		}
		if(i+a[i]<=n){
			fg[i+a[i]].push_back(i);
			if(a[i]%2 != a[i+a[i]]%2) d[i]=1;
		}
		if(d[i]==1) q.push(i);
	}
	
	while(!q.empty()){
		int v=q.front();q.pop();
		for(int i=0;i<fg[v].size();i++){
			int u=fg[v][i];
			if(d[u]==-1){
				d[u]=d[v]+1;
				q.push(u);
			}
		}
	}
	
	for(int i=1;i<=n;i++) printf("%d ",d[i]);
	
	return 0;
} 
