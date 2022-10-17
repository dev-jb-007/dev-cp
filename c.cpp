#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define pbds tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lld;
typedef unsigned long long ull;
typedef char ch;
typedef vector<int> vi;
typedef vector<long long int> vl;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef vector<int,int> vpii;
typedef vector<long long int,int> vpli;
typedef vector<long long int,long long int> vpll;
typedef vector<int,long long int> vpil;
typedef vector<double,double> pdd;
typedef unordered_map<int,int> umii;
typedef unordered_map<long long int,long long int> umll;
typedef unordered_map<long long int,int> umli;
typedef unordered_map<int,long long int> umil;
typedef unordered_map<int,char> umic;
typedef unordered_map<long long int,char> umlc;
#define mod 1000000007
#define ST string
#define F first
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define S second
#define store(x) store.count(x)
#define PB push_back
#define MP make_pair
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORL(i,a,b) for(long long i=a;i<b;i++)
#define FORS(s) for(auto i:s)
#define FORV(V) for(auto i:V)
#define sortVector(V) sort(V.begin(),V.end);
#define vecInput(V,n) for(ll i=0;i<n;i++) cin>>V[i];
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void solve(){
    ll n,m;
    cin>>n>>m;
    ll k;
    cin>>k;
    ll req_mask=0;
    for(ll i=0;i<k;i++)
    {
		ll a;
		cin>>a;
		a--;
		req_mask=(req_mask|(1<<a));
	}
	ll l;
	cin>>l;
	ll initial_mask=0;
	for(ll i=0;i<l;i++)
    {
		ll a;
		cin>>a;
		a--;
		initial_mask=(initial_mask|(1<<a));
	}
	vector<ll> books(m,0);
	vector<ll> cost(m,0);
	for(ll i=0;i<m;i++)
	{
		cin>>cost[i];
	}
	for(ll i=0;i<m;i++)
	{
		ll a;
		cin>>a;
		ll mask=0;
		for(ll j=0;j<a;j++)
		{
			ll b;
			cin>>b;
			b--;
			mask=(mask|(1<<b));
		}
		books[i]=mask;
	}
	ll maxi=(1<<16);
	vector<vector<ll>> dp(m+1,vector<ll>(maxi,INT_MAX));
	dp[0][initial_mask]=0;
	for(ll i=1;i<=m;i++)
	{
		for(ll mask=0;mask<=maxi;mask++)
		{
			ll temp=(mask|books[i-1]);
			dp[i][temp]=min(dp[i][temp],dp[i-1][mask]+cost[i-1]);
		}
		for(ll mask=0;mask<=maxi;mask++)
		{
			dp[i][mask]=min(dp[i-1][mask],dp[i][mask]);
		}
	}
	ll ans=INT_MAX;
	for(ll mask=0;mask<=maxi;mask++)
	{
		if((mask&req_mask)==req_mask){
			ans=min(ans,dp[m][mask]);
		}
	}
	if(ans==INT_MAX)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	
}
int main(int argc, const char * argv[]) {
ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
