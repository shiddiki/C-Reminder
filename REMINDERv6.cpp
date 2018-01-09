#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <tchar.h>
#include <conio.h>
#include <time.h>
#include<Wincon.h>
#include<bits/stdc++.h>
#include <stdbool.h>
#include<iostream>
#define inf 999999999999
using namespace std;

///.,.,.,..,.,.,..,.,.....,.,...,.,.,.,.,.,.,.,.,.,.
void SetColor(int ForgC);
void job();
void newEntry();
void countdown();
void menu();
void checkfile();
void history();
void tprint();
void checkcolseAS();
void sortt();
    int year,month,day,hour,minute;
    vector<int>V;
int a[100000];
int b[100000];
int c[100000];
int starting=0;
long long int nowp[100];
long long int nowpsort[100];
int first=0;
string todo[100];
char lini[100];
vector<int>EE;
vector<int>FF;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),coord );
}

void SetColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int flag=0,tt=0;
int uYr,uMn,uDa,uMin,uHr;
int startPoint=0,fpo;
char liNe[50],tut;
int mon,dat,mint,hr,sec,yr,runh,runm;
int countDownT;
int stry,strmon,strd,strh,strmin;
int totwt,datt;
int ti=2,f=1,ff=1;
	int remy,remm,remd,remh,remmin;
    string m="C:\\rem1.mp3";
    string tti;
     FILE *fl;
        FILE *fm;
        string mp3;
        char mps;

time_t s=time(0); //Getting ready for time
tm t=*localtime(&s);
void startTime()
{
    time_t s=time(0); //Getting ready for time
tm t=*localtime(&s);

	strmon= t.tm_mon+1;     //str_t.wMonth;
strd=t.tm_mday;          //str_t.wDay;
strmin=t.tm_min;         // str_t.wMinute;
strh=t.tm_hour;       //str_t.wHour;
//sec=t.tm_sec;      //str_t.wSecond;
stry=t.tm_year+1900;          //str_t.wYear;

}

void crtime()
{
	//SYSTEMTIME str_t;
	//GetSystemTime(&str_t);
	time_t s=time(0); //Getting ready for time
tm t=*localtime(&s);

mon= t.tm_mon+1;     //str_t.wMonth;
dat=t.tm_mday;          //str_t.wDay;
mint=t.tm_min;         // str_t.wMinute;
hr=t.tm_hour;       //str_t.wHour;
sec=t.tm_sec;      //str_t.wSecond;
yr=t.tm_year+1900;          //str_t.wYear;
datt=dat;

//cout<<sec<<endl;

}
///checking time validity


int check(int a,int b,int c,int d,int e)
{
    time_t s=time(0); //Getting ready for time
tm t=*localtime(&s);

	mon= t.tm_mon+1;     //str_t.wMonth;
dat=t.tm_mday;          //str_t.wDay;
mint=t.tm_min;         // str_t.wMinute;
hr=t.tm_hour;       //str_t.wHour;
sec=t.tm_sec;      //str_t.wSecond;
yr=t.tm_year+1900;          //str_t.wYear;
datt=dat;

if(a<yr||b<mon)
    return 0;
else if(a==yr&&b==mon&&c<dat)
{
        return 0;
}
else if(a==yr&&b==mon&&c==dat&&d<hr)
{
    return 0;
}
else if(a==yr&&b==mon&&c==dat&&d==hr&&e<mint)
{
    return 0;
}
    return 1;

}

///counts second
	void wait ( int sec )
	{
		clock_t end_wait;
		end_wait = clock () + sec * CLK_TCK ;
		while (clock() < end_wait) {
		}
	}
BOOL WINAPI AllocConsole(void);


void checkcloseAS()
{
   long long int temp;
    fl = fopen("save.txt", "r");
    fscanf(fl,"%d",&first);
    for(int i=0,tt=0;i<6*first,tt<first;i=i+6,tt++)
    {
        fscanf(fl,"%d",&remy);
            fscanf(fl,"%d",&remm);
            fscanf(fl,"%d",&remd);
            fscanf(fl,"%d",&remh);
            fscanf(fl,"%d",&remmin);
            fscanf(fl,"%s",&liNe);

            temp=remy*100+remm;
            temp=temp*100+remd;
            temp=temp*100+remh;
            temp=temp*100+remmin;
            nowpsort[tt]=temp;
            todo[tt]=liNe;
    }
    tt=first;

    for(int i=0;i<tt;i++)
        for(int j=i;j<tt;j++)
    {
        if(nowpsort[i]>nowpsort[j])
        {
            swap(nowpsort[i],nowpsort[j]);
            swap(todo[i],todo[j]);
        }
    }


    for(int i=0,j=0,l=0;i<tt;i++)
    {
        temp=nowpsort[i];
        while(temp!=0)
        {
            if(l==4)
            {
                nowp[j]=temp%10000;
                temp/=10000;
                l=0;
            }
            else
            {
                nowp[j]=temp%100;
                temp/=100;
                l++;

            }
            j++;

        }
    }


remmin=nowp[0];
remh=nowp[1];
remd=nowp[2];
remm=nowp[3];
remy=nowp[4];
 int length= todo[0].copy(liNe,todo[0].size(),0);
            liNe[length]='\0';



for(int i=0;i<strlen(liNe);i++)
    {
        if(islower(liNe[i]))
            liNe[i]=toupper(liNe[i]);
    }

checkfile();

}

void WORKSTATION()
{
    checkcloseAS();
    SetColor(98);
    cout<<endl;

        long long int yy=0;
        int cnt=0;

        startTime();
        int sleeptime=0;
    char tu;
    flag=0;
    ///....................main working facility
        while(check(remy,remm,remd,remh,remmin-1)!=0)
		{//wait (1);	/* Wait for 1 seconds */
		    if(sleeptime==0)
                {Sleep(2);sleeptime=11;}
            else
                Sleep(60);

if(flag==0)
    countdown();

                ///..............
                gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl;


             {        gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl;
		if(flag!=0)
            {gotoxy(38,10);
                tprint();}
                 //system("cls");
                 gotoxy(38,8);
                    for(int ii=1;ii<5;ii++)
                         {
                                                 Sleep(500);

                                                gotoxy(35,5);
                            printf("---REMINDER---");
                            gotoxy(38,6);
                            cout<<"--------";
                            cout<<endl;

                                                 if(flag!=0)
                                                 {gotoxy(38,10);
                                             tprint();}

                                            // gotoxy(38+ii,8);
                                                // cout<<ii;
                            gotoxy(38+ii,12);
                            cout<<".";
                                if(flag!=0)
                                     {gotoxy(38,10);
                                     tprint();}
                                     SetColor(95);
                                     gotoxy(35,18);
                cout<<"Press Enter to Menu"<<endl;
                //cout<<remm<<" "<<remh<<" "<<remmin<<endl;
                SetColor(98);
char tut;
            if (kbhit())
                {
                    tut = getch();

                    if(tut==13)
                        {flag=0;
                            menu();
                            checkcloseAS();
                            //countdown();
                            SetColor(97);
                               gotoxy(35,18);
                cout<<"Press Enter to Menu"<<endl;
                SetColor(98);
                ii=5;
                cnt=7;

                        }
                }


                         }
                 system("cls");
                 if(flag!=0)
                 {gotoxy(38,10);
                 tprint();}
                 gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl;
             }

                      //  system("cls");
                      //  if(flag!=0)
                       // {gotoxy(38,10);
                 //tprint();
                        gotoxy(31,12);
                cout<<"to go"<<endl;



		crtime();
        //if(check(remy,remm,remd,remh,remmin)==0)
          //  break;
//            else
            cnt++;
            if(cnt==8)
            {
                cnt=0;
                startTime();
                countDownT=0;
               // system("cls");
                if(flag!=0)
                {gotoxy(31,12);
                cout<<"to go"<<endl;}

                countdown();
                gotoxy(38,10);
                tprint();
                gotoxy(30,19);
                gotoxy(35,18);
                cout<<"Press Enter to Menu"<<endl;

            }


		}

}
///main function
int main ()
{    crtime();



    SetColor(98);                                ///.......................
    //system("color 48");
    system("cls");
     gotoxy(40,9);
	cout << "Initializing REMINDER..."<<endl;
	//for(int i=0;i<100000000;i++)
      //  V.push_back(i);
	  fm=fopen("C:\\forRem.mp3","r");
        if(fm==NULL)
                {system("cls");
                    SetColor(99);
                    cout<<"forRem.mp3 is not found at C:"<<endl;
                cout<<"audio file is not present or named as forRem"<<endl;
                cout<<"Please copy an audio file to local disk C:"<<endl;

                }
                else
                    {

                        fl = fopen("save.txt", "r");

remy=0;
       fscanf(fl,"%d",&remy);
       fclose(fl);
       if(remy>0)
       {
           cout<<"Reminder is set"<<endl;

           // fl = fopen("save.txt", "r");
            //fscanf(fl,"%d",&startPoint);


           // for(int i=0;i<6;i++)
           //     fgets(liNe, sizeof liNe, fl);
           //fscanf(fl,"%d",&first);



        /*    fscanf(fl,"%d",&remy);
            fscanf(fl,"%d",&remm);
            fscanf(fl,"%d",&remd);
            fscanf(fl,"%d",&remh);
            fscanf(fl,"%d",&remmin);
            fscanf(fl,"%s",&liNe);*/
    //     fclose(fl);

            checkcloseAS();

            system("cls");
            gotoxy(35,10);
            SetColor(92);
            cout<<remy<<"/"<<remm<<"/"<<remd<<endl<<endl;
        gotoxy(35,12);
        printf("%02d:%02d:00",remh,remmin);
        gotoxy(35,16);
        cout<<"Press ENTER to SET time"<<endl;

        SetColor(98);
for(int i=0;i<2;i++)
    {Sleep(1000);
    cout<<".";
                if (kbhit())
                {
                    tut = getch();

                    if(tut==13)
                        newEntry();
                }

                else
            goto big;
    }

       }
       else
       {
           cout<<"redirecting to New Entry...";
           fl=fopen("save.txt","w");
           fprintf(fl,"0");
           fclose(fl);

           Sleep(120);
       }

while(1)
{menu();
checkcloseAS();
big:///work

    for(int i=0;i<strlen(liNe);i++)
    {
        if(islower(liNe[i]))
            liNe[i]=toupper(liNe[i]);
    }


    system("cls");
    gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl;
    gotoxy(35,18);
    if(starting==0)
    {cout<<"initializing..."<<endl;starting=1;}
    else
    cout<<"   loading..."<<endl;
    gotoxy(22,20);
    SetColor(91);
    int fuglu=1000;
    for(int i=0;i<40;i++)
    {fuglu=rand()%60;
        Sleep(30+fuglu);
        printf("%c",177);
    }
    WORKSTATION();

/// calling what to do part*/
job();
goto big;
//menu();



		}
//while(ti--)
    printf("time out at %02d %02d\n",remh,remmin);
   // menu();


		}

}
//		return 0;


void job()
{
    cout<<"playing..."<<endl;
//system(m.c_str());
system("start wmplayer C:\\sid.mp3");
 //fl = fopen("save.txt", "w");
 //fprintf(fl,"0");
 //fclose(fl);
 system("cls");
    gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl<<endl<<endl;
 SetColor(90);
 cout<<"TIME UP...."<<endl;
 cout<<"you have ";
 SetColor(92);
 cout<<liNe;
 SetColor(90);
 cout<<" to do"<<endl;
 SetColor(98);
 system("pause");

 nowpsort[0]=inf;
 for(int i=0;i<5;i++)
    nowp[i]=inf;
    sortt();
    first--;
    checkfile();
 checkcloseAS();



flag=1;

}
void newEntry()
{flag=0;
    system("cls");

    gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl<<endl;

		SetColor(90);
		cout<<"Press BackSpace for main menu..."<<endl;
		for(int i=0;i<4;i++)
            {char tut;
            Sleep(500);
            if (kbhit())
                {
                    tut = getch();

                    if(tut==8)
                        {flag=0;
                        SetColor(98);
                            menu();
                            checkcloseAS();

                        }
                }
            }
system("cls");

    gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl<<endl;


SetColor(98);
cout<<"entry no: "<<first+1<<endl;
    cout<<"enter";
    SetColor(95);
    cout<<" ..YEAR..MONTH..DATE..HOUR..MINUTE..";
    SetColor(98);
    cout<<" (in 24hour format)"<<endl;
    SetColor(92);
            cin>>remy;
            if(remy==-99)
            {SetColor(98);
                menu();
            SetColor(98);
            return;
            }
            cin>>remm>>remd>>remh>>remmin;
            SetColor(98);
        while(check(remy,remm,remd,remh,remmin)!=1)
        { SetColor(92);
        if(remy==0||remm==0||remd==0)  //remh==0||remmin==0
        {
            cout<<"invalid input"<<endl;
            getchar();
        }
        else
        cout<<"invalid time\n  enter ..YEAR..MONTH..DATE..HOUR..MINUTE..(in 24hour format)"<<endl;
    cin>>remy>>remm>>remd>>remh>>remmin;
        }
        SetColor(98);
    fclose(fl);
        cout<<"to do??(use _instead of Space)"<<endl;
        SetColor(90);
        cin>>liNe;
        SetColor(98);
        fl=fopen("save.txt","r");
        fscanf(fl,"%d",&first);
        first++;
        fclose(fl);
        fl=fopen("save.txt","w");
        fprintf(fl,"%d\n",first);
        fclose(fl);
for(int i=0;i<strlen(liNe);i++)
    {
        if(islower(liNe[i]))
            liNe[i]=toupper(liNe[i]);
    }

    tt=first-1;
long long int temp=0,jk=tt*5;
temp=remy*100+remm;
            temp=temp*100+remd;
            temp=temp*100+remh;
            temp=temp*100+remmin;
            nowpsort[tt]=temp;

            nowp[jk++]=remmin;
            nowp[jk++]=remh;
            nowp[jk++]=remd;
            nowp[jk++]=remm;
            nowp[jk++]=remy;

            todo[tt]=liNe;

  //checkcloseAS();

       // fclose(fl);
       // fl=fopen("save.txt","a");

        //for(int i=0;i<6*nth;i++)
            sortt();
        checkfile();


  //      fprintf(fl, "%d\n %d\n %d\n %d\n %d\n %s\n",remy,remm,remd,remh,remmin,liNe);
        //fclose(fl);
        f=2;ti=2,ff=1;
        //fl = fopen("save.txt", "w+");//overwrite
        //startPoint+=6;
        //fprintf(fl,"%d\n",startPoint);
        fclose(fl);
        system("cls");
        checkcloseAS();

        //checkfile();
}

///countdown time
void countdown()
{
    gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";

    gotoxy(35,10);
    int y=remy,mon=remm,d=remd,h=remh,minn=remmin;

    if(minn<strmin)
    {
        minn+=60;
        h--;
        countDownT+=minn-strmin;
    }
    else
        countDownT+=minn-strmin;
    if(h<strh)
    {
        d--;
        h+=24;
         countDownT+=(h-strh)*60;
    }
    else
        countDownT+=(h-strh)*60;
    if(d<strd)
    {
        mon--;
        d+=30;
        countDownT+=((d-strd)*24)*60;
    }
    else
        countDownT+=((d-strd)*24)*60;
    if(mon<strmon)
    {
        mon+=12;
        y--;
        countDownT+=((mon-strmon)*30)*24*60;
    }
    else
        countDownT+=((mon-strmon)*30)*24*60;
      countDownT+=(y-stry)*365*24*60;
     uYr= year=countDownT/(365*24*60);
      uMn=month=(countDownT%(365*24*60))/(30*24*60);
      uDa=day=((countDownT%(365*24*60))%(30*24*60))/(24*60);
      uHr=hour=(((countDownT%(365*24*60))%(30*24*60))%(24*60))/60;
      uMin=minute=(((countDownT%(365*24*60))%(30*24*60))%(24*60))%60;
/*
      if(year>0)
        {if(year==1)
            cout<<year<<" year ";
        else
            cout<<year<<" years ";
        }
      if(month>0)
        {if(month==1)
            cout<<month<<" month ";
            else
              cout<<month<<" months ";
        }

      if(day>0)
        {if(day==1)
            cout<<day<<" day ";
            else
                cout<<day<<" days ";
            }
      if(hour>0)
        {if(hour==1)
            cout<<hour<<" hour ";
            else
                cout<<hour<<" hours ";
            }
      if(minute>=0)
        {if(minute==1)
            cout<<minute<<" minute"<<endl;
            else if(minute>1)
                cout<<minute<<" minutes ";
                else
                    cout<<"less then 1 minute"<<endl;
}
*/
Sleep(600);
flag=1;
system("cls");
gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		gotoxy(38,10);
                 tprint();
gotoxy(31,12);
cout<<"to go"<<endl;
gotoxy(31,14);
cout<<"Work to do: "<<liNe<<endl;
SetColor(94);
gotoxy(35,18);
cout<<"Press Enter to Menu"<<endl;
SetColor(98);
}

void menu()
{
    int choice=1;
    char turn;
    UPDATE:
       // ch=getch();
       	//system("cls");
       	if(flag==1)
        {
             system("cls");
 gotoxy(35,10);
 SetColor(92);
 cout<<liNe<<endl;
 SetColor(98);
 /*pause(1);
 cout<<"Press ENTER to continue"<<endl;
 do{
 turn=getch();}
 while(turn!=13);*/
system("pause");
        }

    do{system("cls");
            gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";

		gotoxy(30,9);
		if(choice==1)
		printf("%c%c%c%c N E W  E N T R Y %c%c%c%c\n",219,178,177,176,176,177,178,219);
		else
		printf("        NEW ENTRY\n");

        gotoxy(31,11);
		if(choice==2)
		printf("%c%c%c%c   T O  D O %c%c%c%c\n",219,178,177,176,176,177,178,219);
		else
		printf("         TO DO\n");
		gotoxy(23,13);

		if(choice==3)
            printf("%c%c%c%c S T A R T  C O U N T D O W N %c%c%c%c\n",219,178,177,176,176,177,178,219);
		else
		printf("            START COUNTDOWN\n");

		gotoxy(34,15);

		if(choice==4)
            printf("%c%c%c%c Q U I T %c%c%c%c\n",219,178,177,176,176,177,178,219);
		else
		printf("      QUIT\n");


		turn=getch();
		if( turn == 72||turn ==75) choice--;
		else if( turn == 80||turn ==77) choice++;

		if(choice == 5) choice=1;
        else if(choice == 0) choice=1;

	}
	while( turn != 13 );

    switch(choice)
    {
        case 1:
             newEntry();
        break;
        case 2:
        history();
        break;
        case 3:
            {fclose(fl);
                fl = fopen("save.txt", "r");
        int furut;
       fscanf(fl,"%d",&furut);
                fclose(fl);
                if(furut>0)
                WORKSTATION();
                else
                {system("cls");
                    SetColor(98);
                gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------"<<endl;
                    SetColor(92);
                    cout<<"nothing to do.....redirecting to NEW ENTRY"<<endl;
                SetColor(98);
                Sleep(2000);
                newEntry();
                checkcloseAS();
                countdown();
                }
            break;}
        case 4:
            {
                system("cls");
                  SetColor(98);
    gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl<<endl;
		SetColor(92);
		gotoxy(34,10);
		cout<<"Are you sure?"<<endl;
		choice=1;
		do
		{gotoxy(32,12);
		if(choice==1)
            cout<<"..Yes..";
        else
            cout<<"  Yes  ";
            gotoxy(42,12);
            if(choice==2)
                cout<<"..No..";
            else
                cout<<"  No  ";
                turn=getch();
                if(turn==72||turn==75)choice--;
                if(turn==80||turn==77)choice++;
                if(choice==3)
                    choice=1;
                if(choice==0)choice=1;
                system("cls");
                SetColor(98);
                gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		SetColor(92);
		gotoxy(34,10);
		cout<<"Are you sure?"<<endl;
		//MessageBox(0, "Are You Sure?" , "" , -1 ) ;
		//MessageBox(0, "QUIT" , "QUIT" , 0 ) ;

		}while(turn!=13);
        if(choice==1)
            {system("cls");
            SetColor(91);

            gotoxy(35,20);
            for(int i=0;i<7;i++)
            {
                Sleep(600);
                if(i==0)
                    cout<<"S ";
                else if(i==1)
                    cout<<"I ";
                else if(i==2)
                    cout<<"D";
                else
                    cout<<". ";
            }
system("cls");
                system("taskkill /f /im cb_console_runner.exe");
                //system("taskkill /f /im REMINDERv4.exe");
                //Sleep(0);
                exit(0);

                }
        else
            {SetColor(98);
                menu();}

            }
        default:
            cout<<"no input"<<endl;
    }
    checkcloseAS();

}
void history()
{sortt();
    checkcloseAS();
    fl = fopen("save.txt", "r");
    char cho;
remy=0;
       fscanf(fl,"%d",&remy);
system("cls");
gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl;



    if(remy<=0)
       {
            printf("REMINDER is not set.\n \n");
            fclose(fl);
            gotoxy(12,12);
              cout<<"----press BACKSPACE to Main Menu----"<<endl;
            cho='H';
            do
            {gotoxy(12,12);
            cout<<"----press BACKSPACE to Main Menu----"<<endl;
            //system("cls",12);
            Sleep(1);
            cho=getch();
            }while(cho!=8);
            flag=0;
            menu();
        }
    else
        {fclose(fl);
        SetColor(93);
            fl = fopen("save.txt", "r");
            //fscanf(fl,"%d",&startPoint);


           // for(int i=0;i<6;i++)
           //     fgets(liNe, sizeof liNe, fl);
           ///...........................................................................
           ///...........................................................................
           ///...........................................................................
           /*
            fscanf(fl,"%d",&remy);
            fscanf(fl,"%d",&remm);
            fscanf(fl,"%d",&remd);
            fscanf(fl,"%d",&remh);
            fscanf(fl,"%d",&remmin);
            fscanf(fl,"%s",&liNe);
            */
            sortt();
            int stt=1,pl=0;
            first=remy;
           // gotoxy(25,14);
            for(int i=0,j=0;i<first*5;i=i+5,j++)
            {remmin=nowp[i+0];
            remh=nowp[i+1];
            remd=nowp[i+2];
            remm=nowp[i+3];
            remy=nowp[i+4];
            //todo[j];
            //cout<<todo[j];
            int length= todo[j].copy(lini,todo[j].size(),0);
            lini[length]='\0';


            if(stt>1)
            {gotoxy(1,15+pl);
            pl+=3;}

            fclose(fl);
            if(check(remy,remm,remd,remh,remmin)!=1)
                {
                    cout<<"time is invalid or passed"<<endl<<"checking next to do list";
                    for(int i=0;i<3;i++)
                    {Sleep(1000);
                    cout<<".";
                    }
                    cout<<endl;
                    ///.................................................................






                }
                else
                {
                    printf("%d: ",stt++);
                    cout<<lini<<endl;
                    printf("at  %02d:%02d:00   %d/%02d/%02d\n\n\n",remh,remmin,remy,remm,remd);
                cout<<endl;
                }
        }
        }
        SetColor(98);
        /*cout<<endl<<"REMINDER is set"<<endl;
        cout << "REMINDER is in progress... to remind you up at ";
        printf("%02d:%02d:00 to %s (24hour format)\n",remh,remmin,liNe);

        */  //  cout<<"set new reminder??\n y/n"<<endl;
           // cin>>tt;
    //if(tt=="y")
      //  {   newEntry();

       // }
///..............
checkcloseAS();
int choice=1;
char turn;
cout<<endl;
SetColor(98);
    do
		{gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		    gotoxy(28,9);
		    cout<<"REMINDER is set"<<endl;
        cout << "REMINDER is in progress... to remind you up at ";
        SetColor(92);
        printf("%02d:%02d:00",remh,remmin);
        SetColor(98);
        printf(" to %s (24hour format) ",liNe);
        cout<<remy<<"/"<<remm<<"/"<<remd<<endl<<endl;
        cout<<" Want to set new reminder??";
         SetColor(90);
		    gotoxy(32,13);
		if(choice==1)
            cout<<"..Yes..";
        else
            cout<<"  Yes  ";
            gotoxy(42,13);
            SetColor(90);
            if(choice==2)
                cout<<"..No..";
            else
                cout<<"  No  ";
                turn=getch();
                if(turn==72||turn==75)choice--;
                if(turn==80||turn==77)choice++;
                if(choice==3)
                    choice=1;
                if(choice==0)choice=1;
                system("cls");
                SetColor(98);
                gotoxy(35,5);
		printf("---REMINDER---");
		gotoxy(38,6);
		cout<<"--------";
		cout<<endl;
		SetColor(98);
		}while(turn!=13);

        if(choice==1)
            newEntry();
            else
                checkcloseAS();


///..............
checkcloseAS();

        cout<<endl<<"REMINDER is set"<<endl;
        cout << "REMINDER is in progress... to remind you up at ";
        printf("%02d:%02d:00     (24hour format)\n",remh,remmin);
        system("cls");

}
void tprint()
{SetColor(92);
    if(year>0)
        {if(year==1)
            cout<<year<<" year ";
        else
            cout<<year<<" years ";
        }
      if(month>0)
        {if(month==1)
            cout<<month<<" month ";
            else
              cout<<month<<" months ";
        }

      if(day>0)
        {if(day==1)
            cout<<day<<" day ";
            else
                cout<<day<<" days ";
            }
      if(hour>0)
        {if(hour==1)
            cout<<hour<<" hour ";
            else
                cout<<hour<<" hours ";
            }
      if(minute>=0)
        {if(minute==1)
            cout<<minute<<" minute"<<endl;
            else if(minute>1)
                cout<<minute<<" minutes ";
                else
                    cout<<"less then 1 minute"<<endl;

}
SetColor(98);
gotoxy(31,14);

cout<<"Work to do: ";
SetColor(90);
cout<<liNe<<endl;
SetColor(98);

cout<<"at  "<<remy<<"/"<<remm<<"/"<<remd<<endl;
printf("%02d:%02d:00     (24hour format)",remh,remmin);

}

void checkfile()
{
    int nth;
                                char nt[100];
                                nth=first;
        fl = fopen("save.txt", "w");
        //fprintf(fl,"\n");
        fprintf(fl,"%d\n",first);
        for(int i=nth*5-1,j=0,l=nth-1;i>=0;i--)
        {

                fprintf(fl,"%d\n",nowp[i]);
            j++;
            if(j==5)
            {int length= todo[l].copy(lini,todo[l].size(),0);
            lini[length]='\0';
                fprintf(fl,"%s\n",lini);
                j=0;
                l--;}
            }
fclose(fl);

}
void sortt()
{
    long long int temp;
    for(int i=0;i<tt;i++)
        for(int j=i;j<tt;j++)
    {
        if(nowpsort[i]>nowpsort[j])
        {
            swap(nowpsort[i],nowpsort[j]);
            swap(todo[i],todo[j]);
        }
    }


    for(int i=0,j=0,l=0;i<tt+1;i++)
    {
        temp=nowpsort[i];
        while(temp!=0)
        {
            if(l==4)
            {
                nowp[j]=temp%10000;
                temp/=10000;
                l=0;
            }
            else
            {
                nowp[j]=temp%100;
                temp/=100;
                l++;

            }
            j++;

        }
    }

}
