#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
 struct admins
 {
 	char username[50];
 	char fname[50];
 	char password[50];
 	char phone[10];
 	char verify[50];
 }admin;
 struct menus
 {
 	char item[20];
 	int price;
 }menu;
 struct customers
 {
 	char name[50];
 	long long int num;
 }customer;
 
 #define ENTER 13 
 #define BKSPC 8
 FILE *fp,*sp;
 void addadmin();
 void removeadmin();
 void input(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0; 
}
void inputpass(char pass[50])
{ 
    int i=0;
    char ch;
    while (1)
{
        ch = _getch(); 
        if (ch==ENTER)
{ 
            pass[i] = '\0'; 
            break;
        }
else if (ch==BKSPC)
{
            if(i>0)
{ 
                i--;
                printf("\b \b"); 
            }
        }
else
{ 
            pass[i++] = ch; 
            printf("* \b");
        }
    }
}
 
 int main()
 {
 	FILE *mp,*tp,*cp;
 	int c,menuc,price,tprice;
 	int find=0,newp,quantity;
 	char back=0,irem[20],choice=0,customerc=0,adminc=0;
 	fp = fopen("admindata.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }
 	
	 	while(1)
 	{
	 flag0:
	c=0;
 	printf("1. admin\n"); 
 	printf("2. customer\n");
 	printf("ko ho ");
 	fflush(stdin);
 	scanf("%d",&c);
 
 	if(c==1)
 	    { 
 	    flag:
 	    	system("cls");
 	    	fflush(stdin);
 	 	   printf("1.change menu\n"); 
 	 	   printf("2.view all the bills\n");
	       printf("2.add admin\n");
 	       printf("3.remove admin\n");
 	       printf("4.view all the admins\n");
 	       printf("press b to go back\n");
 	       printf("What do u wanna do:");
 	       fflush(stdin);
 	       scanf("%d",&adminc);
 	       	
 	      system("cls");
			
 	       switch(adminc)
 	        {
 		      case 1:
 			  {
 			    
 				printf("\n1.add item");
 				printf("\n2.remove item");
 				printf("\n3.change price");
 				printf("\n4.view current menu");
 				printf("\nenter what u wanna do");
 				scanf("%d",&menuc);
 				switch(menuc)
 				{
 					case(1):
 						{
 							flag1:
 				            tp=fopen("menu.txt","a");
 						    fflush(stdin);
 						    
 							printf("\nEnter the name of item:");
 							gets(menu.item);
 							printf("\nEnter the price of item:");
 							scanf("%d",&menu.price);
 							fwrite(&menu,sizeof(menu),1,tp);
 							printf("\ndo u wanna add anything more.if yes press y");
 							fflush(stdin);
 							scanf("%c",&menuc);
 							if(menuc=='Y'||menuc=='y')
 							{
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
 							
						 }
					case(2):
						{
							flag2:
						  printf("\nenter the name of item u wanna remove");
						  scanf("%s",irem);
						  mp=fopen("tempmenu.txt","a+");
						  while(fread(&menu,sizeof(menu),1,tp)==1)
						  {
						  	if(strcmp(irem,menu.item)!=0)
						  	{
						  		fwrite(&menu,sizeof(menu),1,mp);
							  }
							  fclose(mp);
							  fclose(tp);
							  remove("menu.txt");
							  rename("tempmenu.txt","menu.txt");
							  printf("\nDo you wanna remove more item,if yes press y");
                              fflush(stdin);
	                          scanf("%c",&choice);
	                          if(choice=='y'||choice=='Y')
                            	{
                            	  tp=fopen("menu.txt","a+");
	                         	  goto flag2;
                               	}
							  else
							  {
							  	goto flag;
							  }
						  }	
						  break;
						}
						case(3):
							{
								memset(&irem,'0',sizeof(irem));
								flag3:
								printf("\nenter the name of item you wanna change price of:");
								scanf("%s",&irem);
								while(fread(&menu,sizeof(menu),1,tp)==1)
							    {
								  if(strcmp(irem, menu.item)==0)
								  {
								  	printf("enter the new price:");
								  	scanf("%d",&newp);
								  	menu.price=newp;
								  	fseek(tp,-sizeof(menu),SEEK_CUR); // Move the file pointer back to the beginning of the current record
                                    fwrite(&menu, sizeof(menu), 1, tp); // Write the updated record back to the file
                                     find = 1;
								  }
									
								}
								if(!find)
								{
									printf("item not found");
				             	}
				             	else
				             	{
								   printf("price changed succesfully!");
						           printf("\nDo you wanna remove more item,if yes press y");
						        
                                   fflush(stdin);
	                               scanf("%c",&choice);
	                               if(choice=='y'||choice=='Y')
                                 	{
                            
	                         	      goto flag3;
                                 	}
							        else
							       {
							  	      goto flag;
							        }
						      }
						      break;
						  }	
						  case (4):
						  	{
						  		tp=fopen("menu.txt","r");
						  	    while(fread(&menu,sizeof(menu),1,tp)==1)
	 	                           {
	 	                             	printf("%s",menu.item);
	 	                               	printf("%d",menu.price);
	 	                               	printf("\n");
		                            }
									fclose(tp);	
							  }
					break;
				}
					break;
		      }
		      case 2:
		      	{
		      		cp=fopen("customer.txt","r");
		      		while(fread(&customer,sizeof(customer),1,cp)==1)
		      		{
		      			printf("%s\t",customer.name);
		      			printf("%lld",customer.num);
		      			printf("\n");
					  }
					  fclose(cp);
					  break;
				  }
	          case 3:
	          	{
	          	  addadmin();	
	          	  break;
				}
			   case 4:
			   	{
			   	  removeadmin();
			   	  break;
				}
				case 5:
				{
	        	while(fread(&admin,sizeof(admin),1,fp)==1)
	        	{
	        		
	        		printf("\n %s",admin.username);
	        		
	            }
	                printf("press a to go back");
	        		scanf("%c",back);
	        		if(back=='a'||back=='A')
	        		{
	        			goto flag;
					}
	            break;
				}
		   default:
		   {
		   	printf("please enter a valid choice");
		   	goto flag;
		   }
		   }
            break;
	     } 
       
	else if(c==2)
	 	{
	 	  tp=fopen("menu.txt","r");
	 	  rewind(tp);
	 	  cp=fopen("customer.txt","a");
	 	  memset(&irem,'0',sizeof(irem));
	 	  printf("Welcome\n");
	 	  while(fread(&menu,sizeof(menu),1,tp)==1)
	 	  {
	 	  	printf("%s",menu.item);
	 	  	printf(" %d",menu.price);
	 	  	printf("\n");
		  }
		  cflag:
		  printf("Enter your name:");
		  fflush(stdin);
		  gets(customer.name);
		  printf("Enter your contact detail:");
		  scanf("%lld",&customer.num);
		  fwrite(&customer,sizeof(customer),1,cp);
		  printf("Enter the name of item you wanna order: ");
		  fflush(stdin);
		  gets(irem);
		  printf("Enter the quantity u wanna order");
		  scanf("%d",&quantity);
		  while(fread(&menu,sizeof(menu),1,tp)==1)
	 	  {
	 	  	if(strcmp(irem,menu.item)==0)
	 	  	{
	 	  	
	 	  		price=menu.price*quantity;
	 	  	    tprice+=price;
	 	  		
			   }
			   else
			   {
			   	continue;
			   }
        	}
        printf("\nD you wanna order anything else");
        fflush(stdin);
        scanf("%c",&customerc);
        if(customerc=='y'||customerc=='Y')
        {
        	goto cflag;
		}
		else
		{
			fclose(tp);
			printf("BILL\n");
			printf("%s         %lld\n",customer.name,customer.num);
			printf("your total is %d",price);
		}
	 	  break;
		 }
    else
    {
    	printf("invalid choice!");
	}
	 
}

	fclose(fp);
  return 0;
}
void addadmin()
{
	int q;
	char back;
	char confirmpass[50];

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
            fflush(stdin);
            input(admin.fname); 
            printf(" Enter Your Number:\t");
            input(admin.phone);
            printf(" Enter Username:\t");
            input(admin.username);
            printf(" Enter Password:\t");
            inputpass(admin.password); 
            printf("\nEnter Confirmation Password:");
            inputpass(confirmpass);

            if (strcmp(admin.password, confirmpass) == 0)
{ 
                fp = fopen("admindata.txt", "a+");
                if (fp == NULL)
{
                    perror("Error opening file");
                    exit(0);
                }
                
                char a;
                printf("\n\nDo you want to Add a Verifier, In case you forget your password?\n Press Y to confirm:");
                scanf("%c", &a);
                fflush(stdin);
                if (a == 'Y' || a == 'y')
{
                    printf("\nEnter a code(this should be known only by you and it can't be changed):\t");
                    input(admin.verify);
                    printf("\n\nThis must be remembered to change the passcode!!!");  
                }
else
{
                    printf("\nDon't Forget the passcode then");
                }

                fwrite(&admin, sizeof(admin), 1, fp);
                fflush(fp);
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
                fclose(fp);
            }
}
void removeadmin()
{
	char choice;
	char name[50];
	flag2:
	fp=fopen("admindata.txt","a+");
	if(fp==NULL)
	{
		printf("Sorry the file couldnt be opened");
	}
	printf("Who do u wanna remove?");
	scanf("%s",name);
	sp=fopen("tempadmin.txt","a+");
    while(fread(&admin,sizeof(admin),1,fp)==1)
    {
    	if(strcmp(admin.username,name)!=0)
    	{
    	fwrite(&admin,sizeof(admin),1,sp);
        }
	}
	fclose(fp);
	fclose(sp);
	remove("admindata.txt");
	rename("tempadmin.txt","admindata.txt");
	printf("Do you wanna remove more admins:");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y'||choice=='Y')
	{
		goto flag2;
	}
	
}
