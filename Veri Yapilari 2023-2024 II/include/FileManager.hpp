#ifndef FileManager_Hpp
#define FileManager_Hpp

#include <string>
#include <fstream>

class FileManager{
    private:
    int linesCount;
    std::string path;
    bool is_end_of_file(std::ifstream& file);
    public:
    FileManager(std::string path);
    std::string* get_all_lines();
    int get_line_count();
    std::string get_first_line();
    // path, string[] lines, int linesCount

};

#endif