#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <limits>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <limits>
#include <ctime>

#define MAX 30


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal > clock());
}


using namespace std;

struct hbd{
   int M, D, Y;
   char separator;
};


typedef struct information{
   string name;
   struct hbd B;
   char pincode[7];
   string contactnum;
   float deposit;
   int accnum;
}INFO;

typedef struct ATMregister{
       INFO rec[MAX];
       int marker;
}REGIST;



class ATM{
 private:
       REGIST a;
       bool isfull();
       bool isempty();
       int stringlocate(string n);
       int intlocate(int n);

 public:
    //FILE HANDLING
        void save();
        void savebank();
        void retrieve();

    //REGISTRATION FUNCTION ASSISTANT
        void whatname(INFO *L);
        void whataccnum(INFO *L);
        void whatbday(INFO *L);
        void whatcontnum(INFO *L);
        void whatdept(INFO *L);
        void whatpin(INFO *L);

        int stringduplicate(string L);
        int intduplicate (int L);
        int bdaychecker(int a, int b, int c);
        void Clearprevious();

    //PIN CODE ASSISTANT
         void pincode();
         int ConfirmPin(char L[7], char K[7]);
         void conencrypt();
         void encrypt();
         void decrypt();
         void confirm();

    //MAIN FUNCTIONS
          void init();
          void insertcard();
          void registration();
          void addinfos(INFO L);
          void bankopening();
          void setFontStyle(int FontSize);
          void load();
          void welcome();
          void loadfill();
          void warning();
          void display();

};

//GLOBAL VARIABLES
         void gotoxy(int x,int y);
         char pin[7];
         char testpin[7];


int main()
{

    ATM x;
    REGIST a;
    x.init();
    x.retrieve();
    x.insertcard();
    system("COLOR F");
    x.bankopening();

    system("COLOR F");
    x.registration();
    return 0;
}



//BANK OPENING

void ATM::bankopening(){
       setFontStyle(23);
   gotoxy(45,6 ); cout<<"INSERT CARD FOR REGISTRATION";
    load();
    gotoxy(47, 9); loadfill();
    system ("COLOR A");
    warning();
    gotoxy(54, 14);cout<<"NOT REGISTERED";_getch();
    gotoxy(54, 14);cout<<"PRESS ANY KEY   ";_getch();

}


void ATM::warning(){
     gotoxy(47, 12); cout<<"     __________________";
     gotoxy(47, 13); cout<<" ___/                  |";
     gotoxy(47, 14); cout<<"[ = |                  |";
     gotoxy(47, 15); cout<<"[_=_|                  |";
     gotoxy(47, 16); cout<<"     \\_________________|";


     gotoxy(42, 18); cout<<"____________________________________";
     gotoxy(45, 20); cout<<"DO NOT REMOVE CARD WHEN IN USE";
     gotoxy(45, 21); cout<<"OR PROCESS WILL BE TERMINATED";
     gotoxy(42, 22); cout<<"____________________________________";
}


void ATM::insertcard(){
setFontStyle(23);

while(true){
    system("cls");
    system("COLOR F");
    gotoxy(45, 6); cout<<"INSERT CARD FOR REGISTRATION";
    load();
    system("COLOR A");
   if(isempty() == 1)
     break;
    else
        continue;
}

}


void ATM::load(){
    int x, z;
    bool homeScreen = false;
    int n = 0;

	do{
        for(x = 0; x <= 2; x++){
            gotoxy(46, 8 + n);

            if(x == 0){
                for(z = 0; z <=25; z++){
                    if(x == 0 ){
                        if(z == 0 )
                            cout<<char(201);
                        else if (z == 25)
                             cout<<char(187);
                        else
                           cout<<char(205);
                    }
                    }
                     n++;
            }
            else if (x == 1){
                 for(z = 0; z <= 25; z++){
                    if (z==0 || z==25)
                        cout<<char(186);
                    else
                        cout<<" ";

                 }
                 n++;
            }
            else if(x == 2){
                 for(z = 0; z <=25; z++){
                        if(z == 0)
                             cout<<char(200);
                        else if (z == 25)
                             cout<<char(188);
                         else
                             cout<<char(205);
                      }
                  n++;
            }

        }
        homeScreen = true;
    } while(homeScreen == false);
}


void ATM::loadfill(){
    char z = 178;

       for (int i = 0; i<=23; i++){
          cout<<z;
            if (i<10)
                Sleep(200);
            if (i>=10 && i<20)
                Sleep(150);
            if (i>=10)
                Sleep(25);
       }
}



void ATM::setFontStyle(int FontSize){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = FontSize;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // font style
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}



void ATM::init(){
    a.marker = -1;
}



void ATM::addinfos(INFO L){
    if (isfull()){
        cout<<"\n Sorry, Bank membership is now full.\n"<<endl;
        system("pause");
    }
    else{
       a.marker++;
       a.rec[a.marker]= L;
    }
}




void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


bool ATM::isempty(){
     fstream fp;
   int lengthsize;
    fp.open("F:\mypin.txt", ios::in);
    fp.seekp(0,ios::end);
    lengthsize = fp.tellg();
    if (lengthsize == 0){
        return 1;
        fp.close();
    }
    else {
     return 0;
     fp.close();}

}




void ATM::welcome(){
int x, z;
    bool homeScreen = false;
    int n = 0;

	do{
        for(x = 0; x < 25; x++){
            gotoxy(9, 4 + n);

            if(x == 0){   //REGISTRATION TEXT BOX
                for(z = 0; z <=95; z++){
                        if( z==34|| z == 35|| z==36|| z == 37|| z==38|| z == 39|| z==40|| z == 41|| z==42|| z == 43|| z==44|| z == 45 || z == 46|| z==47||z == 48|| z==49||z == 50|| z==51||z == 52|| z==53||z == 54|| z==55||z == 56|| z==57||z == 58|| z==59||z == 60|| z==61||z == 62 )
                            cout<<char(205);
                        else if (z == 33)
                             cout<<char(201);
                        else if (z == 63)
                             cout<<char(187);
                        else
                             cout<<" ";
                    }
                     n++;
            }
            else if (x == 1){
                 for(z = 0; z <= 95; z++){
                    if (z==33 || z==63)
                        cout<<char(186);
                    else
                        cout<<" ";

                 }
                 n++;
            }
            else if(x == 2){
                 for(z = 0; z <=95; z++){
                        if( z==34|| z == 35|| z==36|| z == 37|| z==38|| z == 39|| z==40|| z == 41|| z==42|| z == 43|| z==44|| z == 45 || z == 46|| z==47||z == 48|| z==49||z == 50|| z==51||z == 52|| z==53||z == 54|| z==55||z == 56|| z==57||z == 58|| z==59||z == 60|| z==61||z == 62 )
                             cout<<char(205);
                        else if (z == 33)
                             cout<<char(200);
                        else if (z == 63)
                             cout<<char(188);
                         else
                            cout<<" ";
                      }
                  n++;
            }                                       //END OF REGISTRATION TEXT BOX
            else if (x == 3){                       // NAME AND ACC NO TEXT BOX
                 for(z = 0; z <=95; z++){
                        if(z == 53)
                             cout<<" ";
                        else if (z == 0 ||z == 54)
                             cout<<char(201);
                        else if (z == 52 || z == 95)
                             cout<<char(187);
                        else
                             cout<<char(205);
              }
             n++;
          }
            else if (x == 4){
                for(z = 0; z <= 95; z++){
                    if (z==0 || z==54 || z==52 ||z == 95)
                        cout<<char(186);
                    else
                        cout<<" ";
              }
             n++;
          }
            else if (x == 5){
                 for(z = 0; z <=95; z++){
                        if(z == 53)
                             cout<<" ";
                        else if (z == 0 ||z == 54)
                             cout<<char(200);
                        else if (z == 52 || z == 95)
                             cout<<char(188);
                        else
                             cout<<char(205);
              }
             n++;
          }                                             // END NAME AND ACC NO TEXT BOX
          else if (x == 6 || x == 9 || x == 12){        //REMAINING TEXT BOX
                 for(z = 0; z <=95; z++){
                         if(z == 49)
                             cout<<" ";
                        else if (z == 0 ||z == 50)
                             cout<<char(201);
                        else if (z == 48 || z == 95)
                             cout<<char(187);
                        else
                             cout<<char(205);
              }
             n++;
          }
           else if (x == 7 || x == 10 || x==13){
                 for(z = 0; z <=95; z++){
                         if (z==0 || z==48 || z==50 ||z == 95)
                        cout<<char(186);
                    else
                        cout<<" ";
              }
             n++;
          }
           else if (x == 8|| x==11 || x==14){
                 for(z = 0; z <=95; z++){
                       if(z == 49)
                             cout<<" ";
                       else if (z == 0 ||z == 50)
                             cout<<char(200);
                         else if (z == 48 || z == 95)
                             cout<<char(188);
                        else
                             cout<<char(205);
              }
             n++;
          }                                         //END

        }
        homeScreen = true;
    } while(homeScreen == false);
    gotoxy(12, 8); cout<<"Account name: ";
    gotoxy(66, 8); cout<<"Account Number: ";
    gotoxy(12, 11); cout<<"Birthday (MM/DD/YYYY): ";
    gotoxy(62, 11); cout<<"Contact Number(09XXXXXXXXX): ";
    gotoxy(12, 14); cout<<"Initial Deposit(Min. 5000): Php ";
    gotoxy(62, 14); cout<<"Enter PIN: ";
    gotoxy(62, 17); cout <<"Confirm Pincode: ";
    gotoxy(25, 17); cout <<"o       o       o";
}




void ATM::registration(){

    INFO L;
    string n;

          system ("cls");
           welcome();
            gotoxy(46, 5); cout<<"R E G I S T R A T I O N";
            gotoxy(12, 8);
            whatname(&L);
            gotoxy(66, 8); cout<<"Account Number: "; whataccnum(&L);
            whatbday(&L);
            whatcontnum(&L);
            whatdept(&L);
            whatpin(&L);
                  addinfos(L);
                  gotoxy(46, 20);loadfill();

                save();
                gotoxy(46, 23); cout<<"Registered Successfully!";_getch();
         }


         void ATM::display(){
     system("cls");
    int i;
    cout<<"\n\t\t AccNum\t\tAccName\t\t Bday\t\t ContactNum\t Deposit \t Pincode\n"<<endl;

      for (i=0; i<=a.marker; i++){
         cout <<"\n\t   "<<i+1<<" .) "<< a.rec[i].accnum<<"\t\t"<<a.rec[i].name<<"\t\t"<<a.rec[i].B.M<<a.rec[i].B.separator<<a.rec[i].B.D<<a.rec[i].B.separator<<a.rec[i].B.Y<<"\t"<<a.rec[i].contactnum<<"\t"<<a.rec[i].deposit<<"\t";
         cout<<a.rec[i].pincode<<"\n";
      }
      system("pause");
}



//REGISTRATION FUNCTION ASSISTANT

void ATM::whatname(INFO*L){
    string n;
    do{
          gotoxy(12, 17); cout <<"             o       o       o            ";
          gotoxy(12, 8);cout<<"Account name: "; cin>>n;

         if (stringduplicate(n) == 1){
              gotoxy(22, 17); cout<<"   NAME ALREADY EXIST "; _getch();

         }
         else {
            L->name = n;
         }

 }   while(stringduplicate(n)== 1);

}


void ATM::whataccnum(INFO *L){
    int accntnum;
   do{   srand(time(NULL));
       accntnum = 1000+(rand()%2000);      //Generate Account Number
    }while (intduplicate(accntnum)== 1);

    L->accnum = accntnum;
    cout<< L->accnum;
}


void ATM::whatbday(INFO *L){
    int month, date, year;
    char sep;
  do{
        gotoxy(12, 17); cout <<"             o       o       o            ";
          gotoxy(12, 11); cout<<"Birthday (MM/DD/YYYY): ";
             cin>>month>>sep>>date>>sep>>year;
         if (bdaychecker(month, date, year)== 0){
       gotoxy(24, 17);cout<<"Invalid Birthday!"; _getch();
       }
     else{
           L->B.M = month;
           L->B.separator = sep;
           L->B.D = date;
           L->B.separator = sep;
           L->B.Y = year;
        }
}while(bdaychecker(month, date, year) == 0);


}


void ATM::whatcontnum(INFO *L){
    string n;
    int a;
    do{
            gotoxy(12, 17); cout <<"             o       o       o            ";
       gotoxy(62, 11); cout<<"Contact Number(09XXXXXXXXX): "; cin>>n;
          a = n.length();
          if( a != 11){
        gotoxy(25, 17); cout<<" INVALID INPUT     ";  _getch();
          }
          else {
            L->contactnum = n;
          }
    }while(a!=11);
}


void ATM::whatdept(INFO *L){
    float n;
    do {
            gotoxy(12, 17); cout <<"             o       o       o            ";
     gotoxy(12, 14); cout<<"Initial Deposit(Min. 5000): Php "; cin>>n;
        if (n < 5000){
          gotoxy(20, 17); cout<<"MINIMUM DEPOSIT IS Php5000.00   "; _getch();
        }
        else {
            L->deposit = n;
            break;
        }
      }while( n <5000);
}



void ATM::whatpin(INFO *L){
   do {
         gotoxy(12, 17); cout <<"             o       o       o            ";
          gotoxy(62, 14); cout<<"Enter PIN: ";
              pincode();
              encrypt();
        gotoxy(62, 17); cout <<"Confirm Pincode: ";
              confirm();
              conencrypt();
              if (ConfirmPin (pin, testpin) == 1){
                 strcpy(L->pincode, pin);
                 break;
              }
              else{
                gotoxy(25, 17);cout<<"PIN DOES NOT MATCH";_getch();
              }
   }while(ConfirmPin(pin, testpin)== 0);
}




//MAIN FUNCTIONS ASSISTANT

/*void ATM::Clearprevious(){
      while (getch>1){
         ini=ini*(pow(hypin,hypin));
         hypin--;
       }
       system("cls");

}

*/

int ATM::bdaychecker(int a, int b, int c){
     if (a>=12){
       return 0;
     }
     else if (b>=31){
       return 0;
     }
     else if (c<=1850 ||c>=2008){
       return 0;
     }
     else
        return 1;
}



int ATM:: stringlocate(string n){
   int i;
   for (i=0;i<=a.marker;i++){
        if (n==a.rec[i].name)
           return i;
      }
      return -1;
}



int ATM::intlocate(int n){
   int i;
   for (i=0;i<=a.marker;i++){
        if (n==a.rec[i].accnum)
           return i;
      }
      return -1;
}



int ATM::intduplicate(int L){
     int p;
     p = intlocate(L);
       if (p> -1){
           return 1;
       }
       else {  return 0;
       }
}



int ATM::stringduplicate(string n){
     int p;
     p = stringlocate(n);
       if (p>-1){
           return 1;
       }else{
          return 0;
       }
}



bool ATM::isfull(){
   return(a.marker == MAX-1);
}




//PIN CODE ASSISTANT

int ATM::ConfirmPin(char L[7], char M[7]){
    int i;
	for(i = 0; i < 7; i++)
	{
		if(L[i] == M[i])
		{
		    return 1;    break;
		}
		else
		{
			return 0;    break;
		}
	}
}



void ATM::pincode(){
int index =0;
char ch;
while((ch=getch())!=13 && index<5){
    if (index<0)
        index=0;
    if(ch==8){//backspace ascii is 8
        putch('\b');
        putch(' ');
        putch('\b');
        index--;
     continue;
    }
    if(isdigit(ch)){
     pin[index++]=ch;
     putchar('*');
    }
}
if (index==5)
    pin[index++]=ch;
pin[index]='\0';

}



void ATM::confirm(){
int index =0;
char ch;
while((ch=getch())!=13 && index<5){
    if (index<0)
        index=0;
    if(ch==8){          //backspace ascii is 8
        putch('\b');
        putch(' ');
        putch('\b');
        index--;
     continue;
    }
    if(isdigit(ch)){
     testpin[index++]=ch;
     putchar('*');
    }
}
if (index==5)
    testpin[index++]=ch;
testpin[index]='\0';

}



void ATM::encrypt(){
int i=0;
while(pin[i]!='\0'){
    pin[i]=pin[i] + 106;
    i++;
}

}



void ATM::conencrypt(){
int i=0;
while(testpin[i]!='\0'){
    testpin[i]=testpin[i] + 106;
    i++;
}

}



void ATM::decrypt(){
int i=0;
while(pin[i]!='\0'){
    pin[i]=pin[i] - 106;
    i++;
}

}







//FILE HANDLING

void ATM::save(){
    system(" COLOR A");
    fstream fp;
fp.open("BankDatabase.dbf", ios::out);
   if (!fp){
    cout <<"File error.\n";
    system("pause");
   }
else {
    for (int i = 0;i<=a.marker;i++){
        fp <<a.rec[i].accnum <<endl<<a.rec[i].name<<endl<<a.rec[i].B.M<<endl<<a.rec[i].B.separator<<endl<<a.rec[i].B.D<<endl<<a.rec[i].B.separator<<endl<<a.rec[i].B.Y<<endl<<a.rec[i].contactnum<<endl<<a.rec[i].deposit<<endl<<a.rec[i].pincode<<endl;

}
    fp.close();
   }

  savebank();


}


void ATM::savebank(){
    fstream fp;
      fp.open("E:\mypin.txt",ios::out);
        if (!fp){
       cout <<"File error.\n";
        system("pause");
   }
else {
        fp << a.rec[a.marker].accnum<<endl<<a.rec[a.marker].pincode<<endl;
    }
    fp.close();
}



void ATM::retrieve(){

fstream fp;
fp.open("BankDatabase.dbf", ios::in);
if (!fp){
    cout<<"File error.\n";
    system("pause");
}
else {

   int daccnum, dmonth, ddate, dyear;
   string dname;
   string dbday;
   string dcontactnum;
   float ddeposit;
   char dpincode[7], dsep;
while(true){
        fp >>daccnum >>dname >>dmonth >>dsep >>ddate >>dsep >>dyear >>dcontactnum >>ddeposit >>dpincode;
        fp.ignore();
        if (!fp.eof()){
           a.marker++;
           a.rec[a.marker].accnum = daccnum;
           a.rec[a.marker].name = dname;
           a.rec[a.marker].B.M = dmonth;
           a.rec[a.marker].B.separator = dsep;
           a.rec[a.marker].B.D = ddate;
           a.rec[a.marker].B.separator = dsep;
           a.rec[a.marker].B.Y = dyear;
           a.rec[a.marker].contactnum = dcontactnum;
           a.rec[a.marker].deposit = ddeposit;
           strcpy (a.rec[a.marker].pincode, dpincode);
           }
        else
           break;
     }
    }
    fp.close();

}

