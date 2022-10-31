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

const int mod = 998244353;
ll INF=1e18;
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
mint power(mint x, int y){
    mint prod = 1;
    while(y){
        if(y&1) prod = (prod * x);
        x = (x * x);
        y /= 2;
    }
    return prod;
}
void chmin(double &a,double &b)
{
	a=min(a,b);
}
vector<mint> fact(200005,0);
mint ncr(int n, int r){
    if(n < r) return 0;
    mint ans = fact[n];
    mint x = (fact[r] * fact[n - r]);
    ans *= power(x, mod - 2);
    return ans;
}
bool AreSame(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}
double calc(pair<ll,ll> c,pair<ll,ll> d,ll speed)
{
	pair<double,double> a={c.first,c.second};
	pair<double,double> b={d.first,d.second};
	double one=(a.first-b.first);
	double two=(a.second-b.second);
	return sqrt(one*one+two*two)/speed;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll>> town(n);
	vector<pair<ll,ll>> quest(m);
	for(ll i=0;i<n;i++)
	{
		cin>>town[i].first>>town[i].second;
	}
	for(ll i=0;i<m;i++)
	{
		cin>>quest[i].first>>quest[i].second;
	}
	ll maxi1=(1<<n);
	ll maxi2=(1<<m);
	debug(maxi1);
	debug(maxi2);
	vector<vector<vector<vector<double>>>> dp(maxi1,vector<vector<vector<double>>>(maxi2,vector<vector<double>>(n+1,vector<double>(m+1,INF))));
	for(ll i=0;i<n;i++)
	{
		ll mask=(1<<i);
		dp[mask][0][i+1][0]=calc({0,0},town[i],1);
	}
	for(ll i=0;i<m;i++)
	{
		ll mask=(1<<i);
		dp[0][mask][0][i+1]=calc({0,0},quest[i],1);
	}
	for(ll mask1=0;mask1<maxi1;mask1++)
	{
		for(ll mask2=0;mask2<maxi2;mask2++)
		{
			//Town to town
			ll dev=__builtin_popcount(mask2);	
			ll speed=(pow(2,dev));
			//Town to town
			for(int j=0;j<n;j++)
			{
				if(((1<<j)&(mask1))==0) continue;
				for(int i=0;i<n;i++)
				{
					if(((1<<i)&(mask1))==0)
					{
						double val=dp[mask1][mask2][j+1][0]+calc(town[i],town[j],speed);
						dp[(mask1|(1<<i))][mask2][i+1][0]=min(dp[(mask1|(1<<i))][mask2][i+1][0],val);
					}
				}
				for(int i=0;i<m;i++)
				{
					if(((1<<i)&(mask2))==0)
					{
						double val=dp[mask1][mask2][j+1][0]+calc(town[j],quest[i],speed);
						dp[mask1][(mask2|(1<<i))][0][i+1]=min(dp[mask1][(mask2|(1<<i))][0][i+1],val);
					}
				}
			}
			//Quest to town
			for(int j=0;j<m;j++)
			{
				if(((1<<j)&(mask2))==0) continue;
				for(int i=0;i<n;i++)
				{
					if(((1<<i)&(mask1))==0)
					{
						double val=dp[mask1][mask2][0][j+1]+calc(town[i],quest[j],speed);
						dp[(mask1|(1<<i))][mask2][i+1][0]=min(dp[(mask1|(1<<i))][mask2][i+1][0],val);
					}
				}
				for(int i=0;i<m;i++)
				{
					if(((1<<i)&(mask2))==0)
					{
						double val=dp[mask1][mask2][0][j+1]+calc(quest[j],quest[i],speed);
						dp[mask1][(mask2|(1<<i))][0][i+1]=min(dp[mask1][(mask2|(1<<i))][0][i+1],val);
					}
				}
			}
		}
	}
	double ans=INF;
	for(ll i=0;i<maxi2;i++)
	{
		for(int j=0;j<n;j++)
		{
			ll dev=__builtin_popcount(i);
			ll speed=pow(2,dev);
			ans=min(ans,dp[maxi1-1][i][j+1][0]+calc(town[j],{0,0},speed));
		}
		for(int j=0;j<m;j++)
		{
			if((i&(1<<j))!=0)
			{
				ll dev=__builtin_popcount(i);
				ll speed=pow(2,dev);
				ans=min(ans,dp[maxi1-1][i][0][j+1]+calc(quest[j],{0,0},speed));
			}
		}
	}
	printf("%0.9f\n",ans);
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
