#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#define MAX 30

using namespace std;


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal > clock());
}

typedef struct information{
   string name;
   string bday;
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
      int locate(int n);

 public:
     void init();
    void withdraw(int a);
    void deposit(int b);
    void balance(int c);
    void transfer(int d);
    void changePIN(char x[7]);
    void retrieve();
    void save();
     void decrypt();
 };
 int menu();
 int amount;
 char newpin[7];
 int acc;


int main()
{
     ATM x;
    //char j[7], k[7];
        srand(time(NULL));
    //x.insertcard();
    x.init();
    x.retrieve();

    while (1){
    switch (menu()){
        case 1: cout<<"Enter amount: "; cin>>amount; x.withdraw(amount); break;
        case 2: cout<<"Enter amount: "; cin>>amount; x.deposit(amount); break;
        case 3: cout<<"Enter amount: "; cin>>amount;x.balance(amount); break;
        case 4: cout<<"Enter Acc no. yout want to transfer: "; cin>>amount; x.transfer(acc); break;
        case 5: cout<<"Enter current PIN: "; cin>>newpin; x.changePIN(newpin); break;
        case 6: x.save();exit(0); break;
        default: cout<<" Please choose from the choices only!"<<endl;
                  system("pause");

        }
    }
    return 0;


}

void ATM::init(){
    a.marker = -1;
}


int menu(){
  int ch;
system ("cls");
cout <<"               MENU "<<endl;
cout <<"=================================="<<endl;
cout<<"    [1] Withdraw"<<endl;
cout<<"    [2] Deposit"<<endl;
cout<<"    [3] Balance"<<endl;
cout<<"    [1] Fund transfer"<<endl;
cout<<"    [2] Change PIN"<<endl;
cout<<"    [3] Exit"<<endl;
cout <<"=================================="<<endl;
cout<<"     Enter chosen number here: ";cin >>ch;

return ch;

}



void ATM::withdraw(int a){
    a.rec[i].deposit - a;

}



void ATM::deposit(int b){
    a.rec[i].deposit + b;
}



void ATM::balance(int c){
    cout<<"\t"<<a.rec[i].deposit<<"\t";

}




void ATM::transfer(int d){
     int p, q, w;
     p = locate(d);

    cout<<"Enter amount you want to transfer: "; cin>> amount;
    q = a.rec.deposit - amount;

    if (P<0){
        cout<<"\n Account does not exist";
        system("pause");
    }
    else {
        w =  a.rec[p].deposit + amount;
        system ("pause");
    }


    }




void ATM::changePIN(char x[7]){
      int p, q, w;
     p = locate(d);
    if (p==0){
        cout<<"\n Account does not exist";
        system("pause");
    }
    else
    cout<<"Enter new Pin: "; cin>> amount;
     strcpy (a.rec[p].pincode, amount);
     system ("pause");

}




void ATM::save(){
    fstream fp;
fp.open("BankDatabase.dbf", ios::out);
   if (!fp){
    cout <<"File error.\n";
    system("pause");
   }
else {
    for (int i = 0;i<=a.marker;i++){
        fp << a.rec[i].accnum <<endl<<a.rec[i].name<<endl<< a.rec[i].bday<<endl <<a.rec[i].contactnum<<endl<<a.rec[i].deposit<<endl<<a.rec[i].pincode<<endl;

}
    fp.close();
   }
}


void ATM::retrieve(){

fstream fp;
fp.open("BankDatabase.dbf", ios::in);
if (!fp){
    cout<<"File error.\n";
    system("pause");
}
else {

   int daccnum;
   string dname;
   string dbday;
   string dcontactnum;
   float ddeposit;
   char dpincode[7];
while(true){
        fp >>daccnum >>dname >>dbday >>dcontactnum >>ddeposit >>dpincode;
        fp.ignore();
        if (!fp.eof()){
           a.marker++;
           a.rec[a.marker].accnum = daccnum;
           a.rec[a.marker].name = dname;
           a.rec[a.marker].bday = dbday;
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


