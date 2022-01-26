class Solution {
    public int tallestBillboard(int[] rods) {
        int dp[]=new int[10001];
        dp[0]=1;
        for(int rod : rods){
            int prevDp[]=dp.clone();
            for(int j=0;j<=10000;j++){
              dp[j]=Math.max(dp[j],j+rod>10000||prevDp[j+rod]==0 ? 0 : prevDp[j+rod]+rod);
              dp[j]=Math.max(dp[j],prevDp[Math.abs(j-rod)]==0 ? 0 : prevDp[Math.abs(j-rod)]+rod);    
            }
        }
        return (dp[0]-1)/2;
    }
}