// class Solution {
// public:
//         int mod= 1e9+7;
//         int ans=1;
//         void backtrack(int ind,int prod, int n){
//                 if(ind==n){ans=max(ans,prod);return;}                
//                 for(int i=ind;i<n;i++){
//                   backtrack(i+1,(prod*(i-ind+1))%mod,n);
//                 }
//         }
//     int maxNiceDivisors(int primeFactors) {
//             int n=primeFactors;
           
//                 backtrack(0,1,n);
           
//         return ans;
//     }
     
// };

// class Solution{
//   public:
//         long long int  mod=1e9+7;
//         long long int ans=1;
//             int maxNiceDivisors(int primeFactors) {
//             int n=primeFactors;
            
//             while(n!=0){
//                if(n==7){ans=(ans*12)%mod;n=0;}
//                if(n==5){ ans=(ans*6)%mod;n=0;}
//                 if(n==4){ans=(ans*4)%mod;n=0;}
//                  if(n==3){ans=(ans*3)%mod;n=0;}
//                 if(n==2){ans=(ans*2)%mod;n=0;}
//                 if(n==1){ans=(ans*1)%mod;n=0;}
//                  if(n>=6){ans=(ans*9)%mod;n-=6;}

//             }
           
//         return ans;
//     }
// };
//
class Solution{
  public:
        const long long int  mod=1e9+7;
        long long int ans=1;
        
        long long int modExpo(long long int x,long long int n){
                if(n==0)return 1;
                if(n&1)return (x*modExpo((x*x)%mod,n>>1))%mod;
                else return (modExpo((x*x)%mod,n>>1))%mod;
                
        }
         
            int maxNiceDivisors(int primeFactors) {
            int n=primeFactors;
            // ans=modExpo(3,n/3);
            // if(n%3==1)ans=(ans/3)<<2;
            // if(n%3==2)ans=ans<<1;
            if(n==1)return 1;
            if(n%3==0)ans=modExpo(3,n/3);
            if(n%3==1)ans=modExpo(3,(n-4)/3)<<2;
            if(n%3==2)ans=modExpo(3,(n-2)/3)<<1;      
                    
            
           
        return ans%mod;
    }
};
