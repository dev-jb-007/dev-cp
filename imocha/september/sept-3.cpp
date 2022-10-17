#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int helper(int x, int y, vector<int>&arr)
{
    int sum = 0;
    map<int,int> mp;
    mp[0]++;
    int ans = 0;
    for(int i = 0; i<(int)arr.size(); i++){
        if(arr[i] == 0)
        {
            sum += (-y);
		}
        else{
            sum += (x);
		}
        if(mp.count(sum)){
            ans += mp[sum];
			ans%=mod;			
		}
        mp[sum]++;
    }
    return ans;
}
int main(){
	int n;
	cin>>n;
	int x,y;
	cin>>x>>y;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<helper(x,y,arr)<<"\n";
}
