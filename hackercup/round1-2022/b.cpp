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
ll mod=1e9+7;
void self_add(int64_t &a,int64_t b)
{
	a+=b;
	if(a>=mod)
	{
		a-=mod;
	}
}
void self_sub(int64_t &a,int64_t b){
	a-=b;
	if(a<0){
		a+=mod;
	}
}
void solve(){
    int64_t n,q;
    cin>>n;
    vector<pair<int64_t,int64_t>> vec(n);
    int64_t a=0,b=0,c=0;
    int64_t d=0,e=0,f=0;
    for(int64_t i=0;i<n;i++)
    {
		cin>>vec[i].first>>vec[i].second;
		self_add(a,(vec[i].first*vec[i].first)%mod);
		self_add(a,(vec[i].second*vec[i].second)%mod);
		self_add(b,vec[i].first);
		self_add(c,vec[i].second);
	}
	cin>>q;
	vector<pair<int64_t,int64_t>> query(q);
	for(int64_t i=0;i<q;i++)
	{
		cin>>query[i].first>>query[i].second;
		self_add(d,(query[i].first*query[i].first)%mod);
		self_add(d,(query[i].second*query[i].second)%mod);
		self_add(e,query[i].first);
		self_add(f,query[i].second);
	}
	int64_t ans=0;
	self_add(ans,(n*d)%mod);
	self_add(ans,(q*a)%mod);
	self_sub(ans,(2*b*e)%mod);
	self_sub(ans,(2*c*f)%mod);
	cout<<ans<<"\n";
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
