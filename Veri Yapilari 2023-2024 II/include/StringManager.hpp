#ifndef StringManager_HPP
#define StringManager_HPP

#include <iostream>
class StringManager{
    public:
    static std::string* split(std::string str,std::string delimiter);
    static std::string* split(int slicesCount,std::string str,std::string delimiter);
    static int get_slices_count(std::string str, std::string delimiter);
};

#endif