        #include<bits/stdc++.h>
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
vector<ll> seg_tree;
ll MAXN=200001;
vl eulerTree;
vl start;
vl e;
vl val;
ll timer=0;
vl tree[200001];
void dfs(ll node,ll parent)
{
    start[node]=timer;
    eulerTree[timer]=node;
    timer++;
    for(auto i:tree[node])
    {
        if(i!=parent)
        {
            dfs(i,node);
        }
    }
    eulerTree[timer]=node;
    e[node]=timer;
    timer++;
}
//void build(){
	//for(int i=n;i<2*n;i++)
	//{
		
	//}
//}
void build(ll m){
	for(ll i=m-1;i>=0;i--)
	{
		seg_tree[i]+=(seg_tree[2*i]+seg_tree[2*i+1]);
	}
}
void modify(ll pos,ll m,ll value)
{
	pos+=m;
	seg_tree[pos]=value;
	for(;pos>1;pos=pos/2)
	{
		seg_tree[pos/2]=(seg_tree[pos]+seg_tree[pos^1]);
	}
}
ll query(ll left,ll right,ll m)
{
	ll ans=0;
	for(left+=m,right+=m;left<right;left=left/2,right=right/2)
	{
		if(left&1) ans+=seg_tree[left++];
		if(right&1) ans+=seg_tree[--right];
	}
	return ans;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    e.resize(n+1,0);
    start.resize(n+1,0);
    eulerTree.resize(2*n+1,0);
    val.resize(n+1,0);
    for(ll i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    val[0]=0;
    for(ll i=1;i<n;i++)
    {
        ll c,d;
        cin>>c>>d;
        tree[c].PB(d);
        tree[d].PB(c);
    }
    dfs(1,0);
    ll m=eulerTree.size();
	while(__builtin_popcount(m)!=1)
	{
		eulerTree.PB(0);
		m++;
	}
    //for(int i=0;i<m;i++)
    //{
		//cout<<eulerTree[i]<<" ";
	//}
	seg_tree.resize(2*m,0);
	for(ll i=m;i<2*m;i++)
	{
		seg_tree[i]=val[eulerTree[i-m]];
		val[eulerTree[i-m]]=(-val[eulerTree[i-m]]);
	}
	//debug(eulerTree);
	//debug(seg_tree);
	build(m);
	while(q--)
	{
		ll type;
		cin>>type;
		if(type==1)
		{
			ll node;
			cin>>node;
			ll value;
			cin>>value;
			modify(start[node],m,value);
			modify(e[node],m,-value);
		}
		else{
			ll x;
			cin>>x;
			cout<<query(0,start[x]+1,m)<<endl;
		}
	}
}
int main(int argc, const char * argv[]) {
ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
