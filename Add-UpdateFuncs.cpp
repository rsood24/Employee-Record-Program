//
//  AddFuncs.cpp
//  Final Project
//
//  Created by Ritesh Sood on 11/27/16.
//  Copyright © 2016 Ritesh Sood. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "BSTree.h"
#include <string>

using namespace std;

vector<Node*> search(Node* tree, int num);                  // These are the prototypes for the Menu displays
vector<Node*> subSearch(vector<Node*> tree, int num);       // and the search functions which are used by the
void displaySearchMenu();                                   // updateAnode
void displayUpdateMenu();


///////////////////////////////////////
/// This function allocates a Node* ///
/// It asks the user for each field ///
/// and affiliates. Fills the Node* ///
/// and passes it into the tree wh- ///
/// ich is then returned            ///
///////////////////////////////////////

BSTree* addNodeToTree(BSTree* tree)
{
    Node* temp = new Node;
    double key;
    individual person;
    
    cout << "Please enter the ID:\n";
    cin >> key;
    temp->setKey(key);
    cin.ignore();
    cout << "\nPlease enter the First name:\n";
    getline(cin, person.fName);
    cout << "\nPlease enter the Middle initial:\n";
    getline(cin, person.mName);
    cout << "\nPlease enter the Last name:\n";
    getline(cin, person.lName);
    cout << "\nPlease enter the Company name:\n";
    getline(cin, person.compN);
    cout << "\nPlease enter the Home Phone number:\n";
    getline(cin, person.hPhone);
    cout << "\nPlease enter the Office Phone number:\n";
    getline(cin, person.oPhone);
    cout << "\nPlease enter the Email:\n";
    getline(cin, person.email);
    cout << "\nPlease enter the Mobile PHone number:\n";
    getline(cin, person.mPhone);
    cout << "\nPlease enter the Street Address:\n";
    getline(cin, person.stAd);
    cout << "\nPlease enter the City:\n";
    getline(cin, person.city);
    cout << "\nPlease enter the State:\n";
    getline(cin, person.state);
    cout << "\nPlease enter the Zip code:\n";
    getline(cin, person.zip);
    cout << "\nPlease enter the Country:\n";
    getline(cin, person.country);
    
    temp->setA_Conatct(person);
    string choice = "";
    
    while(choice != "Enter" && choice != "enter")
    {
        cout << "\nType in information for an affiliate of the entry.\n Or\n type ""Enter"" to add entry to the database:\n";
        cin >> choice;
        
        temp->setAffiliates(choice);
    }
    
    tree->addNode(temp);
    
    return tree;
}

///////////////////////////////////////////////
/// This function allows the user to update ///
/// a field of an entry. It creates a new   ///         // It uses the search functions to acquire the right Node.
/// fills it with the new data and the data ///
/// from the old node. Then it deletes the  ///
/// old node from the tree and passes the   ///
/// new one in.                             ///
///////////////////////////////////////////////

BSTree* updateNode(BSTree* tree)
{
    
    int choice;
    vector<Node*> vec;
    
    displaySearchMenu();
    cin >> choice;
    
    while(choice < 1 || choice > 9)
    {
        cout << "\nPlease enter a valid option:\n";
        cin >> choice;
    }
    
    vec = search(tree->Root(), choice);
    
    while (vec.size() == 0)
    {
        cout << "Since that search did not find the entry\n Lets try again\n";
        
        vec = search(tree->Root(), choice);
    }
    while(vec.size() > 1)
    {
        string answer;
        cout << "There are multiple records which have that field in common.\n";
        cout << "\n Would you like to do a subsearch on these records?\n";
        cout << " Enter: yes or no\n";
        cin >> answer;
        if(answer == "yes" || answer == "Yes")
        {
            displaySearchMenu();
            cin >> choice;
            vec = subSearch(vec, choice);
        }
        else if( answer == "no" || answer == "No")
            break;
        else
            cout << "Invalid input\n";
    }
    

        displayUpdateMenu();
        cin >> choice;
        Node* temp = new Node;
    
        if(choice == 1)
        {
            double key;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new ID:\n";
            cin >> key;
            temp->setKey(key);
            person = vec[0]->getA_Contact();
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 2)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new First name:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.fName = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 3)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Middle initial:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.mName = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 4)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Last name:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.lName = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 5)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Company name:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.compN = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 6)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Home Phone number:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.hPhone = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 7)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Office Phone number:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.oPhone = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 8)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Email:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.email = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 9)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Mobile Phone number:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.mPhone = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 10)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Street Address:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.stAd = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 11)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new City name:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.city = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 12)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new State name:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.state = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 13)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new Zip code:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.zip = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        else if(choice == 14)
        {
            string name;
            individual person;
            vector<string> line = vec[0]->getAffiliates();
            cout << "Please Enter the new country name:\n";
            cin >> name;
            person = vec[0]->getA_Contact();
            person.country = name;
            temp->setKey(vec[0]->Key());
            temp->setA_Conatct(person);
            for(int p = 0; p < line.size(); p++)
            {
                string j = line[p];
                temp->setAffiliates(j);
            }
            tree->deleteNode(vec[0]->Key());
            tree->addNode(temp);
        }
        
    return tree;
}


//////////////////////////////////////
/// This function calls the search ///
/// functions to locate the right  ///
/// node. Then it uses the delete  ///
/// function within the Tree obje- ///
/// ct to remove it.               ///
//////////////////////////////////////

BSTree* deleteAnode(BSTree* tree)
{
    int choice;
    vector<Node*> vec;
    
    displaySearchMenu();
    cin >> choice;
    
    while(choice < 1 || choice > 9)
    {
        cout << "\nPlease enter a valid option:\n";
        cin >> choice;
    }
    
    vec = search(tree->Root(), choice);
    
    while(vec[0] == nullptr)
    {
        cout << "Lets try again\n";
        search(tree->Root(), choice);
    }
    
    while(vec.size() > 1)
    {
        string answer;
        cout << "There are multiple records which have that field in common.\n";
        cout << "\n Would you like to do a subsearch on these records?\n";
        cout << " Enter: yes or no\n";
        cin >> answer;
        if(answer == "yes" || answer == "Yes")
        {
            displaySearchMenu();
            cin >> choice;
            vec = subSearch(vec, choice);
        }
        else if( answer == "no" || answer == "No")
            break;
        else
            cout << "Invalid input\n";
    }
    
    tree->deleteNode(vec[0]->Key());
    cout << "The entry was deleted\n";
    
    return tree;
}



