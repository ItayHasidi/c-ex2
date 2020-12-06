#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
// # define e 'E'
// # define o 'O'
// # define b 'B'
// # define d 'D'
// # define w 'W'
// # define c 'C'
// # define i 'I'
// # define p 'P'
# define e 69
# define o 79
# define b 66
# define d 68
# define w 87
# define c 67
# define i 73
# define p 80

int main(){
    float arr[50][2];
    for (int x = 49; x >= 0 ; x--){
        arr[i][0] = 0;
        arr[i][1] = 0;
    }
    bool flag = true;
    int cha;
    printf("\nPlease choose a transaction type:");
    printf("\n O-Open Account");
    printf("\n B-Balance Inquiry");
    printf("\n D-Deposit");
    printf("\n W-Withdrawal");
    printf("\n C-Close Account");
    printf("\n I-Interest");
    printf("\n P-Print");
    printf("\n E-Exit");
    scanf(" %d",&cha);
    cha = getc(stdin);
    fflush(stdin);
    while(flag){
        flag = false;
        if(cha == o){
            
            float dep;
            printf("‫‪\nPlease enter amount for deposit:‬‬ ");
            scanf(" %f",&dep);
            char ch = getc(stdin);
            // fflush(stdin);
            int asciCh = (int) ch;
            if(asciCh != ' '){
                if(asciCh < '0' || asciCh > '9'){
                printf("Failed to read the amount");
                // cha = ch;
                // putc(ch,stdin);
                // cha = getc(stdin);
                // fflush(stdin);
                }
            }
            
            else if(dep < 0){
                printf("Invalid Amount");
            }
            else if(dep >= 0){
                open(dep, arr);
            }
            else {
                printf("Failed to read the amount");
            }
            flag = true;
        }
        else if(cha == b){
            
            float ac;
            printf("\nPlease enter account number:‬‬ ");
            scanf(" %f",&ac);
            char ch = getc(stdin);
            // fflush(stdin);
            int asciCh = (int) ch;
            if(asciCh != ' '){
            if(asciCh < '0' || asciCh > '9'){
                printf("Failed to read the amount");
                // cha = ch;
                // putc(ch,stdin);
                // cha = getc(stdin);
            }
            }
            else if(ac < 901 || ac > 950){
                printf("Failed to read the account number");
            }
            else{
                biror(ac, arr);
            }
            
            flag = true;
        }
        else if(cha == d){
            float ac=0, am=0;
            printf("\nPlease enter account number: ‬‬");
            scanf(" %e",&ac);
            int x = ac -901;
            int x0 = arr[x][0];
            // int x1 = arr[x][0];
            char ch = getc(stdin);
            // fflush(stdin);
            int asciCh = (int) ch;
            if(asciCh != ' '){
            if(asciCh < '0' || asciCh > '9' ){
                printf("Failed to read the account number");
                // cha = ch;
                // putc(ch,stdin);
                // cha = getc(stdin);
            }
            }
            else if (ac > 950 || ac < 901){
                printf("Invalid account number");
            }
            else if(x0 == 0){
                printf("This account is closed");
            }
            else if(x0 == 1) {
                printf("\nPlease enter the amount to deposit: ");
                scanf(" %f",&am);
                char ch = getc(stdin);
                // fflush(stdin);
                int asciCh = (int) ch;
                if(asciCh != ' '){
                if(asciCh < '0' || asciCh > '9'){
                    printf("Failed to read the amount");
                    // cha = ch;
                    // putc(ch,stdin);
                    // cha = getc(stdin);
                }
                }
                else if(am < 0){
                    printf("Cannot deposit a negative amount");
                }
                else if (am >= 0){
                    deposit(ac, am, arr);
                }
                else{
                    printf("Failed to read the amount");
                }
            }  
            else{
                printf("Failed to read the account number");
            }
            flag = true;
        }
        else if(cha == w){
            float ac, am;
            printf("\nPlease enter account number: ‬‬");
            scanf(" %f",&ac);
            int x = ac -901;
            int x0 = arr[x][0];
            // int x1 = arr[x][1];
            char ch = getc(stdin);
            // fflush(stdin);
            int asciCh = (int) ch;
            if(asciCh != ' '){
            if(asciCh < '0' || asciCh > '9' ){
                printf("Failed to read the account number");
                // cha = ch;
                // putc(ch,stdin);
                // cha = getc(stdin);
            }
            }
            else if (ac > 950 || ac < 901){
                printf("Invalid account number");
            }
            else if(x0 == 0){
                printf("This account is already closed");
            }
            else if(x0 == 1) {
                printf("Please enter the amount to withdraw: ");
                scanf(" %f",&am);
                char ch = getc(stdin);
                // fflush(stdin);
                int asciCh = (int) ch;
                if(asciCh != ' '){
                if(asciCh < '0' || asciCh > '9' ){
                    printf("Failed to read the amount");
                    // cha = ch;
                    // putc(ch,stdin);
                    // cha = getc(stdin);
                }
                }
                else if(am < 0){
                    printf("Cannot withdraw a negative amount");
                }
                else if (am >= 0){
                    withdraw(ac, am, arr);
                }
                else{
                    printf("Failed to read the amount");
                }
            }  
            else{
                printf("Failed to read the account number");
            }
            flag = true;
        }
        else if(cha == c){
            
            float ac;
            printf("\nPlease enter account number: ");
            scanf(" %f",&ac);
            int x = ac -901;
            int x0 = arr[x][0];
            char ch = getc(stdin);
            // fflush(stdin);
            int asciCh = (int) ch;
            if(asciCh != ' '){
            if(asciCh < '0' || asciCh > '9' ){
                printf("Failed to read the account number");
                // cha = ch;
                // putc(ch,stdin);
                // cha = getc(stdin);
            }
            }
            else if(ac > 950 || ac < 901){
                
                printf("Invalid account number");
            }
            else if(x0 == 0){
                printf("This account is already closed");
            }
            else if(x0 == 1){
                close(ac, arr);
            }
            else{
                printf("Failed to read the account number");
            }
            flag = true;
        }
        else if(cha == i){
            
            float am;
            printf("\nPlease enter interest rate: ‬‬");
            scanf(" %f",&am);
            char ch = getc(stdin);
            // fflush(stdin);
            int asciCh = (int) ch;
            if(asciCh != ' '){
            if(asciCh < '0' || asciCh > '9' ){
                printf("Failed to read the interest rate");
                // cha = ch;
                // putc(ch,stdin);
                // cha = getc(stdin);
            }
            }
            else if(am < 0){
                printf("Invalid interest rate");
            }
            else if(am >= 0){
                interest(am, arr);
            }
            else{
                printf("Failed to read the interest rate");
            }
            flag = true;
        }
        else if(cha == p){
            print(arr);
            flag = true;          
        }
        else if(cha == e){
            end(arr);
            break;
        }
        else{
            printf("\nInvalid transaction type");
            cha = '1';
            flag = true;
        }
        printf("\n\nPlease choose a transaction type:");
        printf("\n O-Open Account");
        printf("\n B-Balance Inquiry");
        printf("\n D-Deposit");
        printf("\n W-Withdrawal");
        printf("\n C-Close Account");
        printf("\n I-Interest");
        printf("\n P-Print");
        printf("\n E-Exit");
        scanf(" %d",&cha);
        cha = getc(stdin);
        fflush(stdin);
    }    
    return 0;
}