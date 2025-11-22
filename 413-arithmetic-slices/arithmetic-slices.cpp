class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int len = 0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                if(len==0) {
                    cnt++;
                    len = 3;
                }
                else{
                    len++;
                    cnt+=(len-2);
                }
            }
            else len = 0;
        }
        return cnt;
    }
};