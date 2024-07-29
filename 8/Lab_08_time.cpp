#include <iostream>
using namespace std;
class Time
{
    public:
        Time() : hours{0},mins{0},sec{0}
        {
            cout << "Class has been created" << endl;
        }
        Time(int h, int m, int s)
        {
            cout << "Class has been created" << endl;
            if (s > 59)
            {
                int buf = s / 60;
                m += buf;
                s = s % 60;
            }
            if (m > 59)
            {
                int buf = m / 60;
                h += buf;
                m = m % 60;
            }
            cout << "sec "<< s << endl;
            cout << "min " << m << endl;
            cout << "hours  " << h << endl;
            Setsec(s);
            Setmins(m);
            Sethours(h);
        }
        void Sethours(int h)
        {
            h = hours;
        }
        void Setmins(int m)
        {
            m = mins;
        }
        void Setsec(int s)
        {
            s = sec;
        }
        int Gethours()
        {
            return hours;
        }
        int Getmin()
        {
            return mins;
        }
        int Getsec()
        {
            return sec;
        }
        void Printtime()
        {
	        cout << hours << " : " << mins << " : " << sec << '\n';
        }
        Time Addtime(Time b)
        {
            Time t;
            int temp_sec{0}, temp_min{ 0 }, temp_hour{ 0 };
            temp_sec = sec + b.Getsec();
            if (temp_sec > 59)
            {
                int buf = temp_sec / 60;
                temp_min += buf;
                temp_sec = temp_sec % 60;
            }
            temp_min += mins + b.Getmin();
            if (temp_min > 59)
            {
                int buf = temp_min / 60;
                temp_hour += buf;
                temp_min = temp_min % 60;
            }
            temp_hour += hours + b.Gethours();
            t.Setsec(temp_sec);
            t.Setmins(temp_min);
            t.Sethours(temp_hour);
            return t;

        }
    private:
    	int hours;
    	int mins;
    	int sec;
};

int main()
{
    Time t1 = Time(20,1,5);
    Time t2 = Time(1, 62, 5);
    Time t3 = Time();
    t1.Printtime();
    t2.Printtime();
    t3 = t1.Addtime(t2);
    t3.Printtime();
}





