class Solution {
public:
    bool judgeCircle(string s) {
        return ((count(s.begin(), s.end(), 'L')==count(s.begin(), s.end(), 'R')) == (count(s.begin(), s.end(), 'U')==count(s.begin(), s.end(), 'D'))) ;
    }
};