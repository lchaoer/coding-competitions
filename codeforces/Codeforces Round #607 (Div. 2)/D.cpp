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
char grid[65][65];
int r,c;

int isvalid(){
	bool f=true;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) if(grid[i][j]=='P') f=false;
	}
	if(f) return 1;
	return 0;
}
bool have(){
	for(int i=0;i<r;i++){
		int cnt=0;
		for(int j=0;j<c;j++) if(grid[i][j]=='A') cnt++;
		if(cnt==c) return true;
	}
	for(int i=0;i<c;i++){
		int cnt=0;
		for(int j=0;j<r;j++) if(grid[j][i]=='A') cnt++;
		if(cnt==r) return true;
	}
	return false;
}

void solve(){
	// 全P 
	bool f=false;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) if(grid[i][j]=='A') f=true;
	}
	if(!f){
		printf("MORTAL\n");return;
	}
	//边缘无A 
	bool edge=false;
	for(int i=0;i<r;i++) if(grid[i][0]=='A'||grid[i][c-1]=='A') edge=true;
	for(int i=0;i<c;i++) if(grid[0][i]=='A'||grid[r-1][i]=='A') edge=true;
	if(!edge){
		printf("4\n");return;
	}
	// 已ok 
	if(isvalid()){
		printf("0\n");return; 
	}
	//某边全A 
	int c1=0,c2=0;
	for(int i=0;i<r;i++){
		if(grid[i][0]=='A') c1++;
		if(grid[i][c-1]=='A') c2++;
	}
	if(c1==r||c2==r){
		printf("1\n");return;
	}
	c1=0,c2=0;
	for(int i=0;i<c;i++){
		if(grid[0][i]=='A') c1++;
		if(grid[r-1][i]=='A') c2++;
	}
	if(c1==c||c2==c){
		printf("1\n");return;
	}
	
	
	if(grid[0][0]=='A'||grid[0][c-1]=='A'||grid[r-1][0]=='A'||grid[r-1][c-1]=='A'){
		printf("2\n");
	}
	else{
		if(have()) printf("2\n");
		else printf("3\n");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++) scanf("%s",grid[i]); 
		solve();
	}
	return 0;
} 
