#include <iostream>
#include <vector>
#include <stack>

class Graph {
private:
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;
    std::vector<bool> recursionStack;
    std::vector<int> parent;

    bool dfs(int v, std::stack<int>& path) {
        visited[v] = true;
        recursionStack[v] = true;
        path.push(v);

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                parent[neighbor] = v;
                if (dfs(neighbor, path))
                    return true;
            } else if (recursionStack[neighbor]) {
                // Cycle found, print it
                std::cout << "Cycle detected: ";
                std::vector<int> cycle;
                while (!path.empty() && path.top() != neighbor) {
                    cycle.push_back(path.top());
                    path.pop();
                }
                cycle.push_back(neighbor);
                cycle.push_back(v);
                
                for (auto it = cycle.rbegin(); it != cycle.rend(); ++it) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
                return true;
            }
        }

        path.pop();
        recursionStack[v] = false;
        return false;
    }

public:
    Graph(int nodes) : n(nodes) {
        adj.resize(n);
        visited.resize(n, false);
        recursionStack.resize(n, false);
        parent.resize(n, -1);
    }

    void addEdge(int a, int b) {
        adj[a].push_back(b);
    }

    bool hasCycle() {
        std::stack<int> path;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, path))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        g.addEdge(a, b);
    }

    if (!g.hasCycle()) {
        std::cout << "Graph doesn't contain a cycle" << std::endl;
    }

    return 0;
}
