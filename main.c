#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C:\\Users\\Suman\\Desktop\\ProjectBankingSystem\\validation.h"

#define Max 20

struct BankAccount
{
    char bname[50];
    char ifsccode[12];
    char accno[11];
    char accountHolderName[50];
    int age;
    char gender[10];
    char dob[11];
    char address[100];
    char city[50];
    char accounttype[20];
    double balance;
    char pannumber[10];
    char aadhaarnumber[12];
};

char * generateRandomNumber(char name[])
{
    char acno[8];
    acno[0]=name[0];
    acno[1]='\0';
    for(int i=0;i<strlen(name);i++)
    {
        if (name[i] == ' ')
        {
            char ch = name[i+1];
            char s[3] ={ch,'\0'};
            strcat(acno,s);
        }
    }
    char s1[10];

    int set = rand()%900+100;
    sprintf(s1,"%d",set);
    //return acno;
    char* t = strcat(acno,s1);
    // printf("\n%s\n",t);
    return t;
}

struct BankAccount create()
{
    struct BankAccount cus;
    srand(time(NULL));

    printf("Enter the name of the Bank: ");
    fgets(cus.bname, Max, stdin);
    cus.bname[strlen(cus.bname) - 1] = '\0';

    printf("Enter the IFSC code of the Bank: ");
    fgets(cus.ifsccode, Max, stdin);
    cus.ifsccode[strlen(cus.ifsccode) - 1] = '\0';

    printf("Enter the account holder's name: ");
    fgets(cus.accountHolderName, Max, stdin);
    cus.accountHolderName[strlen(cus.accountHolderName) - 1] = '\0';



    char initials[50];
    // extractInitials(initials, cus.accountHolderName);
    strcpy(cus.accno,generateRandomNumber(cus.accountHolderName));
   // snprintf(cus.accno, sizeof(cus.accno), "%s%d", initials, generateRandomNumber(cus.accountHolderName));
    //cus.accno[strlen(cus.accno) - 1] = '\0';

/*
char acno[8];
    acno[0]=cus.accountHolderName[0];
    acno[1]='\0';
    for(int i=0;i<strlen(cus.accountHolderName);i++)
    {
        if (cus.accountHolderName[i] == ' ')
        {
            char ch = cus.accountHolderName[i+1];
            char s[3] ={ch,'\0'};
            strcat(acno,s);
        }
    }
    char s1[10];
    printf("%s",acno);
    int set = rand()%900+100;
    sprintf(s1,"%d",set);
    //return acno;
     strcpy(cus.accno,strcat(acno,s1));
*/
    printf("Generated Account Number: %s\n", cus.accno);

     printf("Enter the age: ");
    scanf("%d", &cus.age);
    getchar();

    printf("Enter the gender (male/female): ");
        scanf("%s", cus.gender);
        getchar();
    while ( (strcmp(cus.gender,"male")!=0) && (strcmp(cus.gender,"female") !=0 ) )
    {
        printf("Invalid gender. Please enter 'male' or 'female'.\n");
        printf("Enter the gender (male/female): ");
        scanf("%s", cus.gender);
        getchar();
    }
    while(1)
    {


        printf("Enter date of birth(dd/mm/yyyy): ");
        fgets(cus.dob, Max, stdin);
        cus.dob[strlen(cus.dob) - 1] = '\0';

        if (!isvalidbirth(cus.dob))
        {
            printf("Invalid DOB. Please enter a valid Date of Birth.\n");
        }
        else break;
    }
    printf("Enter address: ");
    fgets(cus.address, Max, stdin);
    cus.address[strlen(cus.address) - 1] = '\0';

    printf("Enter city: ");
    fgets(cus.city, Max, stdin);
    cus.city[strlen(cus.city) - 1] = '\0';

    printf("Enter account type(savings or salary): ");
    fgets(cus.accounttype, Max, stdin);
    cus.accounttype[strlen(cus.accounttype) - 1] = '\0';
    while ( (strcmp(cus.gender,"savings")!=0) && (strcmp(cus.gender,"salary") !=0 ) )
    {
        printf("Invalid account type. Please enter 'savings' or 'salary'.\n");
        printf("Enter the account type (savings/salary): ");
        scanf("%s", cus.gender);
        getchar();
    }


    printf("Enter balance: ");
    scanf("%lf", &cus.balance);
    getchar();

    do {
        printf("Enter PAN card number: ");
        fgets(cus.pannumber, Max, stdin);
        cus.pannumber[strlen(cus.pannumber) - 1] = '\0';

        if (!isvalidpan(cus.pannumber))
            printf("Invalid PAN. Please enter a valid PAN.\n");
    } while (!isvalidpan(cus.pannumber));

    do {
        printf("Enter Aadhaar card number: ");
        fgets(cus.aadhaarnumber, Max, stdin);
        cus.aadhaarnumber[strlen(cus.aadhaarnumber) - 1] = '\0';

        if (!isvalidaadhaar(cus.aadhaarnumber))
            printf("Invalid Aadhaar. Please enter a valid Aadhaar.\n");
    } while (!isvalidaadhaar(cus.aadhaarnumber));



    printf("Account created successfully.\n");
    return cus;
}
/*
void update(struct BankAccount e[], int n)
{
    int c;
    char nm[20], add[20],dob[10],id[11];

    printf("Update 1.Name 2.Address 3.DOB ");
    scanf("%d", &c);
    getchar();
    switch (c)
    {
    case 1:
        printf("Enter the account number ");
        scanf("%s", id);
        getchar();
        printf("Enter the updated name ");
        scanf("%s", nm);

        for (int i = 0; i < n; i++)
        {
            if (strcmp(e[i].accno, id) == 0)
            {
                strcpy(e[i].accountHolderName, nm);
                printf("Name updated successfully.\n");

                 return;
            }
        }
        break;

    case 2:
        printf("Enter the account number ");
        scanf("%s", id);
        printf("Enter the updated address ");
        scanf("%s", add);

        for (int i = 0; i < n; i++)
        {
            if (strcmp(e[i].accno, id) == 0)
            {
                strcpy(e[i].address, add);
                printf("Address updated successfully.\n");
                return;
            }
        }
        break;

    case 3:
        printf("Enter the account number ");
        scanf("%s",id);
        printf("Enter the updated dob ");
        scanf("%s", dob);

        if (!isvalidbirth(dob))
        {
            printf("Invalid date of birth.\n");
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (strcmp(e[i].accno, id) == 0)
            {
                strcpy(e[i].dob, dob);
                printf("Date of birth updated successfully.\n");
                return;
            }
        }

        break;
         default:
        printf("Invalid choice.\n");
        break;
    }
    printf("Account not found. Update failed.\n");
}
*/

void updateName(struct BankAccount e[], int n)
{
    char id[10], nm[20];

    printf("Enter the account number: ");
    scanf("%s", id);
    getchar();

    for (int i = 0; i < n; i++)
    {
        if (strcmp(e[i].accno, id) == 0)
        {
            printf("Enter the updated name: ");
            fgets(nm, 20, stdin);
            nm[strlen(nm) - 1] = '\0';
            strcpy(e[i].accountHolderName, nm);
            printf("Name updated successfully.\n");
            return;
        }
    }

    printf("Account not found. Update failed.\n");
}

void updateAddress(struct BankAccount e[], int n)
{
    char id[10], add[20];

    printf("Enter the account number: ");
    scanf("%s", id);
    getchar();

    for (int i = 0; i < n; i++)
    {
        if (strcmp(e[i].accno, id) == 0)
        {
            printf("Enter the updated address: ");
            fgets(add, 20, stdin);
            add[strlen(add) - 1] = '\0';
            strcpy(e[i].address, add);
            printf("Address updated successfully.\n");
            return;
        }
    }

    printf("Account not found. Update failed.\n");
}

void updateDOB(struct BankAccount e[], int n)
{
    char id[10], dob[10];

    printf("Enter the account number: ");
    scanf("%s", id);
    getchar();

    for (int i = 0; i < n; i++)
    {
        if (strcmp(e[i].accno, id) == 0)
        {
            do
            {
                printf("Enter the updated date of birth (dd/mm/yyyy): ");
                fgets(dob, 10, stdin);
                dob[strlen(dob) - 1] = '\0';

                if (!isvalidbirth(dob))
                {
                    printf("Invalid date of birth. Please enter a valid Date of Birth.\n");
                }
                else
                {
                    strcpy(e[i].dob, dob);
                    printf("Date of birth updated successfully.\n");
                    return;
                }
            } while (1);
        }
    }

    printf("Account not found. Update failed.\n");
}


void deposit(struct BankAccount *accounts, int numAccounts)
{
    char accNumber[10];
    double amount;

    printf("Enter the account number for deposit: ");
    scanf("%s", accNumber);

    int accountIndex = -1;
    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accno, accNumber) == 0)
        {
            accountIndex = i;
            break;
        }
    }

    if (accountIndex == -1)
    {
        printf("Account not found. Invalid account number.\n");
    }
    else
    {
        printf("Enter the deposit amount: ");
        scanf("%lf", &amount);

        if (amount <= 0)
        {
            printf("Invalid deposit amount. Please enter a positive amount.\n");
        }
        else
        {
            accounts[accountIndex].balance += amount;
            printf("Deposit successful. Updated balance: %.2f\n", accounts[accountIndex].balance);
        }
    }
}

void withdraw(struct BankAccount *accounts, int numAccounts)
{
    char accNumber[10];
    double amount;

    printf("Enter the account number for withdrawal: ");
    scanf("%s", accNumber);

    int Index = -1;
    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accno, accNumber) == 0)
        {
            Index = i;
            break;
        }
    }

    if (Index == -1)
    {
        printf("Account not found. Invalid account number.\n");
    }
    else
    {
        printf("Enter the withdrawal amount: ");
        scanf("%lf", &amount);

        if (amount <= 0 || amount > accounts[Index].balance)
        {
            printf("Invalid withdrawal amount. Please enter a positive amount within your balance.\n");
        }
        else
        {
            accounts[Index].balance -= amount;
            printf("Withdrawal successful. Updated balance: %.2f\n", accounts[Index].balance);
        }
    }
}

void fundTransfer(struct BankAccount *accounts, int numAccounts)
{
    char sourceAccNumber[10], destAccNumber[10];
    double amount;

    printf("Enter the source account number for funds transfer: ");
    scanf("%s", sourceAccNumber);

    int sourceIndex = -1;
    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accno, sourceAccNumber) == 0)
        {
            sourceIndex = i;
            break;
        }
    }

    if (sourceIndex == -1)
    {
        printf("Source account not found. Invalid account number.\n");
        return;
    }

    printf("Enter the destination account number for funds transfer: ");
    scanf("%s", destAccNumber);

    int destIndex = -1;
    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accno, destAccNumber) == 0)
        {
            destIndex = i;
            break;
        }
    }

    if (destIndex == -1)
    {
        printf("Destination account not found. Invalid account number.\n");
        return;
    }

    printf("Enter the transfer amount: ");
    scanf("%lf", &amount);

    if (amount <= 0 || amount > accounts[sourceIndex].balance)
    {
        printf("Invalid transfer amount. Please enter amount within your balance.\n");
    }
    else
    {
        accounts[sourceIndex].balance -= amount;
        accounts[destIndex].balance += amount;

        printf("Funds transfer successful.\n");
        printf("Source Account Balance: %.2f\n", accounts[sourceIndex].balance);
        printf("Destination Account Balance: %.2f\n", accounts[destIndex].balance);
    }
}

void searchByAccountNumber(struct BankAccount *accounts, int numAccounts)
{
    char accNumber[10];

    printf("Enter the account number to search: ");
    scanf("%s", accNumber);

    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accno, accNumber) == 0)
        {
            printf("Account found:\n");
            printf("Name: %s\n", accounts[i].accountHolderName);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void searchByName(struct BankAccount *accounts, int numAccounts)
{
    char name[50];

    printf("Enter the name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accountHolderName, name) == 0)
        {
            printf("Account found:\n");
            printf("Account Number: %s\n", accounts[i].accno);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void searchByAccountType(struct BankAccount *accounts, int numAccounts)
{
    char accType[20];

    printf("Enter the account type to search: ");
    scanf("%s", accType);

    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accounttype, accType) == 0)
        {
            printf("Account found:\n");
            printf("Account Number: %s\n", accounts[i].accno);
            printf("Name: %s\n", accounts[i].accountHolderName);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void balanceEnquiry(struct BankAccount *accounts, int numAccounts)
{
    char accNumber[10];

    printf("Enter the account number for balance enquiry: ");
    scanf("%s", accNumber);

    for (int i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].accno, accNumber) == 0)
        {
            printf("Account found. Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

int main()
{
    int choice = 0;
    struct BankAccount cus[50];
    int numAccounts = 0;
    do{


    printf("BANKING SYSTEM \n");
    printf("1. Create Account \n");
    printf("2. Update Account Details \n");
    printf("3. Deposit \n");
    printf("4. Withdraw \n");
    printf("5. Funds Transfer \n");
    printf("6. Search details of Account Holder \n");
    printf("7. Balance Enquiry \n");
    printf("8. Exit \n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    int i=0;
    switch (choice)
    {
    case 1:
        // for (int i = 0; i < 3; i++)
        // {
            cus[i++] = create();
        // }
        break;

    case 2:
       // update(cus, i);

       printf("Update\n1. Name\n2. Address\n3. DOB\n");
            int updateChoice;
            scanf("%d", &updateChoice);
            getchar();

            switch (updateChoice)
            {
            case 1:
                updateName(cus, numAccounts);
                break;
            case 2:
                updateAddress(cus, numAccounts);
                break;
            case 3:
                updateDOB(cus, numAccounts);
                break;
            default:
                printf("Invalid choice.\n");
                break;
            }
        break;

    case 3:
        deposit(cus, 3);
        break;

    case 4:
        withdraw(cus, 3);
        break;

    case 5:
        fundTransfer(cus, 3);
        break;

    case 6:
        printf("1. Search by Account Number\n");
        printf("2. Search by Name\n");
        printf("3. Search by Account Type\n");
        int searchChoice;
        scanf("%d", &searchChoice);

        switch (searchChoice)
        {
        case 1:
            searchByAccountNumber(cus, 3);
            break;

        case 2:
            searchByName(cus, 3);
            break;

        case 3:
            searchByAccountType(cus, 3);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
        break;

    case 7:
        balanceEnquiry(cus, 3);
        break;

    case 8:
        printf("Exiting the program.\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }
    }while(choice != 8);

    return 0;
}
