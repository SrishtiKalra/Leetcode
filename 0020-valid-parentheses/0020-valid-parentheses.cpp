class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;
        int i = 0;

        unordered_map<char,char> mp = {
            {'}','{'},
            {']', '['},
            {')', '('}
        };

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                st.push(s[i]);
            }
            else{

                if(!st.empty() && st.top()==mp[s[i]]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(!st.empty()){
            return false;
        }

        return true;
        
    }
};