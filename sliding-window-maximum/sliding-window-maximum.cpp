class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            // TC : O(N)
            // SC : O(K)
        deque<int>dq;
            vector<int>res;
         int n=nums.size();   
            for(int i=0;i<n;i++){
                    if(!dq.empty() && i-dq.front()==k)dq.pop_front();
                    while(!dq.empty() && nums[dq.back()]<=nums[i])dq.pop_back();
                    if( dq.empty() || nums[i]<nums[dq.back()] )dq.push_back(i);
                    if(i>=k-1)res.push_back(nums[dq.front()]);
            }
            return res;
    }
};