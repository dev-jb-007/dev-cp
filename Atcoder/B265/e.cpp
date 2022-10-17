#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define pbds tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long l;
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
template<class T>
bool isFloatequal(T a,T b)
{
    if(abs(a-b)<1e-9)
    {
        return true;
    }
    return false;
}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
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

bool AreSame(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}
ll mod=998244353;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(6);
    for(int i=0;i<6;i++){
		cin>>a[i];
	}
	set<pair<ll,ll>> dev;
	for(int i=1;i<=m;i++)
	{
		ll c,d;
		cin>>c>>d;
		dev.insert({c,d});
	}
	vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(n+1,0)));
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(j+k<=i)
				{
					ll x=a[0]*(j+1)+a[2]*(k)+a[4]*(i+1-(j+1+k));
					ll y=a[1]*(j+1)+a[3]*(k)+a[5]*(i+1-(j+1+k));
					
					if(dev.find({x,y})==dev.end())
					{
						dp[i+1][j+1][k]+=(dp[i][j][k])%mod;
						dp[i+1][j+1][k]%=mod;
					}
					x=a[0]*(j)+a[2]*(k+1)+a[4]*(i+1-(j+k+1));
					y=a[1]*(j)+a[3]*(k+1)+a[5]*(i+1-(j+k+1));
					if(dev.find({x,y})==dev.end())
					{
						dp[i+1][j][k+1]+=(dp[i][j][k])%mod;
						dp[i+1][j][k+1]%=mod;
					}
					x=a[0]*(j)+a[2]*(k)+a[4]*(i+1-(j+k));
					y=a[1]*(j)+a[3]*(k)+a[5]*(i+1-(j+k));
					if(dev.find({x,y})==dev.end())
					{
						dp[i+1][j][k]+=(dp[i][j][k])%mod;
						dp[i+1][j][k]%=mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			if(i+j<=n)
			{
				ans+=(dp[n][i][j])%mod;
				ans%=mod;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(int argc, const char * argv[]) {
ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}
