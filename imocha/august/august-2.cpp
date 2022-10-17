#include<bits/stdc++.h>
using namespace std;
vector<int> tree[100001];
vector<int> Rank(100001,-1);
vector<int> indegree(100001,0);
vector<int> vis(100001,0);
void topo_sort(int n){
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
			Rank[i]=1;
			vis[i]=1;
		}
	}
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		for(auto i:tree[temp])
		{
			if(vis[i]==0)
			{
				if(Rank[i]<Rank[temp]+1)
				{
					Rank[i]=Rank[temp]+1;
				}
				indegree[i]--;
				if(indegree[i]==0)
				{
					q.push(i);
					vis[i]=1;
				}
			}
		}
	}
}
int answerQueries(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		indegree[b]++;
	}
	topo_sort(n);
	int answer=0;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		if(Rank[a]<Rank[b])
		{
			answer++;
		}
	}
	return answer;
}
int main(int argc, const char * argv[]) {

    cout<<answerQueries()<<"\n";
    return 0;
}
