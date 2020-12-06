#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"

//returrns the account number between 901 - 950
int open(float money, float arr[50][2]){
    
    int i=0, loc=0, x=0;
    for (i = 49; i >= 0; i--){
        if(arr[i][0] == 0){
            loc = i;
        }
    }
    if(loc >= 0){
        arr[loc][0] = 1;
        arr[loc][1] = money;
        x = loc + 901;
        printf("New account number is: %d",x);
    }
    return 1;
}

int biror(float acNum, float arr[50][2]){
    int x = acNum-901;
    int x0 = arr[x][0];
    if(x0 == 1){
        float temp = arr[x][1];
        printf("The balance of account number %0.0f is: %0.2f",acNum,temp);
    }
    else{
        printf("This account is closed");
    }
    return 1;
}

int deposit(float acNum, float money, float arr[50][2]){
    int x = acNum-901;
    if(arr[x][0] != 0 && money >= 0){
        float cur = arr[x][1];
        cur += money;
        arr[x][1] = cur;
        printf("\nThe new balance is: %0.2f",cur);
    }
    return 1;
}

int withdraw(float acNum, float money, float arr[50][2]){
    
    int x = acNum-901;
    int x0 = arr[x][0];
    if(x0 != 0 && money >= 0){
        float cur = arr[x][1];
        if(cur-money < 0){
            printf("Cannot withdraw more than the balance");
        }
        else{
            cur -= money;
            arr[x][1] = cur;
            printf("The new balance is: %0.2f",cur);
        }
    }
    return 1;
}

int close(float acNum, float arr[50][2]){
    int x = acNum-901;
    if(arr[x][0] != 0){
        arr[x][0] = 0;
        arr[x][1] = 0;
        printf("Closed account number %0.0f",acNum);
    }
    return 1;
}

int interest(float rate, float arr[50][2]){
    if(rate >= 0){
        float temp = 0;
        int i;
        for (i = 0; i < 50; i++){
            temp = arr[i][1] * rate * 0.01;
            temp += arr[i][1];
            arr[i][1] = temp;
        }
    }
    return 1;
}

int print(float arr[50][2]){
    int i;
    for ( i = 0; i < 50; i++)
    {
        if(arr[i][0] == 1){
            float temp1 = i+901;
            float temp2 = arr[i][1];
            printf("\nThe balance of account number %0.0f is: %0.2f",temp1, temp2);
        }
    }
    return 1;
}
    
int end(float arr[50][2]){
    int i;
    for (i = 0; i < 50; i++)
    {
        arr[i][0] = 0;
        arr[i][1] = 0;
    }
    return 1;
}