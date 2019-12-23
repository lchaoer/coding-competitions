#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#include<vector>
#include<queue> 
#include<string>
#define ll long long
#define mod 1000000007
using namespace std;
int gcd(int a,int b){ 
	if(b==0) return a;
	return gcd(b,a%b);
}

int n;

void solve(){
	cout<<9*n<<" "<<8*n;
}

int main(){
	cin>>n;
	solve();
	return 0;
} 
