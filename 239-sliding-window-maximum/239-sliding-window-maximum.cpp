class Solution {
    // TC : (n*log(n))
    // SC : O(k)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // max heap to store to max element in the current window on the top
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            // push the current element of the window
            pq.push({nums[i],i});
            
            // pop all the elements that don't belong to the current window
            // current window [i-k+1,i]
            
            while(pq.top().second < i-k+1){
                pq.pop();
            }
            
            res.push_back(pq.top().first);
        }
        return res;
        
        
    }
};