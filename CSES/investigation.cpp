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


//Modular

const int mod = 1e9+7;

template <const int32_t MOD> struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  modint(int64_t value_) : value(value_ % MOD) {}
  inline modint<MOD> operator+(modint<MOD> other) const {
    int32_t c = this->value + other.value;
    return modint<MOD>(c >= MOD ? c - MOD : c);
  }
  inline modint<MOD> operator-(modint<MOD> other) const {
    int32_t c = this->value - other.value;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> operator*(modint<MOD> other) const {
    int32_t c = (int64_t)this->value * other.value % MOD;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> &operator+=(modint<MOD> other) {
    this->value += other.value;
    if (this->value >= MOD)
      this->value -= MOD;
    return *this;
  }
  inline modint<MOD> &operator-=(modint<MOD> other) {
    this->value -= other.value;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }
  inline modint<MOD> &operator*=(modint<MOD> other) {
    this->value = (int64_t)this->value * other.value % MOD;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }
  inline modint<MOD> operator-() const {
    return modint<MOD>(this->value ? MOD - this->value : 0);
  }
  modint<MOD> pow(uint64_t k) const {
    modint<MOD> x = *this, y = 1;
    for (; k; k >>= 1) {
      if (k & 1)
        y *= x;
      x *= x;
    }
    return y;
  }
  modint<MOD> inv() const { return pow(MOD - 2); } // MOD must be a prime
  inline modint<MOD> operator/(modint<MOD> other) const {
    return *this * other.inv();
  }
  inline modint<MOD> operator/=(modint<MOD> other) {
    return *this *= other.inv();
  }
  inline bool operator==(modint<MOD> other) const {
    return value == other.value;
  }
  inline bool operator!=(modint<MOD> other) const {
    return value != other.value;
  }
  inline bool operator<(modint<MOD> other) const { return value < other.value; }
  inline bool operator>(modint<MOD> other) const { return value > other.value; }
};

template <int32_t MOD> modint<MOD> operator*(int64_t value, modint<MOD> n) {
  return modint<MOD>(value) * n;
}
template <int32_t MOD> modint<MOD> operator*(int32_t value, modint<MOD> n) {
  return modint<MOD>(value % MOD) * n;
}
template <int32_t MOD> istream &operator>>(istream &in, modint<MOD> &n) {
  return in >> n.value;
}
template <int32_t MOD> ostream &operator<<(ostream &out, modint<MOD> n) {
  return out << n.value;
}

using mint = modint<mod>;

//Modular


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
vl graph[100005];
vl graph1[100005];
map<pair<ll,ll>,ll> edges;
ll INF=1e18;
vl dist(100005,INF);
vl dist1(100005,INF);
void dijkstra(ll n){
	set<pair<ll,ll>> s;
	s.insert({0,1});
	vl vis(n+1,0);
	dist[1]=0;
	while(!s.empty())
	{
		pair<ll,ll> temp=*(s.begin());
		if(vis[temp.second])
		{
			s.erase(temp);
		}
		else{
			vis[temp.second]=1;
			s.erase(temp);
			for(auto i: graph[temp.second])
			{
				if(vis[i]==0)
				{
					if(temp.first+edges[{temp.second,i}]<dist[i])
					{
						dist[i]=temp.first+edges[{temp.second,i}];
						s.insert({dist[i],i});
					}
				}
			}
		}
	}
}
void dijkstra_back(ll n){
	set<pair<ll,ll>> s;
	s.insert({0,n});
	vl vis(n+1,0);
	dist1[n]=0;
	while(!s.empty())
	{
		//debug(s);
		pair<ll,ll> temp=*(s.begin());
		if(vis[temp.second])
		{
			s.erase(temp);
		}
		else{
			vis[temp.second]=1;
			s.erase(temp);
			for(auto i: graph1[temp.second])
			{
				if(vis[i]==0)
				{
					if(temp.first+edges[{i,temp.second}]<dist1[i])
					{
						dist1[i]=temp.first+edges[{i,temp.second}];
						s.insert({dist1[i],i});
					}
				}
			}
		}
	}
}
vector<ll> path(100005,0);
vector<ll> maxi(100005,-INF);
vector<ll> mini(100005,INF);
vl vis(100005,0);
ll dest;
void dfs1(ll node)
{
	vis[node]=1;
	if(node==dest){
		path[node]=1;
		maxi[node]=0;
		mini[node]=0;
	}
	else{
		ll ans=0;
		ll a=-INF;
		ll b=INF;
		for(auto i:graph[node])
		{
			if(vis[i]==0)
			{
				dfs1(i);
				if(dist1[i]+edges[{node,i}]+dist[node]==dist[dest])
				{
					ans+=path[i];
					ans=ans%mod;
					a=max(a,maxi[i]+1);
					b=min(b,mini[i]+1);
				}
			}
			else{
				if(dist1[i]+edges[{node,i}]+dist[node]==dist[dest])
				{
					ans+=path[i];
					ans=ans%mod;
					a=max(a,maxi[i]+1);
					b=min(b,mini[i]+1);
				}
			}
		}
		path[node]=ans%mod;
		mini[node]=b;
		maxi[node]=a;
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(edges.count({a,b}))
		{
			edges[{a,b}]=min(edges[{a,b}],c);
		}
		else{
			edges[{a,b}]=c;
			graph[a].PB(b);
			graph1[b].PB(a);
		}
	}
	dijkstra(n);
	cout<<dist[n]<<" ";
	dijkstra_back(n);
	path[n]=1;
	maxi[n]=0;
	mini[n]=0;
	dest=n;
	dfs1(1);
	cout<<path[1]<<" "<<mini[1]<<" "<<maxi[1]<<endl;
	for(ll i=1;i<=n;i++)
	{
		cout<<dist1[i]<<" ";
	}
	cout<<endl;
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
