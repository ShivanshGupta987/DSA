class Solution {
       
private: 
        unordered_map<long long,int>mp1;
        unordered_map<long long,int>mp2;
        
        void backtrack1(int ind,vector<int>& nums1,int size,long long prod){
                if(size==2){
                        mp1[prod]++;
                        return;
                }
                for(int i=ind;i<nums1.size();i++){    
                        backtrack1(i+1,nums1,size+1,prod*nums1[i]);
                }
        }
        void backtrack2(int ind,vector<int>& nums2,int size,long long prod){
                if(size==2){
                        mp2[prod]++;
                        return;
                }
                for(int i=ind;i<nums2.size();i++){    
                        backtrack2(i+1,nums2,size+1,prod*nums2[i]);
                }
        }
        
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
            int ans=0;
            backtrack1(0,nums1,0,1);
            backtrack2(0,nums2,0,1);
            for(unsigned long int x:nums1){
                    unsigned long num=x*x;
                    if(mp2.count(num))ans+=mp2[num];
            }
            for(unsigned long int x:nums2){
                    unsigned long num =x*x;
                    if(mp1.count(num))ans+=mp1[num];
            }
            return ans;
            
        
    }
};