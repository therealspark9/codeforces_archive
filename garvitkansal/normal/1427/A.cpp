//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	ll su = 0;
	for(auto it:a)su+=it;
	if(!su)cout<<"NO";
	else{
		if(su<0)sort(all(a));
		else sort(rall(a));
		cout<<"YES\n";
		ll t = 0;
		for(ll i = 0; i < n; i++){
			if(t + a[i] == 0){
				ll j = i;
				while(j < n and t + a[j] == 0)j++;
				swap(a[i], a[j]);
			}
			cout << a[i] << " ";
			t += a[i];
		}
		
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}