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



const int maxn=5000+5;
string s,c;

void solve(){

	for(int i=0;i<s.length();i++){
		int it=i;
		for(int j=s.length()-1;j>i;j--){
			if(s[j]<s[it]){
				it=j;
			}	
		}
		if(it!=i){
			swap(s[i],s[it]);
			break;
		}
	}
	
	if(s<c) cout<<s<<endl;
	else cout<<"---"<<endl;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>s>>c;
		solve();
	}
	return 0;
} 
