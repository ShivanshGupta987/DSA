
class Solution {
    // TC : O((MAX_DAYS + N) log N)
    // SC : O(N)
    static bool comp( vector<int>& a, vector<int>& b){
        return (a[0] < b[0]) || (a[0]==b[0] && a[1] < b[1]);
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), comp);
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int maxDay = 0;
        for(int i=0;i<n;i++){
            maxDay = max(maxDay, events[i][1]);
        }
        int i = 0;
        for(int day=1; day<=maxDay; day++){
            while(i<n && events[i][0] <= day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < day)pq.pop();
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
        }
        return ans;
        
    }
};