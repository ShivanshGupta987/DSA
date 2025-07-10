class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {
        int n = st.size();

        vector<int>gaps;
        gaps.push_back(st[0]);
        for(int i=1;i<n;i++){
            gaps.push_back(st[i]-et[i-1]);
        }
        gaps.push_back(eventTime-et.back());
        
        
        vector<int>largestRight(gaps.size(),0);
        for(int i=gaps.size()-2; i>=0; i--){
            largestRight[i] = max(largestRight[i+1], gaps[i+1]);
        }

        int ans = 0, largestLeft = 0;

        for(int i=1; i<gaps.size();i++){
            int meetTime = et[i-1] - st[i-1];
            if(meetTime <= max(largestLeft, largestRight[i])) ans = max(ans, gaps[i-1]+gaps[i]+meetTime);
            ans = max(ans, gaps[i]+gaps[i-1]);
            largestLeft = max(largestLeft, gaps[i-1]);
        }
        
        return ans;
    }
};