class Solution {
    // TC : O(N)
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int cur_sum = 0;
        int res = INT_MIN;
        for(int num : nums){
            if(st.find(num)==st.end()){
                res = max(res, cur_sum + num);
                if(num>0) cur_sum += num; 
                st.insert(num);
            }
        }
        return res;
    }
};