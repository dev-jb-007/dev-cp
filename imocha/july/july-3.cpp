#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(100001);
vector<int> color(100001,0);
vector<int> vis(100001,0);
bool bipartite=true;
void dfs(int node,int self_color)
{
	vis[node]=1;
	color[node]=self_color;
	for(auto i:graph[node])
	{
		if(vis[i]==1)
		{
			if(color[i]==self_color)
			{
				bipartite=false;
			}
		}
		else{
			dfs(i,3-self_color);
		}
	}
}
int graphQueries(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1,1);
	int answer=0;
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin>>a>>b;
		if(bipartite&&color[a]!=color[b])
		{
			answer++;
		}
	}
	return answer;
}
int main(int argc, const char * argv[]) {
	cout<<graphQueries()<<endl;
    return 0;
}
