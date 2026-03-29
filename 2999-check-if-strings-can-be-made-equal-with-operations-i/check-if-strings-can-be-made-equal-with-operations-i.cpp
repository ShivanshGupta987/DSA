class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool swap1 = s1[0]==s2[2] && s1[2]==s2[0];
        bool swap2 = s1[1]==s2[3] && s1[3]==s2[1];
        bool p1 = s1[0]==s2[0] && s1[2]==s2[2];
        bool p2 = s1[1]==s2[1] && s1[3]==s2[3];

        return (p1 && p2) || (p1 && swap2) || (swap1 && p2) || (swap1 && swap2);
    }
};