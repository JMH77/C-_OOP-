#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

class Date {
private:
      int year;
      int month;
      int day;

public:
    //���캯��
    Date(int y = 1970, int m = 1, int day = 1) 
       : year(y) , month(m), day(day) {
        normalize();
       }
    
    //��������
    void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
        normalize();
    }

    //�ж��Ƿ�Ϊ����
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    //�ж�һ�������뵱ǰ������������
    int daysFromCurrentDate() const {
        time_t now = time(nullptr);
        tm* currentTime = localtime(&now);const 

        //������ǰ���ڶ���
        Date currentDate(currentTime -> tm_year + 1900,
                         currentTime -> tm_mon + 1,
                         currentTime -> tm_mday
                                               );

        return daysBetween(*this, currentDate);
    }

    //������������֮���������
    static int daysBetween(const Date& d1, const Date& d2) {
        int days1 = dateToDays(d1.year, d1.month, d1.day);
        int days2 = dateToDays(d2.year, d2.month, d2.day);

        return abs(days1 - days2);
    }
    
    // ������������ <<
    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.year << "-" << date.month << "-" << date.day;
        return os;
    }

private:
      //������ת��Ϊ�������ӹ�Ԫ1��1��1����
      static int dateToDays(int year, int month, int day) {
        if (month < 3) {
            month += 12;
            year--;
        }
        
        int days = 365 * year + year / 4 - year / 100 + year / 400 
                  + 306 * (month + 1) / 10 + day - 429;
        
        return days; 
      }
     
      void normalize() {
        if (month < 1) month = 1;
        if (month > 12) month = 12;

        int dayInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear()) dayInMonth[1] = 29;

        if (day < 1) day = 1;
        if (day > dayInMonth[month-1]) day = dayInMonth[month-1];
      }
};

int main() {

    // �������ڶ���
    Date birthDate(2000, 1, 1);
    
    // �������
    std::cout << "����: " << birthDate << std::endl;
    
    // �ж�����
    if (birthDate.isLeapYear()) {
        std::cout << "������" << std::endl;
    } else {
        std::cout << "��������" << std::endl;
    }
    
    // �����뵱ǰ������������
    int days = birthDate.daysFromCurrentDate();
    std::cout << "�������: " << days << " ��" << std::endl;

    system("pause");
    return 0;
}


//������� isLeapYear()���ֲ�δ�������������ֻ���ж�����������������Ƿ�Ϊ����