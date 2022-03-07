class Solution {
        // TC : O(N)
        // SC : O(N)
        #define pii pair<int,int>
public:
    int minTaps(int n, vector<int>& ranges) {
        
            vector<pii>input;
            
            for(int i=0;i<=n;i++){
                    input.push_back(pii(max(0,i-ranges[i]), min(n,i+ranges[i])));
            }
                           
            sort(input.begin(),input.end(),[](const pii a,const pii b){return a.first > b.first; });
            
            int open = 0;
            int currentReach = 0;
            while(!input.empty()){
                    // a gap where no shower can reach
                    if(input.back().first > currentReach) return -1;
               
                    open++; // now at this point one tap will definitely exist which will cover the some portion afterwards currentReach 
                    
                    int nextReach = currentReach;
                    
                    while(!input.empty() && input.back().first<=currentReach){
                            nextReach = max(nextReach, input.back().second);
                            
                            if(nextReach==n) return open;
                            
                            input.pop_back();
                    }
                    
                    currentReach = nextReach;
            }
                                    
            return open;
    }
};





// class Solution {
//         // TC : O(N*R)  // R : 0 <= ranges[i] <= 100
//         // SC : O(N)
        
//         const int MAX = 1e5;
        
// public:
//     int minTaps(int n, vector<int>& ranges) {
        
          
//             vector<int>dp(n+1,MAX);
//             dp[0]=0;
            
//             for(int i=0;i<=n;i++){
//                     for(int j= max(0,i-ranges[i]+1); j<= min(n,i+ranges[i]);j++){
//                             dp[j] = min(dp[j], dp[max(0,i-ranges[i])] +1);
//                     }
//             }
            
//             return dp[n]== MAX ? -1 : dp[n];
//     }
// };


// class Solution {
//        // Worst case -  TC : O(N*N)
//       // BEST CASE - TC : omega(N)
        
//         // SC : O(1)
// public:
//     int minTaps(int n, vector<int>& ranges) {
//             int  minn = 0;
//             int maxx=0;
//             int open = 0;
//             int index = 0;
            
//             while(maxx<n){
//                     for(int i=index;i<ranges.size();i++){
//                             if(i-ranges[i]<=minn && i+ranges[i]>maxx){
//                                     maxx = i+ranges[i];
//                                     index = i;
//                             }
//                     }
//                     if(minn == maxx) return -1;
//                     open++;
//                     minn = maxx;
//             }
//           return open;
//     }
// };




// class Solution {
//         // Brute Force
//         // TC : O(N*N)
//         // SC : O(N)
        
// const int MAX = 100000;
        
// public:
//     int minTaps(int n, vector<int>& ranges) {
        
//             vector<int>dp(n+1,MAX);
            
//             // dp[i] -> minimum no. of taps to be open for watering till ith position
//             dp[0]=0;
//             for(int i=1;i<=n;i++){
//                     for(int j=0;j<=i;j++){
//                     if(j+ranges[j]>=i ) dp[i] = min( dp[max(0,j-ranges[j])] +1, dp[i]);     
//                     }
                   
//             }
            
//             return dp[n] == MAX ? -1 : dp[n]; 
//     }
// };