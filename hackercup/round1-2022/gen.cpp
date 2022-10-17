#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll random(ll a,ll b)
{
	return a+rand()%(b-a+1);
}
int main(int argc,char* argv[]){
	srand(stoi(argv[1]));
	ll n=stoi(argv[2]);
	cout<<n<<"\n";
	for(ll i=1;i<=n;i++)
	{
		ll r=random(1,100);
		ll b=random(1,100);
		ll k=random(2,5);
		cout<<r<<" "<<b<<" "<<k<<"\n";
	}
	cout<<"\n";
}
