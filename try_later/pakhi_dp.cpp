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
template<class T>
bool isFloatequal(T a,T b)
{
    if(abs(a-b)<1e-9)
    {
        return true;
    }
    return false;
}
ll power(ll x, ll y){
    ll prod = 1;
    while(y){
        if(y & 1) prod = (prod * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return prod;
}

void solve(){
    int n,m,s;
    cin>>n>>m>>s;
    vector<vector<int>> dp(m+1,vector<int>(s+1,0));
    vector<vector<int>> dev(m+1,vector<int>(s+1,0));
    for(int i=1;i<=m;i++)
    {
		dp[i][0]=1;
	}
	for(int j=1;j<=m;j++)
	{
		dev[j][0]+=(dev[j-1][0]+dp[j][0]);
	}
    for(int i=2;i<=n;i++)
    {
		vector<vector<int>> new_dp(m+1,vector<int>(s+1,0));
		vector<vector<int>> new_dev(m+1,vector<int>(s+1,0));
		for(int k=1;k<=m;k++)
		{
			for(int p=0;p<s;p++)
			{
				new_dp[k][p+1]+=(dev[k-1][p]);
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int p=0;p<=s;p++)
			{
				new_dp[j][p]+=(j*dp[j][p]);
			}
		}
		dp=new_dp;
		for(int p=0;p<=s;p++)
		{
			for(int j=1;j<=m;j++)
			{
				new_dev[j][p]+=(new_dev[j-1][p]+dp[j][p]);
			}
		}
		dev=new_dev;
	}
    int ans=0;
    for(int i=1;i<=m;i++)
    {
		ans+=(dp[i][s]);
	}
	cout<<ans<<endl;
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
