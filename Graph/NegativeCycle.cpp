/*Bellman Ford's Algorithm for printing Negative Cycle*/
#include <bits/stdc++.h>

using i64 = long long;
const i64 INF = LLONG_MAX / 2;
const int N = 2500 + 1;

struct Edge {
    int a, b; i64 cost;
};
std::vector<Edge> edges;

void negativeCycle(int n)
{
    std::vector<i64> d(n + 1, 0);
    std::vector<int> p(n + 1, -1);
    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (const Edge &e : edges) {
            if (d[e.b] > d[e.a] + e.cost) {
                d[e.b] = std::max(-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) 
        std::cout << "NO\n";

    else {
        std::cout << "YES\n";

        for (int i = 0; i < n; ++i)
            x = p[x];

        std::vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }

        std::reverse(cycle.begin(), cycle.end());

        for (int v : cycle)
            std::cout << v << ' ';
        std::cout << '\n';
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b; i64 c;
        std::cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    negativeCycle(n);
    
    return 0;
}
