#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
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
ll test_case=1;
bool check(ll rh,ll rs,pair<ll,ll> p)
{
	ll dist=pow(rh+rs,2);
	ll temp=(p.first*p.first+p.second*p.second);
	if(temp<=dist)
	{
		return true;
	}
	else{
		return false;
	}
}
ll dist(ll rh,ll rs,pair<ll,ll> p)
{
	ll temp=(p.first*p.first+p.second*p.second);
	return temp;
	
}
void solve(){
    ll rh,rs;
    cin>>rh>>rs;
    ll n;
    cin>>n;
    vector<pair<ll,ll>> red;
    for(ll i=0;i<n;i++)
    {
		pair<ll,ll> a;
		cin>>a.first>>a.second;
		if(check(rh,rs,a))
		{
			red.PB(a);
		}
	}
	ll m;
	cin>>m;
	vector<pair<ll,ll>> yellow;
    for(ll i=0;i<m;i++)
    {
		pair<ll,ll> a;
		cin>>a.first>>a.second;
		if(check(rh,rs,a))
		{
			yellow.PB(a);
		}
	}
	ll ans1=0;
	ll ans2=0;
	//Red
	for(ll i=0;i<(ll)red.size();i++)
	{
		bool flag=false;
		for(ll j=0;j<(ll)yellow.size();j++)
		{
			//debug();
			if(dist(rh,rs,red[i])<dist(rh,rs,yellow[j]))
			{
				
			}
			else{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			ans1++;
		}
	}
	//yellow
	for(ll i=0;i<(ll)yellow.size();i++)
	{
		bool flag=false;
		for(ll j=0;j<(ll)red.size();j++)
		{
			if(dist(rh,rs,yellow[i])<dist(rh,rs,red[j]))
			{
				
			}
			else{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			ans2++;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
}
int main(int argc, const char * argv[]) {
ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<test_case<<": ";
        solve();
        test_case++;
    }
    return 0;
}
