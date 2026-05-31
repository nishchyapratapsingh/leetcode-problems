class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long t = mass;

        for (int ast: asteroids) {
            if (t >= ast) {
                t += ast;
            }
            else return false;
        }

        return true;
    }
};