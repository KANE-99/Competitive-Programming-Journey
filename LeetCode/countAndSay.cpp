/* https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/ */
class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1) {
            return "1";
        }
        
        string fres="",res = countAndSay(n - 1);
        int len = res.size();
        if (len == 1) {
            return "11";
        }
        
        map<char, int> count;
        
        for (int i=1; i<len; i++) {
            if (res[i] == res[i-1]) {
                count[res[i]]++;
            }else{
                fres += to_string(count[res[i-1]]+1)+res[i-1];
                count[res[i-1]] = 0;
            }
        }
        fres += to_string(count[res[len-1]]+1)+res[len-1];
        return fres;
    }
};
