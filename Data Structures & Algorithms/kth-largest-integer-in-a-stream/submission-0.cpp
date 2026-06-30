class KthLargest {
private: 
    int size;
    priority_queue<int,vector<int>,greater<>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for(int n : nums)
        {
            pq.push(n);
        }
        while(pq.size() > size)
        {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size) pq.pop();
        return pq.top();
    }
};
