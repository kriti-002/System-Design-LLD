#include<bits/stdc++.h>

using namespace std;
class LogProcessor{
public:
    static int INFO;
    static int DEBUG;
    static int ERROR;
    LogProcessor *next;
    LogProcessor(LogProcessor* l){
        next=l;
    }
    virtual void log(string message, int logLevel){
        if(next) next->log(message, logLevel);
        else cout<<"No levels further linked."<<"\n";
    }
};
int LogProcessor::INFO = 1;
int LogProcessor::DEBUG = 2;
int LogProcessor::ERROR = 3;
class Info: public LogProcessor{
public:
    Info(LogProcessor *l) : LogProcessor(l){}
    virtual void log(string message, int logLevel){
        if(logLevel == LogProcessor::INFO) cout<<message<<" at log level:"<<logLevel<<"\n";
        else LogProcessor::log(message, logLevel);
    }
};
class Debug: public LogProcessor{
public:
    Debug(LogProcessor *l) : LogProcessor(l){}
    virtual void log(string message, int logLevel){
        if(logLevel == LogProcessor::DEBUG) cout<<message<<" at log level:"<<logLevel<<"\n";
        else next->log(message, logLevel);
    }
};
class Error: public LogProcessor{
public:
    Error(LogProcessor *l) : LogProcessor(l){}
    virtual void log(string message, int logLevel){
        if(logLevel == LogProcessor::ERROR) cout<<message<<" at log level:"<<logLevel<<"\n";
        else next->log(message, logLevel);
    }

};

int main(){
    //cout<<"Hello World!"<<"\n";
    LogProcessor *l= new LogProcessor(NULL);
    LogProcessor* errorLogger = new Error(l);
    LogProcessor* debugLogger = new Debug(errorLogger);
    LogProcessor* infoLogger = new Info(debugLogger);

    infoLogger->log("This is an information message", LogProcessor::INFO);
    infoLogger->log("This is a debug message", LogProcessor::DEBUG);
    infoLogger->log("This is an error message", LogProcessor::ERROR);
    infoLogger->log("This log level is not handled", 4);

    return 0;
}
