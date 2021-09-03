
class Point
{
private:
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    double getDistance(Point& P2) {
        return sqrt((this->x - P2.x) * (this->x - P2.x) + (this->y - P2.y) * (this->y - P2.y));
    }	  
};

