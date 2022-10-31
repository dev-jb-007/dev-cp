#include<bits/stdc++.h>
using namespace std;
vector<int> tree[200005];
vector<int> vis(200005,0);
vector<int> a(200005,0);
void dfs(int node,int par,int color)
{
	cout<<node<<endl;
	vis[node]=1;
	for(auto i:tree[node])
	{
		if(i!=par&&a[i]==color&&vis[i]==0)
		{
			dfs(i,node,color);
		}
	}
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int c,d;
		cin>>c>>d;
		tree[c].push_back(d);
		tree[d].push_back(c);
	}
	//for(auto j:tree[1])
	//{
		//cout<<j<<" ";
	//}
	//cout<<endl;
	int white=0,black=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		if(a[i]==1)
		{
			white++;
			cout<<"white"<<endl;
			dfs(i,-1,1);
			
		}
		else{
			black++;
			cout<<"black"<<endl;
			dfs(i,-1,0);
			
		}
	}
	cout<<min(black,white)<<endl;
}
int main(){
	int t;
	t=1;
	while(t--)
	{
		solve();
	}
}
