'''3. Write a Python program to create a class representing a bank. Include methods for managing 
customer accounts and transactions. '''

class BankAccount:
    def __init__(self, acc_no, holder, bal=0.0):
        self.acc_no = acc_no
        self.holder = holder
        self.bal = bal

    def deposit(self, amt):
        if amt > 0:
            self.bal += amt
            print(f"Deposited: ${amt}. New Balance: ${self.bal}")
        else:
            print("Deposit amount must be positive.")

    def withdraw(self, amt):
        if 0 < amt <= self.bal:
            self.bal -= amt
            print(f"Withdrawn: ${amt}. New Balance: ${self.bal}")
        else:
            print("Invalid withdrawal amount or insufficient funds.")

    def get_balance(self):
        print(f"Account Balance: ${self.bal}")
        return self.bal

class Bank:
    def __init__(self, name):
        self.name = name
        self.accts = {}

    def create_account(self, acc_no, holder, init_bal=0.0):
        if acc_no in self.accts:
            print("Account already exists.")
        else:
            self.accts[acc_no] = BankAccount(acc_no, holder, init_bal)
            print(f"Account created for {holder} with balance ${init_bal}")

    def get_account(self, acc_no):
        return self.accts.get(acc_no, None)

    def display_accounts(self):
        print(f"Accounts in {self.name}:")
        for acc_no, acc in self.accts.items():
            print(f"{acc_no}: {acc.holder}, Balance: ${acc.bal}")

# Example Usage
bank = Bank("MyBank")
bank.create_account(101, "Alice", 500)
bank.create_account(102, "Bob", 1000)
bank.display_accounts()

alice_acc = bank.get_account(101)
if alice_acc:
    alice_acc.deposit(200)
    alice_acc.withdraw(100)
    alice_acc.get_balance()
