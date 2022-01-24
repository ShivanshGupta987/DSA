class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
            // TC:O(N)
            // SC: O(N)
            int n=a.size();
        vector<int>swap(n,1);
            vector<int>not_swap(n,0);
            for(int i=1;i<n;i++){
                             swap[i]=not_swap[i]=n;
                            if(a[i-1]<a[i] && b[i-1]<b[i]){
                                 swap[i]=swap[i-1]+1;
                                    not_swap[i]=not_swap[i-1];
                            }
                    
                    
                    if(a[i-1]<b[i] && b[i-1]<a[i]){
                            swap[i]=min(swap[i],not_swap[i-1]+1);
                            not_swap[i]=min(not_swap[i],swap[i-1]);
                    }
            }
            return min(swap[n-1],not_swap[n-1]);
    }
};