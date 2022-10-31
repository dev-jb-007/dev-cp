#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int one=0;
	for(auto i:s)
	{
		if(i=='A') one++;
	}
	if(one>(n-one))
	{
		cout<<"Anton\n";
	}
	else if(one==(n-one))
	{
		cout<<"Friendship\n";
	}
	else{
		cout<<"Danik\n";
	}
}
