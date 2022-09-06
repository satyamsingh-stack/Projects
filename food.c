/* This code will run only in turbo c */
/* Author -> Satyam Singh */
#include<stdio.h>
#include<string.h>					//Used to access inbuilt functions of string 
#include<process.h>				 	//Used to access inbuilt function like exit, system("pause")
#include<malloc.h>					//Used to allocate memory dynammicaly 
#include<conio.h>
void screen1();		//Prototype of screen1 function

struct food{
	char iteam1[21],rate1[4];	//Represent the group to related variables into one place(food). This structure is generally used to store the food iteams.
	int sno1;			// iteam1 ,rate1, sno1 etc. are the member of the structure.
	struct food *next1;
};

struct food * head1,*tail1;

struct drink{
	char iteam2[21],rate2[4];	//Represent the group to related variables into one place(drink). This structure is generally used to store the drink iteams.
	int sno2;			//iteam2 ,rate2, sno2 etc. are the member of the structure.
	struct drink *next2;
};
struct drink* head2,*tail2;

struct customer{
	char name[21],address[51],mobile[11];  //This is used to Store the record of customer
};

struct customer c;
FILE *fp;		//Global variable used to declare the File

void line(){
	int n;
	for(n=1;n<=80;n++){
		textcolor(LIGHTRED);  	/*This Function will Simply Create Line */
		cprintf("_");		//cprintf is used for color printing
	}
	printf("\n");
}

void whitebox(int size){
	int i;
	textbackground(WHITE);
	for(i=1;i<=size;i++){
		cprintf(" ");		/*This Function will make a white rectangular Box*/
	}
	textbackground(BLACK);
}

void yellowbox(int size){
	int i;
	textbackground(YELLOW);
	for(i=1;i<=size;i++){
		cprintf(" ");		/*This Function will make a yellow rectangular Box*/
	}
	textbackground(BLACK);
}

void drawbox(int sr, int sc, int r, int c){		/*This Function will make a rectangular Box, Here sr= starting row, sc= starting column, r=row, c= Column*/			
	int i,j;
	gotoxy(sc,sr);
	textcolor(LIGHTBLUE);
	cprintf("%c",201);			
	for(i=1;i<=c;i++)
	   cprintf("%c",205);
	cprintf("%c",187);
	for(i=1;i<=r;i++)
	{
	  gotoxy(sc,sr+i);
	  cprintf("%c",186);
	  gotoxy(sc+c+1,sr+i);
	  cprintf("%c",186);
	}
	gotoxy(sc,sr+i);
	cprintf("%c",200);
	for(i=1;i<=c;i++)
	   cprintf("%c",205);
	cprintf("%c",188);
}


void add_food_iteam(){      	//This Function is used to add food item in the menu, using Linkedlist insertion at end.        
	struct food *new_food=(struct food*)malloc(sizeof(struct food));
	system("cls");
	drawbox(7,17,8,50);			
	textcolor(YELLOW+BLINK);
	gotoxy(27,6);
	cprintf(">> Add Food Iteams in the MENU <<");
	printf("\n\n");
	gotoxy(20,9);				//gotoxy function is used to set the pointer to the specific x and y cordinates.
	textcolor(CYAN);
	cprintf("Enter Iteam Id : "); gotoxy(37,9); yellowbox(5); gotoxy(37,9);	scanf("%d",&new_food->sno1);
	gotoxy(20,11);
	cprintf("Enter Food Iteam : "); gotoxy(38,11); yellowbox(10); gotoxy(38,11);	fflush(stdin);	gets(new_food->iteam1);
	gotoxy(20,13);
	textcolor(RED);
	cprintf("Enter Rate : "); gotoxy(32,13); whitebox(5); gotoxy(32,13);	fflush(stdin);	gets(new_food->rate1);
	printf("\n");
	new_food->next1=NULL;
	if(head1==NULL){
		head1=tail1=new_food;				//algo to add food iteams at the end of the linkedlist
	}
	else{
		tail1->next1=new_food;
		tail1=new_food;
	}
	gotoxy(30,15);
	textcolor(GREEN+BLINK);
	cprintf("Succesfully Added...");
	gotoxy(1,23);
	system("pause");
}

void add_drink_iteam(){				//This Function is used to add drink item in the menu, using Linkedlist insertion at end.
	struct drink *new_drink=(struct drink*)malloc(sizeof(struct drink));
	system("cls");
	drawbox(7,17,8,50);
	textcolor(YELLOW+BLINK);
	gotoxy(26,6);
	cprintf(">> Add DRINK Iteams in the MENU <<");
	printf("\n\n");
	gotoxy(20,9);
	textcolor(CYAN);
	cprintf("Enter Iteam Id : "); gotoxy(37,9); yellowbox(5); gotoxy(37,9);	scanf("%d",&new_drink->sno2);
	gotoxy(20,11);
	cprintf("Enter Drink Iteam : "); gotoxy(39,11); yellowbox(10); gotoxy(39,11);	fflush(stdin);	gets(new_drink->iteam2);
	gotoxy(20,13);
	textcolor(RED);
	cprintf("Enter Rate : "); gotoxy(32,13); whitebox(5); gotoxy(32,13);	fflush(stdin);	gets(new_drink->rate2);
	new_drink->next2=NULL;
	if(head2==NULL){
		head2=tail2=new_drink;   //fflush(stdin) is used for buffer
	}
	else{
		tail2->next2=new_drink;
		tail2=new_drink;				//algo to add drink iteams at the end of the linkedlist
	}
	gotoxy(30,15);
	textcolor(GREEN+BLINK);
	cprintf("Succesfully Added...");
	gotoxy(1,23);
	system("pause");
}

void show_food_iteam(){			//This function will simply display all the available food iteams.
	struct food* ptr;
	system("cls");
	gotoxy(25,1);
	textcolor(MAGENTA+BLINK);
	cprintf(">> All Available Food Iteams <<");
	ptr=head1;
	printf("\n");
	line();
	textcolor(LIGHTBLUE);
	cprintf("%-25s %-25s %-25s","Food Id","Food Iteams","Rate");
	printf("\n");
	line();
	while(ptr!=NULL){
		textcolor(GREEN);
		cprintf("%-25d %-25s %-25s",ptr->sno1,ptr->iteam1,ptr->rate1);
		printf("\n");
		ptr=ptr->next1;
	}
	gotoxy(1,23);
	system("pause");
}

void show_drink_iteam(){			//This function will simply display all the available food iteams.
	struct drink* ptr;
	system("cls");
	gotoxy(25,1);
	textcolor(MAGENTA+BLINK);
	cprintf(">> All Available DRINK Iteams <<");
	ptr=head2;
	printf("\n");
	line();
	textcolor(LIGHTBLUE);
	cprintf("%-25s %-25s %-25s","Drink Id","Drink Iteams","Rate");
	printf("\n");
	line();
	while(ptr!=NULL){
		textcolor(GREEN);
		cprintf("%-25d %-25s %-25s",ptr->sno2,ptr->iteam2,ptr->rate2);
		printf("\n");
		ptr=ptr->next2;
	}
	gotoxy(1,23);
	system("pause");
}

void create_id(){
	system("cls");
	system("cls");			//Here we are creating Id. Means add the data into the file for the future reference.
	drawbox(7,14,10,58);
	textcolor(YELLOW+BLINK);
	gotoxy(30,6);
	cprintf(">> Creating your User Id <<");
	gotoxy(16,10);
	textcolor(GREEN);
	cprintf("Enter Your Name : ");
	whitebox(15);
	gotoxy(34,10);
	fflush(stdin);	gets(c.name);
	gotoxy(16,12);
	textcolor(RED);
	cprintf("Mobile Number : ");
	whitebox(10);
	gotoxy(32,12);
	fflush(stdin);
	gets(c.mobile);
	gotoxy(16,14);
	textcolor(RED);
	cprintf("Current Address : ");
	whitebox(10);
	gotoxy(34,14);
	fflush(stdin);
	gets(c.address);
	fseek(fp,0,SEEK_END);	//fseek() is used to move file pointer associated with a given file to a specific position
	fwrite(&c,sizeof(c),1,fp);
	textcolor(GREEN+BLINK);
	gotoxy(31,16);
	cprintf("Successfully created...");
	gotoxy(1,23);
	system("pause");
}

void show_customer(){		//This function will simply display the record of customers.
	system("cls");
	textcolor(MAGENTA+BLINK);
	gotoxy(25,1);
	cprintf(">> See Your Cutomers Details <<");
	printf("\n");
	line();
	textcolor(LIGHTBLUE);
	cprintf("%-25s %-20s %-30s","Customer Name","Mobile Number","Address");
	printf("\n");
	line();
	rewind(fp);
	textcolor(GREEN);
	while(fread(&c,sizeof(c),1,fp)){
		cprintf("%-25s %-20s %-30s",c.name,c.mobile,c.address);
		printf("\n");
	}
	gotoxy(1,23);
	system("pause");
}

void admin(){			//Admin pannel. Only Admins have the access of this function.
	int l1,l2,id,pass;
	system("cls");
	gotoxy(30,7);
	textcolor(MAGENTA+BLINK);
	cprintf(">> Now, Login As Admin <<");
	drawbox(8,17,7,50);
	gotoxy(28,10);
	textcolor(GREEN);
	cprintf("Enter Admin Id : ");
	whitebox(10);
	gotoxy(45,10);
	scanf("%d",&id);
	gotoxy(28,12);
	textcolor(RED);
	cprintf("Enter Zipcode : ");
	whitebox(10);
	gotoxy(44,12);
	scanf("%d",&pass);
	if(id==318 && pass==2210){			//Admin userid==318 and Admin Password==2210
		int choice;
		fp=fopen("food.dat","rb+");
		if(fp==NULL) fp=fopen("food.dat","wb+");
		for(;;){
			system("cls");
			gotoxy(27,5);
			textcolor(MAGENTA+BLINK);
			cprintf(">>Now You can Edit Any Record<<");
			drawbox(6,20,10,41);
			gotoxy(25,8);
			textcolor(RED);
			cprintf("1");
			printf(" : ");
			textcolor(CYAN);
			cprintf("Add Food Iteams");
			gotoxy(25,9);
			textcolor(RED);
			cprintf("2");
			printf(" : ");
			textcolor(CYAN);
			cprintf("Add Drink Iteams");
			gotoxy(25,10);
			textcolor(RED);
			cprintf("3");
			printf(" : ");
			textcolor(CYAN);
			cprintf("Show Food Iteams");
			gotoxy(25,11);
			textcolor(RED);
			cprintf("4");
			printf(" : ");
			textcolor(CYAN);
			cprintf("Show Drink Iteams");
			gotoxy(25,12);
			textcolor(RED);
			cprintf("5");
			printf(" : ");
			textcolor(CYAN);
			cprintf("See Details of Your All Customer");
			gotoxy(25,13);
			textcolor(RED);
			cprintf("6");
			printf(" : ");
			textcolor(CYAN);
			cprintf("Log Out");
			textcolor(GREEN);
			gotoxy(25,15);
			cprintf("Enter Your Choice : ");
			gotoxy(44,15); whitebox(2); gotoxy(44,15); scanf("%d",&choice);
			switch(choice){		//menu
				case 1: add_food_iteam(); break;		//Add food
				case 2: add_drink_iteam(); break;		//Add Drink
				case 3: show_food_iteam(); break;		//Display Food 
				case 4: show_drink_iteam(); break;		//Display Drink
				case 5: show_customer();break;			//Display Customer
				case 6: fclose(fp);screen1();
				default:{
						gotoxy(30,17);
						textcolor(RED+BLINK);
						cprintf("Invalid Choice...");
						printf("\n\n\n\n\n");
						system("pause");
						}
				}
		}
	}
	else{
		gotoxy(30,15);
		textcolor(LIGHTRED+BLINK);
		cprintf("Wrong Input Given...");
	}
	gotoxy(1,23);
	system("pause");
}

void tree(){
	textcolor(RED);
	cprintf("     *      ");
	printf("\n");
	textcolor(GREEN);
	cprintf("     **     ");
	printf("\n");
	cprintf("    ****    ");			//This function will simply create the tree like diagram
	printf("\n");
	cprintf("   ******   ");
	textcolor(YELLOW);
	printf("\n");
	cprintf("     **     ");
	printf("\n");
	cprintf("    ****    ");
	printf("\n");
	cprintf("   ******   ");
	printf("\n");
	cprintf("  ********  ");
	printf("\n");
	cprintf(" ********** ");
	textcolor(RED);
	printf("\n");
	cprintf("    ****    ");
	printf("\n");
	cprintf("   ******   ");
	printf("\n");
	cprintf("  ********  ");
	printf("\n");
	cprintf(" ********** ");
	printf("\n");
	cprintf("************");
	printf("\n");
	textcolor(BROWN);
	cprintf("    ****    ");
	printf("\n");
	cprintf("    ****    ");
	printf("\n");
	cprintf("    ****    ");
}

void page1(){
	system("cls");
	gotoxy(1,15);
	tree();
	drawbox(10,16,9,53);
	gotoxy(27,12);
	textcolor(MAGENTA);
	cprintf("Current Date is : %s",__DATE__);		//It will display the Current Date
	gotoxy(27,13);						//It will dsplay the Current Time
	cprintf("Current Time is : %s",__TIME__);
	gotoxy(27,14);
	textcolor(RED);
	cprintf("------------------------------");
	textcolor(LIGHTGREEN);
	gotoxy(33,15);
	cprintf("WELCOME TO Food HUB");
	gotoxy(27,16);
	cprintf("------------------------------");
	gotoxy(17,17);
	textcolor(YELLOW);
	cprintf("This is a food/drink iteams ordering system in which");
	gotoxy(17,18);
	cprintf("you can order anything and get on door step");
	gotoxy(28,21);
	textcolor(RED);
	cprintf("No, Chance of data leaked");
	gotoxy(18,22);
	textcolor(MAGENTA);
	cprintf("No, Limit of Users many user can join as possible");
	gotoxy(23,23);
	textcolor(BROWN);
	cprintf("This System is build by Team : ");
	gotoxy(54,23);
	textcolor(CYAN+BLINK);
	cprintf("SATYAM SINGH");
	gotoxy(25,2);
	textcolor(LIGHTMAGENTA+BLINK);
	cprintf("Here only Admin can update data");
	printf("\n");
	line();
	gotoxy(25,4);
	textcolor(LIGHTBLUE);
	cprintf("Easy to Order Food/Drink Iteams");
	printf("\n");
	line();
	gotoxy(34,6);
	textcolor(GREEN);
	cprintf("Payment by UPI");
	printf("\n");
	line();
	gotoxy(23,24);
	system("pause");
}

void loading(){			//Loading like animation function
	int r;
	drawbox(7,23,7,35);
	gotoxy(35,6);
	textcolor(MAGENTA+BLINK);
	cprintf(">> ARRIVING <<");
	gotoxy(25,8);
	textcolor(GREEN);
	cprintf("Your Order is on the Way!");
	gotoxy(25,9);
	textcolor(LIGHTRED);
	cprintf("Arriving...");
	for(r=5;r<=20;r++){
		sleep(1);
		printf("%c",219);
	}
	gotoxy(25,10);
	textcolor(CYAN);
	cprintf("Please Receive Your Order From");
	gotoxy(25,11);
	cprintf("Your Door Step");
	gotoxy(25,12);
	textcolor(YELLOW+BLINK);
	cprintf("Thank you!");
	gotoxy(25,13);
	textcolor(LIGHTBLUE);
	cprintf("We are Looking forward to see");
	gotoxy(25,14);
	cprintf("your order again...");
	gotoxy(1,23);
	system("pause");
}

void UPI(){			//Payment function
	char pin[6],ch;
	int i=0;
	drawbox(7,20,7,40);
	gotoxy(22,12);
	textcolor(LIGHTRED);
	cprintf("Enter Your Pin to make Payment : ");
	while(i<5){
		ch=getch();	putchar('*');
		if(ch=='\r'){
			break;
		}
		pin[i]=ch;
		i++;
	}
	pin[i]='\0';
	printf("\n");
	system("cls");
	loading();
}

void order_food(){			// This function is used to order the food iteam
	int sno;
	struct food* temp;
	system("cls");
	drawbox(7,20,7,40);
	gotoxy(32,6);
	textcolor(MAGENTA+BLINK);
	cprintf(">> ORDER Food <<");
	temp=head1;
	gotoxy(22,8);
	textcolor(GREEN);
	cprintf("Enter Iteam Id : "); gotoxy(41,8);	whitebox(5); gotoxy(41,8);	scanf("%d",&sno);
	while(temp->sno1!=sno && temp!=NULL){
		temp=temp->next1;
	}
	if(temp->sno1==sno){
		textcolor(LIGHTGREEN);
		gotoxy(22,10);
		cprintf("You Order Details is %s in Rs %s",temp->iteam1,temp->rate1);
		printf("\n");
		UPI();	//This is a payment simulation function
	}
	else{
		gotoxy(30,12);
		textcolor(CYAN);
		cprintf("Something Went Wrong...");
		gotoxy(1,23);
		system("pause");
	}
}

void order_drink(){		// This function is used to order the drinks iteam
	int sno;
	struct drink* temp;
	system("cls");
	drawbox(7,20,7,40);
	gotoxy(35,6);
	textcolor(MAGENTA+BLINK);
	cprintf(">> ORDER DRINK <<");
	temp=head2;
	gotoxy(25,8);
	textcolor(GREEN);
	cprintf("Enter Iteam Id : "); gotoxy(41,8);	whitebox(5); gotoxy(41,8);		scanf("%d",&sno);
	while(temp->sno2!=sno && temp!=NULL){
		temp=temp->next2;
	}
	if(temp->sno2==sno){
		textcolor(LIGHTGREEN);
		gotoxy(25,10);
		cprintf("You Order Details is %s in Rs %s",temp->iteam2,temp->rate2);
		printf("\n");
		UPI();	//This is a payment simulation function
	}
	else{
		gotoxy(30,12);
		textcolor(CYAN);
		cprintf("Something Went Wrong...");
		gotoxy(1,23);
		system("pause");
	}
}

void login(){			
	char name1[51],mobile1[11];
	int l1,l2;
	system("cls");
	gotoxy(28,6);
	textcolor(MAGENTA+BLINK);
	cprintf(">> Now, Login with your Id <<");			//Creating the login page
	drawbox(8,17,7,50);
	gotoxy(28,10);
	textcolor(GREEN);
	cprintf("Enter Username : ");
	whitebox(15);
	gotoxy(45,10);
	fflush(stdin);
	gets(name1);
	gotoxy(28,12);
	textcolor(RED);
	cprintf("Enter Mobile Number : ");	fflush(stdin);
	whitebox(10);
	gotoxy(50,12);
	gets(mobile1);
	rewind(fp);
	while(fread(&c,sizeof(c),1,fp)){	//Open the file for reading purpose
		l1=strcmp(name1,c.name);		//Compare the string name1 and c.name
		l2=strcmp(mobile1,c.mobile);		//Compare the string mobile, c.mobile
		if(l1==0 && l2==0){
			int choice;
			for(;;){
				system("cls");
				gotoxy(27,5);
				textcolor(MAGENTA+BLINK);
				cprintf(">>Welcome Back %s <<",name1);
				drawbox(6,20,10,40);
				gotoxy(27,8);
				textcolor(RED);
				cprintf("1");
				printf(" : ");
				textcolor(CYAN);
				cprintf("Show All Food Iteams");
				gotoxy(27,9);
				textcolor(RED);
				cprintf("2");
				printf(" : ");
				textcolor(CYAN);
				cprintf("Show All Drink Iteams");
				gotoxy(27,10);
				textcolor(RED);
				cprintf("3");
				printf(" : ");
				textcolor(CYAN);
				cprintf("Order Food Iteams");
				gotoxy(27,11);
				textcolor(RED);
				cprintf("4");
				printf(" : ");
				textcolor(CYAN);
				cprintf("Order Drink Iteams");
				gotoxy(27,12);
				textcolor(RED);
				cprintf("5");
				printf(" : ");
				textcolor(CYAN);
				cprintf("log out");
				gotoxy(47,14);
				yellowbox(1);
				textcolor(GREEN);
				gotoxy(27,14);
				cprintf("Enter your choice : "); scanf("%d",&choice);
					switch(choice){
						case 1: show_food_iteam(); break;
						case 2: show_drink_iteam(); break;
						case 3: order_food();	break;			//Creating the Food menu
						case 4:	order_drink();	break;
						case 5: fclose(fp);screen1();
						default:
							gotoxy(30,16);
							textcolor(RED+BLINK);
							cprintf("Invalid Choice...");
							printf("\n\n\n\n\n");
							system("pause");
					}
				}
		}
		else{
			gotoxy(34,14);
			textcolor(RED+BLINK);
			cprintf("Something went wrong...");
		}
	}
	printf("\n\n\n\n\n");
	system("pause");
}

void screen1(){
	int choice;
	system("cls");
	for(;;){		//Infinite loop
		fp=fopen("food.dat","rb+");  // Open the food.dat in binary file for both reading and writing.
		if(fp==NULL) fp=fopen("food.dat","wb+");
		system("cls");
		drawbox(7,23,7,35);
		gotoxy(35,6);
		textcolor(MAGENTA+BLINK);
		cprintf(">>MAIN MENU<<");
		textcolor(RED);
		gotoxy(25,8);
		textcolor(RED);
		gotoxy(25,9);
		cprintf("1");
		printf(" : ");
		textcolor(CYAN);
		cprintf("Sign Up");
		textcolor(RED);
		gotoxy(25,10);
		cprintf("2");
		printf(" : ");
		textcolor(CYAN);
		cprintf("Login");
		gotoxy(25,11);
		textcolor(RED);
		cprintf("3");
		printf(" : ");
		textcolor(CYAN);
		cprintf("Login as Admistrator");
		gotoxy(25,12);
		textcolor(RED);
		cprintf("4");
		printf(" : ");
		textcolor(CYAN);
		cprintf("Quit");
		gotoxy(45,13);
		yellowbox(1);
		gotoxy(25,13);
		textcolor(GREEN);
		cprintf("Enter Your Choice : ");		scanf("%d",&choice);
		switch(choice){
			case 1: create_id();	break;
			case 2: login();	break;
			case 3: admin();	break;				//Creating Main Menu
			case 4: fclose(fp);	exit(0);
			default :
				printf("Invalid Choice...");
		}
	}
}

int main(){
	page1();
	screen1();
	return 0;
}  
