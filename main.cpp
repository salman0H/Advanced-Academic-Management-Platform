#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>

using namespace std;

///----------------------------------------------------------------------------------------------------------------------
class date {
    friend bool happy_birthday(date, date);

    friend istream &operator>>(istream &in, date &obj);

    friend ostream &operator<<(ostream &out, date &obj);

public:
    date(const date &obj) {
        day = obj.day;
        month = obj.month;
        year = obj.year;
    }

    date(int, int, int);

    date() {
        day = 0;
        month = 0;
        year = 0;
    }

    /*~date()
    {
        displayinfo();
        cout <<endl << "this is date detructor man!"<<endl;
    }*/
    void setdate(int, int, int);

    int getday() {
        return day;
    }

    int getmonth() {
        return month;
    }

    int getyear() {
        return year;
    }

    void displayinfo() {
        cout << endl << "time you enter : "
             << day << '/' << month << '/' << year << endl;
    }

    date operator++(int) {
        date temp(day, month, year);
        if (month > 0 && month < 7) {
            if (day == 31) {
                day = 1;
                month++;
            } else {
                day++;
            }
        } else if (month > 6 && month < 12) {
            if (day == 30) {
                day = 1;
                month++;
            } else {
                day++;
            }
        } else if (month == 12) {
            if (day == 29) {
                day = 1;
                month = 1;
                year++;
            } else {
                day++;
            }
        }
        return temp;
    }

    date operator--(int) {
        date temp(day, month, year);
        if (month > 0 && month < 7) {
            if (month == 1) {
                if (day == 1) {
                    day = 29;
                    month = 12;
                    year--;
                }
            } else if (day == 1) {
                day = 31;
                month--;
            } else {
                day--;
            }
        } else if (month > 6 && month < 12) {
            if (day == 1) {
                day = 30;
                month--;
            } else {
                day--;
            }
        }
        return temp;
    }

    /*date &operator +(date &after,int &up)
    {
        if(after.month > 0 && after.month < 7)
        {
            if( ( after.day + up )> 32)
            {
                after.day = ( ( after.day + up ) - 31 );
                after.month += 1;
            }else
            {
                after.day += up;
            }
        }else if(after.month > 6 && after.month < 12)
        {
            if( ( after.day + up )> 31)
            {
                after.day = ((after.day + up)-30);
                after.month += 1;
            }else
            {
                after.day += up;
            }
        }else if(after.month == 12)
        {
            if ((after.day + up) > 30) {
                after.day = ((after.day + up) - 29);
                after.month = 1;
            } else {
                after.day += up;
            }
        }
        return after(day,month,year);
    }*/
    date operator+(int up) {
        if (month > 0 && month < 7) {
            if ((day + up) > 32) {
                day = ((day + up) - 31);
                month += 1;
            } else {
                day += up;
            }
        } else if (month > 6 && month < 12) {
            if ((day + up) > 31) {
                day = ((day + up) - 30);
                month += 1;
            } else {
                day += up;
            }
        } else if (month == 12) {
            if ((day + up) > 30) {
                day = ((day + up) - 29);
                month = 1;
                year++;
            } else {
                day += up;
            }
        }
        return date(day, month, year);
    }

    date operator-(int down) {

        if (month > 1 && month < 7) {
            if (month == 1) {
                if ((day - down) < 0) {
                    day = ((day - down) + 31);
                    month = 12;
                    year--;
                }
            }
            if ((day - down) < 0) {
                day = ((day - down) + 31);
                month -= 1;
            } else {
                day -= down;
            }
        } else if (month > 6 && month < 12) {
            if ((day - down) < 0) {
                day = ((day - down) + 30);
                month -= 1;
            } else {
                day -= down;
            }
        } else if (month == 12) {
            if ((day - down) < 0) {
                day = ((day - down) + 29);
                month -= 1;
            } else {
                day -= down;
            }
        }
        return date(day, month, year);
    }

private:
    int day;
    int month;
    int year;
    int days_of_month[13] = {0, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31};
};

///----------------------------------------------------------------------------------------------------------------------
date::date(int _d, int _m, int _y) {
    setdate(_d, _m, _y);
}

void date::setdate(int _day, int _month, int _year) {
    if (_year > 0) {
        year = _year;
    } else {
        year = 1402;
    }

    if (_month > 0 && _month < 13) {
        month = _month;
    } else {
        month = 1;
    }

    if (_day > 0 && _day <= days_of_month[month]) {
        day = _day;
    } else {
        day = 1;
    }
}

bool happy_birthday(date a, date b) {
    if (a.day == b.day && a.month == b.month) {
        return true;
    }
    return false;
}

istream &operator>>(istream &in, date &obj) {
    cout << "\nenter day:";
    in >> obj.day;
    cout << "\nenter month:";
    in >> obj.month;
    cout << "\nenter year:";
    in >> obj.year;
    return in;
}

ostream &operator<<(ostream &out, date &obj) {
    out << endl << obj.day << '/' << obj.month << '/' << obj.year << endl;
    return out;
}

///----------------------------------------------------------------------------------------------------------------------
class student {
    friend istream &operator>>(istream &in, student &obj);
    friend ostream &operator<<(ostream &out, student &obj);

public:

    student( string _name = "not defined", date _info = date(1, 1, 1402), long long int _self_id = 111) {
        name = "";
        birthday = date();
        self_id = 01;
    }

    /*~student()
    {
        displayinf();
        cout <<endl<< "this is  student destructor!"<<endl;
    }*/
    void setname(string);
    void setbirthday(int, int, int);
    void setself_id(long long int);

    string getname() {
        return name;
    }

    date getbirthday() {
        return birthday;
    }

    long long int getself_id() {
        return self_id;
    }

    void displayinf() {
        cout << endl << name << " time of this : ";
        birthday.displayinfo();
        cout << endl;
    }

private:
    string name;
    date birthday;
    long long int self_id;
};

///----------------------------------------------------------------------------------------------------------------------
void student::setbirthday(int _day, int _month, int _year) {
    birthday.setdate(_day, _month, _year);
}

void student::setname(std::string __name) {
    name = __name;
}

void student::setself_id(long long int id) {
    self_id = id;
}

istream &operator>>(istream &in, student &obj) {
    cout << "enter a name: ";
    in >> obj.name;
    cout << "enter your birthday: ";
    in >> obj.birthday;
    cout << "\nenter student id: ";
    in >> obj.self_id;
    return in;
}

ostream &operator<<(ostream &out, student &obj) {
    out << endl << "your name: " << obj.name << endl << "your birthday: " << obj.birthday << endl;
    return out;
}

///----------------------------------------------------------------------------------------------------------------------
class info_student : public student {
    friend istream &operator>>(istream &in, info_student &obj);
    friend ostream &operator<<(ostream &out, info_student &obj);

public:
    info_student()
    {

    }
    info_student(float _avg = 1, date _enter = date(1, 7, 1401), date _out = date(1, 4, 1406),
                 int _vahed = 136,long long int _id = 0,string _name = "") : student(_name,_enter,_id)
    {
        avg = _avg;
        enter = date(_enter);
        out = date(_out);
        vahed = _vahed;
    }

    /*~info_student()
    {
        displayinf();
        cout << "info student detructor!";
    }*/
    void setavg(float _avg) {
        avg = _avg;
    }

    void setenter(date _enter) {
        enter = date(_enter);
    }

    void setout(date _out) {
        out = date(_out);
    }

    void setvahed(int _vahed) {
        vahed = _vahed;
    }

    float getavg() {
        return avg;
    }

    int getvahed() {
        return vahed;
    }

    date getenter() {
        return enter;
    }

    date getout() {
        return out;
    }

    long int duration(date e, date o) {
        long int year;
        year = o.getyear() - e.getyear();
        if (year < 0) {
            year = (-1) * year;
        }
        year *= 365;
        long int month;
        month = o.getmonth() - e.getmonth();
        if (month < 0) {
            month = (-1) * month;
        }
        month = month * 30;
        long int day;
        day = o.getday() - e.getday();
        if (day < 0) {
            day = (-1) * day;
        }
        long int all;
        all = day + month + day;
        return all;
    }

    void educational(float score) {
        if (score > 17) {
            cout << " Great! ";
        } else if (17 > score && score >= 12) {
            cout << " Pass! ";
        } else if (score < 12) {
            cout << " Fail! ";
        }
    }

    void show() {
        student :: displayinf();
        cout << "\nYear of University entrance : " << enter <<
             "\nThe year of exit : " << out <<
             "\nDuration of study : " << duration(enter, out) <<
             "\nEducational status : " << avg << " so ";
        educational(avg);
    }

private:
    float avg;
    date enter;
    date out;
    int vahed;

};

///----------------------------------------------------------------------------------------------------------------------
istream &operator>>(istream &in, info_student &obj) {
    cout << "Enter your score: ";
    in >> obj.avg;
    cout << "Enter your number of vahed in university: ";
    in >> obj.vahed;
    cout << "Enter your enter time: ";
    in >> obj.enter;
    cout << "Enter your out time: ";
    in >> obj.out;
    cout << "Enter self id: ";
    long long int id;
    in >> id;
    obj.setself_id(id);
    cout << "Enter name: ";
    string name;
    in >> name;
    obj.setname(name);

    return in;
}

ostream &operator<<(ostream &out, info_student &obj) {
    //obj.displayinf();
    obj.show();
    return out;
}
//----------------------------------------------------------------------------------------------------------------------
/*class master : public student{
public:
    master(string _lesson = "nothing",student _name_master = student, int _vahed_st = 1)
    {
        lesson = _lesson;
        name_master = student(_name_master);
        vahed_st = _vahed_st;
    }
private:
    string lesson;
    student name_master;
    int vahed_st;


};*/
///----------------------------------------------------------------------------------------------------------------------
int main() {
    cout << "this program test for date class and have another class in this code\n\n";
    cout << "enter a day you like, like today : \n";
    date today;
    cin >> today;
    int number_person;
    cout << "\nenter number of your student: \n";
    cin >> number_person;
    student person[number_person];
    for (int i = 0; i < number_person; i++) {
        cin >> person[i];
    }
    for (int i = 0; i < number_person; i++) {
        if (happy_birthday(today, person[i].getbirthday())) {
            cout << "\nHappy Birthday!\t" << person[i].getname() << endl;
        }
    }
    for (int i = 0; i > -1; i++) {
        int num;
        cout << "\t\tselect your operator:\n"
                "\t1.operator ++ enter number 1\n"
                "\t2.operator -- enter number 2\n";
        cin >> num;
        if (num == 1) {
            today++;
            cout << endl << "\ttest for operator ++: " << today << endl;
            system("Color 0A");
            break;
        } else if (num == 2) {
            today--;
            cout << endl << "\ttest for operator --: " << today << endl;
            system("color 0C");
            break;
        }
    }
    for (int i = 0; i < 120; i++) {
        cout << "+";
    }
    for (int i = 0; i > -1; i++) {
        int num;
        int number;
        cout << "\n\t\tselect your operator:\n"
                "\t3.operator + enter number 3\n"
                "\t4.operator - enter number 4\n";
        cin >> num;
        cout << "\n\tafter select your number for computing: \n";
        cin >> number;
        if (num == 3) {
            today = today + number;
            cout << endl << "\ttest for operator + : " << today << endl;
            system("color 2F");
            break;
        } else if (num == 4) {
            today = today - number;
            cout << endl << "\ttest for operator - : " << today << endl;
            system("color 4F");
            break;
        }
    }
    for (int i = 0; i < 120; i++) {
        cout << "+";
    }
    cout << endl;
    /*
    info_student() student[number_person];
    for (int i = 0; i < number_person; i++) {
        cin >> student[i];
    }
    for (int i = 0; i < number_person; i++) {
        cout << student[i];
    }

    /*date today;
    cin >> today;

    student person;
    cin >> person;

    info_student one;
    cin >> one;

    cout << today;
    cout << person;
    cout << one;*/
    return 0;
}
