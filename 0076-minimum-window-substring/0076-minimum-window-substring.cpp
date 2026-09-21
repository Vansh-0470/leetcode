// so the imp thing is too handle extra duplicates so we need the req counter which was not possible with map size that was used in other same pattern 
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        vector<bool> tchar(128, false);

        for(int i = 0; i < t.length(); i++) {
            m[t[i]]++;
            tchar[t[i]] = true;
        }

        int i = 0;
        int j = 0;
        int length = INT_MAX;
        int strtidx = -1;
        int required_count = t.length();

        while(j < s.length()) {

            if(tchar[s[j]]) {
                if(m[s[j]] > 0) {
                    required_count--;
                }
                m[s[j]]--;
            }

            while(required_count == 0) {

                if(j - i + 1 < length) {
                    length = j - i + 1;
                    strtidx = i;
                }

                if(tchar[s[i]]) {
                    m[s[i]]++;

                    if(m[s[i]] > 0) {
                        required_count++;
                    }
                }

                i++;
            }

            j++;
        }

        if(length == INT_MAX)
            return "";

        return s.substr(strtidx, length);
    }
};