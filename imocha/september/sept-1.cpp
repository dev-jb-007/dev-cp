#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long int ans=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans=max(ans,a[i]&(2*a[j]));
		}
	}
	cout<<ans<<"\n";
}
