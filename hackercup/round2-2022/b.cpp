/* --------------------------------------------------------------------------------
      Author : Bhavik Dholakiya
      Date : 21th September 2022
-----------------------------------------------------------------------------------*/   

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef  long long int ll;

#define v vector<ll>
#define vp vector<pair<ll,ll>>
#define vv vector<v>
#define mp make_pair
#define pb push_back
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pbds tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007
#define nmod 998244353
#define sort(abc) sort(abc.begin(),abc.end());
#define sumt(a) accumulate(a.begin(),a.end(),  0ll)
#define reverse(abcd) reverse(abcd.begin(),abcd.end())
#define input(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
#define print(a) for(auto &i : a){cout<<i<<" ";}
#define pi 3.14159265358979323846
// cout << fixed << setprecision(8) << ans1 << endl;

#ifndef ONLINE_JUDGE
  #include "debug.h"
#else
  #define dbg(...)
#endif

void HareKrishna(){
  string s;
  cin >> s;
  ll n = s.length();
  ll q;
  cin >> q;
  vv dp(26, v(n + 1, 0));
  for(ll i=0; i<26; i++){
    for(ll j=0; j<n; j++){
      dp[i][j + 1] = dp[i][j] + (i == (s[j] - 'a'));
    }
  }
  ll ans = 0;
  while(q--){
    ll l, r;
    cin >> l >> r;
    ll temp = 0;
    if(l % 2 != r % 2){
      continue;
    }
    
    ll which = -1;
    for(ll i=0; i<26; i++){
      if((dp[i][r] - dp[i][l-1]) % 2 == 1){
        which = i;
        temp++;
      }
    }
    if(temp == 1){
      ll x = (l + r)/2;
      bool ok = true;
      for(ll i=0; i<26; i++){
        if(i != which && (dp[i][x - 1] - dp[i][l - 1]) != (dp[i][r] - dp[i][l - 1])/2 && ((dp[i][x] - dp[i][l - 1]) != (dp[i][r] - dp[i][l - 1])/2)){
          
          ok = false;
          break;
        }
      }
      if(ok){
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main(){
  fast_cin();
  int t=1;
  freopen("balanced_chapter_1_validation_input.txt", "r", stdin);
  freopen("hout.txt", "w", stdout);
  cin>>t;
  ll temp=t; 
  // cin.ignore(numeric_limits<streamsize>::max(),'\n');
  while (t--){
    cout<<"Case #"<< temp-t<<": ";
    HareKrishna();
  }

  return 0;
}
