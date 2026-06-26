class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        for(int i = 0;i<k;i++)
        {
            pq.push({nums[i], i});
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        int j = 0;
        for(int i = k;i<nums.size();i++)
        {
            pq.push({nums[i], i});
            j++;
            while(pq.top().second < j) pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
