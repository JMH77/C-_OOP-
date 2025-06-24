#include<iostream>
#include<cstdlib>
using namespace std;

// 矩形类定义
class Rectangle {
private:
    double length;  // 矩形的长
    double width;   // 矩形的宽

public:
    // 构造函数：初始化矩形的长和宽
    Rectangle(double l = 0, double w = 0) : length(l), width(w) {
        cout << "创建矩形对象: 长=" << length << ", 宽=" << width << endl;
    }

    // 析构函数：对象销毁时调用
    ~Rectangle(){
        cout << "销毁矩形对象: 长=" << length << ", 宽=" << width << endl;
    }

    void setLength(double l){
        if(l > 0) length = l;
        else cout << "矩形长度应为正数！" << endl;
    }
    
    void setWidth(double w){
        if(w > 0) width = w;
        else cout << "矩形宽度应为正数！" << endl;
    }   

    //计算矩形面积
    double area(){
        return length * width;
    }

    //计算矩形周长
    double perimeter(){
        return 2 * (length + width);
    }

    void display(){
        cout << "矩形基本信息:" << endl <<
        "长：" << length << "，宽：" << width << endl <<
        "面积：" << area() << "，周长：" << perimeter() << endl;
    }

};

// 主函数：测试Rectangle类
int main() {
    Rectangle r1(5,3);
    r1.display();
    cout << endl;
    
    Rectangle r2;
    r2.display();
    cout << endl;
    r2.setLength(10);
    r2.setWidth(6);
    r2.display();
    cout << endl;

    r1.setLength(7);
    r1.setWidth(2);
    cout << "修改之后 --";
    r1.display();
    cout << endl;

    r1.setLength(-5);
    r2.setWidth(0);
    
    system("pause");
    return 0;
}   


