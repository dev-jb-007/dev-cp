#include<bits/stdc++.h>
using namespace std;
vector<int> tree[100001];
vector<long long int> val(100001,0);
vector<int> vis(100001,0);
priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
long long int mod=1e9+7;
long long int bfs(int node)
{
	queue<int> q;
	q.push(node);
	vis[node]=1;
	long long int curr=0;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		curr+=val[temp];
		for(int i:tree[temp])
		{
			if(vis[i]==0)
			{
				q.push(i);
				vis[i]=1;
			}
		}
	}
	return curr;
}
int calculateCost(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			long long int curr=bfs(i);
			pq.push(curr);
		}
	}
	long long int answer=0;
	while(!pq.empty())
	{
		int first=pq.top();
		pq.pop();
		if(pq.empty())
		{
			break;
		}
		int second=pq.top();
		pq.pop();
		answer+=(first+second)%mod;
		answer=answer%mod;
		pq.push((first+second)%mod);
	}
	return answer;
}
int main(){
	cout<<calculateCost()<<"\n";
}
