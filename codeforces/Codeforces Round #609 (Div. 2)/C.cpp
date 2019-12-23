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

const int maxn=2e5+10;
int n,k;
string x;

void solve(){
	int a[maxn];
	for(int i=n-1;i>=0;i--){
		a[i]=x[i]-'0';
	}
	int b[maxn];
	for(int i=0;i<k;i++){
		b[i]=a[i];
	}
	bool flag=true;
	for(int i=k;i<n;i++){
		b[i]=b[i%k];
		if(b[i]>a[i]) break; // !!!!!!!
		if(b[i]<a[i]){
			flag=false;break;
		}
	}
	if(!flag){
		int i=k-1;
		while(b[i]==9){
			b[i]=0;
			i--;
		}
		b[i]++;
	}
	for(int i=k;i<n;i++){
		b[i]=b[i%k];
	}
	string y="";
	for(int i=0;i<n;i++) y+=b[i]+'0';
	cout<<n<<endl;
	cout<<y;
}

int main(){
	cin>>n>>k>>x;
	solve();
	return 0;
} 
