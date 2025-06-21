class Solution {
    // TC : O(WORD.SIZE)
    // SC : O(1)
public:
    int minimumDeletions(string word, int k) {
        int cnt[26];
        memset(cnt, 0, sizeof (cnt));

        for(int i=0;word[i];i++){
            cnt[word[i]-'a']++;
        }
        vector<int>arr;
        for(auto & x : cnt){
            if(x)arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int m = arr.size();

        vector<int>pre(m+1);
        for(int i=1;i<=m;i++){
            pre[i] = pre[i-1] + arr[i-1];
        }

        int total = pre[m];
        int ans = total;
        int j = 0;
        for(int i=0;i<m;i++){
            while(j<m && arr[j]-arr[i]<=k){
                j++;
            }
            int x = total;
            x -= (pre[j]-pre[i]);
            x -= (m-j)*(arr[i]+k);
            // ans = min(ans, (total-(pre[j]-pre[i]) - ((m-j)*(arr[i]+k))) );
            ans = min(ans, x);
        
            // cout<<"----"<<i<<"--------\n";
            // cout<<total<<" "<<pre[j]-pre[i]<<" "<<((m-j)*(arr[i]+k))<<" "<<ans<<"\n";
            
        }
        return ans;
    }
};