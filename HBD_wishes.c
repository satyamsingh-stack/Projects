#This Code will only work in ancient compiler like Turbo C





#include<stdio.h>
#include<string.h>
#include<process.h>
#include<conio.h>
typedef struct{
	char name[51],date[51];
}hbd;
hbd h;
FILE *fp;
void login();
void line(){
	int i;
	for(i=1;i<=80;i++){
		textcolor(LIGHTGREEN);
		cprintf("_");
	}
	printf("\n");
}
void create(){
	system("cls");
	gotoxy(25,8);
	textcolor(RED+BLINK);
	cprintf(">> ADD NEW BIRTHDAY RECORD <<");
	printf("\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Your Name : ");
	fflush(stdin);
	gets(h.name);
	fflush(stdin);
	gotoxy(15,11);
	textcolor(BROWN);
	cprintf("Enter Birthdate in dd/mm/yyyy formate : ");
	fflush(stdin);
	gets(h.date);
	fseek(fp,0,SEEK_END);
	fwrite(&h,sizeof(h),1,fp);
	gotoxy(15,13);
	textcolor(GREEN+BLINK);
	cprintf("Successfully Created");
	printf("\n");
	system("pause");
}
void start(){
	int choice;
	fp=fopen("hbdc.dat","rb+");
	if(fp==NULL) fp=fopen("hbdc.dat","wb+");
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
		cprintf("Create your Id");
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
			case 1: create();break;
			case 2: login();break;
			case 3: fclose(fp);exit(0);
			default: printf("Invalid Choice...\n");system("pause");
		}
	}
}
void show_all_birthday(){
	system("cls");
	textcolor(RED+BLINK);
	cprintf(">> SHOW ALL RECORD <<");
	printf("\n");
	line();
	textcolor(LIGHTBLUE);
	cprintf("%-30s %-30s","NAME","BIRTHDATE");
	printf("\n");
	line();
	rewind(fp);
	textcolor(GREEN);
	while(fread(&h,sizeof(h),1,fp)){
		cprintf("%-30s %-30s",h.name,h.date);
		printf("\n");
	}
	printf("\n\n");
	system("pause");
}
void search_birthday(){
	int found=0,l;
	char name1[51];
	system("cls");
	gotoxy(25,8);
	textcolor(RED+BLINK);
	cprintf(">> SEARCH BIRTHDAY <<");
	printf("\n");
	gotoxy(25,10);
	textcolor(BROWN);
	cprintf("Enter Name to Search : ");
	fflush(stdin);
	gets(name1);
	system("cls");
	rewind(fp);
	while(fread(&h,sizeof(h),1,fp)){
		l=strcmp(h.name,name1);
		if(l==0){
			found=1;
			break;
		}
	}
	if(found){
		textcolor(BLUE+BLINK);
		cprintf(">> WE FOUND <<");
		printf("\n");
		line();
		textcolor(LIGHTRED);
		cprintf("%-30s %-30s","NAME","BIRTHDATE");
		printf("\n");
		line();
		textcolor(LIGHTGREEN);
		cprintf("%-30s %-30s",h.name,h.date);
	}
	else{
		printf("RECORD not Found");
	}
	printf("\n");
	system("pause");
}
void remove_birthday(){
	int found=0,l;
	char name1[51];
	system("cls");
	textcolor(RED+BLINK);
	gotoxy(25,8);
	cprintf(">> CLEAR ALL RECORD << ");
	printf("\n");
	gotoxy(25,10);
	textcolor(BROWN);
	cprintf("Name Your Name : ");	fflush(stdin);	gets(name1);
	rewind(fp);
	while(fread(&h,sizeof(h),1,fp)){
		l=strcmp(name1,h.name);
		if(l==0){
			found=1;
			break;
		}
	}
	if(found){
		FILE *temp=fopen("temp","wb");
		rewind(fp);
		while(fread(&h,sizeof(h),1,fp)){
			if(l!=0){
				fwrite(&h,sizeof(h),1,temp);
			}
		}
		fclose(fp);fclose(temp);
		remove("record.dat");rename("temp","record.dat");
		fp=fopen("record.dat","rb+");
		gotoxy(25,11);
		textcolor(GREEN+BLINK);
		cprintf("Record Deleted...");
		printf("\n");
	}
	else
		printf("Record not found");
		printf("\n");
	system("pause");

}
void see_wishes(){
	FILE *fp1;
	char ch;
	system("cls");
	fp1=fopen("wishes.txt","r");
	textcolor(RED+BLINK);
	cprintf(">> Last wishes <<");
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
void send_wishes(){
	FILE *fp1;
	char ch;
	system("cls");
	fp1=fopen("wishes.txt","w");
	gotoxy(25,8);
	textcolor(RED+BLINK);
	cprintf(">> SEND WISHES <<");
	printf("\n");
	gotoxy(10,10);
	textcolor(YELLOW);
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
		textcolor(GREEN+BLINK);
		gotoxy(10,13);
		cprintf("Successfully Send");
	}
	else
	{
		printf("Unable to open File");
	}
	printf("\n\n");
	system("pause");
}
void login(){
	char name1[51],date1[51];
	int l1,l2;
	system("cls");
	gotoxy(25,8);
	textcolor(RED+BLINK);
	cprintf(" >> Now, LOGIN to your Id <<");
	printf("\n");
	gotoxy(15,10);
	textcolor(BROWN);
	cprintf("Enter Username : ");
	fflush(stdin);
	gets(name1);
	gotoxy(15,11);
	cprintf("Enter Date of Birth in dd/mm/yyyy formate : ");
	fflush(stdin);
	gets(date1);
	rewind(fp);
	while(fread(&h,sizeof(h),1,fp)){
		l1=strcmp(name1,h.name);
		l2=strcmp(date1,h.date);
		if(l1==0 && l2==0){
			int choice;
			for(;;){
				system("cls");
				gotoxy(30,6);
				textcolor(LIGHTBLUE+BLINK);
				cprintf(">>You are Login as %s <<",name1);
				printf("\n\n");
				gotoxy(25,8);
				textcolor(RED);
				cprintf("1");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Show all Birthday");
				printf("\n");
				gotoxy(25,9);
				textcolor(RED);
				cprintf("2");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Search Birthday");
				printf("\n");
				gotoxy(25,10);
				textcolor(RED);
				cprintf("3");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Wish Birthday BOY/GIRL");
				printf("\n");
				gotoxy(25,11);
				textcolor(RED);
				cprintf("4");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("See Wishes");
				printf("\n");
				gotoxy(25,12);
				textcolor(RED);
				cprintf("5");
				printf(" : ");
				textcolor(YELLOW);
				cprintf("Clear All Memory");
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
						case 1: show_all_birthday();break;
						case 2: search_birthday();break;
						case 3: send_wishes();	break;
						case 4:	see_wishes();	break;
						case 5: remove_birthday();break;
						case 6: fclose(fp);start();
						default: printf("Invalid Choice...\n");system("pause");
					}
				}
		}
		else{
			gotoxy(15,13);
			textcolor(RED+BLINK);
			cprintf("Something Went Wrong");
			printf("\n");
		}
	}
	system("pause");
}
void HBD_pattern(){
	system("cls");
	textcolor(RED);
	gotoxy(25,1);
	cprintf("  *");
	printf("\n");
	gotoxy(25,2);
	cprintf(" ***");
	printf("\n");
	gotoxy(25,3);
	cprintf("*****");
	printf("\n");
	gotoxy(25,4);
	cprintf(" ***");
	printf("\n");
	gotoxy(25,5);
	cprintf("  *");
	printf("\n");
	textcolor(YELLOW);
	gotoxy(25,6);
	cprintf("  |");
	printf("\n");
	gotoxy(25,7);
	cprintf("  |");
	gotoxy(32,1);
	textcolor(GREEN+BLINK);
	cprintf("H   H BB    DDD");
	printf("\n");
	gotoxy(32,2);
	cprintf("H   H B B   D  D");
	printf("\n");
	gotoxy(32,3);
	cprintf("H   H B  B  D   D");
	printf("\n");
	gotoxy(32,4);
	cprintf("HHHHH BBBB  D    D");
	printf("\n");
	gotoxy(32,5);
	cprintf("H   H B  B  D   D");
	printf("\n");
	gotoxy(32,6);
	cprintf("H   H B B   D  D");
	printf("\n");
	gotoxy(32,7);
	cprintf("H   H BB    DDD");
	printf("\n");
	textcolor(RED);
	gotoxy(52,1);
	cprintf("  *");
	gotoxy(52,2);
	cprintf(" ***");
	printf("\n");
	gotoxy(52,3);
	cprintf("*****");
	printf("\n");
	gotoxy(52,4);
	cprintf(" ***");
	printf("\n");
	gotoxy(52,5);
	cprintf("  *");
	printf("\n");
	textcolor(YELLOW);
	gotoxy(52,6);
	cprintf("  |");
	printf("\n");
	gotoxy(52,7);
	cprintf("  |");
	textcolor(BLUE);
	printf("\n");
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
	textcolor(YELLOW);
	printf("\t\t");
	cprintf("*             WELCOME TO WISH ME HBD             *");
	printf("\n");
	printf("\t\t");
	cprintf("*          ----------------------------          *");
	printf("\n");
	printf("\t\t");
	cprintf("*                                                *");
	printf("\n");
	printf("\t\t");
	cprintf("* This is a system which remember the birthday   *");
	printf("\n");
	printf("\t\t");
	cprintf("* of your near and dear.                         *");
	printf("\n");
	printf("\t\t");
	cprintf("**************************************************");
	textcolor(RED);
	gotoxy(20,19);
	cprintf("No, Chance of forgotten of anyone's Birthday.");
	printf("\n");
	gotoxy(16,20);
	cprintf("You can aslo send your wishes to your near and dear.");
	gotoxy(13,21);
	textcolor(LIGHTRED);
	cprintf("For Bug Report Contact at -> satyamakhilesh2000@gmail.com");
	printf("\n");
	gotoxy(23,22);
	textcolor(BROWN);
	cprintf("This System is build by: ");
	textcolor(LIGHTGREEN+BLINK);
	gotoxy(48,22);
	cprintf("SATYAM SINGH");
	gotoxy(1,7);
	textcolor(RED+BLINK);
	cprintf("  O");
	printf("\n");
	gotoxy(1,8);
	cprintf(" O O");
	printf("\n");
	gotoxy(1,9);
	cprintf("O   O");
	printf("\n");
	textcolor(BROWN);
	gotoxy(1,10);
	cprintf("o   o");
	printf("\n");
	gotoxy(1,11);
	cprintf(" o o");
	printf("\n");
	gotoxy(1,12);
	cprintf("  o");
	printf("\n");
	gotoxy(1,13);
	textcolor(YELLOW);
	cprintf("  |");
	printf("\n");
	gotoxy(1,14);
	cprintf("  !");
	gotoxy(76,7);
	textcolor(RED+BLINK);
	cprintf("  O");
	printf("\n");
	gotoxy(76,8);
	cprintf(" O O");
	printf("\n");
	gotoxy(76,9);
	cprintf("O   O");
	printf("\n");
	textcolor(BROWN);
	gotoxy(76,10);
	cprintf("o   o");
	printf("\n");
	gotoxy(76,11);
	cprintf(" o o");
	printf("\n");
	gotoxy(76,12);
	cprintf("  o");
	printf("\n");
	gotoxy(76,13);
	textcolor(YELLOW);
	cprintf("  |");
	printf("\n");
	gotoxy(76,14);
	cprintf("  !");
	gotoxy(7,14);
	textcolor(LIGHTGREEN);
	cprintf("    ^");
	printf("\n");
	gotoxy(7,15);
	cprintf("   ^ ^");
	gotoxy(7,16);
	cprintf("  ^CAP^");
	gotoxy(7,17);
	cprintf(" ^     ^");
	gotoxy(7,18);
	cprintf("^^^^^^^^^");
	gotoxy(68,14);
	textcolor(LIGHTGREEN);
	cprintf("    ^");
	printf("\n");
	gotoxy(69,15);
	cprintf("  ^ ^");
	gotoxy(70,16);
	cprintf("^CAP^");
	gotoxy(69,17);
	cprintf("^     ^");
	gotoxy(68,18);
	cprintf("^^^^^^^^^");
	gotoxy(1,24);
	system("pause");
}
void alert(){
	system("cls");
	textcolor(LIGHTRED+BLINK);
	printf("\n\n\n");
	printf("\t\t");
	cprintf("    |      A       L     EEEE  RRRR  TTTTT |");
	printf("\n");
	printf("\t\t");
	cprintf("    |    A   A     L     E     R R     T   |");
	printf("\n");
	printf("\t\t");
	cprintf("    |   AAAAAAA    L     EEEE  RR      T   |");
	printf("\n");
	printf("\t\t");
	cprintf("    |  A       A   L     E     R R     T   |");
	printf("\n");
	printf("\t\t");
	cprintf("    ! A         A  LLLL  EEEE  R  R    T   !");
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
	cprintf("->If you are not intially register then first of all create your id");
	printf(".\n\n");
	cprintf("-> After creating id, you can login with your id");
	printf(".\n\n");
	cprintf("-> You can See whose birthday is today,search birthday,Delete Every Single record,wish the birthday to your near and dear's. Once you loged in");
	printf(".\n\n");
	cprintf("-> Last wishes will be autometically disappered after sending new wishes");
	printf(".\n\n");
	system("pause");
}
void load(){
	int row,r;
	system("cls");
	alert();
	printf("\n\n");
	gotoxy(1,7);
	textcolor(RED+BLINK);
	cprintf("  O");
	printf("\n");
	gotoxy(1,8);
	cprintf(" O O");
	printf("\n");
	gotoxy(1,9);
	cprintf("O   O");
	printf("\n");
	textcolor(BROWN);
	gotoxy(1,10);
	cprintf("o   o");
	printf("\n");
	gotoxy(1,11);
	cprintf(" o o");
	printf("\n");
	gotoxy(1,12);
	cprintf("  o");
	printf("\n");
	gotoxy(1,13);
	textcolor(YELLOW);
	cprintf("  |");
	printf("\n");
	gotoxy(1,14);
	cprintf("  !");
	gotoxy(76,7);
	textcolor(RED+BLINK);
	cprintf("  O");
	printf("\n");
	gotoxy(76,8);
	cprintf(" O O");
	printf("\n");
	gotoxy(76,9);
	cprintf("O   O");
	printf("\n");
	textcolor(BROWN);
	gotoxy(76,10);
	cprintf("o   o");
	printf("\n");
	gotoxy(76,11);
	cprintf(" o o");
	printf("\n");
	gotoxy(76,12);
	cprintf("  o");
	printf("\n");
	gotoxy(76,13);
	textcolor(YELLOW);
	cprintf("  |");
	printf("\n");
	gotoxy(76,14);
	cprintf("  !");
	gotoxy(7,14);
	textcolor(LIGHTGREEN);
	cprintf("    ^");
	printf("\n");
	gotoxy(7,15);
	cprintf("   ^ ^");
	gotoxy(7,16);
	cprintf("  ^CAP^");
	gotoxy(7,17);
	cprintf(" ^     ^");
	gotoxy(7,18);
	cprintf("^^^^^^^^^");
	gotoxy(68,14);
	textcolor(LIGHTGREEN);
	cprintf("    ^");
	printf("\n");
	gotoxy(69,15);
	cprintf("  ^ ^");
	gotoxy(70,16);
	cprintf("^CAP^");
	gotoxy(69,17);
	cprintf("^     ^");
	gotoxy(68,18);
	cprintf("^^^^^^^^^");
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
int main(){
	HBD_pattern();
	instructions();
	load();
	start();
	return 0;
}
