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

void solve(){
	ll t, w, b;
	cin >> t >> w >> b;
	ll gcd = __gcd(w,b);
	double ww, bb;
	ww = w/gcd, bb = b;
	if(ww*bb > 6*1e18){
		if(t < min(w,b))cout<<"1/1";
		else{
			gcd = __gcd(min(w,b)-1,t);
			cout<<(min(w,b)-1)/gcd<<"/"<<t/gcd;
		}
		//cout<<"x";
		return;
	}
	ll lcm = b*(w/gcd);
	ll p = min(w,b)*(t/lcm) + min(t-(t/lcm)*lcm, min(w,b)-1), q = t;
	gcd = __gcd(p,q);
	cout<<p/gcd<<"/"<<q/gcd;
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