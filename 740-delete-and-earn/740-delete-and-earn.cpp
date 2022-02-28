class Solution {
   // TC : O(N)  // N -> maximum element in array
   // SC : O(1)
  
public:
    int deleteAndEarn(vector<int>& nums) {
      int maxx = *max_element(nums.begin(),nums.end());
      int  n = nums.size();      
      vector<int> inc(maxx+1), // inc[i] -> max points when ith element included
      exc(maxx+1) ; // exc[i] -> represents max points if ith element is excluded
       
      vector<int>table(maxx+1,0);  
      for(auto num : nums) table[num]++;

      inc[0]= 0; exc[0]=0;
      for(int i=1;i<=maxx;i++){
         inc[i] = exc[i-1] + i*table[i];
         exc[i] = max(inc[i-1], exc[i-1]);
      }
            return max(inc[maxx],exc[maxx]);
    }
};