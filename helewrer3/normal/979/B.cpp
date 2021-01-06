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
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	vll sa(60,0), sb(60,0), sc(60,0);
	for(auto it:a)sa[it - 'A']++;
	for(auto it:b)sb[it - 'A']++;
	for(auto it:c)sc[it - 'A']++;
	sort(rall(sa));
	sort(rall(sb));
	sort(rall(sc));
	if(n == 1 and sa[0] == sz(a))sa[0] -= 2;
	if(n == 1 and sb[0] == sz(b))sb[0] -= 2;
	if(n == 1 and sc[0] == sz(c))sc[0] -= 2;
	ll x = min(sz(a), sa[0] + n);
	ll y = min(sz(b), sb[0] + n);
	ll z = min(sz(c), sc[0] + n);
	ll v = max({x,y,z});
	if (x == v and y != v and z != v)cout << "Kuro";
	else if (y == v and x != v and z != v)cout << "Shiro";
	else if (z == v and x != v and y != v)cout << "Katie";
	else cout << "Draw";
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi