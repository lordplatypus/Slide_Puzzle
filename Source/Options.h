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

    // void SetRandomEmptyBoxPlacement(const bool randomEmptyBoxPlacement);
    // const bool GetRandomEmptyBoxPlacement() const;

    // void SetRowNum(const int rowNum);
    // const int GetRowNum() const;
    // void SetColumnNum(const int columnNum);
    // const int GetColumnNum() const;

    // void SetBoxRed(const int boxRed);
    // const int GetBoxRed() const;
    // void SetBoxGreen(const int boxGreen);
    // const int GetBoxGreen() const;
    // void SetBoxBlue(const int boxBlue);
    // const int GetBoxBlue() const;
    // void SetBoxAlpha(const int boxAlpha);
    // const int GetBoxAlpha() const;

    // void SetBackgroundRed(const int backgroundRed);
    // const int GetBackgroundRed() const;
    // void SetBackgroundGreen(const int backgroundGreen);
    // const int GetBackgroundGreen() const;
    // void SetBackgroundBlue(const int backgroundBlue);
    // const int GetBackgroundBlue() const;
    // void SetBackgroundAlpha(const int backgroundAlpha);
    // const int GetBackgroundAlpha() const;

    // void SetNumSize(const int numRed);
    // const int GetNumSize() const;
    // void SetNumRed(const int numRed);
    // const int GetNumRed() const;
    // void SetNumGreen(const int numGreen);
    // const int GetNumGreen() const;
    // void SetNumBlue(const int numBlue);
    // const int GetNumBlue() const;
    // void SetNumAlpha(const int numAlpha);
    // const int GetNumAlpha() const;

    // void SetOutlineSize(const int outlineSize);
    // const int GetOutlineSize() const;
    // void SetOutlineRed(const int outlineRed);
    // const int GetOutlineRed() const;
    // void SetOutlineGreen(const int outlineGreen);
    // const int GetOutlineGreen() const;
    // void SetOutlineBlue(const int outlineBlue);
    // const int GetOutlineBlue() const;
    // void SetOutlineAlpha(const int outlineAlpha);
    // const int GetOutlineAlpha() const;

private:
    //File Manager
    FileManager FM_;
    //Image directory path
    std::string imageDirectoryPath_{"./"};
    //Option map
    std::unordered_map<std::string, int> options_;
    


    // //Random empty box placement (difficulty)
    // bool randomEmptyBoxPlacement_{false};
    // //Number of boxes
    // int rowNum_{0};
    // int columnNum_{0};
    // //Empty box color
    // int boxRed_{0};
    // int boxGreen_{0};
    // int boxBlue_{0};
    // int boxAlpha_{0};
    // //Background Color
    // int backgroundRed_{0};
    // int backgroundGreen_{0};
    // int backgroundBlue_{0};
    // int backgroundAlpha_{0};
    // //Hint number size and color
    // int numSize_{0};
    // int numRed_{0};
    // int numGreen_{0};
    // int numBlue_{0};
    // int numAlpha_{0};
    // //Outline size and color
    // int outlineSize_{0};
    // int outlineRed_{0};
    // int outlineGreen_{0};
    // int outlineBlue_{0};
    // int outlineAlpha_{0};
};

#endif