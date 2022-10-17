
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
const int MAXN=2e5+1;
vector<int> tree[MAXN];
vector<int> Parent(MAXN);
vector<int> Size(MAXN);
map<pair<int,int>,ll> edge;
int find_set(int v) {
    if (v==Parent[v])
    {
        return v;
	}
    return Parent[v] = find_set(Parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Size[a] < Size[b])
            swap(a, b);
        Parent[b] = a;
        Size[a] += Size[b];
    }
}
bool comp(pair<ll,pair<int,int>> &a,pair<ll,pair<int,int>> &b)
{
	return a.first<b.first;
}
void solve(){
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector<pair<ll,pair<int,int>>> vec(m);
    for(int i=1;i<=m;i++)
    {
		int a,b;
		ll c;
		cin>>a>>b>>c;
		tree[a].PB(b);
		tree[b].PB(a);
		//edge[{a,b}]=c;
		//edge[{b,a}]=c;
		vec[i-1]={c,{a,b}};
	}
	sort(vec.begin(),vec.end(),comp);
	for(int i=1;i<=n;i++)
	{
		Parent[i]=i;
		Size[i]=1;
	}
	ll ans=0;
	for(int i=0;i<m;i++){
		if(find_set(vec[i].second.first)!=find_set(vec[i].second.second))
		{
			if(vec[i].first>k)
			{
				ans+=(vec[i].first-k);
			}
			union_sets(vec[i].second.first,vec[i].second.second);
		}
	}
	if(ans!=0)
	{
		cout<<ans<<"\n";
	}
	else{
		ll ans1=1e9;
		for(ll i=1;i<=m;i++)
		{
			ans1=min(ans1,abs(vec[i-1].first-k));
		}
		cout<<ans1<<"\n";
	}
	for(int i=1;i<=n;i++)
	{
		tree[i].clear();
		Size[i]=0;
		Parent[i]=-1;
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
