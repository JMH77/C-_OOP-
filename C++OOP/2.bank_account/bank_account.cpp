#include<iostream>
#include<string>
#include<vector>
using namespace std;

//������ - ��¼ÿ�ʽ��׵���ϸ��Ϣ
class Transaction {
private:
double amount; //���׽��
string type;   //�������ͣ�������ȡ�

public:
       //���캯�� - ��ʼ�����׽�������
       Transaction(double amount, const string &type)
             :amount(amount) , type(type) {}

       //��ʾ������Ϣ
       void display() const {
            cout << type << ":" << (type == "Deposit" ? "+" : "-")
            << amount << endl; 
       }

};


class BankAccount {
private:
       string accountHolder;   //�˻�����������
       double balance;         //�˻����
       vector<Transaction> transactions; //�˻����׼�¼

public:
       BankAccount(const string &accountHolder , double initBalance = 0)
               :accountHolder(accountHolder) , balance(initBalance) {}
               
       //����
       void deposit(double amount) {
        if(amount > 0){
            balance += amount;
            transactions.emplace_back(amount , "Deposit");//��¼���ν���
            cout << "���ɹ�" << amount << endl;
        } else {
            cout << "�������Ϊ������" << endl;
        }
       }

       //ȡ���
       void withdraw(double amount) {
        if(amount > 0 && balance >= amount) {
            balance -= amount;
            transactions.emplace_back(amount , "Withdrawal");//��¼���ν���
            cout << "ȡ��ɹ�" << amount << endl;
        } else if(amount <= 0) {
            cout << "ȡ��ʧ�ܣ������Ч��" << endl;
        } else {
            cout << "ȡ��ʧ�ܣ����㣡" << endl;
        }
       }

       //��ʾ��ǰ�˻����
       void displayBalance() const {
        cout << "�˻������ˣ�" << accountHolder << endl;
        cout << "�˻����" << balance << endl;
       }

       //��ʾ��ʷ���׼�¼
       void displayTransactionHistory() const {
        cout << "��ʷ���׼�¼��" << endl;
        for(const auto& transaction : transactions) {
            transaction.display(); //����Transaction�����ʾ����
        }
       }
};


int main(){
    BankAccount account1("����", 1574.67);

    //��ʾ�˻���Ϣ
    account1.displayBalance();

    account1.deposit(3000);
    account1.withdraw(2745);
    account1.withdraw(10000);
    account1.deposit(5000);

    account1.displayBalance();
    account1.displayTransactionHistory();

    system("pause");
    return 0;
}