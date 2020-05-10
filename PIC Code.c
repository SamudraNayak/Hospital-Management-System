//   Header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//   Creating a structure
struct ad
{
    char name[30];
    char disease[30];
    int cabin,age;
    long double phone;
}
x[100];//Structure variable
int n,i,sum=0,g,flag,num;

//   Function declaration
void read();
void add();
void view();
void search();
void edit();
void del();
void write();

//   Main function
int main()
{
read();
    int c;
    printf("Simple Hospital Management System\n");
    while(c!=6)
    {
printf("Enter your choice**\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption=");
        scanf("%d",&c);//choice for option
        if(c==1)//add
        {
            system("clear");
            add();
        }
        else if(c==2)//view
        {
            system("clear");
            view();
        }
else if(c==3)//search
        {
            system("clear");
            search();
        }
        else if(c==4)//edit
        {
            system("clear");
            edit();
        }
        else if(c==5)//delete
        {
            system("clear");
            del();
        }
        else if(c==6)
        {
            write();
            return 0;
        }
        else
        {
            system("clear");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
        }
        }

//   Adding a record
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n",num);//how many inputs
    printf("How many entry do you want to add=\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num; i<sum; i++)
    {
        printf("\n");
        printf("Enter patient's Name = ");
        scanf("%s",x[i].name);
        printf("\n");
        printf("Enter disease = ");
        scanf("%s",x[i].disease);
        printf("\n");
        printf("Enter the age = ");
        scanf("%d",&x[i].age);
        printf("\n");

printf("Enter cabin no = ");
        scanf("%d",&x[i].cabin);
        printf("\n");
        printf("Enter phone number = ");
        scanf("%Lf",&x[i].phone);
       printf("\n");
        num++;
    } }

//   View the record
void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("Serial Number=%d\n",i);
        printf("Name = ");
        puts(x[i].name);
        printf("Disease = ");
        puts(x[i].disease);
        printf("Cabin no = %d\n Phone number =%Lf\n     Age=%d",x[i].cabin,x[i].phone,x[i].age);
        printf("\n\n"); } }

//   Edit the record
void edit()
{
    int q,p;
    printf("\n");
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n");
    printf("Option=");
    scanf("%d",&q);//option
    if(q<=5)
    {
     printf("Enter the serial no of that patient= (0 - %d)=",num
     -1);
     scanf("%d",&p);//serial number
     if(p<num)
        {
               if(q==1)
            {
               printf("Enter the new name=");
               scanf("%s",x[p].name);
            }
else if(q==2)
            {
                printf("Enter the new Disease=");
                scanf("%s",x[p].disease);
            }
            else if(q==3)
            {
                printf("Enter the new Age=");
                scanf("%d",&x[p].age);
            }
            else if(q==4)
            {
                printf("Enter the new Cabin no=");
                scanf("%d",&x[p].cabin);
            }
           else if(q==5)
            {
                printf("Enter the new Phone no =");
                scanf("%Lf",&x[p].phone);
            }  }
      }
 else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");  }    }

//   Searching a particular record
void search()
{     int s,h,f;
       char u[100];

        f=1;

        printf("Enter the name of the person whom you want to search=");
        scanf("%s",u);

        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);

                 printf("Cabin no = %d\nPhone number = 0%Lf\nAge =   %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
}
        }
        if(f==1){
            printf("\nNot Found\n");
            }
}

//   Deleting a record
void del()
{
    int f,h;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&f);
    if(f<num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\nOption = ");
        scanf("%d",&h);

 if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].cabin=x[f+1].cabin;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
        }
        else if(h==2)
        {
            strcpy(x[f].name,"Cleared");
        }
        else if(h==3)
        {
            strcpy(x[f].disease,"Cleared");
        }
else if(h==4)
        {
            x[f].age=0;
        }
        else if(h==5)
        {
            x[f].cabin=0;
        }
        else if(h==6)
        {
            x[f].phone=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}

//   Reading a record
void read()
{
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("patient.txt","w");
fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");

    }

    num = fread(x, sizeof(struct ad),100, fp);
    fclose(fp);
}

//   Writing a record
void write()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(0);
    }
    fwrite(x, sizeof(struct ad),num, fp);

    fclose(fp);
}
