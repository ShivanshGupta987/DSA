class Solution {
    // TC : O(n log n * 10^m)
    // SC : O(n * 10^m)
    // m : floor((n+1)/2)
public:
    long long countGoodIntegers(int n, int k) {
        long long ans = 0;
        int base = pow(10, (n-1)/2);
        int skip = n&1;
        unordered_set<string>dict;
        for(int i = base; i<base*10; i++){
            string s = to_string(i);
            s += string(s.rbegin()+skip, s.rend());
            long long palindromeInteger = stoll(s);
            if(palindromeInteger%k==0){
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }

        vector<long long>fact(n+1,1);
        for(int i=2;i<=n;i++){
            fact[i] = i*fact[i-1];
        }
        for(const string &s : dict){
            vector<int>cnt(10);
            for(auto ch : s){
                cnt[ch-'0']++;
            }
            long long total = (n-cnt[0])*fact[n-1];
            for(int x : cnt){
                total /= fact[x];
            } 
            ans += total;
        }
        return ans;
    }
};