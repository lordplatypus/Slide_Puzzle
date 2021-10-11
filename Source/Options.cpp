#include "Options.h"
#include <iostream>

Options::Options()
{
    SetDefault(); //if config fails, just in case
    SetConfig();
}

Options::~Options()
{}

void Options::SetDefault()
{
    imageDirectoryPath_ = "./";
    options_["Rand Empty"] = 0;
    options_["Row"] = 4;
    options_["Column"] = 4;
    options_["Empty Red"] = 0;
    options_["Empty Green"] = 0;
    options_["Empty Blue"] = 0;
    options_["Empty Alpha"] = 255;
    options_["Number Size"] = 0;
    options_["Number Red"] = 0;
    options_["Number Green"] = 0;
    options_["Number Blue"] = 0;
    options_["Number Alpha"] = 255;
    options_["Background Red"] = 0;
    options_["Background Green"] = 0;
    options_["Background Blue"] = 0;
    options_["Background Alpha"] = 255;
    options_["Outline Size"] = 0;
    options_["Outline Red"] = 0;
    options_["Outline Green"] = 255;
    options_["Outline Blue"] = 255;
    options_["Outline Alpha"] = 255;
}

void Options::SetConfig()
{
    std::fstream inputStream("config"); //open config
    std::string dummy; //string to store lines
    while (std::getline(inputStream, dummy))
    {//while there are still lines to read
        if (dummy[0] == '#' || dummy == "") continue; //don't read lines that start with '#', nor blank lines
        if (dummy == "Image Directory")
        {
            std::getline(inputStream, dummy);
            SetImageDirectory(dummy);
        }
        else
        {
            std::string value = ""; //make a string to hold the value of the option
            std::getline(inputStream, value); //store value
            SetOption(dummy, std::stoi(value)); //add it to the option map
        }
    }
    inputStream.close(); //close config
}

void Options::SetOption(const std::string& optionName, const int value)
{
    options_[optionName] = value;
}

const int Options::GetOption(const std::string& optionName)
{
    return options_[optionName];
}

void Options::SetImageDirectory(const std::string& value)
{
    imageDirectoryPath_ = value;
    if (imageDirectoryPath_[imageDirectoryPath_.size() - 1] != '/') imageDirectoryPath_ += "/"; //add a "/" at the end if it doesn't have one
}

const std::string& Options::GetImageDirectory() const
{
    return imageDirectoryPath_;
}

void Options::SaveConfig()
{
     std::fstream inputStream("config"); //read the active file
    std::ofstream outputStream_("temp.txt"); //make a temp file to copy the data over to
    std::string dummy; //string to copy lines from the active file
    while (std::getline(inputStream, dummy))
    {//while there are lines to read copy them to the temp file
        outputStream_ << dummy << std::endl;
        if (dummy[0] == '#' || dummy == "") continue;
        if (dummy == "Image Directory")
        {
            std::string value = ""; //string to "eat" next input
            std::getline(inputStream, value); //"eat" next input
            outputStream_ << GetImageDirectory() << std::endl; //put in stored image directory path
        }
        else
        {
            std::string value = ""; //string to "eat" next input
            std::getline(inputStream, value); //"eat" next input
            outputStream_ << GetOption(dummy) << std::endl; //put in stored value
        }
    }
    inputStream.close(); //close the active file
    outputStream_.close(); //close the temp file
    remove("config"); //delete the now old config file and
    rename("temp.txt", "config"); //replace it with the temp file
}