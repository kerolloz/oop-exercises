#include <string>
#include <climits>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

class Exercise{
    private:
        int from;
        int to;
        void createExercise(){
            string command = createExerciseFolderCommand + to_string(from);

            if(system(command.c_str()) == 0) {
                string filesCreationCommand =
                        "cd " + +"-" + to_string(from) + "/ &&"
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
        const static string folderNameTemplate;

        Exercise(){
            this->from =this->to = calculateNextExerciseNumber(folderNameTemplate);
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
            struct dirent *entry;
            DIR *dir = opendir(path);
            
            if (dir == NULL) {
                return 1;
            }
            int maxExerciseNumber = INT_MIN;
            while ((entry = readdir(dir)) != NULL) {
                string fileName(entry->d_name);
                if(isExerciseDir(fileName)){
                    string exerciseNumber = fileName.substr(folderNameTemplate.size(), fileName.size());
                    maxExerciseNumber = max(maxExerciseNumber, stoi(exerciseNumber));
                }
                
            }
            closedir(dir);
            return maxExerciseNumber+1;
        }
        void create(){
            while(from < to){
                createExercise();
                from++;
            }
        }


};