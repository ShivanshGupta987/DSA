class Solution {
        // TC: O(N^2)
        // SC: O(N)
public:
    int minSteps(int n) {
        vector<int>mem(n+1,0);
            for(int i=0;i<n+1;i++)mem[i]=i;
            mem[1]=0;
            mem[0]=mem[1]=0;
           for(int i=2;i<n+1;i++){
                   int minn=mem[i];
                   for(int j=2;j<=500;j++){
                           if(i%j==0){
                                   minn=min(minn,mem[i/j]+ j);
                                   break;
                           }
                          
                   }
                   mem[i]=minn;
           }
            return mem[n];
    }
        int operations(int a,int b){
                if((b-a)%a==0)return (b/a);
                else return 0;
        }
        
};