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
    char role[50];
};
//input garna ko lagi function banako, we dont have to use fgets paxi, we can just call this function
void input(char ch[50]) 
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0; // done so that it does not take enter(\n) as input
}
//same thing as input but yeta chai letters like * le replace garxa(this also a function,so it only needs calling)
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
    printf("\n 4. Delete Records");
    printf("\n 5. Exit");
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
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    system("cls");
                    printf("\n\t\t\t\t\tSIGN UP");
                    printf("\n Are you signing up as an admin or customer? (Enter 'admin' or 'customer'):\t");
            input(user.role);

            if (strcmp(user.role,"admin")==0) 
			{
                int admin_exists = 0;
                p=fopen("P:\\Login2\\Users.txt","r");
                if (p!=NULL) 
				{
                    struct user temp;
                    while (fread(&temp, sizeof(struct user), 1, p)) 
					{
                        if (strcmp(temp.role, "admin") == 0) 
						{
                            admin_exists = 1;
                            break;
                        }
                    }
                    fclose(p);
                }
                if (admin_exists) 
				{
                    printf("\n\a An admin already exists! Redirecting to login page...\n");
                    goto login;
                }
            }
            printf("\n Enter Your Full Name:\t");
            input(user.name); // yo function bhaye paxi fflush garnu pardaina
            printf(" Enter Your Number:\t");
            input(user.phone);
            	while (1) 
    				{
        				int username_exists = 0;
        				printf(" Enter Username:\t");
        				input(user.username);

        				p=fopen("P:\\Login2\\Users.txt","r");
        				if (p != NULL) 
        				{
            				struct user temp;
            				while (fread(&temp, sizeof(struct user), 1, p)) 
            				{
                				if (strcmp(temp.username, user.username) == 0) 
                				{
                    				username_exists = 1;
                    				printf("\n\a Username already exists! Please choose a different username.\n");
                    				
                    				break;
                				}
            				}
            				fclose(p);
        				}
        				if (!username_exists) 
        				{
            				break;  // If username is unique,it goes out of the loop and moves on
        				}
    }
            confirmpassword:
            printf(" Enter Password:\t");
            inputpass(user.password); // encryption function is used
            printf("\nEnter Confirmation Password:");
            inputpass(confirmpass);

            if (strcmp(user.password, confirmpass) == 0) 
			{ // confirm pass milxa ki nai
                p = fopen("P:\\Login2\\Users.txt", "a+");
                if (p == NULL) 
				{
                    printf("Error opening file");// just shows the error printf le print
                    break;
                }
                // Asking If user wants to put a verifier question
                char a;
                printf("\n\nDo you want to Add a Verifier Question In case you forget your password?\n Press Y to confirm:");
                scanf("%c", &a);
                fflush(stdin);
                if (a == 'Y' || a == 'y') 
				{
                    printf("\n\nThis must be remembered to change the passcode!!!");   
                    printf("\nPlease Enter a Code U will Remember:");
                    input(user.verify);
                } 
				else 
				{
                    printf("Password Yaad Rakhne Hai Feri");
                }

                fwrite(&user, sizeof(struct user), 1, p);
                fflush(p);
                if (fwrite != 0) 
				{
                    printf("\n\n\t\t\t\tLoading");
                    for (int q=0;q<3;q++) 
					{
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    printf("\n\n Registration Successful");
                    break;
                } 
				else 
				{
                    printf("\n\n Registration Failed");
                }
                fclose(p);
            } 
			else 
			{
                printf("\n\a Password Do not Match!!!!\n");
            }
            goto confirmpassword;// in 123
            break;

        case 2:
{
    login:
    printf("Redirecting Please Wait");
    for (int q = 0; q < 3; q++) 
    {
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf("\b \b");
        printf("\b \b");
        printf("\b \b");
    }
    system("cls");
    printf("\n\t\t\t\t\t------LOGIN------");

    char username[50], passw[50];
    struct user login;
    int flag = 0;
    int z = 0; // number of tries

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
        if (strcmp(login.username, username) == 0 && strcmp(login.password, passw) == 0)
        {
            printf("\n\n\t\t\t\tLoading");
            for (int q = 0; q < 3; q++) 
            {
                Sleep(200);
                printf(".");
                Sleep(200);
                printf(".");
                Sleep(200);
                printf(".");
                Sleep(400);
                printf("\b \b");
                printf("\b \b");
                printf("\b \b");
            }
            printf("\n\n\n\t\t\t\t Login Success");

            if (strcmp(login.role, "admin") == 0)
            {
                printf("\n\t\t\t\tWelcome Admin %s", login.username);
            }
            else
            {
                printf("\n\t\t\t\tWelcome Customer %s", login.username);
            }

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
        while (z > 2 && z < 4)
        {
            printf("\n\nAttempt Limit Reached");
            goto teta; // 264 ma xa
        }
        goto loggin; //line 208
    }
    // this block of code activates after failed attempt 3 times
    teta:
    while (z > 2 && z < 4)
    {
        int m;
        Sleep(2000);
        system("cls");
        printf("\n\n\t\t\t\tRedirecting ");
        for (int q = 0; q < 3; q++) 
        {
            Sleep(200);
            printf(".");
            Sleep(200);
            printf(".");
            Sleep(200);
            printf(".");
            Sleep(200);
            printf("\b \b");
            printf("\b \b");
            printf("\b \b");
        }
    mathi:
        system("cls");
        printf("\t\t\t\t-----PASSCODE REDEMPTION-----");
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
                while (fread(&login, sizeof(struct user), 1, p))
                {
                    if (strcmp(login.username, username) == 0 && strcmp(login.verify, verify) == 0)
                    {
                        printf("\nEnter New Password:");
                        inputpass(login.password); // SEEK_SET for beginning of the file, SEEK_END end of file
                        fseek(p, -(long)sizeof(struct user), SEEK_CUR); // SEEK_CUR means current position, this line of code takes the cursor back to the necessary user ko username tira, so the pass can be changed
                        fwrite(&login, sizeof(struct user), 1, p); //the - sign infront of the sizeof is to move the cursor back in the file
                        printf("\nPassword changed successfully.");
                        fclose(p);
                        goto end; //in line 331
                    }
                }
                printf("\n Please Check your Username!!!");
                fclose(p);
                exit(0);
            }
            case 2:
                printf("\n Ok BYE BYE");
                exit(0);

            default:
                printf("Wrong input");
                goto mathi; //line 258
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
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf(".");
                        Sleep(200);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    system("cls");
                    printf("\n\t\t\t\t\t------DETAILS------");
            struct user detail;
            p = fopen("P:\\Login2\\Users.txt", "r");
            if (p==NULL) 
			{
                printf("\n\nThere is no User recorded for now");
                break;
            }
            rewind(p);//cursor moves on the first line of the file
            printf("\n\nAll User Details:\n");
            while (fread(&detail, sizeof(struct user), 1, p)) //prints all the details of the users.
			{
                printf("\n|Name:\t%s", detail.name);
                printf("\n|UserName:\t%s", detail.username);
                printf("\n|Phone:\t%s\n", detail.phone);
                printf("\n|Role:\t%s\n",detail.role);
            }
            fclose(p);
        }
        break;
        case 4://deleting a particular file
        	   printf("Redirecting Please Wait");
    		for (int q=0;q<3;q++) 
			{
        		Sleep(200);
        		printf(".");
        		Sleep(200);
        		printf(".");
        		Sleep(200);
        		printf(".");
        		Sleep(200);
        		printf("\b \b");
        		printf("\b \b");
        		printf("\b \b");
         	}
            	system("cls");
        		printf("\n\t\t\t\t\t------DELETE RECORDS------");
        		char delete_username[50];// made an array to take input for deletion of the file of the user
        		printf("\nEnter Username to delete record:\t");
        		input(delete_username);

        		printf("\nEnter 'DELETE_CONFIRM' to confirm deletion:\t");
        		char confirm_delete[50];
        		input(confirm_delete);

        		if (strcmp(confirm_delete, "DELETE_CONFIRM") == 0) /*mathi delete_username bhannne array ma j type gareko thiyo tei namile samma u cant delete the files, 
        														   	this is done so that user doesn't accidentally delete their record	*/
	    		{
            		FILE *temp = fopen("P:\\Login2\\temp.txt","w");// creates the temp(new) file for transferring the 
            		if (temp==NULL) 
		    		{
                		printf("Error creating temporary file");
                		break;
            		}

            		p=fopen("P:\\Login2\\Users.txt", "r");
            		if (p==NULL) 
		    		{
                		printf("\n\nNo File Detected");
                		fclose(temp);
                		break;
            		}

            		int deleted=0;// flag to see if the file has been deleeted or not
            		while (fread(&user, sizeof(struct user), 1, p)) 
		    		{
                		if (strcmp(user.username, delete_username) != 0) // checks the entered username(thats going to be deleteed) to the username in the file,
                														// its transferring the unmatched file to another file, it only goes to else if the useeername are mathced
			    		{
                    		fwrite(&user, sizeof(struct user), 1, temp);
                		} 
			    		else 
			    		{
                    		deleted=1;
                		}
            		}
            		fclose(p);
            		fclose(temp);
            		if (deleted==1) 
		    		{
                		remove("P:\\Login2\\Users.txt");// yesle chai original file lai delete garxa (this remove and rename function is contained in the stdio.h header file)
                		rename("P:\\Login2\\temp.txt", "P:\\Login2\\Users.txt");// renames the temporary file to the original file name, hence making the temp file your main file now
                		printf("\n\nRecord deleted successfully.");
            		} 
		    		else 
		    		{
                		remove("P:\\Login2\\temp.txt");
                		printf("\n\nUsername not found.");
            		}
        		} 
	    		else 
	    		{
            		printf("\n\nDeletion cancelled.");
        		}    		
        	break;
        	
        case 5:
            printf("\n\n\t\t\t\t*****Thanks For The Visit*****\n");
            exit(0);

        default:
            printf("\n\n\t\t\t\tWrong Input!!! Try Again\n");
            goto here;//line 68
            break;
    }
    return 0;
}
