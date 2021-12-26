class Solution {
public:
        // TC: O(N Log(N))
        // SC:O(N)
    int longestSubarray(vector<int>& nums, int limit) {
         
//             int l=0,r=0;   
//             multiset<int>ms;
//             for(r=0;r<nums.size();r++){
//                    ms.insert(nums[r]);
//                    if(*ms.rbegin()-*ms.begin()>limit)ms.erase(ms.find(nums[l++])); 
//             }
            
//             return r-l;
            
            deque<int>maxd;
            deque<int>mind;
            int i=0,j;
            
            for(j=0;j<nums.size();j++){
                    while(!maxd.empty() && nums[j]>maxd.back()) maxd.pop_back();
                    while(!mind.empty() && nums[j]<mind.back()) mind.pop_back();
                    
                    maxd.push_back(nums[j]);
                    mind.push_back(nums[j]);
                    
                    if(maxd.front()-mind.front()>limit){
                            if(maxd.front()==nums[i])maxd.pop_front();
                            if(mind.front()==nums[i])mind.pop_front();
                            i++;
                            
                    }
            }
            
            
           return j-i;
    }
};

// Logic behind the problem 
   
//  when we encoutered with the valid subarray(let us say x elements) further we are    //  going to consider valid subarray of greater of length of previous elements. That's  //  why we are incresing index of right end of the window countinuously. Here, the main //  beauty lies.
