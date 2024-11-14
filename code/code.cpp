#include<iostream>
#include<string.h>
#include<climits>
#include<fstream>
#include<Windows.h>
using namespace std;
#define INF 999
int mindistance(float distance[],bool stat[])
{
	float minimum=INT_MAX,ind;
	for(int k=0;k<25;k++)
	{
		if(stat[k]==false && distance[k]<=minimum)
		{
			minimum=distance[k];
			ind=k;
		}
	}
	return ind;
}
void dijkstra(float graph[25][25],int source, string stations[24])
{
	float distance[25];
	bool stat[25];
	for(int k=0;k<25;k++)
	{
		distance[k]=INT_MAX;
		stat[k]=false;
	}
	distance[source]=0;
	for(int k=0;k<25;k++)
	{
		int m=mindistance(distance,stat);
		stat[m]=true;
		for(int k=0;k<25;k++)
		{
			if(!stat[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
				distance[k]=distance[m]+graph[m][k];
		}
	}
	cout<<"\n\n\n Number of Stations from "<<"["<<stations[source]<<"] is"<<endl;
	for(int k=source+1;k<24;k++){

	cout<<"Enter"<<" "<<k<<" "<<"To Cheak Distance Between "<<stations[source]<<" To "<<"["<<stations[k]<<"]"<<" "<<"Station"<<endl;
	}
	int n;
	cout<<"Enter Station to cheak distance to Each other:"<<endl;
    string phrase = "Enter the corresponding number to arrival station";
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
    cin>>n;
    system("cls");
    cout<<"Total Distance from "<<"["<<stations[source]<<"]"<<" To "<<stations[n]<<" is "<<"["<<distance[n]<<"]"<<"KM"<<endl;
    phrase = "distance frome departure to arrival is";
    command = "espeak \"" + phrase + "\"";
    charCommand = command.c_str();
    system(charCommand);
    cout<<"\n"<<endl;
    cout<<"path from departure station to arrival station"<<endl;
    cout<<"\n"<<endl;
    phrase = "path from departure station to arrival station";
    command = "espeak \"" + phrase + "\"";
    charCommand = command.c_str();
    system(charCommand);
    for(int k=source;k<n;k++){
        cout<<stations[k]<<" -> "<<stations[k+1]<<" "<<"Station  total distance covered is: "<<"["<<distance[k+1]<<"]"<<"KM"<<endl;
	}
}

int login()
{
    char dum,u_name[30],name[30],g_pwd[30],pwd[30];
    int flag=0,count=4;
 cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"<<endl;
    cout<<"\t\t\t\t\t\t*WELLCOME TO LOGIN*"<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    cout<<"Enter your USER NAME  : "<<endl;
    string phrase = "Enter your USER NAME";
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
    cin>>name;
    cout<< "Enter the PASSWORD   : "<<endl;
    phrase = "Enter your password";
    command = "espeak \"" + phrase + "\"";
    charCommand = command.c_str();
    system(charCommand);
    cin>>pwd;
    fstream f;
    f.open("user_logins.txt",ios::in);
    f.seekg(0);
    while(f)
    {
        f.get(dum);
        f.get(u_name,30);
        f.get(dum);
        f.get(g_pwd,30);
        if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)==0)
        {
            flag=1;
            string phrase = "You have successfully login";
            string command = "espeak \"" + phrase + "\"";
            const char *charCommand = command.c_str();
            system(charCommand);
            system("cls");
            break;
        }
        else if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)!=0)
        {
            do
            {
                 string phrase = "INCORRECT PASSWORD try again";
                 count--;
                 cout<<"Incorrect password "<<count<<" more attemps left"<<endl;
                 string command = "espeak \"" + phrase + "\"";
                 const char *charCommand = command.c_str();
                 system(charCommand);
                 cout<<"Re-Enter the PASSWORD :"<<endl;
                 cin>>pwd;
            }while(count!=1 && strcmp(pwd,g_pwd)!=0 );
            if(strcmp(pwd,g_pwd)==0){
               flag=1;
               string phrase = "You have successfully login";
               string command = "espeak \"" + phrase + "\"";
               const char *charCommand = command.c_str();
               system(charCommand);
               system("cls");
               break;
            }
            else{
                flag=0;
                cout<<"You have cross the limits of password"<<endl;
                cout<<"You wil be directed to home page and account has been locked"<<endl;
                string phrase = "You have cross all limits of password attemp Your account has been locked please login again";
                string command = "espeak \"" + phrase + "\"";
                const char *charCommand = command.c_str();
                system(charCommand);
                system("cls");
                break;
            }
        }
    }
    if(flag==0 && count==4){
        cout<<"\n\t\t\tSORRY!!! USER NAME and PASSWORD does not Exist"<<endl;
        string phrase = "SORRY USER NAME and PASSWORD does not Exist";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
        system("cls");
        f.close();
    }
    return flag;
}

void signup()
{
    cout << "\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \n";
    cout << "\t\t\t\t\t\t*WELLCOME TO SIGNUP*\n";
    cout << "\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \n";

    char name[30], pwd[30], check_pwd[30];

    fstream f;
    f.open("user_logins.txt", ios::in);

    int flag;
    cout << "Create your user name : ";
    string phrase = "Create your USER NAME And PASSWORD: ";
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
    cin >> name;

    do
    {
        f.seekg(0);
        flag = 1;

        while (f)
        {
            char g_name[30], g_pwd[30], dum;
            f.get(dum);
            f.get(g_name, 30);
            f.get(dum);
            f.get(g_pwd, 30);

            if (strcmp(g_name, name) == 0)
            {
                flag = 0;
                cout << "\n\t\t\t----SORRY! USER-NAME ALREADY EXISTS----\n";
                cout << "Enter the USER NAME : ";
                cin >> name;
                break;
            }
        }
    } while (flag == 0);

    f.close();

    f.open("user_logins.txt", ios::out | ios::app);
    cout<<"Enter your PASSWORD : ";
    cin>>pwd;
    cout<<"Re-Enter your PASSWORD : ";
    cin>>check_pwd;
    while(strcmp(pwd,check_pwd)!=0)
    {
        cout<<"\t\t\t----INCORRECT PASSWORD!!!----"<<endl;
        cout<<"Enter your PASSWORD : ";
        cin>>pwd;
        cout<<"Re-Enter your PASSWORD : ";
        cin>>check_pwd;
    }
    f<<endl<<name<<endl<<pwd;
 cout<<"\n\t\t\t\t\t  YOUR NEW ID IS CREATING PLEASE WAIT";
	for(int i=0;i<6;i++)
	{
		cout<<".";
		Sleep(500);
    }
	cout<<"\n\n\t\t\t\t\t\aCONGRATULATION!!!YOUR ID CREATED SUCCESSFULL....Please wait";
	Sleep(2000);
	system("CLS");
    f.close();
}
int main()
{
	float graph[25][25]={
{0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1.1, 0, 0.7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0},
{0, 0, 0, 0, 0.7, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1.1, 0, 2.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 2.3, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1.1, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 3.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 3.8, 0, 1.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.2, 0, 0.9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.9, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.5, 0, 2.5, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.5, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1.1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 3.5, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.5, 0, 1.2, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.2, 0, 1.3, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.3, 0, 1.1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 0.5, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 3.5}};
	int source;
	 int n,W,ch,flag;
    char s;
    cout<<"\t----------------------------------------WELCOME TO DELHI Metro (ORANGE) ----------------------------------------\t\n\n";
    string phrase = "DELHI METRO WELCOMES YOU";
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
    do
    {
        cout<<endl;
        cout<<"\t\t\t\t_____________________\n";
        cout<<"\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_____________\xdb\xdb\xdb\xdb\xdb\xdb \n";
        cout<<"\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 1) LOGIN    \xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 2) REGISTER \xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 3) EXIT     \xdb\xdb\xdb\xdb\xdb\xdb\n";
         cout<<"\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_____________\xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_____________\xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"Enter your Choice : ";
        string phrase = "Enter your Choice";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
        cin>>ch;
        system("cls");
        switch(ch)
        {
            case 1:
                flag=login();
                break;
            case 2:
                signup();
                cout<<"Do you want to LOGIN (0/1)? : ";
                cin>>s;
                if(s=='0')
                    flag=login();
                else
                {
                    cout<<"\t\t\t\t\t\t\t THANK YOU \n";
                    phrase = "Thank you";
                    command = "espeak \"" + phrase + "\"";
                    charCommand = command.c_str();
                    system(charCommand);
                    exit(1);
                }
                break;
            case 3:
                cout<<"\t\t\t\t\t\t\t THANK YOU \n";
                phrase = "Thank you";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                exit(0);
                break;
            default:
                cout<<"\t\t\t----INCORRECT CHOICE!!!----"<<endl;
                phrase = "Incorrect choice";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                system("cls");
                break;
        }
    }while(flag!=1);
    if(flag==1)
    {
	string stations[24]={"Janak Puri West ","Dabri Mor - Janakpuri South","Dashrath Puri ","Palam","Sadar Bazaar Cantonment","Terminal 1 IGI Airport","Shankar Vihar"
	,"Vasant Vihar","Munirka","RK Puram","IIT Delhi","Hauz Khas","Panchsheel Park",
	"Chirag Delhi","Greater Kailash","Nehru Enclave","Kalkaji Mandir","Okhla NSIC","Sukhdev Vihar","JAMIA MILLIA ISLAMIA",
	"Okhla Vihar ","Jasola Vihar Shaheen Bagh","Kalindi Kunj","Okhla Bird Sanctuary"};
	char x;
    cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    cout<<"\t\t\t\t\t\t\t WELLCOME TO ORANGE Line Metro PORTAL "<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    string phrase = "WELLCOME TO ORANGE Line Metro portal";
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
    do
    {
        for(int i=0;i<24;i++){
            cout<<"Enter "<<" "<<i<<" "<<" for "<<stations[i]<<endl;
        }
    	cout<<"Enter the  departure station"<<endl;
    	phrase = "Enter the corresponding number of departure station";
        command = "espeak \"" + phrase + "\"";
        charCommand = command.c_str();
        system(charCommand);
    	cin>>source;
    	system("cls");
    	dijkstra(graph,source,stations);
    	cout<<"Press 0 for continue:"<<endl;
    	cout<<"Press 1 for exit:"<<endl;
    	cin>>x;
        system("cls");
	}while(x=='0');
	cout<<"\t\t\t\t\t\t\t THANK YOU \n";
    phrase = "Thank you";
    command = "espeak \"" + phrase + "\"";
    charCommand = command.c_str();
    system(charCommand);
    }
	return 0;

}
