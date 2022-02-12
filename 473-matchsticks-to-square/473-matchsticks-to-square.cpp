// TC: O(4^N)
// SC: O(N)
class Solution {
        
        int lar=0; // length of the largest possible matchstick
        vector<int>sums; // to store current length of sides 
       
        bool dfs(vector<int>& ms,int ind ){
                if(ind==ms.size())
                return sums[0]==sums[1]&& sums[1]==sums[2] && sums[2]==sums[3];
                
                int element=ms[ind];
                
                for(int i=0;i<4;i++){
                        if(sums[i]+element<=lar)
                        {
                           sums[i]+=element;
                           if(dfs(ms,ind+1))return true;
                           sums[i]-=element;
                        }
                }
                return false;
                
        }   
public:
    bool makesquare(vector<int>& ms) {
            
            int sum = accumulate(ms.begin(),ms.end(),0); 
            if(sum %4!=0)return false;
            sort(ms.begin(),ms.end(),greater<int>()); 
            sums.resize(4);
            lar=sum/4;
            return dfs(ms,0);
           
    }
};