'''6. Create  a  class  "BankAccount"  with  attributes  account  number  and  balance.  Implement 
methods to deposit and withdraw funds, and a display method to show the account details.'''

class BankAccount:
    def __init__(self, acc_no, balance=0.0):
        self.acc_no = acc_no
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited: ${amount}. New Balance: ${self.balance}")
        else:
            print("Deposit amount must be positive.")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            print(f"Withdrawn: ${amount}. New Balance: ${self.balance}")
        else:
            print("Invalid withdrawal amount or insufficient funds.")

    def display(self):
        print(f"Account Number: {self.acc_no}, Balance: ${self.balance}")

# Example Usage
acc = BankAccount(101, 500)
acc.deposit(200)
acc.withdraw(100)
acc.display()
