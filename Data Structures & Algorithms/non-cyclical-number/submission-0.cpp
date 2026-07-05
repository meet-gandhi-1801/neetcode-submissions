class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> s;
        while(1)
        {
        
            int sum = 0;

            int a = n;
            while(a)
            {
                int t = a%10;
                a /= 10;
                sum += t*t; 
            }
            if(sum == 1) return true;

            n = sum;
            if(s.find(n) != s.end()) break;
            s.insert(n);
        }
        return false;
        
    }
};
