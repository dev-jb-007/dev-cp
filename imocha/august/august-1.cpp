#include<bits/stdc++.h>
using namespace std;
int minOperation(){
    int n;
    cin>>n;
    vector<int> a(n),d(n),oper(n,INT_MAX),vis(n,0);
    for(int i=0;i<n;i++)
    {
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
    queue<int> q;
    for(int i=0;i<n;i++)
    {
		if(a[i]==0)
		{
			oper[i]=0;
			vis[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		if(vis[(temp+d[temp])%n]==0)
		{
			oper[(temp+d[temp])%n]=1+oper[temp];
			vis[(temp+d[temp])%n]=1;
			q.push((temp+d[temp])%n);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{		ans=max(ans,oper[i]);
		if(vis[i]==0)
		{
			return -1;
		}
	}
	return ans;
}
int main(int argc, const char * argv[]) {
	cout<<minOperation()<<"\n";
    return 0;
}
