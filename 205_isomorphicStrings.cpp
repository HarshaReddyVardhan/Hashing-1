// Time -- O(n) -- N-- length of the string
// Space -- O(1) -- As there are only a Constant Number of ASCII Character -- Max of 256


// Approach : store the mapping in separate maps to check if they are mapped properly

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smap,tmap;
        int sl = s.size(),tl = t.size();
        if(sl != tl) return false;
        for(int i =0 ;i<sl;++i){
            if(smap.find(s[i]) == smap.end()){
                smap[s[i]] = t[i];
            }
            else{
                if(smap[s[i]] != t[i]) return false;
            }

            if(tmap.find(t[i]) == tmap.end()){
                tmap[t[i]] = s[i];
            }
            else{
                if(tmap[t[i]] != s[i]) return false;
            }
        }
        
        return true;
    }
};
