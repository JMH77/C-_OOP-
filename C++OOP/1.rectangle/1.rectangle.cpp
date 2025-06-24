#include<iostream>
#include<cstdlib>
using namespace std;

// �����ඨ��
class Rectangle {
private:
    double length;  // ���εĳ�
    double width;   // ���εĿ�

public:
    // ���캯������ʼ�����εĳ��Ϳ�
    Rectangle(double l = 0, double w = 0) : length(l), width(w) {
        cout << "�������ζ���: ��=" << length << ", ��=" << width << endl;
    }

    // ������������������ʱ����
    ~Rectangle(){
        cout << "���پ��ζ���: ��=" << length << ", ��=" << width << endl;
    }

    void setLength(double l){
        if(l > 0) length = l;
        else cout << "���γ���ӦΪ������" << endl;
    }
    
    void setWidth(double w){
        if(w > 0) width = w;
        else cout << "���ο��ӦΪ������" << endl;
    }   

    //����������
    double area(){
        return length * width;
    }

    //��������ܳ�
    double perimeter(){
        return 2 * (length + width);
    }

    void display(){
        cout << "���λ�����Ϣ:" << endl <<
        "����" << length << "����" << width << endl <<
        "�����" << area() << "���ܳ���" << perimeter() << endl;
    }

};

// ������������Rectangle��
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
    cout << "�޸�֮�� --";
    r1.display();
    cout << endl;

    r1.setLength(-5);
    r2.setWidth(0);
    
    system("pause");
    return 0;
}   


