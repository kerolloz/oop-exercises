#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#define endl '\n'

using namespace std;

string questionFolderNameTemplate = "question-";

bool isQuestionDir(string dirName){
    if(dirName.size() <= questionFolderNameTemplate.size()) return false;
    for(size_t i = 0; i < questionFolderNameTemplate.size(); i++)
    {
        if(questionFolderNameTemplate[i] != dirName[i]) return false;
    }
    return true;
    
}

int calculateNextQuestionNumber(const char *path) {
   struct dirent *entry;
   DIR *dir = opendir(path);
   
   if (dir == NULL) {
      return 1;
   }
   int maxQuestionNumber = INT_MIN;
   while ((entry = readdir(dir)) != NULL) {
       string fileName(entry->d_name);
       if(isQuestionDir(fileName)){
           string questionNumber = fileName.substr(questionFolderNameTemplate.size(), fileName.size());
           maxQuestionNumber = max(maxQuestionNumber, stoi(questionNumber));
       }
       
   }
   closedir(dir);
   return maxQuestionNumber+1;
}

int main (int argc, char** argv) {
    string createQuestionFolderCommand = "mkdir " + questionFolderNameTemplate;
    int nextQuestionNumber = 1;

    if(argc == 1){
        // no question number is provided
        // we will comupte the  next question number
        nextQuestionNumber = calculateNextQuestionNumber(".");
    }else if(argc == 2){
        string questionNumber(argv[1]);
        nextQuestionNumber = stoi(questionNumber); 
    }else{
        cout << "ERROR: Please provide the question number only!" << endl;
        return -1;
    }

    createQuestionFolderCommand += to_string(nextQuestionNumber);

    if(system(createQuestionFolderCommand.c_str()) == 0) // system returns 0 on successful execution of command
        cout << questionFolderNameTemplate << nextQuestionNumber  << " created!" << endl;

    
}