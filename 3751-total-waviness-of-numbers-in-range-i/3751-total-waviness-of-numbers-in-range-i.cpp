class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for (int i = num1; i <= num2; i++) {
            if (i < 101) {
                continue;
            }
            string t = to_string(i);

            for (int j = 1; j < t.length()-1; j++) {
                if ((t[j] > t[j-1] && t[j] > t[j+1]) || (t[j] < t[j-1] && t[j] < t[j+1])) waviness++;
            }
        }

        return waviness;
    }
};