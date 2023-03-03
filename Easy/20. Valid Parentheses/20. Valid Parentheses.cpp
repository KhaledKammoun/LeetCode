class Solution {
public:
    bool isValid(string s) {
        stack<char>stc ;
        
        for (int i = 0 ; i<s.size() ;i++){
            if (!stc.empty() && ((s[i] == '}' && stc.top() == '{') || 
                                 (s[i] == ')' && stc.top() == '(') || 
                                 (s[i] == ']' && stc.top() == '[')))
                stc.pop() ;
            else 
                stc.push(s[i]) ;
            
        }
        return stc.empty() ;
    }
};