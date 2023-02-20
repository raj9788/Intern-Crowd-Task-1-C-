#include <iostream>
#include <vector>
#include <string>
using namespace std;

//structure of storing the Birthday Information of a person
typedef struct Birthday
{
    string name;
    int date;
    int month;
    int year;
} Birthday;

//method to add birthday
void addBithday(vector<Birthday> &birthdayList)
{
    Birthday person;
    cout << "Enter the name of person :: ";
    cin.ignore(); 
    getline(cin,person.name);
    cout << "Enter the Birthday (DD/MM/YYYY) :: ";
    scanf("%d/%d/%d", &person.date, &person.month, &person.year);
    birthdayList.push_back(person);
}

//method to search birthday
void searchBirthday(vector<Birthday> &birthdayList)
{
    string name;
    cout << "Enter name: ";
    cin.ignore(); 
    getline(cin,name);

    for (Birthday person : birthdayList)
    {
        if (person.name == name)
        {
            cout << "Found " << person.name << "'s birthday: " << person.date << "/" << person.month << "/" << person.year << endl;
            return;
        }
    }

    cout << "Could not find birthday for " << name << "\n";
}
//method to display list of monthly birthdays
void displayMonthlyBirthdays(vector<Birthday> &birthdayList)
{
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << "Monthly Birthdays:" << endl;
    cout << "===================" << endl;

    for (int i = 1; i <= 12; i++)
    {
        cout << "Month " << months[i-1] << ":" << endl;

        for (Birthday person : birthdayList)
        {
            if (person.month == i)
            {
                cout << person.name << " - " << person.date << endl;
            }
        }

        cout << endl;
    }
}

//main function
int main()
{
    vector<Birthday>birthdayList;
    string _continue="y";
    while(_continue=="y"||_continue=="yes"||_continue=="Y"||_continue=="YES"){
        int choice;
        cout<<"Choose the command\n";
        cout<<"1. Add Birthday\n";
        cout<<"2. Search Birthday by Name\n";
        cout<<"3. Display Monthly Birthdays\n";
        cin>>choice;
        switch(choice){
            case 1:
                addBithday(birthdayList);
                break;
            case 2:
                searchBirthday(birthdayList);
                break;
            case 3:
                displayMonthlyBirthdays(birthdayList);
                break;
            default:
                cout<<"Invalid Input Try Again\n";
        }
        cout<<"Do you want to Continue\n";
        cin>>_continue;

    }
    return 0;
}