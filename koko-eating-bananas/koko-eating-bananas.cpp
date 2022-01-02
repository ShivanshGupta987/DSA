class Solution {
       // TC: O(log(max(piles)))
private:
    bool isPossible(vector<int>& piles,int n,int h){
            int count=0;
            for(auto x:piles){
                    count+=(x%n)?(x/n)+1:x/n;
                    if(count>h)return false;
            }
            return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
            
            int l=1;
            int r=0;
            
            for(auto x:piles)r=max(r,x);
            
            while(l<r){
                    int mid=l+(r-l)/2;
                   if(isPossible(piles,mid,h))r=mid;
                   else l=mid+1;
            }
            return l;
        
    }
};