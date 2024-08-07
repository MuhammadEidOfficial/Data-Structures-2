#include "StringManager.hpp"
std::string* StringManager::split(std::string str,std::string delimiter){
    int slicesCount = get_slices_count(str,delimiter);
    return split(slicesCount,str,delimiter);
}
std::string* StringManager::split(int slicesCount,std::string str,std::string delimiter){
    size_t pos = 0;
    std::string token;
    int slices_count = slicesCount;
    std::string* splitted_array = new std::string[slices_count];
    int i = 0;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        splitted_array[i] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        i++;
    }
    splitted_array[i] = str;

    return splitted_array;
}
int StringManager::get_slices_count(std::string str, std::string delimiter){
    int count = 0;
    for (char ch : str) {
        if (ch == ' ') {
            count++;
        }
    }
    count++;
    return count;
}