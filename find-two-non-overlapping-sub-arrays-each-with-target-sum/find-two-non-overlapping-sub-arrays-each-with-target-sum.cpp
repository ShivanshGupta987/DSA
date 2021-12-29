class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
       int ans=INT_MAX , n=arr.size(), len=INT_MAX, cur_len=INT_MAX;
            int start=0,end=0;
            int sum=0;
            vector<int>min_len(n,INT_MAX);
            for(end=0;end<n;end++){
                   sum+=arr[end];
                    
                    while(sum>target){
                            sum-=arr[start];
                            start++;
                    }
                    
                    if(target==sum){
                            int cur_len = end-start+1;
                            if(start>0 && min_len[start-1]!=INT_MAX ){
                                    ans=min(ans,min_len[start-1]+cur_len);
                            }
                            len=min(len,cur_len);
                    }
                    min_len[end]=len;
            }
            return ans==INT_MAX?-1:ans;
    }
};