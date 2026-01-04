//#ifndef STRUCTURES_H
//#define STRUCTURES_H
//#include <string>
//#include <vector>
//using namespace std;
//
//struct User {
//    int userID;
//    string username;
//    string password;
//    string bio;
//    vector<int> followers; 
//    vector<int> following; 
//    User* left;  
//    User* right; 
//};
//#endif

//#ifndef STRUCTURES_H
//#define STRUCTURES_H
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//struct User {
//    int userID;
//    string username;
//    string password;
//    string bio;
//    vector<int> followers;  // Adjacency list for followers 
//    vector<int> following;  // Adjacency list for following 
//    User* left;  
//    User* right; 
//
//    User() : left(nullptr), right(nullptr) {}
//};
//
//#endif

#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <string>
#include <vector>
using namespace std;

struct User {
    int userID;
    string username;
    string password;
    string bio;
    vector<int> followers; // Adjacency list for followers
    vector<int> following; // Adjacency list for following
    User* left;  
    User* right; 

    User() : left(nullptr), right(nullptr) {}
};
#endif