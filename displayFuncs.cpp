//
//  displayFuncs.cpp
//  Final Project
//
//  Created by Ritesh Sood on 11/27/16.
//  Copyright © 2016 Ritesh Sood. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Node.h"
#include "BSTree.h"

using namespace std;


/// Displays the search Menu ///

void displaySearchMenu()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////\n";
    cout << "Which field would you like to use for the search?\n";
    cout << " 1: ID\n";
    cout << " 2: First Name\n";
    cout << " 3: Last Name\n";
    cout << " 4: Company Name\n";
    cout << " 5: Email\n";
    cout << " 6: City\n";
    cout << " 7: State\n";
    cout << " 8: Zip\n";
    cout << " 9: Country\n";
    cout << "//////////////////////////////////////////////////\n";
    cout << "//////// Enter the Field number to search ////////\n";
    cout << "//////////////////////////////////////////////////\n";
}


/// Displays the Edit Menu ///

void displayUpdateMenu()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////\n";
    cout << "Which field of the entry would you like to Edit?\n";
    cout << " 1: ID\n";
    cout << " 2: First Name\n";
    cout << " 3: Middle Initial\n";
    cout << " 4: Last Name\n";
    cout << " 5: Company Name\n";
    cout << " 6: Home Phone Number\n";
    cout << " 7: Office Phone Number\n";
    cout << " 8: Email\n";
    cout << " 9: Mobile Phone Number\n";
    cout << "10: Street Address\n";
    cout << "11: City\n";
    cout << "12: State\n";
    cout << "13: Zip\n";
    cout << "14: Country\n";
    cout << "//////////////////////////////////////////////////\n";
    cout << "///////// Enter the Field number to Edit /////////\n";
    cout << "//////////////////////////////////////////////////\n";
}


/// Display the search results in a vector ///

void displaysearch(vector <Node*> vec)
{
    for( int i = 0; i < vec.size(); i++)
    {
        individual person = vec[i]->getA_Contact();
        vector <string> affiliate;
        affiliate = vec[i]->getAffiliates();
        
        cout << setprecision(0) << fixed;
        cout << vec[i]->Key() << endl;
        cout << person.fName << endl;
        cout << person.mName << endl;
        cout << person.lName << endl;
        cout << person.compN << endl;
        cout << person.hPhone << endl;
        cout << person.oPhone << endl;
        cout << person.email << endl;
        cout << person.mPhone << endl;
        cout << person.stAd << endl;
        cout << person.city << endl;
        cout << person.state << endl;
        cout << person.zip << endl;
        cout << person.country << endl;
        
        for(int p = 0; p < affiliate.size(); p++)
            cout << affiliate[p] << endl;
        
        cout << person.line << endl;
    }
}


/// Displays the Entire Data Base ///

void displayDataBase(Node* tree)
{
    if(tree != nullptr)
    {
        if(tree->Right() != nullptr)
        {
            displayDataBase(tree->Right());
        }
        vector<string> hold = tree->getAffiliates();
        individual person = tree->getA_Contact();
        cout << setprecision(0) << fixed;
        cout << tree->Key() << endl;
        cout << person.fName << endl;
        cout << person.mName << endl;
        cout << person.lName << endl;
        cout << person.mName << endl;
        cout << person.hPhone << endl;
        cout << person.oPhone << endl;
        cout << person.email << endl;
        cout << person.mPhone << endl;
        cout << person.stAd << endl;
        cout << person.city << endl;
        cout << person.state << endl;
        cout << person.zip << endl;
        cout << person.country << endl;
        
        for(int i = 0; i < hold.size(); i++)
        {
            cout << hold[i] << endl;
        }
        
        cout << person.line << endl;
        
        if(tree->Left() != nullptr)
        {
            displayDataBase(tree->Left());
        }
    }

}


/// Displays the Main Menu ///

void displayMainMenu()
{
    cout << endl;
    cout << "///////////////////////////////////////\n";
    cout << "Welcome to the database Program\n";
    cout << "Here are your menu options\n";
    cout << "///////////////////////////////////////\n";
    cout << " 1: Read database from a file\n";
    cout << " 2: Add a new record to database\n";
    cout << " 3: Update a record in the database\n";
    cout << " 4: Search a record in the database\n";
    cout << " 5: Delete a record in the database\n";
    cout << " 6: Sort and Write database to a file\n";
    cout << " 7: Display the Entire database\n";
    cout << " 8: Exit the Program\n";
    cout << "///////////////////////////////////////\n";
    cout << " Enter an option: ";
}


/// Displays the menu for the all of the sort options ///

void displaySortMenu()
{
    cout << endl;
    cout << "//////////////////////////////////////////////////\n";
    cout << "Which field would like for the sort?\n";
    cout << " 1: ID\n";
    cout << " 2: First Name\n";
    cout << " 3: Middle Initial\n";
    cout << " 4: Last Name\n";
    cout << " 5: Company Name\n";
    cout << " 6: Home Phone Number\n";
    cout << " 7: Office Phone Number\n";
    cout << " 8: Email\n";
    cout << " 9: Mobile Phone Number\n";
    cout << "10: Street Address\n";
    cout << "11: City\n";
    cout << "12: State\n";
    cout << "13: Zip\n";
    cout << "14: Country\n";
    cout << "//////////////////////////////////////////////////\n";
    cout << "///////// Enter the Field number to Sort /////////\n";
    cout << "//////////////////////////////////////////////////\n";
}








