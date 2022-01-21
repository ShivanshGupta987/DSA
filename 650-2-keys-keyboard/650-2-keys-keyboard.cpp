class Solution {
        // TC: O(N^2)
        // SC: O(N)
        
public:
    int mem[1001]={[0 ... 1000]=0};
    int minSteps(int n) {
            if(n==1)return 0;
            if(mem[n]!=0)return mem[n];
        
            for(int i=0;i<1001;i++)mem[i]=i;

            mem[0]=mem[1]=0;
           for(int i=2;i<1001;i++){
                   int minn=mem[i];
                   for(int j=2;j<=34;j++){
                           if(i%j==0){
                                   minn=min(minn,mem[i/j]+ j);
                                   break;
                           }
                          
                   }
                   mem[i]=minn;
           }
            return mem[n];
    }
        
        
};