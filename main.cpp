//
//  main.cpp
//  Final Project
//
//  Created by Ritesh Sood on 11/2/16.
//  Copyright © 2016 Ritesh Sood. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "BSTree.h"
#include "Node.h"


using namespace std;
BSTree* whichFile();
BSTree* ReadFromFile(istream& inFile);
BSTree* addNodeToTree(BSTree* tree);
BSTree* updateNode(BSTree* tree);
BSTree* deleteAnode(BSTree* tree);
void searchArec(BSTree* tree);
void displayMainMenu();
void writeToFile(BSTree* tree);
void displayDataBase(Node* tree);




int main() {
    
    BSTree * data_Base = nullptr;
    
    int option = 0;
    
    displayMainMenu();
    
    cin >> option;
    
    while(option != 8)
    {
        if(option == 1)
        {
            data_Base = whichFile();
        }
        else if(option == 2)
        {
            if(data_Base == nullptr)
            {
                data_Base = new BSTree;
            }
            data_Base = addNodeToTree(data_Base);
        }
        else if(option == 3)
        {
            if(data_Base == nullptr)
            {
                cout << "\nThe database is empty\n There is nothing to update\n";
            }
            else
                data_Base = updateNode(data_Base);
        }
        else if(option == 4)
        {
            if(data_Base == nullptr)
                cout << "\nThe database is empty\n There is nothing to search\n";
            else
                searchArec(data_Base);
        }
        else if(option == 5)
        {
            if(data_Base == nullptr)
                cout << "\nThe database is empty\n There is nothing to delete\n";
            else
                data_Base = deleteAnode(data_Base);
        }
        else if(option == 6)
        {
            writeToFile(data_Base);
        }
        else if(option == 7)
        {
            displayDataBase(data_Base->Root());
        }
        
        displayMainMenu();
        
        cin >> option;
    }

    return 1;
}
