//#include "GitHub.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//using namespace std;
//
//commitNode::commitNode(string msg) {
//    commitMsg = msg;
//    next = nullptr;
//}
//
//fileNode::fileNode(string name) {
//    fileName = name;
//    next = nullptr;
//}
//
//repositoryNode::repositoryNode(string name, bool isPublic) {
//    repositoryName = name;
//    this->isPublic = isPublic;
//    forkCount = 0;
//    commit = nullptr;
//    files = nullptr;
//    next = nullptr;
//}
////userNode::userNode() {
////
////}
//userNode::userNode(string name, string pass) {
//    userName = name;
//    password = pass;
//    repositories = nullptr;
//    followers = new userNode * [100];
//    following = new userNode * [100];
//    next = nullptr;
//    followingCount = 0;
//}
//
//userNode::~userNode() {
//    delete[] followers;
//    delete[] following;
//}
//
//GitHub::GitHub() {
//    users = nullptr;
//    loggedInUser = nullptr;
//    
//    readFromCSV(); // Load data from file when the program starts
//}
//
//GitHub::~GitHub() {
//    userNode* currentUser = users;
//    while (currentUser != nullptr) {
//        userNode* nextUser = currentUser->next;
//        deleteRepository(currentUser->repositories);
//        delete currentUser;
//        currentUser = nextUser;
//    }
//}
//
//void GitHub::registerUser() {
//    string name, password;
//    cout << "Enter the username: ";
//    cin >> name;
//    cout << "Enter the password: ";
//    cin >> password;
//    userNode* existingUser = searchUser(name);
//    if (existingUser != nullptr) {
//        cout << "User already exists! please choose a different username" << endl;
//        return;
//    }
//    userNode* newUser = new userNode(name, password);
//    if (users == nullptr) {
//        users = newUser;
//    }
//    else {
//        newUser->next = users;
//        users = newUser;
//    }
//
//    writeToCSV();
//    cout << "User registered successfully!" << endl;
//}
//
//void GitHub::loginUser() {
//    string userName, password;
//    cout << "Enter your username: ";
//    cin >> userName;
//    cout << "Enter your password: ";
//    cin >> password;
//    userNode* user = searchUser(userName);
//    if (user != nullptr && user->password == password) {
//        //kIsUserLoggedIn = true;
//        loggedInUser = user;
//        cout << "Login successful!" << endl;
//    }
//    else {
//        cout << "Invalid username or password!" << endl;
//    }
//}
//
//void GitHub::logoutUser() {
//   // kIsUserLoggedIn = false;
//    cout << "User logged out successfully!" << endl;
//}
//
//void GitHub::viewUserProfile() {
//    string name;
//    cout << "Enter the username: ";
//    cin >> name;
//    userNode* currentUser = searchUser(name);
//    if (currentUser != nullptr) {
//        cout << "Username: " << currentUser->userName << endl;
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//void GitHub::createRepository() {
//    string name, repoName;
//    char isPublic;
//    cout << "Enter the username: ";
//    cin >> name;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    cout << "Is the repository public? (y/n): ";
//    cin >> isPublic;
//    bool visibility = (isPublic == 'y' || isPublic == 'Y');
//    userNode* currentUser = searchUser(name);
//    if (currentUser != nullptr) {
//        repositoryNode* newRepo = new repositoryNode(repoName, visibility);
//        newRepo->next = currentUser->repositories;
//        currentUser->repositories = newRepo;
//        writeToCSV();
//        cout << "Repository " << repoName << " created successfully!" << endl;
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//void GitHub::deleteRepository() {
//    string userName, repoName;
//    cout << "Enter the username: ";
//    cin >> userName;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    userNode* currentUser = searchUser(userName);
//    if (currentUser != nullptr) {
//        repositoryNode* prev = nullptr;
//        repositoryNode* currentRepo = currentUser->repositories;
//        while (currentRepo != nullptr && currentRepo->repositoryName != repoName) {
//            prev = currentRepo;
//            currentRepo = currentRepo->next;
//        }
//        if (currentRepo != nullptr) {
//            if (prev == nullptr) {
//                currentUser->repositories = currentRepo->next;
//            }
//            else {
//                prev->next = currentRepo->next;
//            }
//            deleteCommit(currentRepo->commit);
//            deleteFile(currentRepo->files);
//            delete currentRepo;
//            writeToCSV();
//            cout << "Repository " << repoName << " deleted successfully!" << endl;
//        }
//        else {
//            cout << "Repository " << repoName << " not found!" << endl;
//        }
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//void GitHub::forkRepository() {
//    string sourceName, targetName, repoName;
//    cout << "Enter your username: ";
//    cin >> targetName;
//    cout << "Enter the username of the repository to fork: ";
//    cin >> sourceName;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    userNode* sourceUser = searchUser(sourceName);
//    userNode* targetUser = searchUser(targetName);
//    if (sourceUser != nullptr && targetUser != nullptr) {
//        repositoryNode* sourceRepo = searchRepository(sourceUser->repositories, repoName);
//        if (sourceRepo != nullptr) {
//            repositoryNode* newRepo = new repositoryNode(repoName, sourceRepo->isPublic);
//            newRepo->next = targetUser->repositories;
//            targetUser->repositories = newRepo;
//            writeToCSV();
//            cout << "Repository " << repoName << " forked successfully!" << endl;
//        }
//        else {
//            cout << "Repository " << repoName << " not found!" << endl;
//        }
//    }
//    else {
//        cout << "Source user or target user not found!" << endl;
//    }
//}
//
//void GitHub::changeRepoVisibility() {
//    string userName, repoName;
//    char isPublic;
//    cout << "Enter the username: ";
//    cin >> userName;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    cout << "Is the repository public? (y/n): ";
//    cin >> isPublic;
//    bool visibility = (isPublic == 'y' || isPublic == 'Y');
//    userNode* currentUser = searchUser(userName);
//    if (currentUser != nullptr) {
//        repositoryNode* currentRepo = searchRepository(currentUser->repositories, repoName);
//        if (currentRepo != nullptr) {
//            currentRepo->isPublic = visibility;
//            writeToCSV();
//            cout << "Repository visibility updated successfully!" << endl;
//        }
//        else {
//            cout << "Repository " << repoName << " not found!" << endl;
//        }
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//void GitHub::addCommit() {
//    string userName, repoName, commitMsg;
//    cout << "Enter your username: ";
//    cin >> userName;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    cout << "Enter the commit message: ";
//    cin.ignore();
//    getline(cin, commitMsg);
//    userNode* currentUser = searchUser(userName);
//    if (currentUser != nullptr) {
//        repositoryNode* currentRepo = searchRepository(currentUser->repositories, repoName);
//        if (currentRepo != nullptr) {
//            commitNode* newCommit = new commitNode(commitMsg);
//            newCommit->next = currentRepo->commit;
//            currentRepo->commit = newCommit;
//            writeToCSV();
//            cout << "Commit added successfully!" << endl;
//        }
//        else {
//            cout << "Repository " << repoName << " not found!" << endl;
//        }
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//void GitHub::addFile() {
//    string userName, repoName, fileName;
//    cout << "Enter your username: ";
//    cin >> userName;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    cout << "Enter the file name: ";
//    cin >> fileName;
//    userNode* currentUser = searchUser(userName);
//    if (currentUser != nullptr) {
//        repositoryNode* currentRepo = searchRepository(currentUser->repositories, repoName);
//        if (currentRepo != nullptr) {
//            fileNode* newFile = new fileNode(fileName);
//            newFile->next = currentRepo->files;
//            currentRepo->files = newFile;
//            writeToCSV();
//            cout << "File added successfully!" << endl;
//        }
//        else {
//            cout << "Repository " << repoName << " not found!" << endl;
//        }
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//void GitHub::deleteFile() {
//    string userName, repoName, fileName;
//    cout << "Enter your username: ";
//    cin >> userName;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    cout << "Enter the file name: ";
//    cin >> fileName;
//    userNode* currentUser = searchUser(userName);
//    if (currentUser != nullptr) {
//        repositoryNode* currentRepo = searchRepository(currentUser->repositories, repoName);
//        if (currentRepo != nullptr) {
//            fileNode* prev = nullptr;
//            fileNode* currentFile = currentRepo->files;
//            while (currentFile != nullptr && currentFile->fileName != fileName) {
//                prev = currentFile;
//                currentFile = currentFile->next;
//            }
//            if (currentFile != nullptr) {
//                if (prev == nullptr) {
//                    currentRepo->files = currentFile->next;
//                }
//                else {
//                    prev->next = currentFile->next;
//                }
//                delete currentFile;
//                writeToCSV();
//                cout << "File " << fileName << " deleted successfully!" << endl;
//            }
//            else {
//                cout << "File " << fileName << " not found!" << endl;
//            }
//        }
//        else {
//            cout << "Repository " << repoName << " not found!" << endl;
//        }
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//void GitHub::viewRepositoryStats() {
//    string userName, repoName;
//    cout << "Enter your username: ";
//    cin >> userName;
//    cout << "Enter the repository name: ";
//    cin >> repoName;
//    userNode* currentUser = searchUser(userName);
//    if (currentUser != nullptr) {
//        repositoryNode* currentRepo = searchRepository(currentUser->repositories, repoName);
//        if (currentRepo != nullptr) {
//            cout << "Repository Name: " << currentRepo->repositoryName << endl;
//            cout << "Visibility: " << (currentRepo->isPublic ? "Public" : "Private") << endl;
//            cout << "Number of forks: " << currentRepo->forkCount << endl;
//            commitNode* currentCommit = currentRepo->commit;
//            int commitCount = 0;
//            while (currentCommit != nullptr) {
//                commitCount++;
//                currentCommit = currentCommit->next;
//            }
//            cout << "Number of commits: " << commitCount << endl;
//            fileNode* currentFile = currentRepo->files;
//            int fileCount = 0;
//            while (currentFile != nullptr) {
//                fileCount++;
//                currentFile = currentFile->next;
//            }
//            cout << "Number of files: " << fileCount << endl;
//        }
//        else {
//            cout << "Repository " << repoName << " not found!" << endl;
//        }
//    }
//    else {
//        cout << "User not found!" << endl;
//    }
//}
//
//
//void GitHub::followUser() {
//    string follower, followed;
//    cout << "Enter the username of the follower: ";
//    cin >> follower;
//    cout << "Enter the username of the user to be followed: ";
//    cin >> followed;
//    if (graph.hasEdge(follower, followed)) {
//        cout << "User " << follower << " is already following " << followed << endl;
//    }
//    else {
//        graph.addEdge(follower, followed);
//        cout << "User " << follower << " is now following " << followed << endl;
//    }
//}
//
//void GitHub::unfollowUser() {
//    string follower, followed;
//    cout << "Enter the username of the follower: ";
//    cin >> follower;
//    cout << "Enter the username of the user to be unfollowed: ";
//    cin >> followed;
//    if (graph.hasEdge(follower, followed)) {
//        graph.removeEdge(follower, followed);
//        cout << "User " << follower << " is no longer following " << followed << endl;
//    }
//    else {
//        cout << "User " << follower << " is not following " << followed << endl;
//    }
//}
//void GitHub::writeToCSV() {
//    // Write user data to CSV file
//    ofstream outFile("users.csv");
//    if (outFile.is_open()) {
//        userNode* currentUser = users;
//        while (currentUser != nullptr) {
//            outFile << currentUser->userName << "," << currentUser->password << ",";
//            outFile << currentUser->followingCount << ",";
//            for (int i = 0; i < currentUser->followingCount; i++) {
//                outFile << currentUser->following[i]->userName << ",";
//            }
//            outFile << endl;
//            currentUser = currentUser->next;
//        }
//        outFile.close();
//    }
//    else {
//        cerr << "Error: Unable to open file for writing" << endl;
//    }
//}
//
//void GitHub::readFromCSV() {
//    // Read user data from CSV file
//    ifstream inFile("users.csv");
//    if (inFile.is_open()) {
//        string line;
//        while (getline(inFile, line)) {
//            stringstream ss(line);
//            string token;
//            getline(ss, token, ','); // username
//            string userName = token;
//            getline(ss, token, ','); // password
//            string password = token;
//            userNode* newUser = new userNode(userName, password);
//            getline(ss, token, ','); // following count
//            int followingCount = stoi(token);
//            for (int i = 0; i < followingCount; i++) {
//                getline(ss, token, ','); // followed user
//                userNode* followedUser = searchUser(token);
//                if (followedUser != nullptr) {
//                    newUser->following[newUser->followingCount++] = followedUser;
//                }
//            }
//            if (users == nullptr) {
//                users = newUser;
//            }
//            else {
//                newUser->next = users;
//                users = newUser;
//            }
//        }
//        inFile.close();
//    }
//    else {
//        cerr << "Error: Unable to open file for reading" << endl;
//    }
//}
//
//userNode* GitHub::searchUser(string name) {
//    userNode* currentUser = users;
//    while (currentUser != nullptr) {
//        if (currentUser->userName == name) {
//            return currentUser;
//        }
//        currentUser = currentUser->next;
//    }
//    return nullptr;
//}
//
//repositoryNode* GitHub::searchRepository(repositoryNode* node, string name) {
//    while (node != nullptr) {
//        if (node->repositoryName == name) {
//            return node;
//        }
//        node = node->next;
//    }
//    return nullptr;
//}
//
//void GitHub::deleteCommit(commitNode* node) {
//    while (node != nullptr) {
//        commitNode* temp = node;
//        node = node->next;
//        delete temp;
//    }
//}
//
//void GitHub::deleteFile(fileNode* node) {
//    while (node != nullptr) {
//        fileNode* temp = node;
//        node = node->next;
//        delete temp;
//    }
//}
//
//void GitHub::deleteRepository(repositoryNode* node) {
//    while (node != nullptr) {
//        repositoryNode* temp = node;
//        node = node->next;
//        deleteCommit(temp->commit);
//        deleteFile(temp->files);
//        delete temp;
//    }
//}
