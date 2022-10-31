#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int temp=min(c,d);
	int ans=0;
	ans+=(min(a,temp)*256);
	a-=min(a,temp);
	ans+=(min(a,b)*32);
	cout<<ans<<endl;
}
