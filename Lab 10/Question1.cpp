
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string s;
	cin>>s;
	
	for(int i = 0; i < s.size(); i++)
	{
		s[i] = s[i]+(i+1);
	}
	fstream file;
	file.open("file1", ios::out);
	file<<s;
	
	file.close();
	
	file.open("file1", ios::in);
	string s1;
	file>>s1;
	for(int i = 0; i < s.size(); i++)
	{
		cout << char(s1[i] - (i + 1));
	}
	file.close();
	return 0;
}
