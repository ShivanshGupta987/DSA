class Solution {
        // TC : O(N)
        // SC : O(1)
        // Top - Down Dp
    #define ll long long
    const ll mod  = 1e9 + 7;
    unordered_map<string,int>mp;
public:
        Solution(){
                 mp["**"] = 15;
                 mp["*0"] = 2;
                 mp["*1"] = 2;
                 mp["*2"] = 2;
                 mp["*3"] = 2;
                 mp["*4"] = 2;
                 mp["*5"] = 2;
                 mp["*6"] = 2;
                 mp["*7"] = 1;
                 mp["*8"] = 1;
                 mp["*9"] = 1;
                 mp["1*"] = 9;
                 mp["2*"] = 6;
        }
public:
    int numDecodings(string s) {
          int n=s.size();
          ll ans = 0;
          ll first = 1 , second = 0;  
            
          for(int i=n-1;i>=0;i--){
             if(s[i]=='0') {
                ans=0;  second = first; first = 0; continue;
             }
             ans = ( (s[i]=='*'?9:1)*first) % mod;
             
             if(i<n-1){
                     string key = s.substr(i,2);
                     cout<<key<<" ";
                     if(mp.find(key)!=mp.end()) ans = (ans + mp[key]*second)% mod;
                     else {
                             int num = stoi(s.substr(i,2));
                             if(num>9 && num<27) ans = (ans + second) % mod;
                     }
             } 
            second = first; first = ans; 
          }
         return (int)ans;
    }
};









//  Memory Limit Exceeded

// class Solution {
//         // TC : O(N)
//         // SC : O(N)
//   #define ll long long       
//         const ll mod = 1e9 + 7;
        
//     ll helper(string s, int i, vector<int>& memo){
//       int n=s.size(); 
//       if(i==n)return 1ll;
       
//       if(memo[i]!=-1) return memo[i];
//       if(s[i]=='0')return memo[i]=0;
            
//       ll ans = 0;
//       if(s[i]=='*'){
//            ans =  (ans + 9ll*helper(s,i+1,memo)) % mod;
//            if(i<n-1 && s[i+1]=='*') ans =(ans + 15ll* helper(s,i+2,memo))% mod;
          
//            else if(i<n-1 && s[i+1]<='6') ans = (ans + 2ll* helper(s,i+2,memo) ) % mod;
//            else if(i<n-1) ans = (ans + helper(s,i+2,memo) ) % mod;
           
//       }
//       else {
//               ans = (ans + helper(s,i+1,memo))%mod ;
              
//               if(i<n-1 && s[i+1]=='*'){
//                       if(s[i]=='1')   ans = (ans + 9ll* helper(s,i+2,memo))%mod ;
//                       else if(s[i]=='2')  ans = (ans +  6ll*helper(s,i+2,memo))%mod ;
//               }
//               else if(i<n-1) {
//                       int num = stoi(s.substr(i,2));
//                       if(num>9 && num<27)  ans = (ans + helper(s,i+2,memo))%mod ;
//               }
              
//       }
//             return memo[i]=ans;
      
//     }
// public:
//     int numDecodings(string s) {
//       vector<int>memo(s.size()+1,-1);
          
//       return (int)helper(s,0,memo);  
//     }
// };