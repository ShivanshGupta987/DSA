class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long sum = arr[n-1];
        int t=1;
        for(int i=n-2;i>=0 && t<k; i--){
            if(arr[i]-t <= 0) break;
            sum += (arr[i]-t);
            t++;
        }
        return sum;
    }
};