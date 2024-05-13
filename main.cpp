//#include "GitHub.h"
//#include <iostream>
//using namespace std;
//int main() {
//    GitHub gitHub;
//
//    int choice;
//    
//    do {
//        
//        cout << "=====Welcome to GitHub=====" << endl;
//        cout << "1. Register User" << endl;
//        cout << "2. Login" << endl;
//        cout << "3. Logout" << endl;
//        cout << "4. View User Profile" << endl;
//        cout << "5. Create Repository" << endl;
//        cout << "6. Delete Repository" << endl;
//        cout << "7. Fork Repository" << endl;
//        cout << "8. Change Repository Visibility" << endl;
//        cout << "9. Add Commit" << endl;
//        cout << "10. Add File" << endl;
//        cout << "11. Delete File" << endl;
//        cout << "12. View Repository Stats" << endl;
//        cout << "13. Follow User" << endl;
//        cout << "14. Unfollow User" << endl;
//        cout << "15. Exit" << endl;
//
//        
//        cout << "Enter your choice: ";
//        cin >> choice;
//        system("cls");
//        switch (choice) {
//        case 1:
//            gitHub.registerUser();
//            system("cls");
//            break;
//        case 2:
//            gitHub.loginUser();
//            system("cls");
//            break;
//        case 3:
//            gitHub.logoutUser();
//            system("cls");
//            break;
//        case 4:
//            gitHub.viewUserProfile();
//            system("cls");
//            break;
//        case 5:
//            gitHub.createRepository();
//            system("cls");
//            break;
//        case 6:
//            gitHub.deleteRepository();
//            system("cls");
//            break;
//        case 7:
//            gitHub.forkRepository();
//            system("cls");
//            break;
//        case 8:
//            gitHub.changeRepoVisibility();
//            system("cls");
//            break;
//        case 9:
//            gitHub.addCommit();
//            system("cls");
//            break;
//        case 10:
//            gitHub.addFile();
//            system("cls");
//            break;
//        case 11:
//            gitHub.deleteFile();
//            system("cls");
//            break;
//        case 12:
//            gitHub.viewRepositoryStats();
//            system("cls");
//            break;
//        case 13:
//            gitHub.followUser();
//            system("cls");
//            break;
//        case 14:
//            gitHub.unfollowUser();
//            system("cls");
//            break;
//        case 15:
//            cout << "program khtam hoa" << endl;
//            break;
//        default:
//            cout << "Invalid choice! Please enter a number between 1 and 15." << endl;
//        }
//    } while (choice != 15);
//    return 0;
//}
