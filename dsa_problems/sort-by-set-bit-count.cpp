#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1e+7
#define inf 1e18
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vvi vector<vi>
#define vs vector<string>
#define pr pair<ll, ll>
#define mp map<ll, ll>
#define ump unordered_map<ll, ll>
#define loop(i, a, b) for (ll i = a; i <= b; i++)
#define looprev(i, a, b) for (ll i = a; i >= b; i--)
#define mid l + ((r - l) / 2)
#define sz(x) x.size()

class DSU {
    private:
        vi parent, size;
        int count;

    public:
        DSU(int n) : parent(n+1), size(n+1, 1), count(n) {
            for (int i = 1; i <= n; ++i) {
                parent[i] = i;
            }
        }

        ll find(ll x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        void Union(ll x, ll y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                if (size[x] < size[y]) {
                    swap(x, y);
                }
                parent[y] = x;
                size[x] += size[y];
                count--;
            }
        }

        ll getCount() {
            return count;
        }
};

void solve()
{
    ll n;
    cin >> n;

    vi arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    // Function to count set bits (Brian Kernighan’s Algorithm)
    auto countOne = [](ll x) {
        ll count = 0;
        while (x) {
            x = x & (x - 1);
            count++;
        }
        return count;
    };

    // Stable sort based on set bits (descending)

    // If two elements are considered equal based on sorting condition, then,
    // Their original order stays the same after sorting
    
    stable_sort(arr.begin(), arr.end(), [&](ll a, ll b) {
        return countOne(a) > countOne(b);
    });

    // Output result
    for (auto x : arr) cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}