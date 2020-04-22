//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include <iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

class phonebook{
	char name[30];
	char  phno[20];
	char city[20];
	char  pin[10];
	char email[40];
	public:

void getdata(){
	cout<<"\nEnter Name : ";
	gets(name);
	cout<<"Enter Phone No. : ";
	gets(phno);
	int  x=strlen(phno);
	while(x!=10)
 {
         cout<<"enter valid phone no.:";
	     gets(phno);
	     x=strlen(phno);
}

  cout<<"Enter city : ";
	gets(city);
  cout<<"Enter pin No. : ";
	gets(pin);
int  y=strlen(pin);
	while(y!=6)
 {
             cout<<"enter valid pin no.:";
	     gets(pin);
	     y=strlen(pin);
}
  cout<<"Enter email ID : ";
	gets(email);

}

void showdata(){
	cout<<"\n" ;
	cout<<"Name: "<<name<<endl;
	cout<<"Phoneno:  "<<phno<<endl;
	cout<<"City:   "<<city<<endl;
	cout<<"Pin: "<<pin<<endl;
	cout<<"Email Id: "<<email<<endl;
}

char *getname() { return name; }
char *getcity() { return city; }

};         //class ends here

char nm[30];


//    	global declaration for stream object, object


 fstream fp;
 phonebook record;



//    	function to write in file


void write_record()
   {
    fp.open("telephone.dat",ios::out|ios::app);
    record.getdata();
    fp.write((char*)&record,sizeof(record));
    fp.close();
    cout<<"\n\nThe Record Has Been Created ";
    getch();
   }



//    	function to read all records from file



void display_all()
{          int n=0;
    system("cls");
    cout<<"\n\n\n\t\tDISPLAY ALL RECORDS !!!\n\n";
    fp.open("telephone.dat",ios::in);
    while(fp.read((char*)&record,sizeof(record)))
	{        n++;

	 record.showdata();
	 cout<<"\n\n====================================\n";
	 getch();
	 }
	 cout<<"Total  NO. of Records are : "<<n;
    fp.close();
    getch();
}



//    	function to read specific record from file



void display_record()
{   char nm[30];
		system("cls");
		cout<<"\n\n\tPlease Enter The name of the person ";
		gets(nm);
    int flag=0;
    fp.open("telephone.dat",ios::in);
    while(fp.read((char*)&record,sizeof(record)))
	{
	 if(strcmp(record.getname(),nm)==0)
		{
		 cout<<"The Record You Searched For is :"<<endl;
		 record.showdata();
		 flag=1;
		}
	}
    fp.close();
if(flag==0)
 cout<<"\n\nRecord not exist";
    getch();
}


			 // DISPLAY A PARTICULAR CITY RECORD


void display_recordcity()
{   char ct[50];  int no=0;
		system("cls");
		cout<<"\n\n\tPlease Enter The name of the city ";
		gets(ct);
    int flag=0;
    fp.open("telephone.dat",ios::in);
    while(fp.read((char*)&record,sizeof(record)))
	{
	 if(strcmp(record.getcity(),ct)==0)
		{    no++;
		 record.showdata();
		 flag=1;
		}
	}
	cout<<"\n\n Total Records  "<<no;
    fp.close();
if(flag==0)
 cout<<"\n\nRecord does not exist";
    getch();
}









//       function to modify record of file



void modify()
{

    char nm[30];int found=0;
			system("cls");
			cout<<"\n\n\tTo Modify ";
			cout<<"\n\n\tPlease Enter The name of the person\n";
			 cout<<"\n																																																																																																																												\twhose details you want to update :";
			gets(nm);
    fp.open("telephone.dat",ios::in|ios::out);
    while(fp.read((char*)&record,sizeof(record)) && found==0)
	   {
	     if(strcmp(record.getname(),nm)==0)
		   {
		    record.showdata();
		    cout<<"\nPlease Enter The New Details"<<endl;
		    record.getdata();
		    int pos=-1*sizeof(record);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&record,sizeof(record));
		    cout<<"\n\n\t Record Updated";
		    found=1;
			 record.showdata();
		   }
	     }
    fp.close();
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}

//    	function to delete record of file
void delete_record()
   {  int found =0;
    char confirm='n';
    char nm[10];
    system("cls");
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The  name of the person You Want To Delete : ";
    cin>>nm;
    fp.open("telephone.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&record,sizeof(record)))
	{

	 if(strcmp(record.getname(),nm)==0)
		{
			record.showdata();
			found =1;
cout<<"Are You Sure You Want To Delete The  Record  ";
cin>>confirm;
if(confirm=='n')
{  cout<<"Record Still There ";
		 fp2.write((char*)&record,sizeof(record));
		 }   }
else
fp2.write((char*)&record,sizeof(record));
	 }
	 if(confirm!='n')
cout<<"Record Deleted..";
    fp2.close();
    fp.close();
    remove("telephone.dat");
    rename("Temp.dat","telephone.dat");
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
    }

//    	THE MAIN FUNCTION OF PROGRAM


void menu()
{
    char ch;
  do
    {
	  system("cls");
	  cout<<endl<<endl<<endl<<endl;
      cout<<"\n\n\t \t \t \t \t \tTELEPHONE DIRECTORY ";
	  cout<<"\n\n\t \t \t \t \t \tMAIN MENU";
	  cout<<"\n\n\t \t \t \t \t \t1.CREATE RECORD";
	  cout<<"\n\n\t \t \t \t \t \t2.DISPLAY ALL RECORD";
	  cout<<"\n\n\t \t \t \t \t \t3.SEARCH A PARTICULAR RECORD";
	  cout<<"\n\n\t \t \t \t \t \t4.SEARCH RECORDS OF PARTICULAR CITY";
	  cout<<"\n\n\t \t \t \t \t \t5.MODIFY A RECORD";
	  cout<<"\n\n\t \t \t \t \t \t6.DELETE RECORD";
	  cout<<"\n\n\t \t \t \t \t \t7.EXIT";
	  cout<<"\n\n\t \t \t \t \t \tPlease Select Your Option (1-7) ";
	  ch=getch();
	  switch(ch)
	  {
		 case '1': system("cls");
			   write_record();
			   break;
		  case '2':display_all();
			   break;

	      case '3': display_record();
			break;

	       case '4' :display_recordcity();
			 break;
      case '5':
			modify();
			break;
      case '6': delete_record();
		break;

      case '7':
		 exit(0);
	   default:cout<<"ENTER VALID CHOICE";
   }
      }
while(ch!='7');
}
int main()
{
menu();
return 0;
}


//    			END OF PROJECT

