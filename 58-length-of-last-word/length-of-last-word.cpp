class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while(i >= 0 && !isalnum(s[i])){
            i--;
        }
        int counter = 0;
        while(i >= 0 && s[i] != ' '){
            counter++;
            i--;
        }
        return counter;
    }
};