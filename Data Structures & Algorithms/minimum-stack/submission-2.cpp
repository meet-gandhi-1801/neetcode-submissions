class MinStack {

private:
    int global_min;
    vector<pair<int,int>> s;
public:
    MinStack() {
        global_min = 1e9;
    }
    
    void push(int val) {
        if(global_min == 1e9) global_min = val;
        s.push_back({val,global_min});
        global_min = min(global_min,val);
    }
    
    void pop() {
        auto p = s.back();
        if(p.first == global_min) global_min = p.second;
        s.pop_back();
        if(s.size() == 0) global_min =1e9;
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return global_min;
    }
};
