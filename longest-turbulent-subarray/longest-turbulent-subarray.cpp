class Solution {

public:
    int maxTurbulenceSize(vector<int>& arr) {
            
            int n=arr.size();
            int ans=0;
            
            for(int i=0,cnt=0;i<n-1;i++,cnt*=-1 ){
                    
                    if(arr[i]>arr[i+1]) cnt = cnt>0 ? cnt+1 : 1;
                    else if(arr[i]<arr[i+1]) cnt = cnt<0 ? cnt-1 : -1;
                    else cnt=0;
                    ans=max(ans,abs(cnt));
            }
            return ans+1;
           
    }
};