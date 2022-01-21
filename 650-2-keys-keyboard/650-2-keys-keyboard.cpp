class Solution {
        // TC: O(N^2)
        // SC: O(N)
        
public:
    int mem[1001];
    int minSteps(int n) {
            if(n==1)return 0;
            
            if(mem[n]!=0)return mem[n];
        
            for(int i=0;i<1001;i++)mem[i]=i;

            mem[0]=mem[1]=0;
           for(int i=2;i<1001;i++){
                   
                   if(isPrime(i)){
                          continue;
                   }
                   
                   
                   for(int j=2;j<=34;j++){
                           if(i%j==0){
                                  mem[i]=mem[i/j]+ j;
                                   break;
                           }
                          
                   }
                
           }
            return mem[n];
    }
        bool isPrime(int n){
                int primes[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
                for(int i=0;i<11;i++){
                        if(primes[i]==n)return true;
                }
                return false;
        }
        
        
};