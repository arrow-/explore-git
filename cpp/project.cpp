#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>
#include <fstream>
using namespace std;

#define GAP "\n\n\n\n\n\n\t\t\t"
#define TAB "\t\t\t\t"
#define clear "clear"

#define BLACK        0
#define BLUE         1
#define GREEN        2
#define CYAN         3
#define RED          4
#define MAGENTA      5
#define BROWN        6
#define LIGHTGRAY    7
#define DARKGRAY     8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTCYAN    11
#define LIGHTRED     12
#define LIGHTMAGENTA 13
#define YELLOW       14
#define WHITE        15
#define BLINK        128

      
    int bgc=40;  
    void clreol(){
      printf("\033[K");
      }
      
    void insline(){
      printf( "\x1b[1L");
      }
  
    void delline(){
      printf( "\033[1M");
      }

    void gotoxy(int x,int y){
      printf("\033[%d;%df",y,x);
      }
      
    void clrscr(){
      printf( "\033[%dm\033[2J\033[1;1f",bgc);
      }
      
    void textbackground(int color){
      switch(color%16){
	  case BLACK:          bgc=40;break;
	  case BLUE:           bgc=44;break;
	  case GREEN:          bgc=42;break;
	  case CYAN:           bgc=46;break;
	  case RED:            bgc=41;break;
	  case MAGENTA:        bgc=45;break;
	  case BROWN:          bgc=43;break;
	  case LIGHTGRAY:      bgc=47;break;
	  case DARKGRAY:       bgc=40;break;
	  case LIGHTBLUE:      bgc=44;break;
	  case LIGHTGREEN:     bgc=42;break;
	  case LIGHTCYAN:      bgc=46;break;
	  case LIGHTRED:       bgc=41;break;
	  case LIGHTMAGENTA:   bgc=45;break;
	  case YELLOW:         bgc=43;break;
	  case WHITE:          bgc=47;break;
	}
      }

    void textcolor(short color){  
      switch(color%16){
	  case BLACK:          printf("\033[0;%d;%dm",30,bgc);break;
	  case BLUE:           printf("\033[0;%d;%dm",34,bgc);break;
	  case GREEN:          printf("\033[0;%d;%dm",32,bgc);break;
	  case CYAN:           printf("\033[0;%d;%dm",36,bgc);break;
	  case RED:            printf("\033[0;%d;%dm",31,bgc);break;
	  case MAGENTA:        printf("\033[0;%d;%dm",35,bgc);break;
	  case BROWN:          printf("\033[0;%d;%dm",33,bgc);break;
	  case LIGHTGRAY:      printf("\033[0;%d;%dm",37,bgc);break;
	  case DARKGRAY:       printf("\033[1;%d;%dm",30,bgc);break;
	  case LIGHTBLUE:      printf("\033[1;%d;%dm",34,bgc);break;
	  case LIGHTGREEN:     printf("\033[1;%d;%dm",32,bgc);break;
	  case LIGHTCYAN:      printf("\033[1;%d;%dm",36,bgc);break;
	  case LIGHTRED:       printf("\033[1;%d;%dm",31,bgc);break;
	  case LIGHTMAGENTA:   printf("\033[1;%d;%dm",35,bgc);break;
	  case YELLOW:         printf("\033[1;%d;%dm",33,bgc);break;
	  case WHITE:          printf("\033[1;%d;%dm",37,bgc);break;
	}
      }
    
    int ungetch(int ch){
      return ungetc(ch, stdin);
      }
    
    int getch_echo(int i){
      struct termios oldt, newt;
      int ch;
      tcgetattr( STDIN_FILENO, &oldt );
      newt = oldt;
      newt.c_lflag &= ~ICANON;
      if(i)
		newt.c_lflag &=  ECHO;
      else
		newt.c_lflag &= ~ECHO;
      tcsetattr( STDIN_FILENO, TCSANOW, &newt );
      ch = getchar();
      tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
      return ch;
      }
      
    int getch(){
      getch_echo(0);
      }
      
    int getche(){
      getch_echo(1);
      }
    int kbhit(){
      struct termios oldt, newt;
      int ch;
      int oldf;    
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);    
      ch = getchar();    
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      fcntl(STDIN_FILENO, F_SETFL, oldf);    
      if(ch != EOF){
	ungetc(ch, stdin);
	return 1;
	}    
      return 0;
      }


class users
{
public: 
	char username[20];
	char password[20];
	int isadmin;

}adminpass,newuser,authuser;

void header();
void decrypt(char *);
void encrypt(char * loggeduser)
{
	char systemvar[40];
	char secretkey[20];
	int i;
	strcpy (secretkey,"shieldcryptpassword");

	sprintf(systemvar,"%s/secure.dat",loggeduser);
	fstream file(systemvar, ios::in);
	char d_password[15];
	file>>d_password;
	//cout<<d_password;
	for(i=0; i<strlen(d_password); i++)
	{
		d_password[i]+=secretkey[i];

	}

	//cout<<"\nEncrypted password : "<<d_password<<endl;

	decrypt(d_password);
	if(!file)
	{
		header();
		cout<<"\t\t\t\tFile cannot be opened!";
	}

}

void hiddenpass()
{
	char pass[10];
	int i=0,j=0,count=0;
	system("clear");
	cout<<"Enter password : ";
	while(1)
	{
		pass[i]=getch();

		if(pass[i]==10)
			break;
		else if(pass[i]==127)
		{
			if(count>0)
				--count;
			pass[i]=0;
			--i;
			system("clear");
			cout<<"Enter password :";
			for(j=0; j<count && j>=0; j++)
			{
				cout<<"#";
			}
		}
		else
		{
			++i;
			++count;
			cout<<"#";
		}
		
	}

	//cout<<"\n\nThe password entered is : "<<pass<<endl;
}

void decrypt(char *estring)
{
	char secretkey[20];
	strcpy(secretkey,"shieldcryptpassword");
	int i;
	for(i=0; i<strlen(estring); i++)
	{
		estring[i]-=secretkey[i];
	}

	//cout<<"\nReal password : "<<estring<<endl;

}
void header()
{
	system("clear");
	printf("\n\t\t\t\t\t\t   ____   __    _         __     __       ____    ____\n");
	printf("\t\t\t\t\t\t  / __/  / /   (_) ___   / / ___/ /      / __ \\  / __/\n");
	printf("\t\t\t\t\t\t _\\ \\   / _ \\ / / / -_) / / / _  /      / /_/ / _\\ \\  \n");
	printf("\t\t\t\t\t\t/___/  /_//_//_/  \\__/ /_/  \\_,_/       \\____/ /___/  \n");
	printf("\t\t\t\t\t\t_____________________________________________________\n");
	printf("\t\t\t\t\t\t\t\tThe simplest OS,ever.");
                                                      
}
 
 int spawnterm()

{
	header();
	cout<<GAP;
	cout<<"\t\t Inspired by bash terminal. Type 'bye' to exit\n\n\n";
	getchar(); getchar(); fflush(stdin);
	system("zsh");
	return 0;
}

void showip(char const* loggeduser)
{
	ifstream file;
	char systemvar[50];
	char *fcontent;
	long size;
	header();
	cout<<GAP;
	cout<<"\n";
	sprintf(systemvar,"ifconfig | grep inet > %s/IP.txt",loggeduser);
	system(systemvar);
	sprintf(systemvar, "%s/IP.txt",loggeduser);
	file.open(systemvar);
	if(!file)
		cout<<"Error! Make sure you have write permissions in here!";
	else
		while(file)
		{
			file.getline(systemvar,50, '\n');
			cout<<endl<<systemvar<<endl;
		}


}


//This function thanks the user.
void thank()
{
	header();
	char note[100];
	sprintf(note,"espeak \"Powering off Shield. Please wait\"");
	cout<<GAP<<"\t\t\tThank you for using ShieldOS. You are Awesome!";
	system(note);
	exit(0);
}
int selectengine(char *);
int webutilities(char const * loggeduser)
{
	int webchoice,webchoice1;	
	do
	{
		header();
		int choice;
		FILE *fp; char systemvar[20];
		char *fcontent,url[100];
	    long size;
	    char websites[10][20]={"www.google.co.in","www.facebook.com","www.wikipedia.org","www.yahoo.co.in","www.flipkart.com","www.youtube.com","www.redbus.in","www.toi.in","www.reddit.com","www.amazon.in"};

					cout<<GAP;
					cout<<"\n\t\t\t\t\t\t   Welcome to Web Utilities. You have the following choices:\n\n";
					cout<<"\n\t\t\t\t\t\t\t     |||||||||||||||||||||||||||||||";
					cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t  ||";
					cout<<"\n\t\t\t\t\t\t\t     ||   1. Speed links\t  ||";
					cout<<"\n\t\t\t\t\t\t\t     ||   2. View IP Details\t  ||";
					cout<<"\n\t\t\t\t\t\t\t     ||   3. Open URL \t\t  ||";
					cout<<"\n\t\t\t\t\t\t\t     ||   4. Shield Search Engine ||";
					cout<<"\n\t\t\t\t\t\t\t     ||   5. Go Back\t\t  ||";
					cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t  ||";
					cout<<"\n\t\t\t\t\t\t\t     |||||||||||||||||||||||||||||||";
					cout<<"\n\n\n\n\t\t\t\t\t\t Enter your choice : ";

					scanf("%d",&webchoice);
					switch(webchoice)
					{
						case 1:
							header();
							printf(GAP);
							cout<<"\n\t\t\t\tChoose one of the following speed links to get instant access to that website.\n\n";
							cout<<"\n\t\t\t\t\t\t\t     |||||||||||||||||||||||||||||||";
							cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t  ||";
							cout<<"\n\t\t\t\t\t\t\t     ||  1.Google \n\t\t\t\t\t\t\t     ||  2.Facebook \n\t\t\t\t\t\t\t     ||  3.Wikipedia \n\t\t\t\t\t\t\t     ||  4.Yahoo! \n\t\t\t\t\t\t\t     ||  5.Flipkart";
							cout<<"\n\t\t\t\t\t\t\t     ||  6.YouTube \n\t\t\t\t\t\t\t     ||  7.Redbus \n\t\t\t\t\t\t\t     ||  8.The Times Of India ";
							cout<<"\n\t\t\t\t\t\t\t     ||  9.Reddit \n\t\t\t\t\t\t\t     ||  10.Amazon \n\t\t\t\t\t\t\t     ||  0.Go Back";
							cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t  ||";
							cout<<"\n\t\t\t\t\t\t\t     |||||||||||||||||||||||||||||||";
							cout<<"\n\n\n\n\t\t\t\t\t\t\t\tEnter your choice : ";
							scanf("%d",&webchoice1);
							switch(webchoice1)
								{
								case 1: 
									sprintf(systemvar,"firefox %s",websites[0]);
									system(systemvar);
									break;
								
								case 2: 
									sprintf(systemvar,"firefox %s",websites[1]);
									system(systemvar);
									break;
									
								
								case 3: 
									sprintf(systemvar,"firefox %s",websites[2]);
									system(systemvar);
									break;
									
								
								case 4: 
									sprintf(systemvar,"firefox %s",websites[3]);
									system(systemvar);
									break;
									
								
								case 5: 
									sprintf(systemvar,"firefox %s",websites[4]);
									system(systemvar);
									break;
									
								
								case 6: 
									sprintf(systemvar,"firefox %s",websites[5]);
									system(systemvar);
									break;
									
								
								case 7: 
									sprintf(systemvar,"firefox %s",websites[6]);
									system(systemvar);
									break;
									
								
								case 8:
									sprintf(systemvar,"firefox %s",websites[7]);
									system(systemvar);
									break;
									
								
								case 9: 
									sprintf(systemvar,"firefox %s",websites[8]);
									system(systemvar);
									break;
									
								
								case 10: 
									sprintf(systemvar,"firefox %s",websites[9]);
									system(systemvar);
									break;
								}

					case 2:
				
							showip(loggeduser);
							break;
						
					case 3:
						
						header();
						printf(GAP);
						cout<<"\t\t\t\t\tEnter the Web URL : ";
						scanf("%s",url);
						sprintf(systemvar,"firefox %s ",url);
						system(systemvar);
						break;

					case 4:
						
						header();
						printf(GAP);
						cout<<"\n\t\t\t\t\t\t\t    ||||||||||||||||||||||||||||||||";
						cout<<"\n\t\t\t\t\t\t\t    ||   Shield Search Engine \t  ||";
						cout<<"\n\t\t\t\t\t\t\t    ||||||||||||||||||||||||||||||||";
						cout<<GAP;
						cout<<"\t\t\t\t\tEnter the search term : ";
						cin>>url;
						selectengine(url);
						break;

					case 5: 
						return 0;
				
					}
	}while(webchoice<5);
}

int selectengine(char * url)
{
	header();
	cout<<GAP;
	int choice;
	char systemvar[50];
	cout<<"\n\n\t\t\t\t\t\t\t\t Shield Search Beta\n";
	cout<<"\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~\n\n\n";
	cout<<"\n\t\t\t\t\t\t\t    ||||||||||||||||||||||||||||||||";
	cout<<"\n\t\t\t\t\t\t\t    ||\t\t\t\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   1. Google Search\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   2. DuckDuckGo Search\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   3. Bing Search\t\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   4. Yahoo Search\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   5. Go Back\t\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||\t\t\t\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||||||||||||||||||||||||||||||||";
	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t Enter your choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
			sprintf(systemvar,"firefox https://www.google.com/?q=%s",url);
			system(systemvar);
			return 0;
		case 2:
			sprintf(systemvar,"firefox https://www.duckduckgo.com/?q=%s",url);
			system(systemvar);
			return 0;
		case 3:
			sprintf(systemvar,"firefox https://www.bing.com/?q=%s",url);
			system(systemvar);
			return 0;
		case 4:
			sprintf(systemvar,"firefox https://search.yahoo.com/yhs/search?p=%s",url);
			system(systemvar);
			return 0;
		case 5:
		default:
			return 0;


	}


}

int shieldchat(char const * loggeduser)
{
	char systemvar[100],ip[15];
	int choice,port;
	goback:
	header();
	cout<<GAP;
	sprintf(systemvar,"notify-send \"Hello %s \" \"Welcome  to  ShieldChat  Beta. \"",loggeduser);
	system(systemvar);
	cout<<"\n\n\t\t\t\t\t\t\t\t Shield Chat Beta v.0.1\n";
	cout<<"\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~\n\n\n";
	cout<<"\n\t\t\t\t\t\t\t    ||||||||||||||||||||||||||||||||";
	cout<<"\n\t\t\t\t\t\t\t    ||\t\t\t\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   1. Host Connection\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   2. Connect To Host\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   3. View IP address\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   4. ShieldChat Help\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||   5. Go Back\t\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||\t\t\t\t  ||";
	cout<<"\n\t\t\t\t\t\t\t    ||||||||||||||||||||||||||||||||";
	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t Enter your choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
			header();
			cout<<GAP;
			cout<<"\n\n\t\t\t\t\t\t\t\t Shield Chat Beta Host\n";
			cout<<"\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~\n\n\n";
			cout<<GAP<<"\n\n";
			printf(TAB);
			cout<<"\t\t\tEnter your secret 4 digit number : ";
			scanf("%d",&port);
			header();
			cout<<GAP<<"\n\n";
			printf(TAB);
			cout<<"\t\t    Establishing connectivity using your key %d ...",port;
			sprintf(systemvar,"nc -l -p %d",port);
			cout<<"\n\n\n\t\t\t\tYou are now listening for any incoming connection on your IP address";
			cout<<"\n\n\n\t\t\t\tConnected!. Press Ctrl+C to exit anytime " ;
			system(systemvar);
		goto goback;
		
		case 2:
			header();
			cout<<"\n\n\t\t\t\t\t\t\t\t Shield Chat Beta Client\n";
			cout<<"\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~\n\n\n";
			cout<<GAP<<"\n\n";
			printf(TAB);
			cout<<"Enter the host IP Address : ";
			scanf("%s",ip);
			cout<<"\n\n\n\n\t\t\t\t\t Enter your ShieldNick : ";
			char nick[10];
			cin>>nick;
			cout<<"\n\n\n\n";
			cout<<"\t\t\t\t\tEnter the secret 4 digit number of host : ";
			scanf("%d",&port);
			header();
			cout<<GAP<<"\n\n";
			cout<<TAB;
			cout<<"\t\t Establishing connectivity to the host "<<ip<<" with key "<<port;
			sprintf(systemvar,"nc %s %d",ip,port);
			cout<<"\n\n\n\t\t\t\t\tYou are now looking for the host with the secret key..";
			cout<<"\n\n\n\t\t\t\tConnected!. Press Ctrl+C to exit anytime ";
			system(systemvar);
		goto goback;

		case 3:

			showip(loggeduser);
		goto goback;

		case 4 :

			header();
			cout<<GAP<<"\n\n";
			system("clear");
			cout<<"\t\t\t\t\t\t _______         _______           _______ _________\n";
			cout<<"\t\t\t\t\t\t   ____ \\       (  ____ \\|\\     /|(  ___  )\\__   __/\n";
			cout<<"\t\t\t\t\t\t| (    \\/       | (    \\/| )   ( || (   ) |   ) (  \n"; 
			cout<<"\t\t\t\t\t\t| (_____  _____ | |      | (___) || (___) |   | |   \n";
			cout<<"\t\t\t\t\t\t(_____  )(_____)| |      passFiepassFie|  ___  ||  ___  |   | |   \n";
			cout<<"\t\t\t\t\t\t      ) |       | |      | (   ) || (   ) |   | |   \n";
			cout<<"\t\t\t\t\t\t/\\____) |       | (____/\\| )   ( || )   ( |   | |   \n";
			cout<<"\t\t\t\t\t\t\\_______)       (_______/|/     \\||/     \\|   )_(   \n";
					                                                    
			cout<<"\n\n\t\t\t\t\t   ShieldChat. An open source chat platform made for Shield OS.\n\n\n\n\n";
			cout<<"\n\n\t\t\t\tShieldChat Beta uses the netcat libraries used by a Linux opearting system. Although,netcat libraries were not\n";
			cout<<"\t\t\t\t\tmade to implement chat, a hacky trick using netcat enables a user to chat over the wifi.";
			getchar();getchar(); fflush(stdin);
		goto goback;

		case 5:
			return 0;
		default :
		goto goback;


	}
}


void core(char const * loggeduser)
{
	int choice;
	void authenticate(void);
	char note[100];


	int webchoice,webchoice1;	
	FILE *fp; char systemvar[20];
	char *fcontent;
	long size;
	char websites[10][20]={"www.google.co.in","www.facebook.com","www.wikipedia.org","www.yahoo.co.in","www.flipkart.com","www.youtube.com","www.redbus.in","www.toi.in","www.reddit.com","www.amazon.in"};
	goback:
	header();
	printf(GAP);
	cout<<"\n\t\t\t\t\t\t\t     |||||||||||||||||||||||||||||||";
		cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t  ||";
		cout<<"\n\t\t\t\t\t\t\t     ||   1. Web Utilities\t  ||";
		cout<<"\n\t\t\t\t\t\t\t     ||   2. Shield Chat (Beta)\t  ||";
		cout<<"\n\t\t\t\t\t\t\t     ||   3. Shield Term (Beta)\t  ||";
		cout<<"\n\t\t\t\t\t\t\t     ||   4. Application Launcher ||";
		cout<<"\n\t\t\t\t\t\t\t     ||   5. File Manager\t  ||";
		cout<<"\n\t\t\t\t\t\t\t     ||   6. Logout\t\t  ||";
		cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t  ||";
		cout<<"\n\t\t\t\t\t\t\t     |||||||||||||||||||||||||||||||";
		cout<<"\n\n\n\n\t\t\t\t\t\t Enter your choice : ";
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				gotoweb:
				webutilities(loggeduser);
			goto goback;

			case 2:
				shieldchat(loggeduser);
				goto goback;

			case 3:
					spawnterm();
					goto goback;
			 case 4: case 5:
					system("clear");
					header();
					cout<<"\n\n\n\n\t\t\t\tThis feature is coming soon. Please visit github.com/sachinkamath/project-3rdsem to stay updated!";
					sprintf(note,"espeak \"This feature will be coming soon! Please checkout our GitHub Page.\"");
					system(note);
					getchar();getchar();fflush(stdin);
					goto goback;
			case 6:
					authenticate();

			default:
				goto goback;

		}
}

int admin(void);
void authenticate()
{
	FILE *fp;
	int choice,attempts=3;
	char confirmuser[20],confirmpass[20],systemvar[20];
	goback:
	header();
	printf(GAP);
	char note[100];
	sprintf(note,"espeak \"Welcome to Shield Authentication System. Please Select an Option.\"");
	system(note);
	cout<<"\t\t\t\tWelcome to Shield Authentication System.\n\n\n";
	cout<<"\t\t\t\t\t\t\t     ||||||||||||||||||||||||||||||||";
		cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     || 1. Authenticate As Admin   ||";
		cout<<"\n\t\t\t\t\t\t\t     || 2. Authenticate As User\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     || 3. Continue As Guest\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     || 4. Download Source Code\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     || 5. Fork on GitHub\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     || 6. Check for Updates\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     || 7. Power Off\t\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t   ||";
		cout<<"\n\t\t\t\t\t\t\t     ||||||||||||||||||||||||||||||||";
		cout<<"\n\n\n\n\t\t\t\t\t\t\t Enter your choice : ";
		cin>>choice;	

		switch(choice)
		{
			case 1:
				admin();
				break;
			case 2:
				header();
				printf(GAP);
				cout<<"\t\t\tEnter your username : ";
				cin>>confirmuser;
				sprintf(systemvar,"%s/secure.dat",confirmuser);

				fp=fopen(systemvar,"r");
				if(fopen(systemvar,"r")==NULL)
				{
					system("clear");header();
					printf(GAP);
					cout<<"\n\n\n\t\t\t\t\t\t\t\tNo such User exists! ";
					//(1)
					//{
						//if(kbhit())
						//{
							//kbhit();
							//break;
						//}
					//cl}
					goto goback;
				}
				tryagain:
				fread(&authuser, sizeof(authuser),1,fp);
				header();
				printf(GAP);
				cout<<"\t\t\t\tEnter the password for user "<<confirmuser<<" : ";
				cin>>confirmpass;

				if(!strcmp(authuser.password,confirmpass))
				{
					core(confirmuser);
				}
				else
				{
					
				--attempts;
				if(attempts)
				{
					printf("\t\t\t\t\t\tSorry! Wrong password Entered! %d attempts left ",attempts);
					system("clear");
					goto tryagain;
				}

				else
				authenticate();
				}
			break;

			case 3:
				header();
				cout<<"\n\n\n\n\n\t\t\t";
				cout<<"You have chosen to use the Guest Account.Any files you store will be deleted after you logout.";
				getchar();getchar();fflush(stdin);
				system("rm -rf guest/");
				system("mkdir guest");
				core("guest");
			break;

			case 4:
				header();
				cout<<GAP;
				cout<<"\tThe source will be downloaded from the GitHub repo and will be saved as Shield-Source";
				system("mkdir Shield-Source");
				system("git clone https://github.com/sachinkamath/shield-OS");
				cout<<"\n\n\n\t\t\tSuccessfully downloaded the archives. Happy Hacking :)";	
				getchar();getchar(); fflush(stdin);	
				goto goback;

			case 5:
				system("firefox https://github.com/sachinkamath/shield-OS");
				goto goback;

			case 6:
				header();
				cout<<GAP;
				cout<<"\tPlease wait while we check for updates on this version..\n\n";
				system("git pull https://github.com/sachinkamath/shield-OS ");
				getchar();getchar(); fflush(stdin);
				goto goback;

			case 7:
					thank();
			default : 

				goto goback;

		}


}

//This function authenticates the admin credentials and creates an admin user if it is the first time run.
int admin(void)
{
	void makeuser(void);
	FILE *fr, *fw;
	char confirmpass[20],confirmuser[20],systemvar[20];
	int attempts=3;
	if(fopen("admin/secure.dat", "r")==NULL)
	{
		sprintf(systemvar,"mkdir admin");
		system(systemvar);
		system("clear");
		header();
		printf(GAP);
		cout<<"\b\b\b\b\b\b\bAdmin not present. Please create a new password";
		fw=fopen("admin/secure.dat", "w+");
		printf(GAP);
		cout<<"\b\b\b\b\b\bEnter the new Admin password : ";
		cin>>adminpass.password;
		printf(GAP);
		cout<<"\b\b\bConfirm the new password : ";
		cin>>confirmpass;
		strcpy(adminpass.username,"admin");
		adminpass.isadmin=1;
		if(!strcmp(adminpass.password,confirmpass))
		{
			system("clear");
			header();
			printf(GAP);
			cout<<"\n\n\t\t\t\tPasswords Matching.";
			printf(GAP);
			fwrite(&adminpass,sizeof(adminpass),1,fw);
			rewind(fw);
			fcloseall();
			makeuser();
		}			
	}
	else
	{
		system("clear");header();
		
		printf(GAP);

		cout<<"\t\t\tEnter your username : ";
		cin>>confirmuser;
		sprintf(systemvar,"%s/secure.dat",confirmuser);

		fr=fopen(systemvar,"r");
		if(fopen(systemvar,"r")==NULL)
		{
			system("clear");header();
			printf(GAP);
			cout<<"\n\n\nNo such User exists! ";
			getchar();getchar();fflush(stdin);
			authenticate();
		}
		else
		{
			fread(&adminpass,sizeof(adminpass),1,fr);
			if(!adminpass.isadmin)
			{
				system("clear");header();
				printf(GAP);
				cout<<"\t\t\t\t\tYou do not have Administrative privileges.";
				getchar(); getchar(); fflush(stdin);
				authenticate();
			}
			tryagain:
			system("clear");header();
			printf(GAP);
			cout<<"\t\t\tEnter your password : ";
			cin>>confirmpass;
			if(!strcmp(confirmpass,adminpass.password))
			{
				system("clear");header();
				printf(GAP);
				cout<<"\a\t\t\t\t    Successfully authenticated!";

				makeuser();
			}
			else
			{
					
				--attempts;
				if(attempts)
				{
					printf("\t\t\t\t\t\tSorry! Wrong password Entered! %d attempts left ",attempts);
					system("clear");
					goto tryagain;
				}

				else
				return 0;
			}
		}
	}
}	




//This function is responsible for handling new users. Requires Admin privilege.
void makeuser()
{
	
	FILE *fp; char systemvar[20];
	char *fcontent;
        long size;

    char dname[20],dpass[20],filename[20],deleteuser[20];
    int dadmin;
	char *confirm;
	int i=0,choice;
	system("clear");
	
	goback:header();
	header();

	cout<<GAP;
	cout<<"\t\t\t\t     |||||||||||||||||||||||||||||";
	cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||   1. Add User\t\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||   2. View Users\t\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||   3. Modify A User\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||   4. Delete A User\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||   5. Web Utilities\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||   6. Chat Client\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||   7. Logout\t\t||";
	cout<<"\n\t\t\t\t\t\t\t     ||\t\t\t\t||";
	cout<<"\n\t\t\t\t\t\t\t     |||||||||||||||||||||||||||||";
	cout<<"\n\n\n\n\t\t\t\t\t\t Enter your choice : ";
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:

			system("clear");header();
			printf(GAP);
			cout<<"\t\t\t\tEnter the Username : ";
			scanf("%s",newuser.username);
			sprintf(systemvar, "%s,secure.dat",newuser.username);
			if(fopen(systemvar,"r")!=NULL)
			{

				system("clear");header();
				printf(GAP);
				cout<<"\t\t\t\tThe username already exists. Try again.";
				char note[100];
				sprintf(note,"espeak \"User already exists. Please Try Again\"");
				system(note);
				goto goback;
			}
			cout<<"\n\n\t\t\t\t\t\t\t Enter Password : ";
			scanf("%s",newuser.password);
			cout<<"\n\n\t\t\t\t\tDo you want to provide Administration rights to this user? (1/0) : ";
			scanf("%d",&newuser.isadmin);

				
			sprintf(systemvar,"mkdir %s",newuser.username);
			system(systemvar);
			sprintf(systemvar,"%s/secure.dat",newuser.username);
			fp=fopen(systemvar,"w+");
            fwrite(&newuser, sizeof(newuser), 1, fp);
            fcloseall();
            goto goback;
			//if(fopen(systemvar,"w+")==NULL)
            

        case 2:
           	system("clear");
            header();
            cout<<GAP;
            cout<<"\t\t\t\t\t";
            system("ls -d */");     //supposed to be system("ls -d <star>/");  ==>FIXME
            getchar();getchar();fflush(stdin);
            goto goback;

        case 3:
            system("clear");
            header();
            cout<<GAP;
            cout<<"\t\t\t\tEnter username:   ";
            scanf("%s",filename);
            if(!strcmp(filename,"admin")|| !strcmp(filename,"guest"))
            {
               	char note[100];
			sprintf(note,"espeak \"This user cannot be modified\"");
			system(note);
               	system("clear");
               	header();
               	cout<<GAP;
               	cout<<"\t\t\t\tSorry! This user cannot be modified!";
               	goto goback;

            }
            sprintf(systemvar,"%s/secure.dat",filename);
            if (fopen(systemvar,"r")==NULL)
            {
                system("clear");
                header();
                cout<<GAP;
                cout<<"\n\n\nNo such user exists";
                goto goback;
            }
                
            fp=fopen(systemvar,"r");
            fread(&newuser,sizeof(newuser),1,fp);
            cout<<"\t\t\t\tEnter new username or enter 'same' to retain the original : ";
            scanf("%s",dname);
  
            if(strcmp(dname,"same"))
                strcpy(newuser.username,dname);
            cout<<"\n\t\t\t\tEnter new password or enter 'same' to retain the original : ";
            scanf("%s",dpass);
            if(strcmp(dpass,"same"))
                strcpy(newuser.password,dpass);

            cout<<"\n\t\t\t\tEnter new administrative right or '9' to retain the original : ";
            scanf("%d",&dadmin);
            if(dadmin!=9)
                newuser.isadmin=dadmin;

            sprintf(systemvar,"rm -rf %s",filename);
            system(systemvar);
            sprintf(systemvar,"mkdir %s",newuser.username);
			system(systemvar);
			sprintf(systemvar,"%s/secure.dat",newuser.username);      
            fp=fopen(systemvar,"w+");
            fwrite(&newuser,sizeof(newuser),1,fp);
            fflush(fp);
            fclose(fp); 
            goto goback;
          
                
            case 4 :
            
            	system("clear");
                header();
                cout<<GAP;
                cout<<"\t\t\t\tEnter username:   ";
                scanf("%s",filename);
                
                if(!strcmp(filename,"admin")|| !strcmp(filename,"guest"))
                {
                	char note[100];
					sprintf(note,"espeak \"This user cannot be deleted\"");
					system(note);
                	system("clear");
                	header();
                	cout<<GAP;
                	cout<<"\t\t\t\tSorry! This user cannot be deleted!";
                	getchar();getchar();fflush(stdin);
                	goto goback;

                }
      
	            sprintf(systemvar,"%s/secure.dat",filename);
	            if (fopen(systemvar,"r")==NULL)
	            {
	                system("clear");
	                header();
	                cout<<GAP;
	                cout<<"\n\n\nNo such user exists";
	                goto goback;
	            }

	            sprintf(systemvar,"rm -rf %s",filename);
	            system(systemvar);
	            system("clear");
	            header();
	            cout<<GAP;
	            cout<<"\t\t\t\tUser Successfully Deleted!";
	            char note[100];
				sprintf(note,"espeak \"The user has been deleted!\"");
				system(note);
	            getchar();getchar();fflush(stdin);
	            goto goback;
	            break;
            	 

			case 5:
				webutilities("admin");
				goto goback;
			case 6:
				shieldchat("admin");
				goto goback;
			case 7:
				authenticate();
        	default:
        	goto goback;
        }
}
	              
                     


int main()
{
	authenticate();
	//hiddenpass();

}
