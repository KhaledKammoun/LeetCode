class Solution {
public:
    int binaryGap(int N) {
        int max_gap = 0;
        int current_gap = 0;
        while (N > 0) {
            if ((N & 1) == 0) {
                current_gap++;
            } else {
                if (current_gap != 0) {
                    max_gap = max(max_gap, current_gap);
                    current_gap = 0;
                }

            }
            N >>= 1;
        }
        return max_gap ;
    }
};