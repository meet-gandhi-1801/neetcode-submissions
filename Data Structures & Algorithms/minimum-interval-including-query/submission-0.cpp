class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        // Sort intervals by start
        sort(intervals.begin(), intervals.end());

        // Store (query, original index)
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        // {length, end}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> ans(queries.size());

        int i = 0;

        for (auto &[query, idx] : q) {

            // Add all intervals whose start <= query
            while (i < intervals.size() && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];

                pq.push({right - left + 1, right});
                i++;
            }

            // Remove intervals that cannot contain this query
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // Answer
            if (pq.empty())
                ans[idx] = -1;
            else
                ans[idx] = pq.top().first;
        }

        return ans;
    }
};