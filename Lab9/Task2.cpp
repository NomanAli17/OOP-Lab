#include <bits/stdc++.h>
using namespace std;

class Logger{
    vector<string> logs;

    void store(string prefix, string text)
    {
        if(logs.size() > 1000)
        {
            logs.erase(logs.begin());
        }
        string temp = "("+prefix+")"+text;
        logs.push_back(temp);
    }

    public:

    void logInfo(const string& text)
    {
      store("INFO",text);
    }
    void logWarning(const string& text)
    {
        store("WARN",text);

    }
    void logError(const string& text)
    {
        store("ERROR",text);
    }
    vector<string> getMessages()
    {
        return logs;
    }


};

class Auditor
{
    public:
    bool access=false;
    void accesscheck(string password)
    {
        if(password=="DIHH")
        {
            access = true;
        }
    }
    void auditing(Logger &logger)
    {
       if(!access)
       {
        cout<<"failed TO AUTHENTICATE"<<endl;
        return;
       }
       vector<string> Messages=logger.getMessages();
       for(const auto&key:Messages)
       {
            cout<<key<<endl;
       }
    }
};
int main()
{
Logger logger;
Auditor auditor;
logger.logInfo("Network stabilized");
logger.logError("Data nodule error");
auditor.auditing(logger);
auditor.accesscheck("YESSSSSSS");
auditor.accesscheck("DIHH");
auditor.auditing(logger);
 return 0;
}