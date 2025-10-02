#include<bits/stdc++.h>
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string res="";
                while(st.top()!='['){
                    res = st.top()+res;
                    st.pop();
                }
                st.pop();
                string digit="";
                while(!st.empty() && isdigit(st.top())){
                    digit = st.top()+digit;
                    st.pop();
                    
                }
                int dig = stoi(digit);
                while(dig--){
                    for(int j=0;j<res.size();j++){
                        st.push(res[j]);
                    }
                }

            }
            else{
                st.push(s[i]);
            }
        }

        string result="";

        while(!st.empty()){
            result = st.top()+result;
            st.pop();
        }
        return result;



























        // stack<char> st;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]==']'){
                
        //         string res="";
        //         while(st.top()!='['){
        //             res = st.top()+res;
        //             st.pop();
        //         }
        //         st.pop();
        //         string digit="";
        //         while(!st.empty() && isdigit(st.top())){
        //             digit = st.top()+digit;
        //             st.pop();
        //         }
        //         int dig = stoi(digit);
        //         while(dig--){
        //             for(int q=0;q<res.size();q++){
        //                 st.push(res[q]);
        //             }
                    
        //         }

        //     }
        //     else{
                

        //         st.push(s[i]);
                
        //     }


        // }
        // string result;
        // while(!st.empty()){
        //     result = st.top() + result;
        //     st.pop();
        // }
        // return result;




















        // stack<char> st;
        // string res = "";
        // for(int i=0;i<s.length();i++){
        //     string decode = "";
        //     if(s[i]==']'){
        //         while(st.top()!='['){
        //             decode = st.top() + decode;
        //             st.pop();

        //         }
        //         st.pop();
        //         string digit = "";
        //         while(!st.empty() && isdigit(st.top())){
        //             digit = st.top() + digit;
        //             st.pop();
        //         }
        //         int num = std::stoi(digit);
                
        //         while(num--){
        //         for(int j=0;j<decode.length();j++){
        //             st.push(decode[j]);
        //         }
        //         }
        //     }
        //     else{
        //         st.push(s[i]);
        //     }
        // }

        // while(!st.empty()){
        //     res = st.top() + res;
        //     st.pop();
        // }
        // return res;
    }
};