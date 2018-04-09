#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A generic tree node class


//Binary Tree Node

struct individual
{
    string fName;           // Holds all of the Fields accept for affiliates and ID
    string mName;
    string lName;
    string compN;
    string hPhone;
    string oPhone;
    string email;
    string mPhone;
    string stAd;
    string city;
    string state;
    string zip;
    string country;
    string line;
};

/////////////////////////////////////////////////////////////
/// The Node class private section holds three pointers   ///
/// An individual object which contains all of the fields ///
/// A vector<string> to hold the affiliates and a double  ///
/// variable for the I.D.                                 ///
/////////////////////////////////////////////////////////////

class Node {
    
    private:
        vector<string> contacts;
        individual a_Contact;
        Node* left;
        Node* right;
        Node* parent;
        double key;
    public:
        Node()
        {
            key = 4; left = nullptr; right = nullptr; parent = nullptr;
        };
    
        void setA_Conatct(individual dude)
        {
            a_Contact.fName = dude.fName;               /// the setA_Contact function takes in an object of ///
            a_Contact.mName = dude.mName;               /// the individual class and sets all the fields of ///
            a_Contact.lName = dude.lName;               /// a_Contact equal to it.                          ///
            a_Contact.compN = dude.compN;
            a_Contact.hPhone = dude.hPhone;
            a_Contact.oPhone = dude.oPhone;
            a_Contact.email = dude.email;
            a_Contact.mPhone = dude.mPhone;
            a_Contact.stAd = dude.stAd;
            a_Contact.city = dude.city;
            a_Contact.state = dude.state;
            a_Contact.zip = dude.zip;
            a_Contact.country = dude.country;
            a_Contact.line = dude.line;
        };
        void setKey(double Key) { key = Key; };
        void setLeft(Node* aLeft) { left = aLeft; };
        void setRight(Node* aRight) { right = aRight; };
        void setParent(Node* aParent) { parent = aParent; };
        void setAffiliates( string guy )
        {
            contacts.push_back(guy);
        };
    
        individual getA_Contact(){ return a_Contact; }
        vector<string> getAffiliates(){ return contacts; }
        double Key() { return key; };
        Node* Left() { return left; };
        Node* Right() { return right; };
        Node* Parent() { return parent; };
    
};



#endif