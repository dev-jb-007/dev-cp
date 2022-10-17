#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll random(ll a,ll b)
{
	return a+rand()%(b-a+1);
}
int main(int argc,char* argv[]){
	srand(stoi(argv[1]));
	int n=stoi(argv[2]);
	//cin>>n;
	cout<<n<<"\n";
	unordered_map<int,int> dev;
	for(ll i=1;i<=n;i++)
	{
		ll r=random(1,n);
		while(dev[r]==1)
		{
			r=random(1,n);
		}
		cout<<r<<" ";
		dev[r]=1;
	}
	cout<<"\n";
}
