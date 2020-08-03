#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#include<vector>
#include<string>
#include<queue> 
#include<set>
#include<string>
#define ll long long
#define mod 1000000007
// #pragma pack(4)
using namespace std;
int gcd(int a,int b){ 
	if(b==0) return a;
	return gcd(b,a%b);
}

const int N=1e5+5, inf=1<<30;





int main(){

	int n=1;
	for(int i=9;i>=1;i--)
	{
		n=2*(n+1);
	}
	printf("%d\n",n);

	return 0;
} 

