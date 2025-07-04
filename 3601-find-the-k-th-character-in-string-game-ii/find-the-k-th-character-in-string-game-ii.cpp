class Solution {
    // TC : O(log2 k)
    int get_ops(long long k){
        int cnt = 0;
        long long len = 1;
        while((len<<1) <= k){
            len <<= 1;
            cnt++;
        }
        return cnt;
    }
public:
    char kthCharacter(long long k, vector<int>& operations) {
        
        int cnt = 0;
        // int cur_len = 1<<times;
        long long pos = k;
        int times;
        while(pos > 1){
            times = get_ops(pos);
            if((1ll << times) == pos) times--;
            pos -= (1ll << times);
            if(operations[times]) cnt++;
            
        }
        return 'a' + (cnt%26);
    }
};