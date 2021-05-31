/*This code will run only in turbo c */
/* Author -> Satyam Singh */
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<process.h>
typedef struct{
	char name[51],mobile[11];
} message;
message m;
FILE *fp;
void start();
void line(){
	int n;
	for(n=1;n<=80;n++){
		textcolor(LIGHTRED);
		cprintf("_");
	}
	printf("\n");
}
void alert(){
	system("cls");
	textcolor(LIGHTRED+BLINK);
	printf("\n\n\n");
	printf("\t\t");
	cprintf("    !      o       o     oooo  oooo  ooooo !");
	printf("\n");
	printf("\t\t");
	cprintf("    !    o   o     o     o     o o     o   !");
	printf("\n");
	printf("\t\t");
	cprintf("    !   ooooooo    o     oooo  oo      o   !");
	printf("\n");
	printf("\t\t");
	cprintf("    !  o       o   o     o     o o     o   !");
	printf("\n");
	printf("\t\t");
	cprintf("    ! o         o  oooo  oooo  o  o    o   !");
}
void secured(){
	system("cls");
	textcolor(YELLOW+BLINK);
	cprintf("     oooo  oooo  oooo  o  o  oooo  oooo  o o      oooo  o  o     o     ooooo");
	printf("\n");
	cprintf("     o     o     o     o  o  o o   o     o   o    o     o  o    o o      o");
	printf("\n");
	cprintf("     oooo  oooo  o     o  o  oo    oooo  o    o   o     oooo   ooooo     o");
	printf("\n");
	cprintf("        o  o     o     o  o  o o   o     o   o    o     o  o  o     o    o");
	printf("\n");
	cprintf("     oooo  oooo  oooo  oooo  o  o  oooo  o o      oooo  o  o o       o   o");
	printf("\n\n");
	textcolor(RED);
	printf("\t\t");
	cprintf("**************************************************");
	printf("\n");
	printf("\t\t");
	cprintf("*                                                *");
	printf("\n");
	printf("\t\t");
	cprintf("*          Current Date is : %s         *",__DATE__);
	printf("\n");
	printf("\t\t");
	cprintf("*          Current Time is : %s            *",__TIME__);
	printf("\n");
	printf("\t\t");
	cprintf("*          ----------------------------          *");
	printf("\n");
	textcolor(GREEN);
	printf("\t\t");
	cprintf("*             WELCOME TO SECURE CHAT             *");
	printf("\n");
	printf("\t\t");
	cprintf("*          ----------------------------          *");
	printf("\n");
	printf("\t\t");
	cprintf("*                                                *");
	printf("\n");
	printf("\t\t");
	cprintf("*  This is a messaging system in which you can   *");
	printf("\n");
	printf("\t\t");
	cprintf("*  create your group and share message securely  *");
	printf("\n");
	printf("\t\t");
	cprintf("**************************************************");
	printf("\n");
	textcolor(RED);
	gotoxy(27,18);
	cprintf("No, Chance of message leaked.");
	printf("\n");
	gotoxy(11,19);
	cprintf("Last Message will automatically disappers, after a new one send.");
	gotoxy(15,20);
	textcolor(LIGHTBLUE);
	cprintf("No, Limit of Users, many users can join as possible");
	printf("\n");
	gotoxy(23,21);
	textcolor(BROWN);
	cprintf("This System is build by: ");
	textcolor(LIGHTGREEN+BLINK);
	gotoxy(48,21);
	cprintf("SATYAM SINGH");
	printf("\n\n");
	system("pause");
}
void create_id(){
	int i;
	char ch;
	system("cls");
	textcolor(RED+BLINK);
	gotoxy(25,8);
	cprintf(">> Creating your User Id <<");
	printf("\n\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Your Name here : ");
	fflush(stdin);	gets(m.name);
	gotoxy(15,11);
	textcolor(BROWN);
	cprintf("Enter Your 10 Digit Mobile Number : ");
	fflush(stdin);
	gets(m.mobile);
	fseek(fp,0,SEEK_END);
	fwrite(&m,sizeof(m),1,fp);
	textcolor(GREEN+BLINK);
	gotoxy(15,13);
	cprintf("Successfully created...");
	printf("\n\n");
	system("pause");
}
void search_number(){
	int found=0,l;
	char name1[51];
	system("cls");
	gotoxy(25,8);
	textcolor(RED+BLINK);
	cprintf(">> SEARCH NUMBER <<");
	printf("\n");
	gotoxy(25,10);
	textcolor(BROWN);
	cprintf("Enter Name to search : ");	fflush(stdin);
	gets(name1);
	system("cls");
	rewind(fp);
	while(fread(&m,sizeof(m),1,fp)){
		l=strcmp(name1,m.name);
		if(l==0){
			found=1;
			break;
		}
	}
	if(found){
		textcolor(BLUE+BLINK);
		cprintf(">> We Found <<");
		printf("\n");
		line();
		textcolor(RED);
		cprintf("%-40s %-40s","User Name","Contact Details");
		printf("\n");
		line();
		textcolor(GREEN);
		cprintf("%-40s %-40s",m.name,m.mobile);
		printf("\n");
	}
	else
		printf("Record not found");
	printf("\n\n");
	system("pause");
}
void delete_id(){
	int found=0,l;
	char name1[51];
	system("cls");
	textcolor(RED+BLINK);
	gotoxy(25,8);
	cprintf(">> Delete all records <<");
	printf("\n");
	gotoxy(25,10);
	textcolor(BROWN);
	cprintf("Enter Name to delete : ");	fflush(stdin);
	gets(name1);
	rewind(fp);
	while(fread(&m,sizeof(m),1,fp)){
		l=strcmp(name1,m.name);
		if(l==0){
			found=1;
			break;
		}
	}
	if(found){
		FILE *temp=fopen("temp","wb");
		rewind(fp);
		while(fread(&m,sizeof(m),1,fp)){
			if(l!=0){
				fwrite(&m,sizeof(m),1,temp);
			}
		}
		fclose(fp);fclose(temp);
		remove("message.dat");rename("temp","message.dat");
		fp=fopen("message.dat","rb+");
		gotoxy(25,11);
		textcolor(GREEN+BLINK);
		cprintf("Record Deleted...");
		printf("\n");
	}
	else
		printf("Record not found");
		printf("\n");
	printf("\n\n");
	system("pause");
}
void see_contact(){
	system("cls");
	rewind(fp);
	textcolor(RED+BLINK);
	cprintf(">> ALL CONTACTS <<");
	printf("\n");
	line();
	printf("\n");
	printf("%-40s %-40s","User Name","Contact Details");
	printf("\n");
	line();
	textcolor(GREEN);
	while(fread(&m,sizeof(m),1,fp)){
		cprintf("%-40s %-40s",m.name,m.mobile);
		printf("\n");
	}
	system("pause");
}
void see_message(){
	FILE *fp1;
	char ch;
	system("cls");
	fp1=fopen("send.txt","r");
	textcolor(RED+BLINK);
	cprintf(">> Last message <<");
	printf("\n");
	if(fp1!=NULL){
		while((ch=fgetc(fp1))!=EOF){
			putchar(ch);
		}
		fclose(fp1);
	}
	else
		printf("Unable to Open File");
	printf("\n\n");
	system("pause");
}
void send_message(){
	FILE *fp1;
	char ch;
	system("cls");
	fp1=fopen("send.txt","w");
	textcolor(RED+BLINK);
	gotoxy(25,8);
	cprintf(">> SEND MESSAGE <<");
	gotoxy(25,10);
	textcolor(BROWN);
	cprintf("Type message and press '0' to send : ");
	if(fp1!=NULL)
	{
		for(;;)
		{
			fflush(stdin);
			ch=getche();
			if(ch=='0')
				break;
			fputc(ch,fp1);
		}
		fclose(fp1);
	}
	else
	{
		printf("Unable to open File");
	}
	printf("\n\n");
	system("pause");
}
void login(){
	char name2[51],mobile1[11];
	int i,l1,l2,l3;
	system("cls");
	gotoxy(25,8);
	textcolor(RED+BLINK);
	cprintf(">> Now, Login with your Id <<");
	printf("\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter User Name : ");	fflush(stdin);
	gets(name2);
	gotoxy(15,11);
	cprintf("Enter Mobile Number : ");	fflush(stdin);
	gets(mobile1);
	rewind(fp);
	while(fread(&m,sizeof(m),1,fp)){
		l1=strcmp(name2,m.name);
		l3=strcmp(m.mobile,mobile1);
		if(l1==0 && l3==0){
			int choice;
			for(;;){
				system("cls");
				gotoxy(30,6);
				textcolor(LIGHTBLUE+BLINK);
				cprintf(">>You are Login as %s <<",name2);
				printf("\n\n");
				gotoxy(25,8);
				textcolor(RED);
				cprintf("1");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Send Message");
				printf("\n");
				gotoxy(25,9);
				textcolor(RED);
				cprintf("2");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("See Message");
				printf("\n");
				gotoxy(25,10);
				textcolor(RED);
				cprintf("3");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Contacts");
				printf("\n");
				gotoxy(25,11);
				textcolor(RED);
				cprintf("4");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Delete All Record");
				printf("\n");
				gotoxy(25,12);
				textcolor(RED);
				cprintf("5");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Search Number");
				printf("\n");
				gotoxy(25,13);
				textcolor(RED);
				cprintf("6");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Goto Main Menu");
				printf("\n");
				textcolor(GREEN);
				gotoxy(25,15);
				cprintf("Enter your choice : "); scanf("%d",&choice);
				switch(choice){
					case 1: send_message();break;
					case 2: see_message();break;
					case 3: see_contact();	break;
					case 4: delete_id();	break;
					case 5: search_number();	break;
					case 6: fclose(fp);start();
					default: printf("Invalid Choice...\n");system("pause");
				}
			}
		}
		else{
			gotoxy(15,13);
			textcolor(RED+BLINK);
			cprintf("Something went wrong...");
			printf("\n");

		}
	}
	system("pause");
}
void start(){
	int choice;
	fp=fopen("message.dat","rb+");
	if(fp==NULL) fp=fopen("message.dat","wb+");
	for(;;){
		system("cls");
		gotoxy(35,6);
		textcolor(LIGHTBLUE);
		cprintf(">>MAIN MENU<<");
		printf("\n");
		textcolor(RED);
		gotoxy(25,8);
		cprintf("1");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Add Member in group");
		textcolor(RED);
		gotoxy(25,9);
		cprintf("2");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("LOGIN");
		printf("\n");
		gotoxy(25,10);
		textcolor(RED);
		cprintf("3");
		printf(" : ");
		textcolor(YELLOW);
		cprintf("Quit");
		printf("\n");
		gotoxy(25,11);
		textcolor(GREEN);
		cprintf("Enter your choice : "); scanf("%d",&choice);
		switch(choice){
			case 1: create_id();break;
			case 2: login();break;
			case 3: fclose(fp);exit(0);
			default: printf("Invalid Choice...\n");system("pause");
		}
	}
}
void instructions(){
	system("cls");
	textcolor(LIGHTBLUE+BLINK);
	gotoxy(24,4);
	cprintf(">>> Some more features and Working <<<");
	printf("\n\n");
	textcolor(LIGHTRED);
	cprintf("-> Use Number key to do the respective tasks");
	printf(".\n\n");
	cprintf("->If you are not member of the group then first of all create your id");
	printf(".\n\n");
	cprintf("-> After joining the group you can login with your id");
	printf(".\n\n");
	cprintf("-> You can send message, see message, delete id and once you loged in");
	printf(".\n\n");
	cprintf("-> Last message will be autometically disappered after sending new message");
	printf(".\n\n");
	cprintf("-> As this is very secured no chance of data leaked, whenever you feel any distrbance from attackers then any of the group member can delete every single record");
	printf("\n\n");
	system("pause");
}
void load(){
	int row,r;
	system("cls");
	alert();
	printf("\n\n");
	gotoxy(25,12);
	textcolor(BLUE);
	cprintf("->We are fetching your record.");
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
	sleep(1);
	printf("%c",219);
	}
	getch();
}
void main(){
	secured();
	instructions();
	load();
	start();
}
