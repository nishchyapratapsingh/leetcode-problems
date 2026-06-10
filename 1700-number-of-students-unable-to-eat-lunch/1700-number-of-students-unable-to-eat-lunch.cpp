class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular = 0, square = 0;

        for (int s : students) {
            if (s == 0)
                circular++;
            else
                square++;
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (circular == 0)
                    return square + circular;
                circular--;
            } else {
                if (square == 0)
                    return square + circular;
                square--;
            }
        }

        return 0;
    }
};