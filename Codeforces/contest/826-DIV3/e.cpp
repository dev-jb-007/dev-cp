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
//ll ncr(ll n, ll r){
    //if(n < r) return 0;
    //ll ans = fact[n];
    //ll x = (fact[r] * fact[n - r]) % mod;
    //ans *= power(x, mod - 2);
    //return ans % mod;
//}
bool AreSame(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}
bool rec(ll i,ll n,vector<ll> &dp,vector<ll> &a)
{
	if(i<0)
	{
		return false;
	}
	else if(i==0)
	{
		return true;
	}
	else if(i==n+1)
	{
		return true;
	}
	else{
		if(dp[i]!=-1)
		{
			return dp[i];
		}
		else{
			ll flag=0;
			flag|=rec(i+a[i-1]+1,n,dp,a);
			flag|=rec(i-a[i-1]-1,n,dp,a);
			flag|=rec(i+1,n,dp,a);
			dp[i]=flag;
			return dp[i];
		}
	}
}
void solve(){
    ll n;
    cin>>n;
    vl a(n);
    vecInput(a,n);
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    for(ll i=1;i<=n;i++)
    {
		//debug(i);
		if(dp[i-1][0]||dp[i-1][1])
		{
			if(i+a[i-1]<=n)
			{
				dp[i+a[i-1]][0]=1;	
			}
		}
		//debug(i-a[i-1]-1);
		if((i-a[i-1]-1)>=0)
		{
			dp[i][1]|=((dp[i-a[i-1]-1][0]||dp[i-a[i-1]-1][1]));
		}
		//debug(dp[i]);
	}
	if(dp[n][0]||dp[n][1])
	{
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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
