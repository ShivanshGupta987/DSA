class Solution {
    bool isChar(char ch){
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch<='9' && ch>='0');
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
       
        while(i<j){
            while(i<n && !isChar(s[i]))i++;
            while(j>=0 && !isChar(s[j]))j--;
            if(i<j && tolower(s[i])!=tolower(s[j])) return false;
            i++, j--;
        }
        return true;
    }
};