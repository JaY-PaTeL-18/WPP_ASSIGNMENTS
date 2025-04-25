#include<stdio.h>
#include<stdlib.h>

struct BankMgmt {
    int AccNumber;
    char* CustName;
    int AvlBalance;
    char* AccType;
};

void withdrawal(struct BankMgmt* member, int amt) {
    if (member->AvlBalance<amt) printf("You haven't enough balance!");
    else
    {
        member->AvlBalance -= amt;
        printf("Withdrawal Successfully");
    }
    printf("\n");
}

void diposit(struct BankMgmt* member, int amt) {
    member->AvlBalance += amt;
    printf("Amount diposited successfully!\n");
}

void display_balance(struct BankMgmt member) {
    printf("Your available balance is %d\n", member.AvlBalance);
}

int main() {
    struct BankMgmt member = {100155, "VenkatKrishna", 4500, "Saving"};
    while(1) {
        int option;
        printf("Enter the option: ");
        scanf("%d", &option);
        int amt_withdrawal;
        int amt_diposited;
        switch (option)
        {
        case 1:
            printf("Enter the amount you want to withdrawal: ");
            scanf("%d", &amt_withdrawal);
            withdrawal(&member, amt_withdrawal);
            break;
        case 2:
            printf("Enter the amount you want to diposit: ");
            scanf("%d", &amt_diposited);
            diposit(&member, amt_diposited);
            break;
        case 3:
            display_balance(member);
            break;
        case 4:
            exit(0);
        
        default:
            break;
        }
    }

    return 0;
}