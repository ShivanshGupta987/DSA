class Solution {
    int cnt[501];
public:
    int findLucky(vector<int>& arr) {
        memset(cnt, 0, sizeof(cnt));
        int n = arr.size();
        int mx = arr[0];
        for(int i=0;i<n;i++){
            cnt[arr[i]]++;
            mx = max(mx, arr[i]);
        }
        for(int i=mx; i>=1;i--){
            if(i==cnt[i]) return i;
        }
        return -1;
    }
};