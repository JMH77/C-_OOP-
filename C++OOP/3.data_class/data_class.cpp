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
    //构造函数
    Date(int y = 1970, int m = 1, int day = 1) 
       : year(y) , month(m), day(day) {
        normalize();
       }
    
    //设置日期
    void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
        normalize();
    }

    //判断是否为闰年
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    //判断一个日期与当前日期相差的天数
    int daysFromCurrentDate() const {
        time_t now = time(nullptr);
        tm* currentTime = localtime(&now);const 

        //创建当前日期对象
        Date currentDate(currentTime -> tm_year + 1900,
                         currentTime -> tm_mon + 1,
                         currentTime -> tm_mday
                                               );

        return daysBetween(*this, currentDate);
    }

    //计算两个日期之间的天数差
    static int daysBetween(const Date& d1, const Date& d2) {
        int days1 = dateToDays(d1.year, d1.month, d1.day);
        int days2 = dateToDays(d2.year, d2.month, d2.day);

        return abs(days1 - days2);
    }
    
    // 重载输出运算符 <<
    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.year << "-" << date.month << "-" << date.day;
        return os;
    }

private:
      //将日期转换为天数（从公元1年1月1日起）
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

    // 创建日期对象
    Date birthDate(2000, 1, 1);
    
    // 输出日期
    std::cout << "生日: " << birthDate << std::endl;
    
    // 判断闰年
    if (birthDate.isLeapYear()) {
        std::cout << "是闰年" << std::endl;
    } else {
        std::cout << "不是闰年" << std::endl;
    }
    
    // 计算与当前日期相差的天数
    int days = birthDate.daysFromCurrentDate();
    std::cout << "距离今天: " << days << " 天" << std::endl;

    system("pause");
    return 0;
}


//本程序的 isLeapYear()部分并未传入参数，所以只能判断自身这个对象的年份是否为闰年