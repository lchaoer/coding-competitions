#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#include<cstring>
#include<vector>
#define ll long long
using namespace std;

const int maxn=100000+5;
int n;

int isvalid(int x,int y){
	if(x<0||y<0||x>=n||y>=n) return 0;
	return 1;
}

int flip(int f1,int f2,vector<vector<int> > a){
	int cnt=f1+f2;
	if(f1){
		for(int i=0;i<n;i++){
			a[i][i]=1-a[i][i];
		}
	}
	if(f2){
		for(int i=0;i<n-1;i++){
			a[i][i+1]=1-a[i][i+1];
		}
	}
	//////
	for(int i=0;i<n;i++){
		if(a[i][i]){
			cnt++;
			for(int j=-n;j<=n;j++){
				int x=i+j;
				int y=i-j;
				if(!isvalid(x,y)) continue;
				a[x][y]=1-a[x][y];
			}
		}
	}
	for(int i=0;i<n-1;i++){
		if(a[i][i+1]){
			cnt++;
			for(int j=-n;j<=n;j++){
				int x=i+j;
				int y=i+1-j;
				if(!isvalid(x,y)) continue;
				a[x][y]=1-a[x][y];
			}
		}
	}
	////////
	for(int i=0;i<n;i++){
		if(a[i][n-1-i]){
			cnt++;
			for(int j=-n;j<=n;j++){
				int x=i+j;
				int y=n-1-i+j;
				if(!isvalid(x,y)) continue;
				a[x][y]=1-a[x][y];
			}
		}
	}
	for(int i=0;i<n-1;i++){
		if(a[i][n-2-i]){
			cnt++;
			for(int j=-n;j<=n;j++){
				int x=i+j;
				int y=n-2-i+j;
				if(!isvalid(x,y)) continue;
				a[x][y]=1-a[x][y];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]) return 1<<30;
		}
	}
	return cnt;
}


int main(){
	int T;
	scanf("%d",&T);
	int iCase=1;
	while(T--){
		string s;
		cin>>n;
		vector<vector<int> > a(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			cin>>s;
			for(int j=0;j<n;j++){
				if(s[j]=='.') a[i][j]=1;
			}
		}
		int ans=1<<30;
		for(int f1=0;f1<2;f1++){
			for(int f2=0;f2<2;f2++){
				ans=min(ans,flip(f1,f2,a));
			}
		}
		printf("Case #%d: %d\n",iCase,ans);
		iCase++;
	}
	return 0;
} 
