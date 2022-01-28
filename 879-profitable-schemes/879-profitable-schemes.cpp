class Solution {
        #define _mem_(i,j,k)      mem[(i*(n+1)+j)*(mp+1)+k]
        #define mod 1000000007
        int n;
        int mp;
        vector<int>gp;
        vector<int>p;
        int *mem;
        // gm-> no. of group members currently 
        // cp-> current profit
        int dp(int i,int gm,int cp){
              if(gm>n)return 0;
              if(i==gp.size())return cp==mp;
              
              if(_mem_(i,gm,cp)!=-1)return _mem_(i,gm,cp);
             
uint64_t skipCurrentCrime = dp(i+1,gm,cp);
uint64_t takeCurrentCrime = dp(i+1,gp[i]+gm,min(mp,cp+p[i]));
                
                uint64_t res = (skipCurrentCrime + takeCurrentCrime)%mod;
                _mem_(i,gm,cp)=res;
                return res;
        }
        
public:
    int profitableSchemes(int n, int mp, vector<int>& group, vector<int>& profit) {
       this->n=n;
       this->mp=mp;
       gp=group;
       p=profit;
       int numCrimes=group.size();
       int memsize=(numCrimes+1)*(n+1)*(mp+1);
        
        mem = new int[memsize];
        memset(mem,-1,sizeof(int)*memsize);
        return dp(0,0,0);
            
            
    }
};








// Brute Force
// TC: 2^N
// N->group.size()
// class Solution {
      
// public:
        
//         int rec(int min_p,vector<int>&group,vector<int>&profit,int i,int p,int gm, int G){
//                 if(i==group.size() && gm<=G)return p>=min_p?1:0;
//                 if(gm>G)return 0;
//          return rec(min_p,group,profit,i+1,p+profit[i],gm+group[i],G)+
//                  rec(min_p,group,profit,i+1,p,gm,G);
                
//         }
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
  
//       return rec(minProfit,group,profit,0,0,0,n);      
//     }
// };