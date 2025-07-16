class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    int maximumLength(vector<int>& nums) {
        int even = nums[0]%2==0, odd = nums[0]%2==1, alt = 1;
        bool wasEven = nums[0]%2==0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]%2){
                odd++;
                if(wasEven){
                    wasEven = !wasEven;
                    alt++;
                }

            }
            else{
                even++;
                if(!wasEven){
                    wasEven = !wasEven;
                    alt++;
                }
            }
        }
        return max(alt, max(even, odd));
    }
};