#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

 class address {
 private:
     char fname[50],lname[50], country[40],state[40],city[40],street[50],email[50];
     long long phno,pin,house;

 public:
     /*  Create  Address*/
    void createContact(){ //c1
     cout<<"enter your First name ";
     cin>>fname;

     cout<<"enter Last Name: ";
     cin>>lname;

     cout<<"enter Country: ";
     cin>> country;

     cout<<"enter State: ";
     cin>> state;

     cout<<"enter City: ";
     cin>> city;

     cout<<"enter Street Area: ";
     cin>> street;

     cout<<"enter House No: ";
     cin>> house;

     cout<<"enter Area Pin: ";
     cin>> pin;

     cout<<"enter Phone No: ";
     cin>> phno;


     cout<<"enter Email: ";
     cin>> email;

        }

        /* To Print Address  */
        void showContact(){ //c2
        cout<<"Name: " <<fname<<" "<<lname<<endl;
        cout<<"Address: "<<country<<" "<<state<<" "<<city<<" "<<street<<" "<<house<<" "<<pin<<endl;
        cout<<"Contact No.: "<<phno<<endl;
        cout<<"Email: "<<email<<endl;
        }

        void writeOnFile(){ //c3
            char ch;
            ofstream f1;
            f1.open("adsbook.txt",ios::binary | ios::app);
           do{
            createContact();
            f1.write(reinterpret_cast<char*>(this), sizeof(*this));
            cout<<"Do you have next data(y/n)";
            cin>>ch;
           }while(ch =='y');
           cout<<"Address Has Been Sucessfully Created.... ";
           f1.close();
        }
        void readFromFile(){ //c4
        ifstream f2;
        f2.open("adsbook.txt",ios::binary);

        cout<<"\n.................................";
        cout<<"Address List";
        cout<<"\n................................." ;

        while(!f2.eof()){
            if(f2.read(reinterpret_cast<char*>(this), sizeof(*this)))
                {
                showContact();
                cout<<"\n...........................";
                }
            }
            f2.close();

    }
    void searchOnFile(){ //c5
        ifstream f3;
        long long phone;
        cout<<"Enter Phone No.";
        cin>>phone;
        f3.open("adsbook.txt", ios::binary);

         while(!f3.eof()){
            if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))){
                if(phone == phno){
                    showContact();
                    return;
                }
            }
         }
         cout<<"\n\n No Record Found";
         f3.close();
    }

    void deletFromFile(){ //c6
    long long phone;
    int flag =0;
    ofstream f4;
     ifstream f5;
     f5.open("adsbook.txt", ios::binary);
          f4.open("temp.dat", ios::binary);

  cout<<"enter phone no to delete";
  cin>>phone;
  while(!f5.eof()){
    if(f5.read(reinterpret_cast<char*>(this), sizeof(*this))){
        if(phno != phone) {
        f4.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
        else flag = 1;
    }
  }
  f5.close();
  f4.close();
  remove("adsbook.txt");
  rename("temp.dat", "adsbook.txt");

  flag == 1 ?
  cout<<"\tAddress Deleted...":
  cout<<"\tContact Not found...";
    }

    void editContact(){ // c7
    long long phone;
    fstream f6;

    cout<<"Edit Address \n";
    cout<<"\n==================================\n ";
    cout<<"Enter the phone number to be edit: ";
    cin>>phone;
    f6.open("adsbook.txt", ios::binary|ios::out|ios::in);
    while(!f6.eof()){
        if(f6.read(reinterpret_cast<char*>(this), sizeof(*this))){
            if(phone==phno){
                cout<<"Enter new record\n ";
                createContact();
                int pos = -1*sizeof(*this);
                f6.seekp(pos, ios::cur);
                f6.write(reinterpret_cast<char*>(this), sizeof(*this));
                cout<<endl<<endl<<"\tAddress Update...";
                return;
            }
        }
    }
    cout<<"\n\nNo Record Found";
    f6.close();
    }
};

int main(){ // Min function
system("cls");
system("color 3F"); //color XY,X = background color,Y = text color

cout<<"\n\n\n\n\n\n\t\t * WELCOME TO THE ADDRESS BOOK* ";
cout<<"\n\n\n\n\n\n\t\t * Press Enter * ";

 getch();
 while(1){
    address c1;
    int  choise;

    system("cls");
    system("color 03");

    cout<<"\nAddress Book ";
    cout<<"\n\n Main Menu";
    cout<<"\n===================================\n";
    cout<<"[1] Add New Address \n";
    cout<<"[2] List all Address \n";
    cout<<"[3] Search Address \n";
    cout<<"[4] Delete Address \n";
    cout<<"[5] Edit Address \n";
    cout<<"[0] Exit \n";
    cout<<"\n=====================================\n";
    cout<<"Enter Choice: ";
    cin>>choise;

    switch(choise){
        //
    case 1:
    system("cls");
    c1.writeOnFile();
    break;
    //
    case 2:
    system("cls");
    c1.readFromFile();
    break;
    //
    case 3:
    system("cls");
    c1.searchOnFile();
    break;
    //
    case 4:
        system("cls");
        c1.deletFromFile();
        break;
    //
    case 5:
      system("cls");
      c1.editContact();
      break;
     //
    case 0:
        system("cls");
        cout<<"\n\n\n\t\t\t Thank You "<<endl<<endl;
        exit(0);
        break;

    default:
        continue;
        }
        int opt;
        cout<<"\n\n..::Enter the Choice:\n[1] Main Menu\t\t[0]Exit\n";
        cin>>opt;

        switch(opt){
    case 0:
         system("cls");
        cout<<"\n\n\n\t\t\t Thank You "<<endl<<endl;
        exit(0);
        break;
    default:
        continue;
        }
 }
 return 0;
}
