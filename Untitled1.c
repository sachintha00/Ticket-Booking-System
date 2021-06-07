#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    char code[20];
    char name[20];
    char date[20];
    int cost;
};

int seat = 60;

void insert_details();
void viewall();
void find();
void book_ticket();
void old_record();

void main()
{
    int ch;
    do{
    printf("================================================\n");
    printf ("\t MOVIE TICKET BOOKING SYSTERM\n");
    printf("================================================\n");
    printf("\nPress <1> Insert Movie");
    printf("\nPress <2> View All Movie");
    printf("\nPress <3> Find Movie");
    printf("\nPress <4> Book Ticket");
    printf("\nPress <5> View All Transactions");
    printf("\nPress <0> Exit");

    printf("\nEnter Your Choice::");
    scanf("%d",&ch);


    switch (ch)

    {
    case 1:
        insert_details();
        break;
    case 2:
        viewall();
        break;
    case 3:
        find();
        break;
    case 4:
        book_ticket();
        break;
    case 5:
        old_record();
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("Wrong Choice!!");
    }
    }while(ch!=0);

}

void insert_details()
{
    FILE *fp;
    struct book b;
    printf("Enter Movie Code:- ");
    scanf("%s",b.code);
    printf("Enter Name:- ");
    scanf("%s",b.name);
    printf("Enter Release Date:- ");
    scanf("%s",b.date);
    printf("Enter Ticket Price:- ");
    scanf("%d",&b.cost);

    fp = fopen("data.txt","a");

    if(fp == NULL)
        printf("File Not Found");

    else
    {
        fprintf(fp, "%s %s %s %d \n",b.code,b.name,b.date,b.cost);
        printf("Record Insert Successful");
    }
    printf("\n");
  fclose(fp);
  system("CLS");
}

void find() //find details
{
    struct book b;
    FILE *fp;

    char ch[20];
    printf("Enter Movie Code:- ");
    scanf("%s",ch);
    //system("CLS");
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("File Does Not Found!!");
        exit(1);
    }
    else
    {
        while(getc(fp)!=EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,ch)==0)
            {
                printf("\n Record Found \n");
                printf("\n\t\tCode ::%s",b.code);
                printf("\n\t\tMovie Name ::%s",b.name);
                printf("\n\t\tMovie Data ::%s",b.date);
                printf("\n\t\tPrice Of Ticket ::%d",b.cost);
                break;
            }
        }
    }
    fclose(fp);
}
void viewall()
{
    char ch;
    FILE *fp;

    fp = fopen("data.txt", "r");
    if(fp == NULL)
    {
        printf("File Does Not Found!!");
        exit(1);
    }
    else
    {
        while( ( ch = fgetc(fp) ) != EOF)
        {
            printf("%c",ch);
        }

    }
    fclose(fp);
}
//ticket booking
void book_ticket()
{
    struct book b;
    FILE *fp;

    FILE *ufp;

    int total_seat,mobile,total_amount;
    char name[20];

    char ch; //used in display all movie
    char movie_code[20]; //for searching

    //display all movies by default for movie code
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("File Does Not Found");
        exit(1);
    }
    else
    {
        system("cls");
        while( ( ch = fgetc(fp) ) !=EOF)
            printf("%c",ch);
    }
    fclose(fp);



    //display ends
    printf("\n For Book Ticket Choice Movie(Enter Movie Code First Latter Of Movie)\n");
    printf("\n Enter Movie Code :");
    scanf("%s",movie_code);
    //system("clear");
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("File Does Not Found!!");
        exit(1);
    }
    else
    {
        while(getc(fp) !=EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp (b.code,movie_code) == 0)
            {
                printf("\n Record Found\n");
                printf("\n\t\tCode ::%s",b.code);
                printf("\n\t\tMovie Name ::%s",b.name);
                printf("\n\t\tDate ::%s",b.date);
                printf("\n\t\tPrice Of Ticket ::%d",b.cost);
                break;
            }

        }
    }
    printf("\n* Fill Details *");
    printf("\n Your Name :");
    scanf("%s",name);
    printf("\n Mobile Number :");
    scanf("%d",&mobile);
    printf("\n Total Number Of Tickets :");
    scanf("%d",&total_seat);

    total_amount = b.cost * total_seat;

    printf("\n **** ENJOY MOVIE **** \n");
    printf("\n\t\tName : %s",name);
    printf("\n\t\tMobile Number : %d",mobile);
    printf("\n\t\tMovie Name : %s",b.name);
    printf("\n\t\tTotal Seats : %d",total_seat);
    printf("\n\t\tCost Per Ticket ; %d",b.cost);
    printf("\n\t\tTotal Amount ; %d",total_amount);

    ufp=fopen("oldtransection.txt","a");
    if(ufp == NULL)

        printf("File Not Found");

    else
    {
        fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
        printf("\n Record Insert Successful to the old record file");
    }
    printf("\n");

    fclose(ufp);
    fclose(fp);

}


void old_record()
{
    char ch;
    FILE *fp;

    fp = fopen("oldtransection.txt","r");
    if(fp == NULL)
    {
        printf("File Does Not Found");
        exit(1);
    }
    else
    {
        while( ( ch = fgetc(fp) ) != EOF)
            printf("%c",ch);
    }
    fclose(fp);
}
