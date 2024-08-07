#include "FileManager.hpp"

bool FileManager::is_end_of_file(std::ifstream& file){
    return file.peek() == EOF;
}
int FileManager::get_line_count(){
    std::ifstream file(path);
    int count = 0;
    while(!is_end_of_file(file)){
        std::string line;
        std::getline(file,line);
        count++;
    }
    return count;
}
FileManager::FileManager(std::string path){
    this->path = path;
}
std::string* FileManager::get_all_lines(){
    int lines_count = get_line_count();
    std::ifstream file(path);
    if(lines_count > 0){
        std::string* lines = new std::string[lines_count];
        for(int i = 0 ; i < lines_count ; i++)
        {
            getline(file,lines[i]);
        }
        return lines;
    }
    return NULL;
}
std::string FileManager::get_first_line(){
    std::ifstream file(path);
    std::string line;
    std::getline(file,line);
    return line;
}