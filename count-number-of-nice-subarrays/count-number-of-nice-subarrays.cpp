class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     int ans=0;
            int curr_odd=0;
            vector<int>odd;
            for(int i=0;i<nums.size();i++){
                    if(nums[i]&1)odd.push_back(i);
            }
            int j=0;
            int l=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&1)curr_odd++;
                if(curr_odd==k){ans+=(odd[j]-l+1);}
                if(curr_odd==k+1){
                        curr_odd--;
                        l=odd[j]+1;
                        j++;
                        ans+=(odd[j]-l+1);
                }
                
            }
            return ans;
    }
};          