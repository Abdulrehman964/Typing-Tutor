#include"Header_Files/INTRO.h"

void getscore(char[], int speed,float);
void starttyping(char[]); //to start the game
double typingspeed(double, char[],int,int); // to calculate typing speed
void statistics(); //to update high score
void arrow(int, int);
void About();
void help();
void timer();
static int x = 1; //used for x cursor co-ordinate
#define pos1 ;printf("\n\n\t\t\t");
#define pos gotoxy(33, x++) /*for cursor movement*/
#define ln printf(".......................");
//.......................................................................................................................................................................
int z=0;
void delay(unsigned int mseconds) //function for delay
{
  clock_t goal = mseconds + clock();
  while (goal > clock());
}
void Show_Menu();

//...................................................................................
void win_color() 
{
  int key = 0;
  system("cls");
    int choice = 1;
  while (key != 27) 
  {
    key = 0;
    while (key != 13) 
	{
      system("cls");
      pos1;
      printf("#..choose your color choice..#");
      ln
      pos1;
      arrow(1, choice);
      printf("1.black bacground with green font");
      pos1;
      arrow(2, choice);
      printf("2.white bacground with black font");
      pos1;
      arrow(3, choice);
      printf("3.black bacground with purple font");
      pos1;
      arrow(4, choice);
      printf("4.black bacground with green font");
      pos1;
      arrow(5, choice);
      printf("5.grey bacground with white font ");
      pos1;
      arrow(6, choice);
      printf("6.exitt ");
      pos1;
      key = getch();
      if (key == 80 ) {
        choice++;
      } else if (key == 72 ) {
        choice--;
      } else {
        choice = choice;
      }
      if(choice == 7){ choice = 1;
	  }
	  else if(choice == 0){ choice = 6;
	  }
    }
    switch (choice) {
    case 1:
    	z=1;
      system("COLOR 0A");
      break;
    case 2:
    	z=2;
      system("COLOR 0F");
      break;
    case 3:
    	z=3;
      system("COLOR 0D");
      break;
    case 4:
    	z=4;
      system("COLOR 0A");
      break;
    case 5:
    	z=5;
      system("COLOR 8F");
      break;
    case 6:
	  	Show_Menu();
      break;
    }
    key = getch();
  }
  Show_Menu();
}
void setcolor(int ForgC) //function to change setcolor
{
  WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  //We use csbi for the wAttributes word.
  if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
    //Mask out all but the background attribute, and add in the forgournd color
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
  return;
}

//.................................................................................................................................................................................
int t = 10;
int c = 0;

char name[15];
//...............................................................................................................................................................................
void rectangle(int x, int y, int l, int b) //to create a rectangle
{
  int i, m;
  gotoxy(x, y);
  printf("%c", 201);
  for (i = x + 1; i < l - 1; i++) {
    gotoxy(i, y);
    printf("%c", 205);
  }
  gotoxy(i, y);
  printf("%c", 187);

  for (m = y + 1; m < b; m++) {
    gotoxy(x, m);
    for (i = x; i < l; i++) {
      if (i == x || i == l - 1) {
        gotoxy(i, m);
        printf("%c", 186);
      }

    }

  }

  gotoxy(x, m);
  printf("%c", 200);
  for (i = x + 1; i < l - 1; i++) {
    gotoxy(i, m);
    printf("%c", 205);
  }
  gotoxy(i, m);
  printf("%c", 188);
}


//................................................................................................................................................................................
//			main function
int main() 
{
	if(z==1)
	{
		system("COLOR 0A");
	}
	else if(z==2)
	{
		system("COLOR 0F");
	}
	else if(z==3)
	{
		system("COLOR 0D");
	}
	else if(z==4)
	{
		system("COLOR 0A");
	}
	else if(z==5)
	{
		system("COLOR 05");
	}
	Intro();
	system("cls");
    time_t t;
    time( & t);
    rectangle(0, 0, 70, 15);
    x = 1;
    system("cls");
    pos;
	gotoxy(40,10);  
    setcolor(12);
    printf("welcome to typing game ");
    setcolor(10);
    pos;
    gotoxy(40,12);
	printf("%s", ctime( & t));
    pos;
    gotoxy(40,13);
	ln pos;
    gotoxy(40,14);		
    printf("Enter player's name(Maximum 8 letter) :");
    gets(name);
    Show_Menu();
}
//.....................end of main function.................................

//startgame
//..........................................................................
void starttyping(char name[]) 
{
  int correct =0;
  int wrong =0;
  int letter =0;
  int i = 0;
  int t = 5;
  int key = 0;
  double speed;
  clock_t begin, end, current;
  double time_spent = 0;
  char filename[50];
  begin = clock();
  FILE * ptr;
  strcpy(filename, name);
  strcat(filename, ".txt");
  ptr = fopen(filename, "w");
  char str[1000];
  rectangle(0, 0, 70, 15);
  delay(500);
  system("cls");
  printf("\npress esc when finished writing\n\n");
  char s[]={"Human Resource Management, or HRM, is the practice of managing people to achieve better performance."};
  printf("%s",s);
  printf("\n\nStart typing here");
  pos1;
  while (key != 27 && time_spent<=t) 
  {
    current = clock();
    key = getch();
    if (key == s[i]) 
	{
		setcolor(2);
		printf("%c",key);
		letter++;
		
	}
	else 
	{
		setcolor(4);
		printf("%c",key);
		letter++;
		wrong++;
	}
    str[i] = key;
    i++;
    time_spent = ((double)(current - begin)) / CLOCKS_PER_SEC;
  }
  fputs(str, ptr);
  fclose(ptr);
  end = clock();
  time_spent = ((double)(end - begin)) / CLOCKS_PER_SEC;
  speed = (int)(60 * typingspeed(time_spent, filename,correct,wrong));
  system("cls");
  printf("\n\n\t\t\tYour net speed=%.0f words per minute", speed);
  float accuracy;
  float k=letter-wrong;
  float z=0;
  z=k/letter;
  accuracy=z*100;
  printf("\n\t\t\tAccuracy : %.2f",accuracy);
  getscore(name, speed,accuracy); //saves data to file
  ++x;
  
  pos;
  printf("1.# play again #");
  pos;
  int ch;
  printf("2.# main menu #");
  pos;
  printf("3.exit");
  pos;
  printf("Enter your choice::");
  scanf("%d", & ch);
  switch (ch) {
  case 1:
    starttyping(name);
    break; //recursive call
  case 2:
    Show_Menu();
    break;
  case 3:
    system("cls");
    gotoxy(17, 10);
    printf("#This Game is created by our Team Members , Sulaiman,Yahya,and ABDUL REHMAN#");
    delay(1000);
    exit(1);
  default:
    pos;
    printf("wrong choice!");
    pos;
    Show_Menu();
  }

}
//......................end of start game function..........................

void arrow(int realposition, int position) {
  if (realposition == position) {
    printf("oo");
  } else {
    printf("  ");
  }

}
//...........................set function starts..........................
void timer() 
{
  int ch;
  int t = 30;
  system("cls");
  x = 5;
  pos;
  printf("Set the time limit for typing in minute::");
  pos;
  ln
  pos;
  printf("press 0 for 10 sec");
  pos;
  printf("press 1 for 12 sec");
  pos;
  printf("press 2 for 15 sec");
  pos;
  scanf("%d", & ch);
  switch (ch) 
{
  case 0:
    t = 10;
    break;
  case 1:
    t = 12;
    break;
  case 2:
    t = 15;
    break;
  default:
    Show_Menu();
  }
}
//....................sett function ends....................................

//........................................................................
double typingspeed(double time, char name[],int letter,int wrong) 
{
  FILE * ptr;
  ptr = fopen(name, "r");
  int count = 0;
  char k;
  while ((k = fgetc(ptr)) != EOF) 
  {
    if (k == '.' || k == ' ' || k == 13) {
      count++;
    }
  }
  fclose(ptr);
  printf("\n\n\t\t\t :words typed: %d", count);
  pos1;
  return (count / time);
}
void help() 
{
		if(z==1)
	{
		system("COLOR 0A");
	}
	else if(z==2)
	{
		system("COLOR 0F");
	}
	else if(z==3)
	{
		system("COLOR 0D");
	}
	else if(z==4)
	{
		system("COLOR 0A");
	}
	else if(z==5)
	{
		system("COLOR 05");
	}
  system("cls");
  rectangle(0, 0, 70, 15);
  gotoxy(7, 5);
  setcolor(6);

  printf("#......Rules of the Game......#");
  gotoxy(7, 6);
  printf("=>Enter your name as player name");
  gotoxy(7, 7);
  printf("=>Set the time limit under option 3 in main menu(default limit is 30 sec)");
  gotoxy(7, 8);
  printf("=>type as many words in the time limit");
  getch();
  Show_Menu();
}
void About(void) 
{
  system("cls");
  gotoxy(7, 7);
  printf("Typing Tutor is our PF Project and Team Members are Sulaiman,Yahya,Abdul Rehman");
  getch();
  Show_Menu();
}
//.........................................................................
void getscore(char name[], int speed,float accuracy) 
{
  time_t s, val = 1;
  struct tm * current_time;
  s = time(NULL);
  current_time = localtime(&s);
  FILE * fp;
  fp = fopen("file.txt", "a");
  pos;
  if (fp == NULL)
    printf("error in opening file");
  fprintf(fp, "\n\t\t%s\t\t %d/%d/%d\t\t %d\t\t%.2f", name, current_time -> tm_mday, (current_time -> tm_mon + 1), (current_time -> tm_year + 1900), speed,accuracy);
  fclose(fp);
  pos;
  printf("stats updated");
}
void statistics() 
{
	
  int ch;
  FILE * fp;
  system("cls");

  printf("\t\t\t....The statistics are...\n\n\n");
  printf("--------------------------------------------------------------------------------------------------------------");
  printf("\t\t\t\t\t %s\t\t%s\t\t%s\t\t%s", "Name", "  day/month/year/   ", " wpm","Accuracy");
  fp = fopen("file.txt", "r");
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }
  getch();
  Show_Menu();
}
void Show_Menu()
{
	int choice = 1;
    int key = 0;
    	
	    system("cls");
        
        while(key!=13)
		{
        gotoxy(3,3);
        setcolor(15);
        printf("\t\t\t\t\t|MAIN MENU|");//cout<<key<<"---"<<index;
        gotoxy(3,4);
        printf("\t\t\t\t\t============");
        gotoxy(3,6);
        setcolor(15);
        if(choice==1){setcolor(12);}
        printf("\t\t\t\t\tStart Typing");
        gotoxy(3,8);
        setcolor(15);
        if(choice==2){setcolor(12);}
        printf("\t\t\t\t\tView Stats");
        gotoxy(3,10);
        setcolor(15);
        if(choice==3){setcolor(12);}
        printf("\t\t\t\t\tSet The Time Limit");
        gotoxy(3,12);
        setcolor(15);
        if(choice==4){setcolor(12);}
        printf("\t\t\t\t\tHELP");
        gotoxy(3,14);
        setcolor(15);
		if(choice==5){setcolor(12);}
        printf("\t\t\t\t\tAbout ME");
		gotoxy(3,16);
        setcolor(15);
		if(choice==6){setcolor(12);}
        printf("\t\t\t\t\tSet Window Theme");
		gotoxy(3,18);
        setcolor(15);
		if(choice==7){setcolor(12);}
        printf("\t\t\t\t\tExit");
		/////////////UP=224/72 Down=224/80 Enter=13
        key=getch();
        if(key==80){choice++;}
        else if(key==72){choice--;}
        if(choice==8){choice=1;}
        if(choice==0){choice=7;}
        }
        
  switch (choice) {
  case 1:
    starttyping(name);
    break;
  case 2:
    statistics();
    break;
  case 3:
    timer();
    Show_Menu();
    break;
  case 4:
    help();
    break;
  case 5:
    About();
    break;
  case 6:
    win_color();
    break;
  case 7:
    system("cls");
    gotoxy(40, 10);
    setcolor(15);
    printf("#This Game is created by our Team which consists of Sulaiman,Yahya,Abdul Rehman\n\n\n\n");
}
}

