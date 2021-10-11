#ifndef OPTIONS_H_
#define OPTIONS_H_
#include "FileManager.h"
#include <unordered_map>

class Options
{
public:
    Options();
    ~Options();

    void SetDefault();
    void SetConfig();

    void SetOption(const std::string& optionName, const int value);
    const int GetOption(const std::string& optionName);

    void SetImageDirectory(const std::string& value);
    const std::string& GetImageDirectory() const;

    void SaveConfig();

private:
    //File Manager
    FileManager FM_;
    //Image directory path
    std::string imageDirectoryPath_{"./"};
    //Option map
    std::unordered_map<std::string, int> options_;
};

#endif