#include <bits/stdc++.h>

using namespace std;

// Design a File System
class FileSystem {
public:
    virtual void ls() = 0;
};

class File : public FileSystem {
public:
    string name;

    File(string n) : name(n) {}

    void ls() override {
        cout << "File Name: " << name << "\n";
    }
};

class Directory : public FileSystem {
public:
    string name;
    vector<FileSystem*> listOfFile;

    Directory(string n) : name(n) {}

    void add(FileSystem* fileSystemObj) {
        listOfFile.push_back(fileSystemObj);
    }

    void ls() override {
        cout << "Directory Name: " << name << "\n";
        for (auto x : listOfFile) {
            x->ls();
        }
    }
};

int main() {
    Directory home("home");  // Create the home directory once
    while (true) {
        cout << "Welcome to file system\n";
        cout << "Choose 3 options\n";
        cout << "1. ADD FILE\n";
        cout << "2. ADD DIRECTORY\n";
        cout << "3. SHOW\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter the file name: ";
                string name;
                cin >> name;
                FileSystem* f = new File(name);
                cout << "Do you want to create a new directory and add this file there? (Y/N) ";
                char ch;
                cin >> ch;
                if (ch == 'Y') {
                    cout << "Enter the directory name: ";
                    string dirName;
                    cin >> dirName;
                    Directory* d = new Directory(dirName);
                    d->add(f);
                    home.add(d);
                } else home.add(f);
                
                break;
            }
            case 2: {
                cout << "Enter the directory name: ";
                string name; cin >> name;
                Directory* d = new Directory(name);
                home.add(d);
                break;
            }
            case 3: {
                home.ls();
                break;
            }
            default: {
                cout << "Incorrect option, try again.\n";
                break;
            }
        }
        cout << "Do you want to continue? (Y/N) ";
        char contd; cin >> contd;
        if (contd == 'N') break;
    }
    return 0;
}
