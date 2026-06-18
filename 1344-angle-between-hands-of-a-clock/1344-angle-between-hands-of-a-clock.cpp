class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrAngle = hour*30 + minutes/2.0;
        double minAngle = minutes*6;

        double btwAngle = abs(hrAngle - minAngle);
        return min(btwAngle, 360-btwAngle);
    }
};