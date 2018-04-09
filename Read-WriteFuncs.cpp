//
//  Read&WriteFuncs.cpp
//  Final Project
//
//  Created by Ritesh Sood on 11/25/16.
//  Copyright © 2016 Ritesh Sood. All rights reserved.
//

#include "Node.h"
#include "BSTree.h"
#include <list>
#include <fstream>

using namespace std;

vector<Node*> treeToVec(Node* tree, vector<Node*> &vec);
void displaySortMenu();                                     // The displaySortMenu prototype is here
                                                            // sort does not have its own function
                                                            // But is rather implemented within the
                                                            // writeToFile function.

/////////////////////////////////////////////////
/// This function takes in an ifstream object ///
/// and reads in the records into a Node obj- ///
/// ect which is added in the tree one record ///
/// at a time.                                ///
/////////////////////////////////////////////////

BSTree* ReadFromFile( istream& inFile )
{
    BSTree* data;
    data = new BSTree;
    Node* a_Record;
    
    double key;
    list<Node*> alist;
    
    while(!inFile.eof())
    {
        a_Record = new Node;
        individual a_Person;
        string Hold = " ";
        
            inFile >> key;
            a_Record->setKey(key);
            inFile.ignore();
            getline(inFile, a_Person.fName);
            getline(inFile, a_Person.mName);
            getline(inFile, a_Person.lName);
            getline(inFile, a_Person.compN);
            getline(inFile, a_Person.hPhone);
            getline(inFile, a_Person.oPhone);
            getline(inFile, a_Person.email);
            getline(inFile, a_Person.mPhone);
            getline(inFile, a_Person.stAd);
            getline(inFile, a_Person.city);
            getline(inFile, a_Person.state);
            getline(inFile, a_Person.zip);
            getline(inFile, a_Person.country);
            getline(inFile, Hold);
            a_Person.line = "|";
        
            while(Hold != "|")                          // This while loop checks for the end counter "|"
            {
                a_Record->setAffiliates(Hold);
                getline(inFile, Hold);
            }
        
        
        a_Record->setA_Conatct(a_Person);
        data->addNode(a_Record);
        //alist.push_back(a_Record);
    }
    
    return data;
}



/////////////////////////////////////
/// This function allows the user ///
/// enter a specific file for the ///
/// program to read from          ///
/////////////////////////////////////

BSTree* whichFile()
{
    int which;
    ifstream File;
    BSTree* data;
    
    cout << "1: Would you like to enter your own File?\n";
    cout << "   or\n";
    cout << "2: Would you like to use the one already available?\n";    // asks the user for a file or if they
    cin >> which;                                                       // would like to use the one available
    
    if( which == 1 )
    {
        string fileName;
        cout << "Please enter the file name:\n";
        cin >> fileName;                                                // Prompts for the File Name
        File.open(fileName);
        
        while(!File.good())
        {
            cout << "That is an invalid file name\n";                   // Corrupt file check
            cout << "Please enter a new file name\n";
            cin >> fileName;
            File.open(fileName);
        }
        
        cout << "File opened successfully\n";                           // Informs the user the file opened correctly
    }
    
    else if( which != 1)
    {
        File.open("databasesmall.txt");       // opens the file provided in the directory
        if (File.good())
            cout << "File opened successfully\n";
    }
    
    return ReadFromFile(File);                                    // return statement calls the ReadFromFile() function
}                                                                 // which returns a BSTree* to the database


////////////////////////////////////////////
/// This function asks the user how they ///
/// would like the records to be sorted. ///
/// Depending on the users decision the  ///
/// function chooses which sort to perf- ///
/// orm. After the sort it writes the d- ///
/// ata base to "dataOut.txt"            ///
////////////////////////////////////////////

void writeToFile(BSTree* tree)                              // This function uses a seperate selection sort
{                                                           // for each field and prompts the user to choo-
    vector<Node*> vec;                                      // se a field.
    int choice = 0;
    
    vec = treeToVec(tree->Root(), vec);
    
    displaySortMenu();
    cin >> choice;
    
    
    if(choice == 2)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size;
        size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)          // In order to access the fields they are passed
        {                                                               // into an individual object. These objects are
            minIndex = startScan;                                       // declared within the for loops so they go thr-
            individual person = vec[startScan]->getA_Contact();         // ough each entry and sort it out. All the fie-
            double personID = vec[startScan]->Key();                    // lds use this exact same sort.
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;                              // This sort is for the first name
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.fName < minValue.fName)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by First Name\n";
    }
    
    else if(choice == 3)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;                              // This sort is for the middle initial
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.mName < minValue.mName)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by the middle initial.\n";
    }
    
    else if(choice == 4)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;                            // This sort is for the last name
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.lName < minValue.lName)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by the last name\n";
    }
    
    else if(choice == 5)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.compN < minValue.compN)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;                         // This sort is for the Company Name
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by the company name\n";

    }
    
    else if(choice == 6)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.hPhone < minValue.hPhone)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;                         // This sort is for the Home Phone number
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by the Home Phone number\n";

    }
    
    else if(choice == 7)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                                                                            // This sort is for the Office Phone Number
                if(guy.oPhone < minValue.oPhone)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by the Office Phone number\n";

    }
    
    else if(choice == 8)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.email < minValue.email)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;                         // This sort is for the Email
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by Email\n";

    }
    
    else if(choice == 9)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.mPhone < minValue.mPhone)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;                           // This sort is for the Mobile Phone number
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by the Mobile Phone number\n";

    }
    
    else if(choice == 10)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.stAd < minValue.stAd)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;                         // This sort is for the Street Address
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by street address\n";

    }
    
    else if(choice == 11)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.city < minValue.city)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;                       // This sort is for the city
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by city\n";

    }
    
    else if(choice == 12)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;                            // This sort is for the state
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.state < minValue.state)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
    }
    
    else if(choice == 13)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.zip < minValue.zip)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;                         // This sort is for the zip
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by Zip\n";

    }
    
    else if(choice == 14)
    {
        individual minValue;
        double minValueID;
        int startScan, minIndex;
        size_t size = vec.size();
        for(startScan = 0; startScan < (size -1); startScan++)
        {
            minIndex = startScan;
            individual person = vec[startScan]->getA_Contact();
            double personID = vec[startScan]->Key();
            
            minValueID = personID;
            minValue.fName = person.fName;
            minValue.mName = person.mName;
            minValue.lName = person.lName;
            minValue.compN = person.compN;
            minValue.hPhone = person.hPhone;
            minValue.oPhone = person.oPhone;
            minValue.email = person.email;
            minValue.mPhone = person.mPhone;
            minValue.stAd = person.stAd;
            minValue.city = person.city;
            minValue.state = person.state;
            minValue.zip = person.zip;
            minValue.country = person.country;
            
            for(int index = startScan +1 ; index < size; index++)
            {
                individual guy = vec[index]->getA_Contact();
                double guyID = vec[index]->Key();
                
                if(guy.country < minValue.country)
                {
                    minValueID = guyID;
                    minValue.fName = guy.fName;
                    minValue.mName = guy.mName;
                    minValue.lName = guy.lName;
                    minValue.compN = guy.compN;
                    minValue.hPhone = guy.hPhone;
                    minValue.oPhone = guy.oPhone;
                    minValue.email = guy.email;
                    minValue.mPhone = guy.mPhone;
                    minValue.stAd = guy.stAd;                       // This sort is for the country
                    minValue.city = guy.city;
                    minValue.state = guy.state;
                    minValue.zip = guy.zip;
                    minValue.country = guy.country;
                    minIndex = index;
                }
            }
            individual dude = vec[minIndex]->getA_Contact();
            double dudeID = personID;
            dude.fName = person.fName;
            dude.mName = person.mName;
            dude.lName = person.lName;
            dude.compN = person.compN;
            dude.hPhone = person.hPhone;
            dude.oPhone = person.oPhone;
            dude.email = person.email;
            dude.mPhone = person.mPhone;
            dude.stAd = person.stAd;
            dude.city = person.city;
            dude.state = person.state;
            dude.zip = person.zip;
            dude.country = person.country;
            vec[minIndex]->setA_Conatct(dude);
            vec[minIndex]->setKey(dudeID);
            vec[startScan]->setA_Conatct(minValue);
            vec[startScan]->setKey(minValueID);
            
        }
        
        cout << "The database has been sorted by country\n";

    }
    
    else if( choice == 1)                                    // The database is already always sorted by the ID.
    {
        cout << "The database is sorted by id\n";
        ofstream outFile;
        outFile.open("dataOut.txt");
        vector<Node*> vec;
        treeToVec(tree->Root(), vec);
        
        for( int i = 0; i < vec.size(); i++)
        {
            individual lady = vec[i]->getA_Contact();
            vector <string> affiliate;
            affiliate = vec[i]->getAffiliates();
            
            outFile << vec[i]->Key() << endl;               // After the sort the function opens a ofstream file
            outFile << lady.fName << endl;                  // This for loop passes everything into the file
            outFile << lady.mName << endl;
            outFile << lady.lName << endl;
            outFile << lady.compN << endl;
            outFile << lady.hPhone << endl;
            outFile << lady.oPhone << endl;
            outFile << lady.email << endl;
            outFile << lady.mPhone << endl;
            outFile << lady.stAd << endl;
            outFile << lady.city << endl;
            outFile << lady.state << endl;
            outFile << lady.zip << endl;
            outFile << lady.country << endl;
            outFile << lady.line << endl;
        }
        
        outFile.close();
        
    }
    
    
    if(choice != 1)
    {
        ofstream outFile;
        outFile.open("dataOut.txt");
    
        for( int i = 0; i < vec.size(); i++)
        {
            individual lady = vec[i]->getA_Contact();
            vector <string> affiliate;
            affiliate = vec[i]->getAffiliates();
        
            outFile << vec[i]->Key() << endl;               // After the sort the function opens a ofstream file
            outFile << lady.fName << endl;                  // This for loop passes everything into the file
            outFile << lady.mName << endl;
            outFile << lady.lName << endl;
            outFile << lady.compN << endl;
            outFile << lady.hPhone << endl;
            outFile << lady.oPhone << endl;
            outFile << lady.email << endl;
            outFile << lady.mPhone << endl;
            outFile << lady.stAd << endl;
            outFile << lady.city << endl;
            outFile << lady.state << endl;
            outFile << lady.zip << endl;
            outFile << lady.country << endl;
            outFile << lady.line << endl;
        }
    
        outFile.close();
    }
}
