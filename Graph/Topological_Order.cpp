#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> in_degree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    std::vector<int> topo_order;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
        
        count++;
    }
    
    if (count != n) {
        std::cout << "Cycle is found\n";
    } else {
        std::cout << "Cycle is not found\n";
        std::cout << "Topological sort: ";
        for (int v : topo_order) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
