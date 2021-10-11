#include "FileManager.h"
#include <iostream>

FileManager::FileManager()
{
    //Config();
}

FileManager::~FileManager()
{}

void FileManager::Config()
{
    std::fstream inputStream("config"); //open confige
    std::string dummy; //string to store lines
    while (std::getline(inputStream, dummy))
    {//while there are still lines to read
        if (dummy[0] == '#' || dummy == "") continue; //don't read lines that start with '#', nor blank lines
        if (dummy == "Image Directory:") 
        {//fist step
            std::getline(inputStream, dummy); //grab the next line
            if (CheckDirectory(dummy)) SetImageDirectory(dummy); //use the directory in the config if there are no problems
            else SetImageDirectory("./"); //if the directory in the config fails, use "./"
        }
        else
        {
            std::getline(inputStream, dummy);
            configOptions_.push_back(std::stoi(dummy));
        }

        // else if (dummy == "BPM Save File Directory:") 
        // {//second step
        //     std::getline(inputStream, dummy); //grab the next line
        //     if (CheckDirectory(dummy)) SetBPMDirectory(dummy); //use the directory in the config if there are no problems
        //     else SetBPMDirectory("./"); //if the directory in the config fails, use "./"
        // }
    }
    inputStream.close(); //close config
}

const bool FileManager::CheckDirectory(const std::string& string)
{
    DIR *dp; //directory
    if ((dp = opendir(string.c_str())) == NULL) return false; //if the directory doesn't exist, return false
    return true; //return success
}

std::vector<std::string> FileManager::SearchDirectory(const std::string& directoryPath, const std::string& fileType)
{
    std::vector<std::string> fileNames; //vector to store file names

    DIR *dp; //directory
    if ((dp = opendir(directoryPath.c_str())) == NULL)
    {//if the directory fails to open
        fileNames.push_back("Failed to open directory");
        return fileNames;
    }

    struct dirent *dirp; 
    while ((dirp = readdir(dp)) != NULL) 
    {//while there are files to read
        std::string fname = dirp->d_name; //store name of the files
        if(fname.find(fileType) != std::string::npos) fileNames.push_back(fname); //if the file is the right type, store the file name
    }

    return fileNames; //return vector of file names
}



void FileManager::SetImageDirectory(const std::string& imageDirectoryPath)
{
    imageDirectory_ = imageDirectoryPath;
}

const std::string FileManager::GetImageDirectory() const
{
    return imageDirectory_;
}

std::vector<int> FileManager::GetConfigOptions()
{
    return configOptions_;
}