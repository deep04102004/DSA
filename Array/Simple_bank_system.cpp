//2043. Simple Bank System

#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    vector<long long> bal;  // stores balances of each account

public:
    // Constructor
    Bank(vector<long long>& balance) {
        bal = balance;
    }
    
    // Transfer money from account1 to account2
    bool transfer(int account1, int account2, long long money) {
        if (account1 > bal.size() || account2 > bal.size() || bal[account1 - 1] < money) {
            return false;
        }
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }
    
    // Deposit money into an account
    bool deposit(int account, long long money) {
        if (account > bal.size()) {
            return false;
        }
        bal[account - 1] += money;
        return true;
    }
    
    // Withdraw money from an account
    bool withdraw(int account, long long money) {
        if (account > bal.size() || bal[account - 1] < money) {
            return false;
        }
        bal[account - 1] -= money;
        return true;
    }

    // Utility function to print all balances
    void printBalances() {
        cout << "Account balances: ";
        for (auto b : bal) cout << b << " ";
        cout << endl;
    }
};

int main() {
    vector<long long> balance = {100, 200, 300, 400, 500};

    Bank* bank = new Bank(balance);

    cout << boolalpha;

    cout << "Transfer 1->2 (50): " << bank->transfer(1, 2, 50) << endl;   // true
    cout << "Withdraw 3 (100): " << bank->withdraw(3, 100) << endl;       // true
    cout << "Deposit 5 (500): " << bank->deposit(5, 500) << endl;         // true
    cout << "Transfer invalid (1->6): " << bank->transfer(1, 6, 100) << endl; // false
    cout << "Withdraw invalid (4, 1000): " << bank->withdraw(4, 1000) << endl; // false

    bank->printBalances();

    delete bank; // free memory
    return 0;
}
