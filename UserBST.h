//#ifndef USER_BST_H
//#define USER_BST_H
//
//#include "structures.h"
//#include <string>
//#include <algorithm>
//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//class UserBST {
//private:
//    User* root;
//
//    // Recursive helper for BST insertion
//    User* insert(User* node, int id, string name, string pass, string bio) {
//        if (node == nullptr) {
//            User* newUser = new User();
//            newUser->userID = id; newUser->username = name;
//            newUser->password = pass; newUser->bio = bio;
//            newUser->left = newUser->right = nullptr;
//            return newUser;
//        }
//        if (id < node->userID) node->left = insert(node->left, id, name, pass, bio);
//        else if (id > node->userID) node->right = insert(node->right, id, name, pass, bio);
//        return node;
//    }
//
//    // O(log n) Search by ID
//    User* searchID(User* node, int id) {
//        if (node == nullptr || node->userID == id) return node;
//        if (id < node->userID) return searchID(node->left, id);
//        return searchID(node->right, id);
//    }
//
//    // O(n) Search by Username (Tree Traversal) [cite: 39, 211]
//    User* searchName(User* node, string name) {
//        if (node == nullptr) return nullptr;
//        if (node->username == name) return node;
//        User* res = searchName(node->left, name);
//        if (res) return res;
//        return searchName(node->right, name);
//    }
//
//    // Helper to save data to file [cite: 165, 230]
//    void saveRecursive(User* node, ofstream& file) {
//        if (node == nullptr) return;
//        file << node->userID << "," << node->username << "," << node->password << "," << node->bio << "\n";
//        saveRecursive(node->left, file);
//        saveRecursive(node->right, file);
//    }
//
//public:
//    UserBST() : root(nullptr) {}
//
//    // Register with Validation Rules [cite: 37, 171, 172]
//    bool registerUser(int id, string name, string pass, string bio) {
//        if (getUserByUsername(name) != nullptr) {
//            cout << "[Error] Username '" << name << "' already taken.\n";
//            return false;
//        }
//        if (pass.length() < 6) {
//            cout << "[Error] Password must be at least 6 characters.\n";
//            return false;
//        }
//        root = insert(root, id, name, pass, bio);
//        return true;
//    }
//
//    User* getUserByID(int id) { return searchID(root, id); }
//    User* getUserByUsername(string name) { return searchName(root, name); }
//
//    // Social Graph Logic (Maryam's Task)
//    bool followUser(int fID, int tID) {
//        User* f = getUserByID(fID);
//        User* t = getUserByID(tID);
//        if (!f || !t || fID == tID) return false;
//        if (find(f->following.begin(), f->following.end(), tID) != f->following.end()) return false;
//        f->following.push_back(tID);
//        t->followers.push_back(fID);
//        return true;
//    }
//
//    // Persistence [cite: 165, 325]
//    void saveToUsersFile() {
//        ofstream file("users.txt");
//        if (file.is_open()) {
//            saveRecursive(root, file);
//            file.close();
//            cout << "[System] Database saved to users.txt\n";
//        }
//    }
//};
//
//#endif

//#ifndef USER_BST_H
//#define USER_BST_H
//
//#include "structures.h"
//#include <string>
//#include <algorithm>
//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//class UserBST {
//private:
//    User* root;
//
//    // Standard BST Insert by UserID 
//    User* insert(User* node, int id, string name, string pass, string bio) {
//        if (node == nullptr) {
//            User* newUser = new User();
//            newUser->userID = id; newUser->username = name;
//            newUser->password = pass; newUser->bio = bio;
//            return newUser;
//        }
//        if (id < node->userID) node->left = insert(node->left, id, name, pass, bio);
//        else if (id > node->userID) node->right = insert(node->right, id, name, pass, bio);
//        return node;
//    }
//
//    // Fast Search by ID: O(log n) [cite: 137]
//    User* searchID(User* node, int id) {
//        if (node == nullptr || node->userID == id) return node;
//        if (id < node->userID) return searchID(node->left, id);
//        return searchID(node->right, id);
//    }
//
//    // Traversal Search by Username: O(n) [cite: 39, 211]
//    User* searchName(User* node, string name) {
//        if (node == nullptr) return nullptr;
//        if (node->username == name) return node;
//        User* res = searchName(node->left, name);
//        if (res) return res;
//        return searchName(node->right, name);
//    }
//
//    // Helper to save users in order 
//    void saveRecursive(User* node, ofstream& file) {
//        if (node == nullptr) return;
//        file << node->userID << "," << node->username << "," << node->password << "," << node->bio << "\n";
//        saveRecursive(node->left, file);
//        saveRecursive(node->right, file);
//    }
//
//public:
//    UserBST() : root(nullptr) {}
//
//    // Register with Validation Rules [cite: 171, 172]
//    bool registerUser(int id, string name, string pass, string bio) {
//        if (getUserByUsername(name) != nullptr) { // Unique username check [cite: 171]
//            cout << "[Error] Username '" << name << "' already taken.\n";
//            return false;
//        }
//        if (pass.length() < 6) { // Min 6 chars check [cite: 172]
//            cout << "[Error] Password must be at least 6 characters.\n";
//            return false;
//        }
//        root = insert(root, id, name, pass, bio);
//        return true;
//    }
//
//    User* getUserByID(int id) { return searchID(root, id); }
//    User* getUserByUsername(string name) { return searchName(root, name); }
//
//    // Social Logic (Maryam's Task) [cite: 41]
//    bool followUser(int fID, int tID) {
//        User* f = getUserByID(fID);
//        User* t = getUserByID(tID);
//        if (!f || !t || fID == tID) return false;
//        f->following.push_back(tID);
//        t->followers.push_back(fID);
//        return true;
//    }
//
//    void saveToUsersFile() {
//        ofstream file("users.txt"); // Create users.txt 
//        if (file.is_open()) {
//            saveRecursive(root, file);
//            file.close();
//            cout << "[System] Database saved to users.txt\n";
//        }
//    }
//};
//
//#endif

#ifndef USER_BST_H
#define USER_BST_H
#include "structures.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class UserBST {
private:
    User* root;

    User* insert(User* node, int id, string name, string pass, string bio) {
        if (node == nullptr) {
            User* newUser = new User();
            newUser->userID = id; newUser->username = name;
            newUser->password = pass; newUser->bio = bio;
            return newUser;
        }
        if (id < node->userID) node->left = insert(node->left, id, name, pass, bio);
        else if (id > node->userID) node->right = insert(node->right, id, name, pass, bio);
        return node;
    }

    User* searchID(User* node, int id) {
        if (node == nullptr || node->userID == id) return node;
        if (id < node->userID) return searchID(node->left, id);
        return searchID(node->right, id);
    }

    // Traversal for Username Search (Requirement: Page 2)
    User* searchName(User* node, string name) {
        if (node == nullptr) return nullptr;
        if (node->username == name) return node;
        User* res = searchName(node->left, name);
        if (res) return res;
        return searchName(node->right, name);
    }

    void saveUsers(User* node, ofstream& file) {
        if (node == nullptr) return;
        file << node->userID << "," << node->username << "," << node->password << "," << node->bio << "\n";
        saveUsers(node->left, file);
        saveUsers(node->right, file);
    }

public:
    UserBST() : root(nullptr) {}

    // Validation: Unique Name & Password Length
    bool registerUser(int id, string name, string pass, string bio) {
        if (getUserByUsername(name) != nullptr) return false;
        if (pass.length() < 6) return false;
        root = insert(root, id, name, pass, bio);
        return true;
    }

    User* getUserByID(int id) { return searchID(root, id); }
    User* getUserByUsername(string name) { return searchName(root, name); }

    void followUser(int fID, int tID) {
        User* f = getUserByID(fID); User* t = getUserByID(tID);
        if (f && t && fID != tID) {
            f->following.push_back(tID);
            t->followers.push_back(fID);
        }
    }

    void saveToFiles() {
        ofstream f("users.txt");
        if (f.is_open()) { saveUsers(root, f); f.close(); }
    }
};
#endif