class Solution {
public:
    vector<int> process(string needle, int n) {
        vector<int> lps(n);
        
        int i = 0, j = 1;
        while (i<n && j<n) {
            if (needle[i] == needle[j]) {
                lps[j] = i+1;
                i++;
                j++;
            }else {
                if (i == 0) {
                    lps[j] = 0;
                     j++;
                }else{
                    i = lps[i-1];        
                }
            }
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        int ans = -1;
        
        vector<int> temp = process(needle, len2);
        needle.insert(needle.begin(), 0);
        temp.insert(temp.begin(), 0);
        
        int i = 0, j = 0;
        
        for (int it : temp) {
            cout << it << " ";
        }
        
        while (i < len1 && j < len2) {
            if (haystack[i] == needle[j+1]) {
                i++;
                j++;
            }else {
                if (j==0) {
                    i++;
                }else{
                    j = temp[j];  
                }
                              
            }
        }
        
        if (j == len2) {
            ans = i-j;
        }       
        
        return ans;
    }
};
