#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int choice;
        cout<<"1. Log message"<<endl;
        cout<<"2.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                string text;
                int n;
                cout<<"how many time do u want to log?"<<endl;
                cin>>n;
                cout<<"what do u want to log?"<<endl;
                cin>>text;
                
                ofstream file("file2");
                for(int i = 0; i < n; i++)
                {
                    file << text << endl;
                }
                file.close();

                ifstream sizefile("file2", ios::binary | ios::ate);
                streamsize size = sizefile.tellg();
                cout<<"File Size : "<<size<<"bytes"<<endl;
                if(size > 1000000)
                {
                    cout<<"file size is more than 1 mb"<<endl;
                    sizefile.close();
                    return 0;
                }
                break;
            }
            case 2:
            {
                exit(0);
            }
            default:
            break;
        }
    }
    return 0;

    
}