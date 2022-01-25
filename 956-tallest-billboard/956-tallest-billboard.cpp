// // DP 
// class Solution {
        
// // Basically here we are dealing with difference of left beam and right beam instead of length of left beam and right beam
        
// //         Notation  :  dp[d]
                
// //       here dp[d] represents  length of the maximum possible smaller rod that we can have when len(left beam - right beam)==d
// //                 let us say dp[d]=y
                
// //                 Visual representation 
                
// //                        y
// //  left beam           --------
// // right beam          |--------|-------
// //                         y        d
                
// // Initially we are assuming we have no rod hence dp[0]=0
// //           Now we are going to add a rod of  length x
                
// //                 Case 1:   Adding the rod into the bigger beam
        
// //                       y
// //  left beam           --------
// // right beam          |--------|------------
// //                         y        d+x
                    
// //            Hence dp[d+x]=max(dp[d+x],y)    
                        
// //                 Case 2:   Adding the rod into the smaller beam  and d>=x
        
// //                       y         x
// //  left beam           --------|----|
// // right beam          |--------|-------
// //                         y        d
                    
// //            Hence dp[d-x]=max(dp[d-x],y+x) 
                        
                        
// //                  Case 3:   Adding the rod into the smaller beam  and d<=x
        
// //                       y         x
// //  left beam           --------|-----------|
// // right beam          |--------|-------
// //                         y        d
                    
// //            Hence dp[x-d]=max(dp[x-d],y+d)
                
// public:
//     int tallestBillboard(vector<int>& rods) {
//         unordered_map<int,int>dp;
//             dp[0]=0;
//          for(auto x: rods){
//                  unordered_map<int,int>cur(dp);
                 
//                  for(auto it: cur){
//                          int d=it.first;
                         
//                          dp[d+x]=max(dp[d+x],cur[d]);
//                          dp[abs(d-x)]= max(dp[abs(d-x)],cur[d]+min(d,x));
//                  }
//          }   
//             return dp[0];
//     }
// };

// // class Solution {
        
// //         // Brute Force + Purning
// //         private: int maxx=0;
       
// //      void rec(vector<int>& rods, int bkt1,int bkt2,int remain, int i){
             
// //              if(bkt1==bkt2)maxx=max(maxx,bkt1);
             
// //              if(i==rods.size())return;
             
// //             if(bkt1 + bkt2 + remain<=2*maxx || abs(bkt1-bkt2)>remain)return;
// //              if(bkt1==bkt2 && remain==0)return;
          
// //                   rec(rods,bkt1+rods[i],bkt2,remain-rods[i],i+1);
                          
// //              rec(rods,bkt1,bkt2+rods[i],remain-rods[i],i+1);
             
// //              rec(rods,bkt1,bkt2,remain,i+1);
             

// //      }   
// // public:
// //     int tallestBillboard(vector<int>& rods) {
// //             int sum=0;
// //             for(auto x: rods)sum+=x;
// //             rec(rods,0,0,sum,0);
// //         return maxx;
// //     }
// // };


// // Brute Force
// // class Solution {
       
// //      int  rec(vector<int>& rods, int bkt1,int bkt2, int i){
             
// //              if(i==rods.size())return bkt1==bkt2?bkt1:0;
             
// //           return max({
// //                   rec(rods,bkt1+rods[i],bkt2,i+1),
                          
// //              rec(rods,bkt1,bkt2+rods[i],i+1),
             
// //              rec(rods,bkt1,bkt2,i+1)
// //                       })   ;
             

// //      }   
// // public:
// //     int tallestBillboard(vector<int>& rods) {
// //            return rec(rods,0,0,0);
        
// //     }
// // };

class Solution{
   public: 
        int dfs(vector<int>& rs, int i, int s1, int s2, int m_sum, vector<vector<int>> &m) {
  if (s1 > m_sum || s2 > m_sum) return -1;
  if (i >= rs.size()) return s1 == s2 ? s1 : -1;
  if (m[i][abs(s1 - s2)] == -2) {
    m[i][abs(s1 - s2)] = max(-1, max({ dfs(rs, i + 1, s1, s2, m_sum, m),
      dfs(rs, i + 1, s1 + rs[i], s2, m_sum, m), dfs(rs, i + 1, s1, s2 + rs[i], m_sum, m) }) - max(s1, s2));
  }
  return m[i][abs(s1 - s2)] + (m[i][abs(s1 - s2)] == -1 ? 0 : max(s1, s2));
}
int tallestBillboard(vector<int>& rods) {
  int m_sum = accumulate(begin(rods), end(rods), 0) / 2;
  vector<vector<int>> m(rods.size(), vector<int>(m_sum + 1, -2));
  return max(0, dfs(rods, 0, 0, 0, m_sum, m));
}
};
