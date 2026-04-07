class Robot {
    int x, y;
    int row, col;
    int dir;
    int peri;
public:
    Robot(int width, int height) {
        row = height-1;
        col = width-1;
        dir = 0;
        x=0, y=0;
        peri = 2*(row+col);
    }
    
    void step(int num) {

        num %= peri;

        if(num == 0 && x == 0 && y == 0) {
            dir = 3;
            return;
        }

        while(num--) {
            if(dir == 0) {
                if(x + 1 < col+1) x++;
                else {
                    dir = 1;
                    y++;
                }
            }
            else if(dir == 1) {
                if(y + 1 < row+1) y++;
                else {
                    dir = 2;
                    x--;
                }
            }
            else if(dir == 2) {
                if(x - 1 >= 0) x--;
                else {
                    dir = 3;
                    y--;
                }
            }
            else { 
                if(y - 1 >= 0) y--;
                else {
                    dir = 0;
                    x++;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        switch(dir) {
            case 0:
                return "East";
            case 1:
                return "North";
            case 2:
                return "West";
            case 3:
                return "South";
        }
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, row+1);
 * obj->step(tocover);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */