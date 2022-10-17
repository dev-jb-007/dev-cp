#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
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
void solve(){
    ST s;
    cin>>s;
    ll n=s.length();
    vector<vector<ll>> dp(n+1,vector<ll>(26,0));
    for(ll i=1;i<=n;i++)
    {
		for(ll j=0;j<26;j++){
			dp[i][j]+=dp[i-1][j];
		}
		dp[i][s[i-1]-'a']++;
	}
	ll q;
	cin>>q;
	ll ans=0;
	for(ll k=0;k<q;k++){
        ll l,r;
        cin>>l>>r;
        if((r-l)%2)continue;
        ll mid=(l+r)/2;
        vl temp;
        for(ll i=0;i<10;i++)
        {
			temp.PB(i);
		}
		//debug(temp);
        map<ll,ll> m1,m2,m3,m4;
        for(ll j=0;j<26;j++){
            m1[j]=(dp[mid][j]-dp[l-1][j]);
            m2[j]=(dp[r][j]-dp[mid][j]);
            m3[j]=(dp[mid-1][j]-dp[l-1][j]);
            m4[j]=(dp[r][j]-dp[mid-1][j]);
        }
        int flag1=0,flag2=0;
        for(ll j=0;j<26;j++){
            if(flag1==1){
                if(m1[j]!=m2[j]){
                    flag1=2;
                    break;
                }
            }
            else if (flag1==0){
                if(m1[j]!=m2[j]){
                    flag1=1;
                }
            }
        }
        for(ll j=0;j<26;j++){
            if(flag2==1){
                if(m3[j]!=m4[j]){
                    flag2=2;
                    break;
                }
            }
            else if (flag2==0){
                if(m3[j]!=m4[j]){
                    flag2=1;
                }
            }
        }
        if(flag1==1||flag2==1)ans++;
    }
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
