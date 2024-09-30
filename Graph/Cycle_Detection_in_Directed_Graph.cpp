/*DFS algorithm is used to detect cycle in Directed Graph*/
#include <bits/stdc++.h>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
    }
    bool ok = true;
    std::vector<bool> vis(n + 1, false), cycle(n + 1, false);
    
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true;
        cycle[x] = true;
        
        for (int i: adj[x]) {
            if (!vis[i])
                self(self, i);
            else if (cycle[i]) {
                ok = false;
                return;
            }
        }    
        cycle[x] = false;
    };
  
    for (int i = 1; i <= n && ok; i++) {
        if (!vis[i])
            dfs(dfs, i);
    }
    if (!ok)
        std::cout << "Cycle is found\n";
    else
        std::cout << "Cycle is not found\n";
    
    return 0;
}
