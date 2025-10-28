class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        int cnt = 0;
        vector<int>pre(n+1), suff(n+1);
        for(int i=0;i<n;i++){
            pre[i+1]  += pre[i] + nums[i]; 
        }
        for(int i=n-1;i>=0;i--){
            suff[i] += suff[i+1] + nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(pre[i+1]==suff[i]) cnt+=2;
                else if(abs(pre[i+1]-suff[i]) == 1) cnt++;
            }
        }
        return cnt;
    }
};