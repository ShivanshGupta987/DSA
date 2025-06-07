# define pci pair<char,int>

class comp{
    public:
    // As we know either we are designing min heap or max heap the
    // top element is stored at higher index
    // Since we are designing min heap so think like that p2 is an 
    // element at higher index and p1 is an element at lower index
    // so overload comparator acc to what you need the property of 
    // element at higher index/top element.
        bool operator()(const pci& p1, const pci& p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            else return p1.first > p2.first;
        }
};
// TC : O(N log N)
// SC : O(N)
class Solution {
public:
    string clearStars(string s) {
        
        priority_queue<pci, vector<pci>, comp>pq;
        int n = s.size();
        vector<bool>deleted(n,false);


        for(int i=0;i<n;i++){
            if(s[i]!='*') {
                pq.push({s[i], i});
                continue;
            }
            int ind = pq.top().second;
            pq.pop();
            deleted[ind] = true;
        }
        string res="";
        for(int i=0;i<n;i++){
            if(deleted[i] || s[i]=='*') continue;
            res += s[i];
        }
        return res;
    }
};