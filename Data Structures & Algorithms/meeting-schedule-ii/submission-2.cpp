/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& in) {
         sort(in.begin(), in.end(),
             [](const Interval &a, const Interval &b) {
                 return a.start < b.start;
             });
        if(in.size() == 0) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(in[0].end);
        int ans = 1;
        for (int i = 1; i < in.size(); i++) {
            if (pq.top() > in[i].start)
                ans++;
            else
                pq.pop();
            pq.push(in[i].end);
        }
        return pq.size();
    }
};
