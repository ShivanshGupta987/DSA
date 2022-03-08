class Solution {
    int mem[50001];
    int helper(vector<int>& arr, int i ){
            int n = arr.size();
            if(i>=n) return 0;
            else {
                    if(mem[i]!=-1)return mem[i];
                    int ans = INT_MIN;
                    ans = max(ans, arr[i]-helper(arr,i+1));
                    if(i+1<n) ans = max(ans, arr[i]+arr[i+1]-helper(arr,i+2));
                    if(i+2<n) ans = max(ans,arr[i]+arr[i+1]+arr[i+2]-helper(arr,i+3));
                    return mem[i]=ans;
            }
    }
public:
    string stoneGameIII(vector<int>& arr) {
            memset(mem,-1,sizeof(mem));
            int alice = helper(arr,0);
            if(alice>0) return "Alice";
            else if(alice ==0) return "Tie";
            else return "Bob";
    }
};