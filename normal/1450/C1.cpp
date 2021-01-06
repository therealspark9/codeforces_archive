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
	ll n;
	cin>>n;
	char a[n][n];
	ll b[3] = {0};
	for(ll i = 0; i < n; i++)for(ll j = 0; j < n; j++) cin>>a[i][j];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < n; j++) if(a[i][j] == 'X')b[(i+j)%3]++;
	ll rem = 0;
	if(min({b[0], b[1], b[2]}) == b[1])rem = 1;
	if(min({b[0], b[1], b[2]}) == b[2])rem = 2;
	for(ll i = 0; i < n; i++)for(ll j = 0; j < n; j++) if((i+j)%3 == rem and a[i][j] == 'X')a[i][j] = 'O';	
	for(ll i = 0; i < n; i++){for(ll j = 0; j < n; j++) cout<<a[i][j];cout<<endl;}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi