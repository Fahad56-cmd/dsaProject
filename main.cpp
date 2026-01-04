//#include <iostream>
//#include "UserBST.h"
//
//using namespace std;
//
//int main() {
//    UserBST database;
//    database.registerUser(101, "fahad", "pass123", "Team Lead");
//    
//    User* u = database.getUserByID(101);
//    if (u != nullptr) {
//        cout << "SUCCESS! Found User: " << u->username << endl;
//    } else {
//        cout << "Error: User not found." << endl;
//    }
//      // ===== YOUR FOLLOWERS/FOLLOWING TEST CODE =====
//    // Register more users for testing
//    database.registerUser(102, "maryam", "pass456", "Follower Module");
//    database.registerUser(103, "ali", "pass789", "Developer");
//
//    // Make users follow each other
//    database.followUser(102, 101); // Maryam follows Fahad
//    database.followUser(103, 101); // Ali follows Fahad
//    database.followUser(102, 103); // Maryam follows Ali
//
//    // Show followers and following
//    cout << "\n=== FOLLOWERS/FOLLOWING TEST ===\n";
//    database.showFollowers(101);   // Fahad's followers
//    database.showFollowing(102);   // Maryam's following
//
//    // Test unfollow
//    database.unfollowUser(102, 101); // Maryam unfollows Fahad
//
//    cout << "\n=== AFTER UNFOLLOW ===\n";
//    database.showFollowers(101);   // Fahad's followers
//    database.showFollowing(102);   // Maryam's following
//    return 0;
//}

//#include <iostream>
//#include "UserBST.h"
//
//using namespace std;
//
//int main() {
//    UserBST db;
//
//    cout << "--- 📁 Starting Module 1 Validation ---\n";
//
//    // 1. Valid Registration
//    db.registerUser(101, "fahad", "password123", "Team Lead");
//    
//    // 2. Validation Test (Short Password should fail) [cite: 172]
//    cout << "Test (Short Password): ";
//    db.registerUser(102, "ali", "123", "User");
//
//    // 3. Username Search Test 
//    User* u = db.getUserByUsername("fahad");
//    if (u) cout << "SUCCESS: Found User by Name: " << u->username << "\n";
//
//    // 4. File Saving 
//    db.saveToUsersFile();
//
//    cout << "\n--- ✅ MODULE 1 COMPLETE ---" << endl;
//    return 0;
//}


#include <iostream>
#include "UserBST.h"
using namespace std;

int main() {
    UserBST db;
    cout << "--- STARTING 100% MODULE 1 VERIFICATION ---\n";

    // Step 1: Registration
    db.registerUser(101, "fahad", "pass1234", "Lead");
    db.registerUser(102, "maryam", "secure_pass", "Dev");

    // Step 2: Validation Check (Should Fail)
    bool fail = db.registerUser(103, "ali", "123", "Short");
    cout << (!fail ? "[PASS]" : "[FAIL]") << " Password Validation\n";

    // Step 3: Search Check
    User* u = db.getUserByUsername("maryam");
    cout << (u != nullptr ? "[PASS]" : "[FAIL]") << " Username Traversal\n";

    // Step 4: Social Graph Check
    db.followUser(102, 101);
    cout << (db.getUserByID(101)->followers.size() == 1 ? "[PASS]" : "[FAIL]") << " Social Graph\n";

    // Step 5: Persistence
    db.saveToFiles();
    cout << "--- VERIFICATION COMPLETE ---\n";
    return 0;
}