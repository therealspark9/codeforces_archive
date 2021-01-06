//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	sort(all(a));
	vll b(n);
	ll t = 0, ans = 0;
	for(ll i = 1; i < n; i+=2){
		b[i] = a[t];
		t++;
	}
	for(ll i = 0; i < n; i+=2){
		b[i] = a[t];
		t++;
	}
	for(ll i = 1; i < n-1; i++) if(b[i-1] > b[i] and b[i+1] > b[i])ans++;	
	cout << ans << endl;
	for(auto it:b)cout << it << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}