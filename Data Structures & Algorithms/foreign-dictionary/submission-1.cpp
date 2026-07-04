class Solution{
    public:
        pair<char, char> solve(string &a, string &b) {
    int i = 0;

    while (i < a.size() && i < b.size()) {
        if (a[i] != b[i])
            return {a[i], b[i]};

        i++;
    }

    // Invalid case
    if (a.size() > b.size())
        return {'#', '#'};

    // No differing character
    return {'*', '*'};
}
string foreignDictionary(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;

    // Initialize all characters
    for (auto& word : words) {
        for (char c : word) indegree[c] = 0;
    }

    // Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        auto edge = solve(words[i], words[i + 1]);

        if (edge.first == '#') return "";

        if (edge.first == '*') continue;

        // Avoid duplicate edges
        if (adj[edge.first].insert(edge.second).second) {
            indegree[edge.second]++;
        }
    }

    // Kahn's Algorithm
    queue<char> q;

    for (auto& [c, deg] : indegree) {
        if (deg == 0) q.push(c);
    }

    string ans;

    while (!q.empty()) {
        char u = q.front();
        q.pop();

        ans += u;

        for (char v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }

    // Cycle exists
    if (ans.size() != indegree.size()) return "";

    return ans;
}
};