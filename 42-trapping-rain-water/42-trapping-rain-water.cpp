class Solution {
//      main objective is to find out the water trapped over the single bar hence we need to find out the left closest largest bar and right closest largest bar and the water trapped over that bar will be given by distance*bounded_height

// where the distance = right_largest_ind - left_largest_ind -1
//  and  bounded_height = min(h[right_largest_ind],h[left_largest_ind]) - h[current]
    
// TC : O(N)
public:
    int trap(vector<int>& h) {
        int ans = 0;
        int rli = 0; // index of the left nearest largest bar
        stack<int>st;
        while(rli<h.size()){
            while(st.size() && h[rli]>h[st.top()]){
                int current = st.top();
                st.pop();
//              if left_bound does not exist
                if(st.empty())break;
                int lli = st.top(); // index of the right closest largest bar
                int distance = rli - lli -1;
                int bounded_height = min(h[lli],h[rli]) - h[current];
                ans += distance*bounded_height;
            }
            st.push(rli);
            rli++;
        }
        return ans;
        
        
    }
};