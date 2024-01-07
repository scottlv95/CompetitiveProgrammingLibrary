
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define nl "\n"
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(int i=a; i<b; i++)

int n, l;
vector<vector<int>> adj;

int timer;
vi depth;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    // might not be needed
    depth[v] = depth[p] + 1;
    
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}


bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    depth.assign(n, 0);
    dfs(root, root);
}


// helper function for binary lifting
int count_trailing_zeroes(int n) {
    int count = 0;
    while ((n & 1) == 0) {
        count += 1;
        n >>= 1;
    }
    return count;
}
 
// up[u][i] is the 2^i-th ancestor of u
// goUp(u, x) is the node x steps above u
int goUp(int u, int x) {
    if (x == 0) return u;
    return goUp(up[u][count_trailing_zeroes(x)], x - (1 << count_trailing_zeroes(x)));
}

