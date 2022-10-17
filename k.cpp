
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

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++)
    {
		ll a;
		cin>>a;
		vec[i]={a,i};
	}
	sort(vec.begin(),vec.end());
	ll diff=vec[1].first-vec[0].first;
	bool flag=false;
	if(n<=3)
	{
		cout<<1<<endl;
		return;
	}
    for(ll i=1;i<n;i++)
    {
		if(diff!=(vec[i].first-vec[i-1].first))
		{
			flag=true;
		}
	}
	if(!flag)
	{
		cout<<vec[0].second+1<<endl;
		return;
	}
	else{
		flag=false;
		diff=vec[2].first-vec[1].first;
		for(ll i=3;i<n;i++)
		{
			if(vec[i].first-vec[i-1].first!=diff)
			{
				flag=true;
			}
		}
		if(!flag)
		{
			cout<<vec[0].second+1<<endl;
			return;
		}
		diff=vec[2].first-vec[0].first;
		flag=false;
		for(ll i=3;i<n;i++)
		{
			if(vec[i].first-vec[i-1].first!=diff)
			{
				flag=true;
			}
		}
		if(!flag)
		{
			cout<<vec[1].second+1<<endl;
			return;
		}
		
		diff=vec[1].first-vec[0].first;
		debug(diff);
		ll ans=INT_MAX;
		debug(vec);
		ll ct=0;
		for(ll i=2;i<n;i++)
		{
			if(vec[i].first-vec[i-1].first!=diff)
			{
				debug(i);
				ans=min(ans,vec[i].second);
				if(i+1<n)
				{
					if(vec[i+1].first-vec[i-1].first!=diff)
					{
						cout<<-1<<endl;
						return;
					}
					else{
						i++;
					}
				}
				ct++;
			}
		}
		if(ct>=2)
		{
			cout<<-1<<endl;
			return;
		}
		else{
			cout<<ans+1<<endl;
			return;
		}
	}
}
int main(int argc, const char * argv[]) {
ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
