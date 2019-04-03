#include <string>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Exercise{
    private:
        int from;
        int to;
        inline static const string folderNameTemplate = "exercise-";

        void createExercise(){
            chdir("exercises/");
            string command = "mkdir " + folderNameTemplate + to_string(from);

            if(system(command.c_str()) == 0) {
                string filesCreationCommand =
                        "cd " + folderNameTemplate + to_string(from) + "/ &&"
                        "echo '#include \"solution.cpp\"' >  tester.cpp &&"
                        "echo '# Exercise " + to_string(from) + "' > README.md &&"
                        "touch solution.cpp && cd ..";
                system(filesCreationCommand.c_str());

                cout << folderNameTemplate << from << " created!" << endl;
                cout
                        << "\tCreated solution.cpp" << endl
                        << "\tCreated tester.cpp" << endl
                        << "\tCreated README.md" << endl;
            }
        }
        

    public:

        Exercise(){
            this->from =this->to = calculateNextExerciseNumber("exercises/");
        }
        Exercise(int num){
            this->from =this->to = num;
        }
        Exercise(int from, int to){
            if(from > to)
                swap(from, to);
            this->from = from;
            this->to = to;
        }
        
        static bool isExerciseDir(string dirName){
            if(dirName.size() <= folderNameTemplate.size()) return false;
            for(size_t i = 0; i < folderNameTemplate.size(); i++)
            {
                if(folderNameTemplate[i] != dirName[i]) return false;
            }
            return true;
            
        }
        static int calculateNextExerciseNumber(const char *path) {
            // cout << path << endl;
            struct dirent *entry;
            DIR *dir = opendir(path);
            
            if (dir == NULL) {
                return 1;
            }
            int maxExerciseNumber = 0;
            while ((entry = readdir(dir)) != NULL) {
                string fileName(entry->d_name);
                // cout << fileName << endl;
                if(isExerciseDir(fileName)){
                    string exerciseNumber = fileName.substr(folderNameTemplate.size(), fileName.size());
                    maxExerciseNumber = max(maxExerciseNumber, stoi(exerciseNumber));
                }
                
            }
            closedir(dir);
            return maxExerciseNumber+1;
        }
        void create(){
            while(from <= to){
                createExercise();
                from++;
            }
        }


};