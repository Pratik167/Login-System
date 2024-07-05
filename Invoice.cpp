#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13 //Ascii
#define BKSPC 8

struct items
{
    char item[20];
    float price;
    int qty;
};
struct menus
 {
  char item[20];
  int price;
 }menu;
struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};
struct user
{
    char name[50];
    char username[50];
    char password[50];
    char phone[50];
    char verify[50];
};

int admin()
{
FILE *tp,*mp,*cp;
int adminc,menuc,choice;
int newp,find=0;
char irem[20],choicem,cprice[20];
      system("cls");
      fflush(stdin);
   printf("\t\t\t\tPress 1 to Confirm:\t");
      fflush(stdin);
      scanf("%d",&adminc);
      system("cls");
        switch(adminc)
         {
flag:
       case 1:
   {
    mathi:
    system("cls");
     printf("\t\t\t\t------MENU SECTION------");
  printf("\n\n\n\n1.Add item");
  printf("\n2.Remove item");
  printf("\n3.Change price");
  printf("\n4.View current menu");
  printf("\n5.Go back");
  printf("\n6.Exit");
  printf("\nEnter what u wanna do:\t");
  fflush(stdin);
  scanf("%d",&menuc);
  system("cls");
  switch(menuc)
  {
  case(1)://Add item ko
  {
  flag1:
  system("cls");
  printf("Redirecting Please Wait");
        for (int q=0;q<3;q++)
{
                        Sleep(100);
                        printf(".");
                        Sleep(100);
                        printf(".");
                        Sleep(100);
                        printf(".");
                        Sleep(100);
                        printf("\b \b");
                        printf("\b \b");
                        printf("\b \b");
                    }
                    system("cls");
        printf("\t\t\t\t------MENU------");
        printf("\n\n\n\n");
tp=fopen("P:\\invoice\\menu.txt","a+");
while(fread(&menu,sizeof(menu),1,tp)==1)
           {
               printf("+-----------------------------------------------+\n");
                            printf("|%s",menu.item);
                            if(strlen(menu.item)>40)
          {
        goto r;
}
       for(int i=strlen(menu.item);i<=40;i++)
        {
        printf(" ");
}
r:
                              printf("Rs_%d",menu.price);
                            printf("\n+-----------------------------------------------+");
                              printf("\n");
           }
fclose(tp);
  struct menus tempmenu;
             tp=fopen("P:\\invoice\\menu.txt","a+");
     fflush(stdin);
  printf("\nEnter the name of item:");
  gets(menu.item);
  while(fread(&tempmenu,sizeof(tempmenu),1,tp)==1)
  {
  if(strcmp(tempmenu.item,menu.item)==0)
  {
  printf("The item already exists\n");
  printf("Press y to change the price: ");
  scanf("%c",&choicem);
  if(choicem=='y'||choicem=='Y')
  {
  printf("\nEnter the new price of item:");
  scanf("%d",&menu.price);
  fwrite(&menu,sizeof(menu),1,tp);
  goto pricec;
}
printf("check the name of item ");
goto flag1;
}
}
  printf("\nEnter the price of item:");
  scanf("%d",&menu.price);
  fwrite(&menu,sizeof(menu),1,tp);
  pricec:
  printf("\nPress 'y' to add more items:");
  fflush(stdin);
  scanf("%c",&menuc);
  if(menuc=='Y'||menuc=='y')
  {
 fclose(tp);
  goto flag1;
  break;
}
else
{  
   fclose(tp);
   Sleep(1000);
goto flag;
break;
}
goto mathi;
}
case(2):
{
system("cls");
      flag2:
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
find=0;
system("cls");
        printf("\t\t\t\t------MENU------");
        printf("\n\n\n\n");
tp=fopen("P:\\invoice\\menu.txt","a+");
while(fread(&menu,sizeof(menu),1,tp)==1)
           {
               printf("+-----------------------------------------------+\n");
                            printf("|%s",menu.item);
                            if(strlen(menu.item)>40)
           {
        goto s;
}
       for(int i=strlen(menu.item);i<=40;i++)
        {
        printf(" ");
}
s:
                              printf("Rs_%d",menu.price);
                            printf("\n+-----------------------------------------------+");
                              printf("\n");
           }
fclose(tp);
tp=fopen("P:\\invoice\\menu.txt","r");
 printf("\nEnter the name of item yoy want to remove:\t");
 fflush(stdin);
 scanf("%s",irem);
 mp=fopen("P:\\invoice\\tempmenu.txt","w");
 while(fread(&menu,sizeof(menu),1,tp)==1)
 {
  if(strcmp(irem,menu.item)==0)
  {
  find=1;
 }
 else
  {
  fwrite(&menu,sizeof(menu),1,mp);
 }
 }
 if(find==0)
 {
  printf("The item doesnt exist");
  goto flag2;
 }
else
{
 fclose(mp);
 fclose(tp);
 remove("P:\\invoice\\menu.txt");
 rename("P:\\invoice\\tempmenu.txt","P:\\invoice\\menu.txt");
 printf("Item removed succesfully");
 printf("\nPress 'y' to remove more itesm:\t");
                              fflush(stdin);
                         scanf("%c",&choice);
                         if(choice=='y'||choice=='Y')
                            {
                         goto flag2;
                                }
 else
 {
  goto flag;
 }
}
 break;
 goto mathi;
}
case(3):
{
flag3:
system("cls");
find=0;
system("cls");
        printf("\t\t\t\t------MENU------");
        printf("\n\n\n\n");
tp=fopen("P:\\invoice\\menu.txt","a+");
while(fread(&menu,sizeof(menu),1,tp)==1)
           {
               printf("+-----------------------------------------------+\n");
                            printf("|%s",menu.item);
                            if(strlen(menu.item)>40)
           {
        goto t;
}
       for(int i=strlen(menu.item);i<=40;i++)
        {
        printf(" ");
}
t:
                              printf("Rs_%d",menu.price);
                            printf("\n+-----------------------------------------------+");
                              printf("\n");
           }
fclose(tp);
printf("\nenter the name of item you wanna change price of:");
fflush(stdin);
gets(cprice);
tp=fopen("P:\\invoice\\menu.txt","a+");
                       mp=fopen("P:\\invoice\\tempmenu.txt","a+");
while(fread(&menu,sizeof(menu),1,tp)==1)
   {
    if(strcmp(cprice, menu.item)!=0)
    {
    fwrite(&menu,sizeof(menu),1,mp);
    continue;
}
 else if(strcmp(cprice, menu.item)==0)
 {
  printf("enter the new price:");
  scanf("%d",&newp);
  menu.price=newp;   
  fwrite(&menu, sizeof(menu), 1, mp); // Write the updated record back to the file
  find = 1;
  continue;
 }
}
if(!find)
{
printf("item not found");
            }
            else
            {
            done:
            fclose(tp);
            fclose(mp);
            remove("P:\\invoice\\menu.txt");
            rename("P:\\invoice\\tempmenu.txt","P:\\invoice\\menu.txt");
  printf("Price changed succesfully!");
          printf("\nPress 'y' to continue changing the prices:\t");
       
                                   fflush(stdin);
                              scanf("%c",&choice);
                              if(choice=='y'||choice=='Y')
                                  {
                           
                             goto flag3;
                                  }
       else
      {
      fclose(tp);
       goto flag;
       }
     }
     break;
     goto mathi;
 }
 case (4):
  {
  system("cls");
  mathireturns:
        printf("\t\t\t\t------MENU------");
        printf("\n\n\n\n");
tp=fopen("P:\\invoice\\menu.txt","r");
while(fread(&menu,sizeof(menu),1,tp)==1)
           {
               printf("+-----------------------------------------------+\n");
                            printf("|%s",menu.item);
                            if(strlen(menu.item)>40)
            {
        goto u;
			}
       for(int i=strlen(menu.item);i<=40;i++)
        {
        printf(" ");
		}
u:
                              printf("Rs_%d",menu.price);
                            printf("\n+-----------------------------------------------+");
                              printf("\n");
           }
           printf("Press b to go back:");
           fflush(stdin);
           scanf("%s",&choicem);
           if(choicem=='b'||choicem=='B')
           {
            goto mathi;
            fclose(tp);
  		}
 		 else
  		{
  				goto mathireturns;
  				fclose(tp);
  }
break;
 }
 case (5):
  {
  system("cls");
  return 0;
 }
 case (6):
  {
  system("cls");
  return 1;
}
default:
{
printf("Enter valid choice");
}
}
break;
     }
 break;
 }
 return 0;
}
 
//this function generates the top part of your bill, like your restaurants name and the format haru
void generateBillTop(char name[50],char date[30])//just a bunch of prints
{
FILE *p;
    printf("\n\n");
        p=fopen("P:\\invoice\\Users.txt","r");
         if (p == NULL) {
        printf("Error opening file.\n");
       
    }
        struct user datec;
        printf("\t\t    Bing Chilling. Restaurant");
        printf("\n\t\t   --------------------------");
        while(fread(&datec,sizeof(datec),1,p)==1)
        {
        printf("\nContact no:%s",datec.phone);
}
        printf("\nDate:%s",date);
        printf("\nInvoice of: %s",name);
        printf("\n");
        printf("-----------------------------------------------------\n");
        printf("Items:\t\t\t");
        printf(" Qty:\t\t\t");
        printf("Total:\t\t\t");
        printf("\n-----------------------------------------------------");
        printf("\n\n");
        fclose(p);
}
void generateBillMid(char item[30],int qty, float price)//this chai displays the item that was ordered and the prices
{
        int i=0;
        printf("%s",item);
        if(strlen(item)>27)
        {
        goto r;
}
        for(i=strlen(item);i<=25;i++)
        {
        printf(" ");
}
r:
        printf("%d\t\t\t",qty);
        printf("%.2f\t\t\t",qty * price);
        printf("\n");
}

void generateBillBottom(float total)//yo chai paisa wala part ko lagi
{
float dis=0;
    printf("\n");
    if(total>500)
    {
    dis=total*0.1;//10% discount
}
else
{
dis=0;
}
    float netTotal=total-dis;
    float vat=0.09*netTotal;
float grandTotal=netTotal + vat;//netTotal + cgst + sgst
    printf("------------------------------------------------------\n");
    printf("Sub Total\t\t\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t\t\t-----");
    printf("\nNet Total\t\t\t\t\t%.2f",netTotal);
    printf("\nVAT @9%s\t\t\t\t\t\t%.2f","%",vat);
    printf("\n-----------------------------------------------------");
    printf("\nGrand Total\t\t\t\t\t%.2f",grandTotal);
    printf("\n-----------------------------------------------------\n");
}
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
    int check=0,usercheck=0;
    int rv=0;
    struct user user;
    char confirmpass[50];
    here1:
    system("cls");
    printf("\n\t\t\t\t--------Welcome to The Program---------");
    printf("\n\n\n What would you like to do:");
    printf("\n 1. Signup");
    printf("\n 2. Login");
    printf("\n 3. Delete your Account");
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
                           
{
                int admin_exists = 0;
                p=fopen("P:\\invoice\\Users.txt","r");
                if (p!=NULL)
{
                    struct user temp;
                    while (fread(&temp, sizeof(struct user), 1, p))
{
                            admin_exists = 1;
                            break;
                    }
                    fclose(p);
                }
                if (admin_exists)
{
                    printf("\n\a An admin already exists!\n");
                    goto login;
                }
            }
            printf("\n Enter Your Full Name:\t");
            input(user.name); // yo function bhaye paxi fflush garnu pardaina
            numcheck:
            printf(" Enter Your Number:\t");
            input(user.phone);
            if(strlen(user.phone)!=10)
            {
            printf(" Wrong number!!\n");
            goto numcheck;
}
            while (1)
    {
        int username_exists = 0;
        printf(" Enter Username:\t");
        input(user.username);

        p=fopen("P:\\invoice\\Users.txt","r");
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
                p = fopen("P:\\invoice\\Users.txt", "a+");
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
                    printf("\nPlease Enter The Code:");
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
                    printf("\n\n Registration Successful\n");
                    goto login;
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
            goto confirmpassword;
            break;

                case 2:
        {
            login:
            printf("Redirecting to Login Page\n\t\t\t\tPlease Wait");
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
            printf("\n\t\t\t\t\t------LOGIN------");

            char username[50], passw[50];
            struct user login;
            int flag = 0;
            int z = 0; // number of tries

            loggin:
            p = fopen("P:\\invoice\\Users.txt", "r");
            if (p == NULL)
            {
                printf("\n\nNo File Detected");
                break;
            }
            printf("\n Enter your username:\t");
            input(username);
            printf("\n Enter your password:\t");
            inputpass(passw);


            while (fread(&login, sizeof(struct user), 1, p))
            {
                if (strcmp(login.username, username) == 0 && strcmp(login.password, passw) == 0)
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
                    printf("\n\n\n\t\t\t\t Login Success");

                    flag = 1;
                    system("cls");

                    //biling or invoice ko code chai from here
                    int opt,n;
                    struct orders ord;
                    struct orders order;
                    char saveBill = 'y',contFlag = 'y';
                    char name[50];
                    FILE *fp;
                    //first display
                    while(contFlag == 'y')
                    {
                     beta:
                        system("cls");
                        float total = 0;
                        int invoiceFound = 0;
                        printf("\t============Bing Chilling. RESTAURANT============");
                        printf("\n\nPlease select what you wanna do");
                        printf("\n\n1.Generate Invoice");
                        printf("\n2.Show all Invoices");
                        printf("\n3.Search Invoice");
                        printf("\n4.Changes in Menu");
                        printf("\n5.Exit");

                        printf("\n\nYour choice:\t");
                        scanf("%d",&opt);
                        fgetc(stdin);
                        switch(opt)
{
        case 1:
        FILE *tp;
        check=0;
        system("cls");
        printf("\t\t\t\t------MENU------");
        printf("\n\n\n\n");
tp=fopen("P:\\invoice\\menu.txt","a+");
while(fread(&menu,sizeof(menu),1,tp)==1)
           {
               printf("+-----------------------------------------------+\n");
                            printf("|%s",menu.item);
                            if(strlen(menu.item)>40)
           {
        goto r;
			}
       for(int i=strlen(menu.item);i<=40;i++)
        {
        printf(" ");
		}
r:
                              printf("Rs_%d",menu.price);
                            printf("\n+-----------------------------------------------+");
                              printf("\n");
           }
fclose(tp);
        printf("\nPlease enter the name of the customer:\t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1] = 0;
        strcpy(ord.date,__DATE__);
        printf("\nPlease enter the number of items:\t");
        scanf("%d",&n);
        ord.numOfItems = n;
        for(int i=0;i<n;i++)
{
            wrongitem:
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            tp=fopen("P:\\invoice\\menu.txt","a+");
while(fread(&menu,sizeof(menu),1,tp)==1)
{
  if(strcmp(menu.item,ord.itm[i].item)==0)
  {
   printf("Please enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            ord.itm[i].price=menu.price;
            total += ord.itm[i].qty * ord.itm[i].price;
            check=1;
      }
}
            if(check==0)
            {
            printf("Item doesnt exist.");
            goto wrongitem;
}
        }
//invoice ko detail gareepaxi hune display ko lagi
printf("Preparing Bill");
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
        generateBillTop(ord.customer,ord.date);
       
        for(int i=0;i<ord.numOfItems;i++)//kati ota  item order garyo teti samma chai yo loop chalxa
{
            generateBillMid(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
       
        generateBillBottom(total);

        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s",&saveBill);

        if(saveBill=='y'||saveBill=='Y')//invoice save garne bhayee y press garne
{
printf("\n\n\t\t\t\tSaving");
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
            fp = fopen("P:\\invoice\\RestaurantBill.txt","a+");//if presseeed y it opens this restaurantbill.txt file ani fwrite le invoice save garxa
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0)
            printf("\nSuccessfully saved");
            else
            printf("\nError saving");
            fclose(fp);
        }
        break;

        case 2:
        check=0;
        printf("\n\n\t\t\t\tLoading");
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
        fp =fopen("P:\\invoice\\RestaurantBill.txt","r");
        rewind(fp);
        printf("\n  *****Your Previous Invoices*****\n");
        while(fread(&order,sizeof(struct orders),1,fp))
{
           
            float tot = 0;
            generateBillTop(order.customer,order.date);
            for(int i=0;i<order.numOfItems;i++)
{
                generateBillMid(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;
            }
            generateBillBottom(tot);
        }
       
        fclose(fp);
        break;

        case 3:
        printf("Enter the name of the customer:\t");
        fgets(name,50,stdin);
        name[strlen(name)-1] = 0;
        printf("\n\n\t\t\t\tSearching");
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
        fp = fopen("P:\\invoice\\RestaurantBill.txt","r");
        printf("\t*****Invoice of %s*****",name);
        while(fread(&order,sizeof(struct orders),1,fp))
{
            float total = 0;
            if(!strcmp(order.customer,name))
{
            generateBillTop(order.customer,order.date);
            for(int i=0;i<order.numOfItems;i++)
{
                generateBillMid(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                total+=order.itm[i].qty * order.itm[i].price;
            }
            generateBillBottom(total);
            invoiceFound = 1;
            }
       
        }
        if(!invoiceFound)
{
            printf("\nSorry the invoice for %s doesnot exists",name);
        }
        fclose(fp);
        break;
        case 4:
        char back;
        rv=admin();
                if(rv==1)
                {
                printf("Thank You");
                exit(0);
}
else
{
                goto beta;
}
        break;

    case 5:
    printf("\n\t\t Bye Bye :)\n\n");
    exit(0);
    break;

    default:
    printf("Sorry invalid option");
    break;
    }
    printf("\nDo you want to perform another operation?[y/n]:\t");
    scanf("%s",&contFlag);
    }
    printf("\n\t\t Bye Bye :)\n\n");
    printf("\n\n");

                    break; // Exiting the loop once login is successful
                }
            }

            fclose(p);


            // When username or password is incorrect
            if (!flag)
            {
                z++;
                printf("\n\nWrong Username Or Password");
                if (z >= 3)
                {
                    // Maximum attempts reached
                    printf("\n\nAttempt Limit Reached. Redirecting to password recovery...");
                    goto teta;
                }
                printf("\nTry again\n\n");
                goto loggin;
            }

            // Password recovery block after 3 failed attempts
            teta:
            while (z >= 3)
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
                system("cls");
                printf("\t\t\t\t-----PASSCODE REDEMPTION-----");
                printf("\n1. Change Password?");
                printf("\n2. Exit?");
                printf("\n Choose:");
                scanf("%d", &m);
                fgetc(stdin);
                switch (m)
                {
                    case 1:
                    {
                        char verify[50];
                        printf("Enter Verifier Code:\t");
                        input(verify);
                        p = fopen("P:\\invoice\\Users.txt", "r+");
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
                                fseek(p, -(long)sizeof(struct user), SEEK_CUR); // SEEK_CUR means current position
                                fwrite(&login, sizeof(struct user), 1, p);
                                printf("\nPassword changed successfully.");
                                fclose(p);
                                goto end;
                            }
                        }
                        printf("\n Incorrect Verifier Code.");
                        fclose(p);
                        exit(0);
                    }
                    case 2:
                        printf("\n Ok BYE BYE");
                        exit(0);

                    default:
                        printf("Wrong input");
                        goto teta;
                }
            }
            end:
            break;
        }
        case 3:
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
        usnf:
        printf("\nEnter Username to delete record:\t");
        input(delete_username);
         p=fopen("P:\\invoice\\Users.txt", "r");
            if (p==NULL)
    {
                printf("\n\nNo File Detected");
           }
        while (fread(&user, sizeof(struct user), 1, p))
    {
    	     if(strcmp(user.username,delete_username)==0)
    	     {
    	     	usercheck=1;
    	     	continue;
    	     }
    	     
	}
	if(!usercheck)
	{
		printf("USER NOT FOUND!");
		goto usnf;
	}
	fclose(p);
        printf("\nEnter 'DELETECONFIRM' to confirm deletion:\t");
        char confirm_delete[50];
        input(confirm_delete);

        if (strcmp(confirm_delete, "DELETECONFIRM") == 0) /*mathi delete_username bhannne array ma j type gareko thiyo tei namile samma u cant delete the files,
          this is done so that user doesn't accidentally delete their record */
    {
           
            p=fopen("P:\\invoice\\Users.txt", "r");
            if (p==NULL)
    {
                printf("\n\nNo File Detected");
               
                break;
            }

            int deleted=0;// flag to see if the file has been deleeted or not
            while (fread(&user, sizeof(struct user), 1, p))
    {
    	     if(strcmp(user.username,delete_username)==0)
    	     {
    	     	
               		remove("P:\\invoice\\Users.txt");// yesle chai original file lai delete garxa (this remove and rename function is contained in the stdio.h header file
                    deleted=1;
			 }
            }
            fclose(p);
           
        if (deleted==1)
    {
    char a;
                printf("\n\nDo you want to Remove the Current data's too?\n Press Y to confirm:");
                scanf("%s", &a);
                fflush(stdin);
            if (a == 'Y' || a == 'y')
            {
            	remove("P:\\invoice\\Users.txt");
                remove("P:\\invoice\\menu.txt");
                remove("P:\\invoice\\RestaurantBill.txt");
                printf("\n\nRecord deleted successfully.");
                 printf("\nRedirecting Please Wait");
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
                goto here1;
            }
            else
            {
                remove("P:\\invoice\\Users.txt");
				//remove("P:\\invoice\\Users.txt");// yesle chai original file lai delete garxa (this remove and rename function is contained in the stdio.h header file)  
                printf("\n\nAdmin record deleted successfully.");
                 printf("\nRedirecting Please Wait");
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
                goto here1;
}
        }
    else
    {
                remove("P:\\invoice\\temp.txt");
                printf("\n\nUsername not found.");
                goto here1;
            }
        }
    else
    {
            printf("\n\nDeletion cancelled.");
             printf("\nRedirecting Please Wait");
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
            goto here1;
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
