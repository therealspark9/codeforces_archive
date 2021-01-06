/*May The Force Be With Me*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000
//Snippets: bigint, bsearch, graph, splitstring, segtree, delta, sieve, fastexp

using namespace std;

bool MC(pll p1, pll p2) {
    return p1.f < p2.f;
}

ll n, d;
pll arr[size_1d];
map<ll, ll> mp;

void Input() {
    cin >> n >> d;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i].f >> arr[i].s;
    }
    sort(arr, arr + n, MC);
}

void Solve() {
    for (ll i = 0; i < n; i++) {
        mp[i] = mp[i - 1] + arr[i].s;
    }
    ll ans = 0;
    ll st = 0, ed = n - 1;
    for (ll i = 0; i < n; i++) {
        ll st = i, ed = n - 1;
        while (st <= ed) {
            ll mid = st + (ed - st) / 2;
            if (arr[mid].f - arr[i].f < d) {
                ans = max(ans, mp[mid] - mp[i - 1]);
                st = mid + 1;
            }
            else {
                ed = mid - 1;
            }
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll T = 1;
    //cin >> T;
    //ll t = 1;
    while (T--) {
        Input();
        //cout << "Case " << t << ": ";
        Solve();
        //t++;
    }
    return 0;
}