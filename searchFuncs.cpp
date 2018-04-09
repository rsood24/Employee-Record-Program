//
//  searchfunctions.cpp
//  Final Project
//
//  Created by Ritesh Sood on 11/16/16.
//  Copyright © 2016 Ritesh Sood. All rights reserved.
//
//
//  This File holds all of the search functions of the program
//  treeToVec
//  searchID
//  search
//  subSearch
//  searchArec

#include <stdio.h>
#include "Node.h"
#include "BSTree.h"
#include <string>

using namespace std;

void displaysearch(vector<Node*>);                                  // Call to this function displays the search results
void displaySearchMenu();                                           // The User Menu for the search


////////////////////////////////////////////////////////
/// The treeToVec function uses an inorder traversal ///
/// and copies all of the records from a tree into a ///
/// vector.                                          ///
////////////////////////////////////////////////////////
vector<Node*> treeToVec(Node* tree, vector<Node*> &vec)
{
    if(tree != nullptr)
    {
        if(tree->Right() != nullptr)
        {
            treeToVec(tree->Right(), vec);
        }
        vec.push_back(tree);
        if(tree->Left() != nullptr)
        {
            treeToVec(tree->Left(), vec);
        }
    }
    else
        cout << "Theres nothing there to copy\n";
    
    return vec;
}

////////////////////////////////////////////////
/// The searchID function traverses the tree ///
/// in search for the correct ID. There is a ///
/// Node object which is passed through by   ///
/// reference. It will store the correct no- ///
/// de when it is found.                     ///
////////////////////////////////////////////////
void searchID(Node* tree, double number, Node &temp)
{
    if(tree != nullptr)
    {
        if(number > tree->Key())
        {
            if(tree->Right() != nullptr)
                searchID(tree->Right(), number, temp);
            else
                cout << "ID not found\n";
        }
        else if(number < tree->Key())
        {
            if(tree->Left() != nullptr)
                searchID(tree->Left(), number, temp);
            else
                cout << "ID not found\n";
        }
        else if(number == tree->Key())
            temp = *tree;
    }
    else
        cout << "Tree is empty\n";
    
}



///////////////////////////////////////////
/// The search function is basically t- ///
/// he main search function of the pro- ///
/// gram. It has an int parameter which ///
/// tells teh function which field to   ///
/// search.                             ///
///////////////////////////////////////////

vector<Node*> search(Node* tree, int num)               // This function uses the naive algorithm to
{                                                       // do the contains search. This is the algorithm
    vector<Node*> temp;                                 // used in all of the search functions except
    if(tree != nullptr)                                 // the searchID function.
    {
        if(num == 1)
        {
            double number;
            Node index;
            cout << "Please enter the ID you would like to search:\n";
            cin >> number;
            searchID(tree, number, index);
            Node* ptr = &index;
            temp.push_back(ptr);
            
        }
        
        else if(num == 2)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            cout << "Please enter the First name you would like to search:\n";
            cin >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.fName.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.fName[p+j] != name[j])
                                break;
        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
        
        else if(num == 3)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            cout << "Please enter the last name you would like to search:\n";
            cin >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.lName.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.lName[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
        
        else if(num == 4)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            cout << "Please enter the Company name you would like to search:\n";
            cin >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.compN.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.compN[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
        
        else if(num == 5)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            //double size = vec->size() - 1;
            cout << "Please enter the Email you would like to search:\n";
            cin >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.email.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.email[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
        
        else if(num == 6)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            //double size = vec->size() - 1;
            cout << "Please enter the City you would like to search:\n";
            cin  >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.city.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.city[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
        
        else if(num == 7)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            //double size = vec->size() - 1;
            cout << "Please enter the State you would like to search:\n";
            cin >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.state.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.state[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
        
        else if(num == 8)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            //double size = vec->size() - 1;
            cout << "Please enter the Zip code you would like to search:\n";
            cin >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.zip.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.zip[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
        
        else if(num == 9)
        {
            vector<Node*> vec;
            string name;
            vec = treeToVec(tree, vec);
            //double size = vec->size() - 1;
            cout << "Please enter the country you would like to search:\n";
            cin >> name;
            for(int i = 0; i < vec.size(); i++)
            {
                individual guy;
                guy = vec[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.country.length();
                int hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.country[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(vec[i]);
                    }
                }
            }
        }
    }
    
    string decide;
    
    if(temp.size() >= 1)
    {
        cout << "Would you like to see the list of search results?\n";
        cout << "Enter: yes or no\n";
        cin >> decide;
        
        if(decide == "yes")                                     // asks to display the search results
        {
            displaysearch(temp);
        }
        
    }
    else
    {
        cout << "Search did not find what you were looking for\n";      // If the search is invalid
    }
    
    return temp;
}


//////////////////////////////////////////////////////
/// The subSearch is only ever called after search ///
/// The search algorithms return a vector. If this ///
/// vector is > 1 in size. The user is asked if t- ///
/// hey would like to do a sub-search through the- ///
/// vector.                                        ///
//////////////////////////////////////////////////////


vector<Node*> subSearch(vector<Node*> tree, int num)
{
    vector<Node*> temp;
    if(tree[0] != nullptr)
    {
        if(num == 1)
        {
            double hold;
            cout << "Please enter the key to search:\n";
            cin >> hold;
            
            for(int i = 0; i < tree.size(); i++)
            {
                double key;
                key = tree[i]->Key();
                if(key == hold)
                {
                    temp.push_back(tree[i]);
                }
            }
        }
        
        else if(num == 2)            //If num is 2 program searches first name
        {
            string name;
            cout << "Please enter the First Name:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.fName.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.fName[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
        
        else if(num == 3)           //If num is 3 program searches last name
        {
            string name;
            cout << "Please enter the Last Name:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.lName.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.lName[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
        
        else if(num == 4)           //If num is 4 program searches company name
        {
            string name;
            cout << "Please enter the Company Name:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.compN.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.compN[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
        
        else if(num == 5)           //If num is 5 program searches email
        {
            string name;
            cout << "Please enter the email:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.email.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.email[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
        
        else if(num == 6)           //If num is 6 program searches city
        {
            string name;
            cout << "Please enter the City:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.city.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.city[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
        
        else if(num == 7)           //If num is 7 program searches state
        {
            string name;
            cout << "Please enter the State:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.state.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.state[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
        
        else if(num == 8)           //If num is 8 program searches zip
        {
            string name;
            cout << "Please enter the Zip:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.zip.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.zip[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
        
        else if(num == 9)           //If num is 9 program searches country
        {
            string name;
            cout << "Please enter the Country:\n";
            cin >> name;
            
            for(int i = 0; i < tree.size(); i++)
            {
                individual guy;
                guy = tree[i]->getA_Contact();
                
                size_t M = name.length();
                size_t N = guy.country.length();
                size_t hold = N - M;
                if(hold >= 0)
                {
                    for (int p = 0; p <= hold; p++)
                    {
                        int j;
                        for(j = 0; j < M; j++)
                            if(guy.country[p+j] != name[j])
                                break;
                        
                        if(j == M)
                            temp.push_back(tree[i]);
                    }
                }
            }
        }
    }
    else if( tree[0] == nullptr)
        cout << "past search result list is empty\n";
    
    string decide;
    
    if(temp.size() >= 1)
    {
        cout << "Would you like to see the list of search results?\n";
        cout << "Enter: yes or no\n";
        cin >> decide;
        
        if(decide == "yes")
        {
            displaysearch(temp);
        }
        else if(decide != "no" && decide != "yes")
        {
            cout << "Please enter a yes or no\n";
        }
    }
    else
    {
        cout << "Search did not find what you were looking for\n";
    }

    
    return temp;
}


/////////////////////////////////////////////////////
/// This function is only called directly by main ///
/// The only purpose of this search is to search  ///
/// and display a record                          ///
/////////////////////////////////////////////////////

void searchArec(BSTree* tree)
{
    int choice = 0;
    vector<Node*> vec;
    displaySearchMenu();
    cin >> choice;
    
    vec = search(tree->Root(), choice);
    
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

}

////////////////////////////////////////////////
///                                          ///
///                                          ///
////////////////////////////////////////////////




