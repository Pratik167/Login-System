#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13 // Ascii value defining
#define BKSPC 8

struct user
{
    char name[50];
    char username[50];
    char password[50];
    char phone[50];
    char verify[50];
};

void input(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0; // done so that it does not take enter(\n) as input
}
void inputpass(char pass[50])
{ // password type handa * aauxa (Encryption)
    int i=0;
    char ch;
    while (1) // jaba samma next line key or enter press hudaina this function will run
{
        ch = _getch(); // getch reads a single character at a time
        if (ch==ENTER)
{ // activates when we press enter
            pass[i] = '\0'; // enter lai \0 ma convert garxa, so that enter is not taken as a character
            break;
        }
else if (ch==BKSPC)
{
            if(i>0)
{ // index greater than 0
                i--;
                printf("\b \b"); /* eg: pratiks| first \b moves the cursor in front by 1 pratik|s and then replaces s with " "
                                    second \b so that cursor then gets to the original index pratik| */
            }
        }
else
{ // this encrypts the pass by showing * instead of the inputted character
            pass[i++] = ch; // moves the index by 1
            printf("* \b");
        }
    }
}

int main()
{
    system("color 2");
    FILE *p, *v;
    int opt;
    struct user user;
    char confirmpass[50];

    printf("\n\t\t\t\t--------Welcome to The Program---------");
    printf("\n\n\n What would you like to do:");
    printf("\n 1. Signup");
    printf("\n 2. Login");
    printf("\n 3. All Detail");
    printf("\n 4. Exit");
here:
    printf("\n\t\t\t\tYour Choice:\t");
    scanf("%d", &opt);
    fgetc(stdin); // fgetc only scans one character unless it is in a loop unlike in fgets where we can specify how many characters we want to read

    switch (opt)
{
        case 1:
        printf("Redirecting Please Wait");
        for (int q=0;q<3;q++)
{
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    system("cls");
                    printf("\n\t\t\t\t\tSIGN UP");
            printf("\n Enter Your Full Name:\t");
            input(user.name); // yo function bhaye paxi fflush garnu pardaina
            printf(" Enter Your Number:\t");
            input(user.phone);
            printf(" Enter Username:\t");
            input(user.username);
            printf(" Enter Password:\t");
            inputpass(user.password); // encryption function is used
            printf("\nEnter Confirmation Password:");
            inputpass(confirmpass);

            if (strcmp(user.password, confirmpass) == 0)
{ // confirm pass milxa ki nai
                p = fopen("P:\\Login2\\Users.txt", "a+");
                if (p == NULL)
{
                    perror("Error opening file");
                    break;
                }
                // Asking If user wants to put a verifier question
                char a;
                printf("\n\nDo you want to Add a Verifier, In case you forget your password?\n Press Y to confirm:");
                scanf("%c", &a);
                fflush(stdin);
                if (a == 'Y' || a == 'y')
{
                    printf("\nEnter a code(this should be known only by you and it can't be changed):\t");
                    input(user.verify);
                    printf("\n\nThis must be remembered to change the passcode!!!");  
                }
else
{
                    printf("\nDon't Forget the passcode then");
                }

                fwrite(&user, sizeof(struct user), 1, p);
                fflush(p);
                if (fwrite != 0)
{
                    printf("\n\n\t\t\t\tLoading");
                    for (int q = 0; q < 3; q++)
{
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    printf("\n\n Registration Successful");

                }
else
{
                    printf("\n\n Registration Failed");
                }
                fclose(p);
            }
else
{
                printf("\n\aDid you forget your password!!!!");
            }
            break;

        case 2:
{
printf("Redirecting Please Wait");
        for (int q=0;q<3;q++)
{
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    system("cls");
                    printf("\n\t\t\t\t\t------LOGIN------");
            char username[50], passw[50];
            struct user login;
            int flag = 0;
            int z = 0;
loggin:

            printf("\n Enter your username:\t");
            input(username);
            printf("\n Enter your password:\t");
            inputpass(passw);

            p = fopen("P:\\Login2\\Users.txt", "r");
            if (p == NULL)
{
                printf("\n\nNo File Detected");
                break;
            }
            while (fread(&login, sizeof(struct user), 1, p))
{
                if (strcmp(login.username, username) == 0 && strcmp(login.password, passw)==0)
{
                    printf("\n\n\t\t\t\tLoading");
                    for (int q=0;q<3;q++)
{
                        Sleep(500);
                        printf(".");
                        Sleep(500);
                        printf(".");
                        Sleep(500);
                        printf(".");
                        Sleep(500);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    printf("\n\n\n\t\t\t\t Login Success");
                    printf("\n\t\t\t\tWelcome %s", login.username);
                    printf("\n\n|Name:\t%s", login.name);
                    printf("\n|UserName:\t%s", login.username);
                    printf("\n|Phone:\t%s\n", login.phone);
                    flag = 1;
                    break;
                }
            }

            // when password is wrong
            if (!flag)
{
                printf("\n\nWrong Username Or Password");

                printf("\nTry again\n\n");
                z++;
                while (z>2&&z<4)
{
printf("\n\nAttempt Limit Reached");
                    goto teta;
                }
                goto loggin;
            }
            // this block of code activates after failed attempt 3 times
teta:
            while (z>2&&z<4)
{
                int m;
                Sleep(2000);
                system("cls");
                printf("\n\n\t\t\t\tRedirecting ");
                    for (int q=0 ; q<3 ; q++)
{
                        Sleep(500);
                        printf(".");
                        Sleep(500);
                        printf(".");
                        Sleep(500);
                        printf(".");
                        Sleep(500);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
mathi:
system("cls");
printf("\t\t\t\t-----REDEMPTION ARC-----");
                printf("\n1. Change PassWord?");
                printf("\n2. Ki Exit?");
                printf("\n Choose:");
                scanf("%d", &m);
                fgetc(stdin);
                switch (m)
{
                    case 1:
{
                        char verify[50];
                        printf("When You Born?\t:");
                        gets(verify);
                        p = fopen("P:\\Login2\\Users.txt", "r+");
                        if (p == NULL)
{
                            printf("\n\nNo File Detected");
                            break;
                        }
                        while (fread(&login, sizeof(struct user), 1, p)) //we just pulling the structure of login instead of the signup wala, and comparing it with the verify qn
{
                            if (strcmp(login.username, username) == 0 && strcmp(login.verify, verify) == 0)
{
                                printf("\nEnter New Password:");
                                inputpass(login.password);
                                fseek(p, -(long)sizeof(struct user), SEEK_CUR);//this line of code takes the cursor back to the necessary user ko username tira, so the pass can be changed
                                fwrite(&login, sizeof(struct user), 1, p);//the - sign infront of the sizeof is to move the cursor back in the file
                                printf("\nPassword changed successfully.");
                                fclose(p);
                                goto end;
                            }
                        }
                        printf("\n You Imposter");
                        fclose(p);
                        exit(0);
                    }
                    case 2:
                        printf("\n Ok BYE BYE");
                        exit(0);

                    default:
                        printf("Wrong input");
                        goto mathi;
                }
            }
end:
            fclose(p);
            break;
        }
        case 3:
{
printf("Redirecting Please Wait");
        for (int q=0;q<3;q++)
{
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf(".");
                        Sleep(400);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    system("cls");
                    printf("\n\t\t\t\t\t------DETAILS------");
            struct user detail;
            p = fopen("P:\\Login2\\Users.txt", "r");
            if (p == NULL)
{
                printf("\n\nKei Ta hal paila");
                break;
            }
            rewind(p);//cursor moves on the first line of the file
            printf("\n\nAll User Details:\n");
            while (fread(&detail, sizeof(struct user), 1, p)) //prints all the details of the users.
{
                printf("\n|Name:\t%s", detail.name);
                printf("\n|UserName:\t%s", detail.username);
                printf("\n|Phone:\t%s\n", detail.phone);
            }
            fclose(p);
        }
        break;
        case 4:
            printf("\n\n\t\t\t\t*****Thanks For The Visit*****\n");
            exit(0);

        default:
            printf("\n\n\t\t\t\tWrong Input!!! Try Again\n");
            goto here;
            break;
    }
    return 0;
}
