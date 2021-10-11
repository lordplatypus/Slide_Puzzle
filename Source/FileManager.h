#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_
#include <fstream>
#include <vector>
#include <dirent.h>

class FileManager
{
public:
    FileManager();
    ~FileManager();

    void Config(); //read config
    const bool CheckDirectory(const std::string& string); //check directory to see if it exists
    std::vector<std::string> SearchDirectory(const std::string& directoryPath, const std::string& fileType); //check directory for files that contain "fileType"

    //Slide Puzzle Game specific
    void SetImageDirectory(const std::string& imageDirectoryPath);
    const std::string GetImageDirectory() const;
    std::vector<int> GetConfigOptions();

private:
    std::vector<int> configOptions_;
    std::string imageDirectory_;
};

#endif