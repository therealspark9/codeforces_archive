//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
	vll a(n), b(n);
	for(auto &it:a)cin >> it;
	for(ll i = 0; i < n; i++)b[i] = (a[i]/abs(a[i])) * (abs(a[i])/2);
	ll d = 0;
	for(ll i = 0; i < n; i++)d+=b[i];
	for(ll i = 0; i < n; i++){
		if(!d) break;
		if(d > 0){
			if(a[i] < 0 and abs(a[i])%2){
				b[i] =(a[i]/abs(a[i])) * (abs(b[i]) + 1);
				d--;
			}
		}
		else{
			if(a[i] > 0 and a[i]%2){
				b[i]++;
				d++;
			}
		}
	}
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