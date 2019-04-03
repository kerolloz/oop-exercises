class Time{

int hours, min, second;

public:
    Time() : hours(0), min(0), second(0) {}
    Time(int h, int m, int sec){
        this->hours = h;
        this->min = m; 
        this->second = second;
    }

    void Display() const {
        cout << hours << ":" << min << ":" << second << endl; 
    }

    void Add(Time t1, Time t2){
        int H, M, S;
        H = M = S = 0;

        M += (t1.second + t2.second) / 60;
        S += (t1.second + t2.second) % 60;

        H += (t1.min + t2.min) / 60;
        M += (t1.min + t2.min) % 60;

        H += t1.hours + t2.hours;
    
        this->hours = H, this->min = M, this->second = S;
    }
};
