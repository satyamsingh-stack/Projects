/* This code will run only in turbo c */
/* Author -> Satyam Singh */
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include <dos.h>
struct bank
{
    char name[21],add[31],type[10],pin[5];
    int acc;
    float balance, amount;
};
struct bank b;
void line(){
	int n;
	for(n=1;n<=80;n++){
		printf("_");
	}
	printf("\n");
}
void open_account()
{
	system("cls");
	textcolor(RED+BLINK);
	gotoxy(25,8);
	cprintf("<<CREATE YOUR ACCOUNT>>");
	printf("\n\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Your name : ");
	fflush(stdin);
	scanf("%s",&b.name);
	gotoxy(15,11);
	textcolor(BROWN);
	cprintf("Create Your 5 Digit Account No. : ");
	fflush(stdin);
	scanf("%d",&b.acc);
	gotoxy(15,12);
	textcolor(BROWN);
	cprintf("Enter Your Address : ");
	fflush(stdin);
	scanf("%s",&b.add);
	gotoxy(15,13);
	textcolor(BROWN);
	cprintf("Type of account you want to open Saving or Current : ");
	fflush(stdin);
	gets(b.type);
	gotoxy(15,14);
	textcolor(BROWN);
	cprintf("Enter amount to deposite : ");
	fflush(stdin);
	scanf("%f",&b.balance);
	printf("\n\n");
	textcolor(GREEN+BLINK);
	gotoxy(25,15);
	cprintf("Your account is created Successufully!");
	printf("\n");
	system("pause");
	system("cls");
}
void deposite_money()
{
	char name3[21];
	int acc3,a,q;
	system("cls");
	textcolor(RED+BLINK);
	gotoxy(30,8);
	cprintf("<<DEPOSITE MONEY>>");
	printf("\n\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Name of Account Holder : ");
	fflush(stdin);
	scanf("%s",&name3);
	gotoxy(15,11);
	textcolor(BROWN);
	cprintf("Enter Account No. : ");
	fflush(stdin);
	scanf("%d",&acc3);
	gotoxy(15,12);
	textcolor(BROWN);
	cprintf("How much money you want to deposit : ");
	fflush(stdin);
	scanf("%d",&a);
	b.balance+=a;
	q=strcmp(name3,b.name);
	if(q==0 && acc3==b.acc){
		printf("\n");
		gotoxy(20,14);
		textcolor(GREEN+BLINK);
		cprintf("Successufully! Deposited to your Bank Account");
		printf("\n");
	}
	else if(q!=0){
		textcolor(RED+BLINK);
		gotoxy(20,14);
		cprintf("Oops! You have entered wrong Name");
		printf("\n");
	}
	else{
		textcolor(RED+BLINK);
		gotoxy(20,14);
		cprintf("Oops! You have entered wrong Account number");
		printf("\n");
	}
	system("pause");
	system("cls");
}
void display_account()
{       int acc4,i=0,l2;
	char pin4[5],ch;
	system("cls");
	textcolor(RED+BLINK);
	gotoxy(30,8);
	cprintf("<<SHOW ACCOUNT DETAILS>>");
	printf("\n\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Your Account Number : ");
	scanf(" %d",&acc4);
	gotoxy(15,11);
	textcolor(BROWN);
	cprintf("Enter your PIN : ");
	while(i<4){
		fflush(stdin);
		ch=getch();
		putchar('*');
		if(ch=='\r'){
			break;
		}
		pin4[i]=ch;
		i++;
	}
	pin4[i]='\0';
	l2=strcmp(b.pin,pin4);
	if(b.acc==acc4 && l2==0){
		system("cls");
		textcolor(RED+BLINK);
		cprintf("<<Account Details>>");
		printf("\n\n");
		line();
		textcolor(YELLOW);
		cprintf("%-19s %-10s %-10s %-20s %-20s","A/C Holder Name","A/C No.","Type","A/C Holder Address","Available Amount");
		printf("\n");
		line();
		textcolor(GREEN);
		cprintf("%-19s %-10d %-10s %-20s %-200.2f",b.name,b.acc,b.type,b.add,b.balance);
		printf("\n");
	}
	else if(l2!=0){
		textcolor(RED+BLINK);
		gotoxy(25,13);
		cprintf("Please! Enter correct PIN");
		printf("\n");
	}
	else if(b.acc!=acc4){
		textcolor(RED+BLINK);
		gotoxy(25,13);
		cprintf("Please! Enter correct Account Number");
		printf("\n");
	}
	else{
		textcolor(RED+BLINK);
		gotoxy(25,13);
		cprintf("Data Not Found");
		printf("\n");
	}
	printf("\n");
	system("pause");
    system("cls");
}
void withdraw_money()
{
	int acc2,i=0,l;
	char pin2[5],ch;
	system("cls");
	gotoxy(30,8);
	textcolor(RED+BLINK);
	cprintf("<<WITHDRAW MONEY>>");
	printf("\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Account No. : ");
	scanf("%d",&acc2);
	gotoxy(15,11);
	textcolor(BROWN);
	cprintf("Enter Your Pin : ");
	while(i<4){
		fflush(stdin);
		ch=getch();
		if(ch=='\r'){
			break;
		}
		pin2[i]=ch;
		putchar('*');
		i++;
	}
	pin2[i]='\0';
	printf("\n");
	l=strcmp(b.pin,pin2);
	if(acc2==b.acc && l==0){
		gotoxy(15,12);
		textcolor(BROWN);
		cprintf("Enter your amount to Withdrawing : ");
	scanf("%f",&b.amount);
	if(b.amount>b.balance){
		textcolor(RED+BLINK);
		gotoxy(25,14);
		cprintf("Insufficient Balance");
		printf("\n");
		}
		else{
			b.balance=b.balance-b.amount;
		textcolor(GREEN+BLINK);
		gotoxy(25,14);
		cprintf("Available Balance is : %0.2f",b.balance);
		printf("\n");
		}
	}
	else if(acc2!=b.acc){
		textcolor(RED+BLINK);
		gotoxy(25,14);
		cprintf("Oops! You have Entered wrong Account No.");
		printf("\n");
	}
	else{
		textcolor(RED+BLINK);
		gotoxy(25,14);
		cprintf("Oops! You have to Entered wrong Pin");
		printf("\n");
	}
	printf("\n");
    system("pause");
    system("cls");
}
void pin_generate(){
	char name1[21],ch1;
	int acc1,i=0,l3;
	system("cls");
	textcolor(RED+BLINK);
	gotoxy(25,8);
	cprintf("<<GENERATE YOUR PIN HERE>>");
	printf("\n\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Account Holder Name : ");
	fflush(stdin);
	scanf("%s",&name1);
	gotoxy(15,11);
	textcolor(BROWN);
	cprintf("Enter Account Number : ");
	fflush(stdin);
	scanf("%d",&acc1);
	l3=strcmp(name1,b.name);
	if(l3==0 && acc1==b.acc){
		gotoxy(15,12);
		textcolor(BROWN);
		cprintf("Now Create Your 4 Digite Pin : ");
		while(i<4){
			fflush(stdin);
			ch1=getch();	putchar('*');
			if(ch1=='\r'){
				break;
			}
			b.pin[i]=ch1;
			i++;
		}
		b.pin[i]='\0';
		printf("\n");
		textcolor(GREEN+BLINK);
		gotoxy(25,14);
		cprintf("Successfully! Generated Pin");
		printf("\n");
	}
	else if(l3!=0){
		textcolor(RED+BLINK) ;
		gotoxy(25,14);
		cprintf("You have Entered wrong Name");
		printf("\n");
	}
	else if(acc1!=b.acc){
		textcolor(RED+BLINK);
		gotoxy(25,14);
		cprintf("You have Entered wrong Account Number");
		printf("\n");
	}
	printf("\n");
	system("pause");
	system("cls");
}
void sleep(unsigned int mseconds){
	clock_t goal =mseconds+clock();
	while(goal>clock());
}
void load(){
	int row,r;
	textcolor(RED+BLINK);
	gotoxy(35,10);
	cprintf("!!Alart!!");
	printf("\n\n");
	gotoxy(25,12);
	textcolor(YELLOW);
	cprintf("->Bank server is Loading.");
	printf("\n");
	gotoxy(25,13);
	cprintf("->Don't press any key during loading.");
	printf("\n");
	gotoxy(25,14);
	cprintf("->Press Enter key after loading.");
	printf("\n\n");
	gotoxy(25,16);
	textcolor(GREEN+BLINK);
	cprintf("Loading...");
	for(r=1;r<=20;r++){
	sleep(10);
	printf("%c",177);
	}
	getch();
}
void instructions(){
	system("cls");
	textcolor(RED+BLINK);
	cprintf(">>> Bank Instructions <<<");
	printf("\n\n");
	textcolor(YELLOW);
	cprintf("-> Use Number key to do the respective tasks");
	printf(".\n\n");
	cprintf("-> Don't share your bank datails such as pin, account no etc. to any one in any circumstances");
	printf(".\n\n");
	cprintf("-> First, make sure that the area is well lit and you are alone. Be on your guard if other people show up. Stand so that your screen and key presses are masked");
	printf(".\n\n");
	cprintf("-> This is advance ATM in which no need of Debit card for any process");
	printf(".\n\n");
	cprintf("-> Create or enter your PIN when prompted");
	printf(".\n\n");
	cprintf("-> You can withdraw money only from this machine");
	printf(".\n\n");
	system("pause");
}
void drawdbox(int sr, int sc, int r, int c){
	int i,j;
	gotoxy(sc,sr);
	printf("%c",201);
	for(i=1;i<=c;i++)
	   printf("%c",205);
	printf("%c",187);
	for(i=1;i<=r;i++)
	{
	  gotoxy(sc,sr+i);
	  printf("%c",186);
	  gotoxy(sc+c+1,sr+i);
	  printf("%c",186);
	}
	gotoxy(sc,sr+i);
	printf("%c",200);
	for(i=1;i<=c;i++)
	   printf("%c",205);
	printf("%c",188);
}
void flashscreen(){
	struct date d;
	int sr=1,sc=1,r=22,c=78;
	clrscr();
	drawdbox(sr,sc,r,c);
	textcolor(RED+BLINK);
	gotoxy(24,4);
	cprintf(">>> Welcome to Advanced ATM System <<<");
	drawdbox(sr+2,sc+2,r-4,c-4);
	gotoxy(24,6);
	textcolor(YELLOW+BLINK);
	cprintf(">>> Welcome to Advanced ATM System <<<");
	drawdbox(sr+4,sc+4,r-8,c-8);
	gotoxy(24,8);
	textcolor(BLUE+BLINK);
	cprintf(">>> Welcome to Advanced ATM System <<<");
	drawdbox(sr+6,sc+6,r-12,c-12);
	gotoxy(24,10);
	textcolor(CYAN+BLINK);
	cprintf(">>> Welcome to Advanced ATM System <<<");
	drawdbox(sr+8,sc+8,r-16,c-16);
	gotoxy(24,12);
	textcolor(GREEN+BLINK);
	cprintf(">>> Welcome to Advanced ATM System <<<");
	gotoxy(27,14);
	textcolor(LIGHTRED);
	getdate(&d);
	cprintf("Current system date: %d/%d/%d", d.da_day, d.da_mon, d.da_year);
	gotoxy(35,16);
	textcolor(RED);
	cprintf("!!ALEART!!");
	gotoxy(25,17);
	textcolor(BLUE);
	cprintf(">>> You are under survivlance <<<");
	gotoxy(28,19);
	textcolor(LIGHTGREEN);
	cprintf(">>> Made by Satyam Singh <<<");
	gotoxy(7,21);
	textcolor(LIGHTBLUE);
	cprintf(">>> No need of Debit card, Just know your account details only. <<<");
	gotoxy(15,2);
	textcolor(DARKGRAY);
	cprintf(">>> Our Customer's Security is our first Priorirty <<<");
	gotoxy(30,23);
	system("pause");
}
int main(){
	system("cls");
	flashscreen();
	instructions();
	system("cls");
	load();
	system("cls");
	for(;;){
		int choice;
		gotoxy(35,6);
		textcolor(BLUE);
		cprintf(">>MENU<<");
		printf("\n");
		textcolor(RED);
		gotoxy(25,8);
		cprintf("1");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Open Account");
		printf("\n");
		textcolor(RED);
		gotoxy(25,9);
		cprintf("2");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Pin Generation");
		printf("\n");
		gotoxy(25,10);
		textcolor(RED);
		cprintf("3");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Withdraw Money");
		printf("\n");
		textcolor(RED);
		gotoxy(25,11);
		cprintf("4");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Display Account");
		printf("\n");
		textcolor(RED);
		gotoxy(25,12);
		cprintf("5");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Deposite Money");
		printf("\n");
		textcolor(RED);
		gotoxy(25,13);
		cprintf("6");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Exit");
		printf("\n");
		printf("\n");
		textcolor(GREEN);
		gotoxy(20,15);
		cprintf("Enter the number which you want to process: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: open_account();	break;
			case 2: pin_generate();	break;
			case 3: withdraw_money();	break;
			case 4: display_account();	break;
			case 5: deposite_money();	break;
			case 6: printf("Sorry! to see you go\n");exit(0);
			default: printf("Invalid Input...\n"); system("cls");
		}
	}
}    
