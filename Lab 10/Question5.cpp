#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream todolist;

    while(1)
    {
        int choice;
        cout << "***********TO DO List App***************" << endl;
        cout << "1. Add Tasks" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as done" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
        {
            todolist.open("file", ios::app);
            cout << "Enter Task: ";
            string temp;
            getline(cin, temp);
            todolist << temp << endl;
            todolist.close();
            break;
        }

        case 2:
        {
            cout << "Showing Tasks........" << endl;
            todolist.open("file", ios::in);
            string temp;
            while (getline(todolist, temp))
            {
                cout << temp << endl;
            }
            todolist.close();
            break;
        }

        case 3:
        {
            vector<string> str;
            string task;
            cout << "Enter task which is done: ";
            getline(cin, task);
            todolist.open("file", ios::in);
            string temp;
            while(getline(todolist, temp))
            {
                if(temp == task)
                {
                    temp += " done";
                }
                str.push_back(temp);
            }
            todolist.close();

            todolist.open("file", ios::trunc);
            todolist.close();

            todolist.open("file", ios::out);
            for(int i = 0; i < str.size(); i++)
            {
                todolist << str[i] << endl;
            }
            todolist.close();
            break;
        }

        case 4:
        {
            exit(0);
            break;
        }
        
        default:
            break;
        }
    }
    return 0;
}