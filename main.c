#include <stdio.h>
#include <stdlib.h>
/*******************************************************************

# Project      : Payment System (ATM)
# Author       : Osama Shehta Saqr
# Contact      : osama.ibn.saqr@gmail.com
# linkedin     : https://www.linkedin.com/in/osama-shehta-saqr/

********************************************************************/
typedef struct
{
    char ID ;
    int  Password;
    int  Balance;
} Account;
/** Creating Objects **/
Account User_1 = {11,111,50000};
Account User_2 = {22,222,70500};
Account User_3 = {33,333,9000};

char LoginToSystem(void);
void PrintBalance(char accountID);
void Deposit(char accountID, int cash_amount);
void Transfer(int accountID);
char Withdraw(char accountID, int cash_amount);

char accountID       = 0;
int  accountPassword = 0;
int  cash_amount     = 0;
int main()
{
    char Operatin = 0;
    char validity = 0;
    char Menu     = 0;

    printf("\n    Osama Saqr Bank ATM Services: Welcome!\n\n");

    printf("--------------  DATA ENTRY  --------------\n\n");

    validity = LoginToSystem();

    if(validity == 1)
    {
        printf("\n\n--------------  YOUR BALANCE  --------------\n\n");
        PrintBalance(accountID);
    }

    while(1)
    {
        printf("\n--------------  DISPLAY MENU  --------------\n\n");

        printf("Press 'M' To Display The Menu : ");
        scanf(" %c",&Menu);
        if((validity == 1) && ( Menu == 'M'))
        {

            printf("\n--------------  MENU OPERATION  --------------\n\n");

            printf("For Deposit Press : 'D'\nFor Transfer Press: 'T'\nFor Withdraw Press: 'W'\nFor Cancel Press  : 'C'\n");
            scanf("%s",&Operatin);


            if(Operatin=='D')
            {
                printf("\n--------------  DEPOSIT OPERATION  --------------\n\n");

                printf("Submit the amount of money you wish to Deposit : ");
                scanf("%d",&cash_amount);
                Deposit( accountID, cash_amount);

            }
            else if(Operatin=='T')
            {
                printf("\n--------------  TRANSFER OPERATION  --------------\n\n");

                Transfer( accountID);

            }
            else if(Operatin=='W')
            {
                printf("\n--------------  WITHDRAW OPERATION  --------------\n\n");

                char value = 0;
                printf("Submit the amount of money you wish to Withdraw : ");
                scanf("%d",&cash_amount);
                value = Withdraw( accountID,  cash_amount);
            }
            else if(Operatin=='C')
            {
                printf("\n--------------  CANCELING OPERATION  --------------\n\n");

                printf("Thank you for choosing Osama Saqr Bank. Your trust drives us to serve you better. Have a great day!\n\n");

                return 0;
            }
            else
            {
                printf("\n--------------  WRONG OPERATION  --------------\n\n");
                printf("Wrong Operation Please Enter a Valid One!\n");
            }
        }
        else
        {
            printf("\nInvalid Key, Please Press 'M'\n");
        }
    }
    return 0;
}

char LoginToSystem(void)
{
    char flag = 0;
    printf("Enter Your ID and Password : ");
    scanf("%d%d",&accountID,&accountPassword);
    while(flag == 0)
    {

        if(accountID==User_1.ID)
        {
            if(accountPassword==User_1.Password)
            {
                flag = 1;
            }
            else
            {
                printf("Please Enter a Correct ID And Password : ");
                scanf("%d%d",&accountID,&accountPassword);
            }
            break ;
        }
        else if(accountID==User_2.ID)
        {
            if(accountPassword==User_2.Password)
            {
                flag = 1;
            }
            else
            {
                printf("Please Enter a Correct ID And Password : ");
                scanf("%d%d",&accountID,&accountPassword);
            }
            break ;
        }
        else if(accountID==User_3.ID)
        {
            if(accountPassword==User_3.Password)
            {
                flag = 1;
            }
            else
            {
                printf("Please Enter a Correct ID And Password : ");
                scanf("%d%d",&accountID,&accountPassword);
            }
            break ;
        }
        else
        {
            printf("Please Enter a Correct ID And Password : ");
            scanf("%d%d",&accountID,&accountPassword);
        }
    }
    return flag;
}

void PrintBalance(char accountID)
{
    if(accountID==User_1.ID)
    {
        printf("Your balance :%d\n",User_1.Balance);
    }
    else if(accountID==User_2.ID)
    {
        printf("Your balance :%d\n",User_2.Balance);
    }
    else if(accountID==User_3.ID)
    {
        printf("Your balance :%d\n",User_3.Balance);
    }
}

void Deposit(char accountID, int cash_amount)
{
    if(accountID == User_1.ID)
    {
        User_1.Balance += cash_amount;
        printf("\nThe operation was completed successfully Your balance : %d\n",User_1.Balance);
    }
    else if(accountID == User_2.ID)
    {
        User_2.Balance += cash_amount;
        printf("\nThe operation was completed successfully Your balance : %d\n",User_2.Balance);
    }
    else if(accountID == User_3.ID)
    {
        User_3.Balance += cash_amount;
        printf("\nThe operation was completed successfully Your balance : %d\n",User_3.Balance);
    }
}

void Transfer(int accountID)
{
    int accountID2 = 0,cash_amount = 0,flag = 0;
    printf("Enter  The Second Account ID and cash amount : ");
    scanf("%d%d",&accountID2,&cash_amount);
    while(flag == 0)
    {
        if(accountID == User_1.ID)
    {
        if(User_1.Balance >= cash_amount)
        {
            if(accountID2 == User_2.ID || accountID2 == User_3.ID)
            {
                User_1.Balance -= cash_amount;
                if(accountID2 == User_2.ID)
                {
                    User_2.Balance += cash_amount;
                }
                else
                {
                    User_3.Balance += cash_amount;
                }
                printf("\nThe operation was completed successfully Your balance : %d\n",User_1.Balance);
                flag = 1;
            }
            else
            {
                printf("Invalid destination account ID.\n");
                printf("Please Enter The Second Account ID and cash amount : ");
                scanf("%d%d",&accountID2,&cash_amount);
            }
        }
        else
        {
            printf("You can't make this operation, Your Balance Is Not Enough\n");
            printf("Please Enter The  cash amount : ");
            scanf("%d",&cash_amount);
        }
    }
    else if(accountID == User_2.ID)
    {
        if(User_2.Balance >= cash_amount)
        {
            if(accountID2 == User_1.ID || accountID2 == User_3.ID)
            {
                User_1.Balance -= cash_amount;
                if(accountID2 == User_1.ID)
                {
                    User_1.Balance += cash_amount;
                }
                else
                {
                    User_3.Balance += cash_amount;
                }
                printf("\nThe operation was completed successfully Your balance : %d\n",User_1.Balance);
                flag = 1;
            }
            else
            {
                printf("Invalid destination account ID.\n");
                printf("Please Enter The Second Account ID and cash amount : ");
                scanf("%d%d",&accountID2,&cash_amount);
            }
        }
        else
        {
            printf("You can't make this operation, Your Balance Is Not Enough\n");
            printf("Please Enter The  cash amount : ");
            scanf("%d",&cash_amount);
        }
    }
    else if(accountID == User_3.ID)
    {
        if(User_3.Balance >= cash_amount)
        {
            if(accountID2 == User_1.ID || accountID2 == User_2.ID)
            {
                User_1.Balance -= cash_amount;
                if(accountID2 == User_1.ID)
                {
                    User_1.Balance += cash_amount;
                }
                else
                {
                    User_2.Balance += cash_amount;
                }
                printf("\nThe operation was completed successfully Your balance : %d\n",User_1.Balance);
                flag = 1;
            }
            else
            {
                printf("Invalid destination account ID.\n");
                printf("Please Enter The Second Account ID and cash amount : ");
                scanf("%d%d",&accountID2,&cash_amount);
            }
        }
        else
        {
            printf("You can't make this operation, Your Balance Is Not Enough\n");
            printf("Please Enter The  cash amount : ");
            scanf("%d",&cash_amount);
        }
    }
    else
    {
        printf("Invalid ID,\n");
        printf("Please Enter The Second Account ID and cash amount : ");
        scanf("%d%d",&accountID2,&cash_amount);
    }
}
}

char Withdraw(char accountID, int cash_amount)
{
    char flag = 0;
    while(flag == 0)
    {
        if(accountID == User_1.ID)
    {
        if(User_1.Balance >= cash_amount)
        {
            User_1.Balance -= cash_amount;
            printf("\nThe operation was completed successfully Your balance : %d\n",User_1.Balance);
            flag = 1;
        }
        else
        {
            printf("You can't make this operation, Your Balance Is Not Enough\n");
            printf("Please Enter The  cash amount : ");
            scanf("%d",&cash_amount);
        }
    }
    else if(accountID==User_2.ID)
    {
        if(User_2.Balance >= cash_amount)
        {
            User_2.Balance -= cash_amount;
            printf("\nThe operation was completed successfully Your balance : %d\n",User_2.Balance);
            flag = 1;
        }
        else
        {
            printf("You can't make this operation, Your Balance Is Not Enough\n");
            printf("Please Enter The  cash amount : ");
            scanf("%d",&cash_amount);
        }
    }
    else if(accountID==User_3.ID)
    {
        if(User_3.Balance >= cash_amount)
        {
            User_3.Balance -= cash_amount;
            printf("\nThe operation was completed successfully Your balance : %d\n",User_3.Balance);
            flag = 1;
        }
        else
        {
            printf("You can't make this operation, Your Balance Is Not Enough\n");
            printf("Please Enter The  cash amount : ");
            scanf("%d",&cash_amount);
        }
    }
    else
    {
        printf("Invalid ID,\n");
        printf("Please Enter The Account ID and cash amount : ");
        scanf("%d%d",&accountID,&cash_amount);
    }
    }
    return flag ;
}
