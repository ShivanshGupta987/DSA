class Solution {
        private:
        bool isPossible(vector<int>&q,int num,int n){
                int count=0;
               for(auto x:q){
                      count+= (x+num-1)/num;
                       if(count>n)return true;
               } 
                return false;
        }
public:
    int minimizedMaximum(int n, vector<int>& q) {
            
            // TC: O(m log(100000))
            //  m -> q.size()
          
        int low=1;
         int high=100000;
            while(low<high){
             int mid=(low+high)/2;
                    if(isPossible(q,mid,n)){
                          low=mid+1;
                    }
                    else high=mid;
            }
            
            return low;
    }
};