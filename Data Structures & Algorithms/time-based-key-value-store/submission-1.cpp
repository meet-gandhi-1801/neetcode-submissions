class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mp;
public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        sort(mp[key].begin(),mp[key].end());
    }
    
    string get(string key, int timestamp) {
        auto &v = mp[key];
        int l = 0;
        int h = v.size() - 1;
        string ans = "";
        if(v.size() == 0) return ans;
        
        while(l <= h)
        {
            int mid = (l + h) >> 1;
            if(v[mid].first == timestamp) return v[mid].second;
            else if (v[mid].first < timestamp)
            {
                ans = v[mid].second;
                l = mid + 1;
            }
            else 
            {
                h = mid - 1;
            }
        }
        return ans;
    }
};
