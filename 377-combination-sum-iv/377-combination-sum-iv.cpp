class Solution {
        
        // TC : O(Target*Length(nums))
public:
    int combinationSum4(vector<int>& nums, int target) {
             
            int N = target;
            vector<unsigned int>res(N+1);
            res[0]=1;
            
            for(int i=0;i<=N;i++){
                    for(int num : nums){
                            if(i>=num){
                                    res[i]+=res[i-num];
                            }
                    }
            }
            return res[N];
    }
};