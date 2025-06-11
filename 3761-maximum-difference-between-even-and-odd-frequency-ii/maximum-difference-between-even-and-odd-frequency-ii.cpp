class Solution {
    int get_status(int a, int b){
        return ((a%2)*2) + (b%2);
    }
public:
    int maxDifference(string s, int k) {
        
        int n = s.size();
        int ans = INT_MIN;
        

        
        for(char char_a='0'; char_a<'5'; char_a++){
            for(char char_b='0'; char_b<'5'; char_b++){
                if(char_a==char_b) continue;
                
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                vector<int>min_prev_diff(4, INT_MAX);
               
                for(int right=0; right<n; right++){

                    if(s[right]==char_a) cnt_a++;
                    if(s[right]==char_b) cnt_b++;

                    while(right-left>=k && cnt_b-prev_b>=2){

                        int prev_status = get_status(prev_a, prev_b);
                        min_prev_diff[prev_status] = min(min_prev_diff[prev_status], prev_a - prev_b);

                        left++;
                        if(s[left]==char_a) prev_a++;
                        if(s[left]==char_b) prev_b++;
                    }

                    // if(right>=k-1){
                        int current_status = get_status(cnt_a, cnt_b);
                        int target_status = current_status ^ 2;
                        if(min_prev_diff[target_status]!=INT_MAX) ans = max(ans, (cnt_a-cnt_b) - min_prev_diff[target_status]);
                    // }
                }
            }
        }
        return ans;


    }
};