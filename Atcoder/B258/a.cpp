#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,x;
	cin>>n>>x;
	vector<pair<ll,ll>> a(n);
	vector<ll> pref(n,0);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;
		if(i==0)
		{
			pref[i]=(a[i].first+a[i].second);
		}
		else{
			pref[i]=((a[i].first+a[i].second)+pref[i-1]);
		}
	}
	ll ans=pref[0]+max(x-1,0ll)*a[0].second;
	for(ll i=1;i<n;i++)
	{
		ans=min(ans,pref[i]+max(x-i-1,0ll)*a[i].second);
	}
	cout<<ans<<endl;
	return 0;
}
