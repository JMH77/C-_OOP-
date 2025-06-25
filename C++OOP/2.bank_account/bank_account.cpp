#include<iostream>
#include<string>
#include<vector>
using namespace std;

//交易类 - 记录每笔交易的详细信息
class Transaction {
private:
double amount; //交易金额
string type;   //交易类型（存款或者取款）

public:
       //构造函数 - 初始化交易金额和类型
       Transaction(double amount, const string &type)
             :amount(amount) , type(type) {}

       //显示交易信息
       void display() const {
            cout << type << ":" << (type == "Deposit" ? "+" : "-")
            << amount << endl; 
       }

};


class BankAccount {
private:
       string accountHolder;   //账户持有人姓名
       double balance;         //账户余额
       vector<Transaction> transactions; //账户交易记录

public:
       BankAccount(const string &accountHolder , double initBalance = 0)
               :accountHolder(accountHolder) , balance(initBalance) {}
               
       //存款功能
       void deposit(double amount) {
        if(amount > 0){
            balance += amount;
            transactions.emplace_back(amount , "Deposit");//记录本次交易
            cout << "存款成功" << amount << endl;
        } else {
            cout << "存款金额须为正数！" << endl;
        }
       }

       //取款功能
       void withdraw(double amount) {
        if(amount > 0 && balance >= amount) {
            balance -= amount;
            transactions.emplace_back(amount , "Withdrawal");//记录本次交易
            cout << "取款成功" << amount << endl;
        } else if(amount <= 0) {
            cout << "取款失败：金额无效！" << endl;
        } else {
            cout << "取款失败：余额不足！" << endl;
        }
       }

       //显示当前账户余额
       void displayBalance() const {
        cout << "账户持有人：" << accountHolder << endl;
        cout << "账户余额" << balance << endl;
       }

       //显示历史交易记录
       void displayTransactionHistory() const {
        cout << "历史交易记录：" << endl;
        for(const auto& transaction : transactions) {
            transaction.display(); //调用Transaction类的显示方法
        }
       }
};


int main(){
    BankAccount account1("张三", 1574.67);

    //显示账户信息
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