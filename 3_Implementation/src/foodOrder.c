#include"order.h"


void main()
{   
        system("cls");
	printf(" ----------------------------------------------------------------------------\n");
	printf("|               Heyy Folks order your food now!!!!                            |\n");
	printf(" ----------------------------------------------------------------------------\n\n\n");
	printf("          1. ADMINISTRATION SECTION \n\n          2. CUSTOMER SECTION \n\n          3. Exit \n\n\n             Enter Your Choice --->");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		administration();
	}
	else if(choice==2)
	{
		customer();
	}
	
	else if(choice==3)
	{
		exit(0);
	}

	else
	{
		printf("Please Re-enter The Correct input");
		main();
	}
}

void administration()
{  
	system("cls");
	printf("          1. Add New Employee\n\n          2. view records \n\n         3.View orders\n\n          4. Back To Main Menu \n\n             Enter Your Choice --->");
	int n;
	scanf("%d",&n);
		printf("\n\n");
	
	printf("\n\n");
	if(n==1)
	{
		addrecord();
	}
	
	else if(n==2)
	{
		viewrecord();
	}

	else if(n==3)
	{
		FILE *list;
		char viw;
		list = fopen("order.txt","rt");
		while((viw=fgetc(list))!=EOF)
		{
			printf("%c",viw);
		}
		fclose(list);
		printf(" Press ENTER to return to main menu");
      if(getch()==13)
      administration();
	}
	else if(n==4)
	{
		main();
	}
	else
	{
		printf("Please Re-enter The Correct input");
		if(getch())
		administration();
	}
	
}

void addrecord()
{
	system("cls");
	fp=fopen("record1.txt","a");
	if(getdata()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&emp,sizeof(emp),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("The Record Is Successfully Saved ! !\n\n");
		printf("Save any more?(Y / N): ");
		if(getch()=='n')
	    	administration();
		else
	    	system("cls");
	    	addrecord();
	}	
}


void viewrecord() 
{
    system("cls");
    printf("              Employee Details\n\n");
    printf("            DEPARTMENT        ID        EMPLOYEE NAME        D.O.B        Y.O.J        PLACE\n\n");
    
    fp=fopen("record1.txt","r");
    while(fread(&emp,sizeof(emp),1,fp)==1)
    {
		printf("%s",emp.department);
		printf("%d",emp.id);
		printf("%s",emp.name);
		printf("%d/%d/%d",emp.dd,emp.mm,emp.yy);
		printf("%d",emp.YOJ);
		printf("%s",emp.place);
	}
      
      fclose(fp);
      printf(" Press ENTER to return to main menu");
      if(getch()==13) 
      administration();
      
}


int checkid(int c)  
{
	rewind(fp);
	while(fread(&emp,sizeof(emp),1,fp)==1)
	if(emp.id==c)
	   return 0; 
    else 
	   return 1; 
}

int getdata()
{
	int is_leap = 0, flag = 1;
	printf("        Employee ID :\t");
	scanf("%d",&t);
	if(checkid(t)==0)
	{
		printf("\n\n");
		printf("\a        The Employee Record Already Exists !!!\a");
		getch();
		main();
		return 0;
	}
	emp.id=t;
	printf("        Employee Name : ");
	scanf("%s",emp.name);
	printf("        Date Of Birth (dd/mm/yyyy) :");
	scanf("%d/%d/%d",&emp.dd,&emp.mm,&emp.yy);
      
    if (emp.yy >= 1800 && emp.yy <= 9999) 
    {
        if ((emp.yy % 4 == 0 && emp.yy % 100 != 0) || (emp.yy % 400 == 0)) 
        {
            is_leap = 1;
        }
        if(emp.mm >= 1 && emp.mm <= 12)
        {
             if (emp.mm == 2)
            {
                if (is_leap && emp.dd == 29) 
                {
                    flag = 1;
                }
                else if (emp.dd > 28) 
                {
                    flag = 0;
                }
            }
            else if (emp.mm == 4 || emp.mm == 6 || emp.mm == 9 || emp.mm == 11) 
            {
                if (emp.dd > 30)
                {
                    flag = 0;
                }
            }
            else if(emp.dd > 31)
            {            
                flag = 0;
            }        
        }

        else
        {
            flag = 0;
        }
    }
    else
    {
        flag = 0;
    }


  if(flag)
  {
	printf("        Year OF Joining :");
	scanf("%d",&emp.YOJ);
	printf("        Place :");
	scanf("%s",emp.place);
	printf("        Department :");
	scanf("%s",emp.department);
	return 1;
  }
  else
  {
  	printf("Enter valid details\n Press enter to retype or X to get back to menu");
    if(getch()==13) 
  	 addrecord();
  	else
  		administration();
  }
}


void customer()
{

  system("cls");
  printf("       1. Veg\n\n               2. Non-Veg\n\n               3. Soft\n\n               4. Chats\n\n               5. Back To Main Menu\n\n   Enter Your Choice  -->");
  int k;
  scanf("%d",&k);
  
  if(k==1)
  {
    system("cls");
    vegmenu();
  }
  else if(k==2)
  {
    system("cls");
    nonvegmenu();
  }
  if(k==3)
  {
    system("cls");
    //drinksMenu();
  }

  if(k==4)
  {
    system("cls");
    //chatsmenu();
  }
  else if(k==5)
  {
    system("cls");
    main();
  }
  else
  {
    printf("!Please Re-enter The Correct Option......\n\n");
    customer();
  }
}


void nonvegmenu()
{
  int choice;
  int again;
  int quantity;
  double price=0;
  printf("                    Non Veg. Menu\n");
  printf("--------------------------------------------------\n");
  char n;
  FILE *nmenu;
  nmenu = fopen("nonveg.txt","rt");
  while((n=getc(nmenu))!=EOF)
  {
    printf("%c",n);
  }
  printf("\n\nEnter What You Want :");
  printf("\n\n");
  scanf("%d",&choice);
  if(choice==1)
  {
    printf("Quantity : ");
    scanf(" %d",&quantity);
    total=total + 100*(quantity);
    printf("\n");
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf(" %d",&again);
    if(again==1)
    {
      printf("\n\n");
      nonvegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is :%.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
      details();
    }
  }
  else if(choice==2)
  {
    printf("Quantity :");
    scanf(" %d",&quantity);
    total=total + 120*(quantity);
    printf("\n");
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf(" %d",&again);
    if(again==1)
    {
      printf("\n\n");
      nonvegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is :%.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
      details();
    }
  }
  else if(choice==3)
  {
    printf("Quantity :");
    scanf(" %d",&quantity);
    total=total + 85*(quantity);
    printf("\n");
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf(" %d",&again);
    if(again==1)
    {
      printf("\n\n");
      nonvegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is :%.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
      details();
    }
  }
  else if(choice==4)
  {
    printf("Quantity :");
    scanf(" %d",&quantity);
    total=total + 35*(quantity);
    printf("\n");
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf(" %d",&again);
    if(again==1)
    {
      printf("\n\n");
      nonvegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is :%.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
      details();
    }
  }
  else if(choice==5)
  {
    system("cls");
    customer();
  }
  else
  {
    printf(" Re-enter THe Correct Option\n\n");
    nonvegmenu();
  }
}

void details()
{
  char fname[20];
  char lname[20];
  long long int phone;
  char address[40];
  printf("Please Give Your Contact Details \n");
  printf(" First Name : ");
  scanf("%s",fname);
  printf("Last Name : ");
  scanf("%s",lname);
  printf("Phone : ");
  scanf("%lld",&phone);
  printf("Address : ");
  scanf("%s",address);
 
  printf("\n\n");
  printf("Your Entered Details Are --->\n");
  FILE *cust;
  cust = fopen("order.txt","a");
  fprintf(cust,"Order Placed By : %s %s\nPhone number : %lld\n",fname,lname,phone);
  fclose(cust);
  printf("    -->First Name :  %s\n    -->Last Name   :  %s\n    -->Phone     :%lld \n    -->Address  :%s \n     \n",fname,lname,phone,address);
  printf("\n\n\n");
  
  printf("Press Any To The Main page.");
  if(getch())
  customer();
}



void vegmenu(void)
{
  int choice;
  int again;
  int quantity;
  
  double price=0;
  
  printf("***********************VEGETARIAN MENU**********************\n\n");
  char v;
  FILE *vmenu;
  
    vmenu=fopen("vegmenu.txt","rt");
  while((v=getc(vmenu))!=EOF)
        {
          printf("%c",v);
    }
         fclose(vmenu);
    printf("\n\nEnter What You Want :");
    printf("\n\n");
    scanf("%d",&choice);
  if(choice==1)
  {
    printf("Quantity :  ");
    scanf("%d",&quantity);
    total=total + 40*(quantity);
    printf("\n");
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf("%d",&again);
    printf("\n");
    if(again==1)
    {
      printf("\n\n");
      vegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
      details();
    }
  }
  else if(choice==2)
  {
    printf("Quantity :");
    scanf("%d",&quantity);
    total=total + 60*(quantity);
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf("%d",&again);
    if(again==1)
    {
      printf("\n\n");
      vegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
  
      details();
    }
  }
  else if(choice==3)
  {
    printf("Quantity :  ");
    scanf("%d",&quantity);
    total=total + 45*(quantity);
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf("%d",&again);
    if(again==1)
    {
      printf("\n\n");
      vegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
  
      details();
    }
  }
  else if(choice==4)
  {
    printf("Quantity :");
    scanf("%d",&quantity);
    total=total + 35*(quantity);
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf("%d",&again);
    if(again==1)
    {
      printf("\n\n");
      vegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
  
      details();
    }
  }
  else if(choice==5)
  {
    printf("Quantity :");
    scanf("%d",&quantity);
    total=total + 150*(quantity);
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf("%d",&again);
    if(again==1)
    {
      printf("\n\n");
      vegmenu();
    }
    else if(again==2)
    {
      printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
      int totl = total;
      FILE *ttl;
      ttl = fopen("order.txt","a");
      fprintf(ttl,"\nGrand Total : %d\n",totl);
      fclose(ttl);
      details();
    }
      
  }
  else if(choice==6)
  {
    system("cls");
    customer();
  }
  else
  {
    printf("Wrong Input! Re-enter THe Correct Option\n\n");
    if(getch())
    vegmenu();
  }
}
