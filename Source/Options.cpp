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

    // SetRandomEmptyBoxPlacement(false);

    // SetRowNum(4);
    // SetColumnNum(4);

    // SetBoxRed(0);
    // SetBoxGreen(0);
    // SetBoxBlue(0);
    // SetBoxAlpha(255);

    // SetBackgroundRed(0);
    // SetBackgroundGreen(0);
    // SetBackgroundBlue(0);
    // SetBackgroundAlpha(255);

    // SetNumSize(0);
    // SetNumRed(0);
    // SetNumGreen(0);
    // SetNumBlue(0);
    // SetNumAlpha(255);

    // SetOutlineSize(0);
    // SetOutlineRed(0);
    // SetOutlineGreen(255);
    // SetOutlineBlue(255);
    // SetOutlineAlpha(255);
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
}

const std::string& Options::GetImageDirectory() const
{
    return imageDirectoryPath_;
}


// void Options::SetRandomEmptyBoxPlacement(const bool randomEmptyBoxPlacement)
// {
//     randomEmptyBoxPlacement_ = randomEmptyBoxPlacement;
// }

// const bool Options::GetRandomEmptyBoxPlacement() const
// {
//     return randomEmptyBoxPlacement_;
// }



// void Options::SetRowNum(const int rowNum)
// {
//     rowNum_ = rowNum;
// }

// const int Options::GetRowNum() const
// {
//     return rowNum_;
// }

// void Options::SetColumnNum(const int columnNum)
// {
//     columnNum_ = columnNum;
// }

// const int Options::GetColumnNum() const
// {
//     return columnNum_;
// }



// void Options::SetBoxRed(const int boxRed)
// {
//     boxRed_ = boxRed;
// }

// const int Options::GetBoxRed() const
// {
//     return boxRed_;
// }

// void Options::SetBoxGreen(const int boxGreen)
// {
//     boxGreen_ = boxGreen;
// }

// const int Options::GetBoxGreen() const
// {
//     return boxGreen_;
// }

// void Options::SetBoxBlue(const int boxBlue)
// {
//     boxBlue_ = boxBlue;
// }

// const int Options::GetBoxBlue() const
// {
//     return boxBlue_;
// }

// void Options::SetBoxAlpha(const int boxAlpha)
// {
//     boxAlpha_ = boxAlpha;
// }

// const int Options::GetBoxAlpha() const
// {
//     return boxAlpha_;
// }



// void Options::SetBackgroundRed(const int backgroundRed)
// {
//     backgroundRed_ = backgroundRed;
// }

// const int Options::GetBackgroundRed() const
// {
//     return backgroundRed_;
// }

// void Options::SetBackgroundGreen(const int backgroundGreen)
// {
//     backgroundGreen_ = backgroundGreen;
// }

// const int Options::GetBackgroundGreen() const
// {
//     return backgroundGreen_;
// }

// void Options::SetBackgroundBlue(const int backgroundBlue)
// {
//     backgroundBlue_ = backgroundBlue;
// }

// const int Options::GetBackgroundBlue() const
// {
//     return backgroundBlue_;
// }

// void Options::SetBackgroundAlpha(const int backgroundAlpha)
// {
//     backgroundAlpha_ = backgroundAlpha;
// }

// const int Options::GetBackgroundAlpha() const
// {
//     return backgroundAlpha_;
// }




// void Options::SetNumSize(const int numSize)
// {
//     numSize_ = numSize;
// }

// const int Options::GetNumSize() const
// {
//     return numSize_;
// }

// void Options::SetNumRed(const int numRed)
// {
//     numRed_ = numRed;
// }

// const int Options::GetNumRed() const
// {
//     return numRed_;
// }

// void Options::SetNumGreen(const int numGreen)
// {
//     numGreen_ = numGreen;
// }

// const int Options::GetNumGreen() const
// {
//     return numGreen_;
// }

// void Options::SetNumBlue(const int numBlue)
// {
//     numBlue_ = numBlue;
// }

// const int Options::GetNumBlue() const
// {
//     return numBlue_;
// }

// void Options::SetNumAlpha(const int numAlpha)
// {
//     numAlpha_ = numAlpha;
// }

// const int Options::GetNumAlpha() const
// {
//     return numAlpha_;
// }



// void Options::SetOutlineSize(const int outlineSize)
// {
//     outlineSize_ = outlineSize;
// }

// const int Options::GetOutlineSize() const
// {
//     return outlineSize_;
// }

// void Options::SetOutlineRed(const int outlineRed)
// {
//     outlineRed_ = outlineRed;
// }

// const int Options::GetOutlineRed() const
// {
//     return outlineRed_;
// }

// void Options::SetOutlineGreen(const int outlineGreen)
// {
//     outlineGreen_ = outlineGreen;
// }

// const int Options::GetOutlineGreen() const
// {
//     return outlineGreen_;
// }

// void Options::SetOutlineBlue(const int outlineBlue)
// {
//     outlineBlue_ = outlineBlue;
// }

// const int Options::GetOutlineBlue() const
// {
//     return outlineBlue_;
// }

// void Options::SetOutlineAlpha(const int outlineAlpha)
// {
//     outlineAlpha_ = outlineAlpha;
// }

// const int Options::GetOutlineAlpha() const
// {
//     return outlineAlpha_;
// }