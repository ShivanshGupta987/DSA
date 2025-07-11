# define pli pair<long long,int>
// TC : O(n* log n)
// SC : O(n)
class comp{
    public:
    bool operator()(const pli &p1, const pli &p2){
        return p2.first < p1.first || (p1.first == p2.first && p2.second < p1.second);
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());

        // hashmap for cnt no. of times a room is used
        vector<int>cnt(n,0);

        // pair<end_time, room_no>  ---- min heap 
        priority_queue<pli, vector<pli>, comp>pq_meets;
        // int<free_room_no>  ------- min heap 
        priority_queue<int, vector<int>, greater<int>>free_rooms;

        for(int i=0;i<n;i++){
            free_rooms.push(i);
        }
        
        for(int i=0;i<m;i++){
            int start = meetings[i][0], end = meetings[i][1];
            while(!pq_meets.empty() && pq_meets.top().first <= start){
                int room =pq_meets.top().second; 
                free_rooms.push(room);
                pq_meets.pop();
            }

            if(free_rooms.empty()){
                long long last_meet_end_time =  pq_meets.top().first;
                int room = pq_meets.top().second;
                pq_meets.pop();
                pq_meets.push({last_meet_end_time + end - start, room});
                cnt[room]++;
            }
            else {
                int room = free_rooms.top();
                free_rooms.pop();
                pq_meets.push({end ,room});
                cnt[room]++;
            }
            
        }

        int max_cnt_room_idx = 0;
        int max_cnt = cnt[0];
        for(int i=1;i<n;i++){
            if(cnt[i] > max_cnt){
                max_cnt_room_idx = i;
                max_cnt = cnt[i];
            }
        }
    
        return max_cnt_room_idx;
    }
};