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

double n, l;
vector<double> a, b;

double tim(double x){
	if(x <= a[0]) return x;
	double res = a[0], vel = 1;
	for(ll i = 0; i < n; i++){
		vel++;
		if(i == n-1) res += (x - a[i])/vel;
		else if(x <= a[i+1]){
			res += (x - a[i])/vel;
			return res;
		}
		else res += (a[i+1] - a[i])/vel;
	}
	return res;
}

double timb(double x){
	if(x >= b[0]) return abs(x - l);
	double res = l - b[0], vel = 1;
	for(ll i = 0; i < n; i++){
		vel++;
		if(i == n-1) res += abs(x - b[i])/vel;
		else if(x >= b[i+1]){
			res += abs(x - b[i])/vel;
			return res;
		}
		else res += abs(b[i+1] - b[i])/vel;
	}
	return res;
}

void input(){
	cin >> n >> l;
	a.resize(n), b.resize(n);
	for(auto &it:a)cin >> it;
	b = a;
	reverse(all(b));
}

void solve(){
	double st = 0, ed = l;
	for(ll i = 0; i < 1000 and st + 10e-18 < ed; i++){
		double mid = 0.5 * (ed + st);
		if(tim(mid) > timb(mid) + 10e-7)ed = mid;
		else if(tim(mid) + 10e-7 < timb(mid))st = mid;
		else{
			cout << tim(mid);
			return;
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