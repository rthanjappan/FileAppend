//this is a test changeing the fist line

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";

    fstream dataFile;
    dataFile.open("CSC450_mod5-2.txt", ios::app);
    string *stringArray = new string[50];
    string str;
    char choice;

    if (!dataFile.fail()) {
        do {
            cout << "please enter your name : ";
            getline(cin, str);
            dataFile << str << endl;

            cout << "please enter your address : ";
            getline(cin, str);
            dataFile << str << endl;

            cout << "please enter your email id : ";
            getline(cin, str);
            dataFile << str << endl;

            cout << "\nDo you want to continue(Y/N) ?  ";
            cin >> choice;
            getline(cin, str);
            cout << endl;
        } while (toupper(choice) != 'N');
    }
    else {
        cout << "Error : Opening file." << endl;
    }

    dataFile.close();

    //Searching for name
    ifstream dataFile1;
    string searchName,str1; bool flag = false;
    dataFile1.open("CSC450_mod5-2.txt", ios::in);
    vector<string> names;
    while (getline(dataFile1, str)) {
        names.push_back(str);
        getline(dataFile1, str);
        getline(dataFile1, str);
    }
    cout << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i];
    }
    cout << endl;
    do {

        cout << "Please enter your name to search : ";
        getline(cin, searchName);
        //getline(cin, str);
        for(int i=0;i<names.size();i++){

            cout << "The name read from vector is : " <<names[i] << endl;
            cout << "The search name is : " << searchName << endl;
            if (names[i] == searchName) {
                flag = true;
                
                break;
            }
            
        }

        if (flag) {
            cout << "\nYour name exists in the file CSC450_mod5-2.txt." << endl;
        }
        else {
            cout << "\nYour name does not found in the file CSC450_mod5-2.txt." << endl;
            
        }
        flag = false;
        cout << "\nDo you want to search another name(Y/N) ?  ";
        cin >> choice;
        getline(cin, str1);
        cout << endl;
     } while (toupper(choice) != 'N');

     dataFile1.close();
    ////do {

    ////    cout << "Please enter your name to search : ";
    ////    getline(cin, searchName);
    ////    //getline(cin, str);
    ////    while (getline(dataFile1, str)) {
    ////        cout <<"The name read from file is : " << str << endl;
    ////        cout << "The search name is : " << searchName << endl;
    ////        if (str == searchName) {
    ////            flag = true;
    ////            getline(dataFile1, str);
    ////            getline(dataFile1, str);
    ////            break;
    ////        }
    ////        getline(dataFile1, str);
    ////        getline(dataFile1, str);
    ////    }

    ////    if (flag) {
    ////        cout << "Your name exists in the file CSC450_mod5-2.txt." << endl;
    ////    }
    ////    else {
    ////        cout << "Your name does not found in the file CSC450_mod5-2.txt." << endl;
    ////        dataFile1.close();
    ////        dataFile1.open("CSC450_mod5-2.txt", ios::in);
    ////    }
    ////    flag = false;
    ////    cout << "Do you want to search another name(Y/N) ?  ";
    ////    cin >> choice;
    ////    getline(cin, str1);
    ////    cout << endl;
    ////    dataFile1.seekg(0, ios_base::beg);
    //} while (toupper(choice) != 'N');
     //dataFile1.close();
    
    return 0;
}

