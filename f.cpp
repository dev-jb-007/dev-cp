
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
int64_t INF=9223372036854775807;
bool AreSame(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}
int64_t mini(int64_t a,int64_t b)
{
	if(a<b)
	{
		return a;
	}
	else{
		return b;
	}
}
void solve(){
    ll r,g,b;
    cin>>r>>g>>b;
    vl red(r),green(g),blue(b);
    vecInput(red,r);
    vecInput(green,g);
    vecInput(blue,b);
    sort(red.begin(),red.end());
    sort(green.begin(),green.end());
    sort(blue.begin(),blue.end());
    int64_t ans=INF;
    //cout<<ans<<endl;
    debug(red);
    debug(green);
    debug(blue);
    for(ll i=0;i<r;i++)
    {
		vector<int64_t> one(2,INF),two(2,INF);
		ll ct=upper_bound(green.begin(),green.end(),red[i])-green.begin();
		if(ct!=(ll)green.size())
		{
			one[1]=green[ct];
		}
		ct--;
		if(ct>=0)
		{
			one[0]=green[ct];
		}
		ct=upper_bound(blue.begin(),blue.end(),red[i])-blue.begin();
		if(ct!=(ll)blue.size())
		{
			two[1]=blue[ct];
		}
		ct--;
		if(ct>=0)
		{
			two[0]=blue[ct];
		}
		//cout<<one[0]<<" "<<one[1]<<endl;
		//cout<<two[0]<<" "<<two[1]<<endl;
		int64_t help=INF;
		for(ll j=0;j<2;j++)
		{
			for(ll k=0;k<2;k++)
			{
				if(one[j]<=(1e9)&&two[k]<=(1e9))
				{
					help=mini(help,(one[j]-red[i])*(one[j]-red[i])+(red[i]-two[k])*(red[i]-two[k])+(one[j]-two[k])*(one[j]-two[k]));	
				}
			}
		}
		//cout<<help<<"\n";
		ans=min(ans,help);
	}
	for(ll i=0;i<g;i++)
    {
		vector<int64_t> one(2,INF),two(2,INF);
		ll ct=upper_bound(red.begin(),red.end(),green[i])-red.begin();
		//debug(ct);
		if(ct!=(ll)red.size())
		{
			one[1]=red[ct];
		}
		ct--;
		if(ct>=0)
		{
			one[0]=red[ct];
		}
		ct=upper_bound(blue.begin(),blue.end(),green[i])-blue.begin();
		if(ct!=(ll)blue.size())
		{
			two[1]=blue[ct];
		}
		ct--;
		if(ct>=0)
		{
			two[0]=blue[ct];
		}
		int64_t help=INF;
		//cout<<one[0]<<" "<<one[1]<<endl;
		//cout<<two[0]<<" "<<two[1]<<endl;
		for(ll j=0;j<2;j++)
		{
			for(ll k=0;k<2;k++)
			{
				if(one[j]<=(1e9)&&two[k]<=(1e9))
					help=mini(help,(int64_t)(one[j]-green[i])*(one[j]-green[i])+(int64_t)(green[i]-two[k])*(green[i]-two[k])+(int64_t)(one[j]-two[k])*(one[j]-two[k]));
			}
		}
		ans=min(ans,help);
	}
	for(ll i=0;i<b;i++)
    {
		vector<int64_t> one(2,INF),two(2,INF);
		ll ct=upper_bound(green.begin(),green.end(),blue[i])-green.begin();
		if(ct!=(ll)green.size())
		{
			one[1]=green[ct];
		}
		ct--;
		if(ct>=0)
		{
			one[0]=green[ct];
		}
		ct=upper_bound(red.begin(),red.end(),blue[i])-red.begin();
		if(ct!=(ll)red.size())
		{
			two[1]=red[ct];
		}
		ct--;
		if(ct>=0)
		{
			two[0]=red[ct];
		}
		int64_t help=INF;
		for(ll j=0;j<2;j++)
		{
			for(ll k=0;k<2;k++)
			{
				if(one[j]<=(1e9)&&two[k]<=(1e9))
					help=mini(help,(int64_t)(one[j]-blue[i])*(one[j]-blue[i])+(int64_t)(blue[i]-two[k])*(blue[i]-two[k])+(int64_t)(one[j]-two[k])*(one[j]-two[k]));
			}
		}
		ans=min(ans,help);
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
