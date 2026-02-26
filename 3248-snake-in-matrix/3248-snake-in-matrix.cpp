class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0;
        int j = 0;

       for (string str : commands) {
            if (str == "UP") {
                i--;
            }
            else if (str == "RIGHT") {
                j++;
            }
            else if (str == "DOWN") {
                i++;
            }
            else if (str == "LEFT") {
                j--;
            }
        }

        return (i*n) + j;
    }
};