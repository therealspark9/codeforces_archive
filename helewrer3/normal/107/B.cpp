//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
#define endl "\n"
using namespace std;

double ncr(ll n, ll r){
	if(r>n)return 0;
	double res = 1;
	for(ll i = 1; i <= r; i++) res=res*(n-r+i)/i;
	return res;
}

void solve(){
	ll n, m, k, cnt=0;
	double num = 0, den = 0;
	cin >> n >> m >> k;
	k--, n--;
	vll a(m);
	for(auto &it:a)cin >> it;
	for(ll i = 0; i < m; i++)if(i!=k)cnt+=a[i];
	a[k]--;
	if(cnt+a[k] < n){
		cout<<-1;
		return;
	}
	for(ll i = 1; i <= a[k]; i++){
		ll tn = n - i;
		if(tn < 0)break;
		num += ncr(a[k],i)*ncr(cnt, tn);
	}
	den = ncr(cnt,n) + num;
	double ans = (double)num/(double)den;
	cout << ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  ll t = 1;
  //cin >> t;
  while(t--){
    solve();
    cout << endl;
  }
  return 0;
}