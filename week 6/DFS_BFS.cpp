#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Ham them canh
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u); // do thi vo huong
}

// DFS bang stack
void DFS_list(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

// BFS bang queue
void BFS_list(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);

    // Dùng hàm addEdge để thêm cạnh
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    int start;
    cin >> start;

    cout << "DFS: ";
    DFS_list(start, graph);
    cout << "\n";

    cout << "BFS: ";
    BFS_list(start, graph);
    cout << "\n";

    return 0;
}
