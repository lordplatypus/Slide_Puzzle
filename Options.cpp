#include "Options.h"

Options::Options()
{
    SetDefault();
}

Options::~Options()
{}

void Options::SetDefault()
{
    SetRandomEmptyBoxPlacement(false);

    SetRowNum(4);
    SetColumnNum(4);

    SetBoxRed(0);
    SetBoxGreen(0);
    SetBoxBlue(0);
    SetBoxAlpha(255);

    SetBackgroundRed(0);
    SetBackgroundGreen(0);
    SetBackgroundBlue(0);
    SetBackgroundAlpha(255);

    SetNumSize(32);
    SetNumRed(0);
    SetNumGreen(0);
    SetNumBlue(0);
    SetNumAlpha(255);

    SetOutlineSize(0);
    SetOutlineRed(0);
    SetOutlineGreen(255);
    SetOutlineBlue(255);
    SetOutlineAlpha(255);
}



void Options::SetRandomEmptyBoxPlacement(const bool randomEmptyBoxPlacement)
{
    randomEmptyBoxPlacement_ = randomEmptyBoxPlacement;
}

const bool Options::GetRandomEmptyBoxPlacement() const
{
    return randomEmptyBoxPlacement_;
}



void Options::SetRowNum(const int rowNum)
{
    rowNum_ = rowNum;
}

const int Options::GetRowNum() const
{
    return rowNum_;
}

void Options::SetColumnNum(const int columnNum)
{
    columnNum_ = columnNum;
}

const int Options::GetColumnNum() const
{
    return columnNum_;
}



void Options::SetBoxRed(const int boxRed)
{
    boxRed_ = boxRed;
}

const int Options::GetBoxRed() const
{
    return boxRed_;
}

void Options::SetBoxGreen(const int boxGreen)
{
    boxGreen_ = boxGreen;
}

const int Options::GetBoxGreen() const
{
    return boxGreen_;
}

void Options::SetBoxBlue(const int boxBlue)
{
    boxBlue_ = boxBlue;
}

const int Options::GetBoxBlue() const
{
    return boxBlue_;
}

void Options::SetBoxAlpha(const int boxAlpha)
{
    boxAlpha_ = boxAlpha;
}

const int Options::GetBoxAlpha() const
{
    return boxAlpha_;
}



void Options::SetBackgroundRed(const int backgroundRed)
{
    backgroundRed_ = backgroundRed;
}

const int Options::GetBackgroundRed() const
{
    return backgroundRed_;
}

void Options::SetBackgroundGreen(const int backgroundGreen)
{
    backgroundGreen_ = backgroundGreen;
}

const int Options::GetBackgroundGreen() const
{
    return backgroundGreen_;
}

void Options::SetBackgroundBlue(const int backgroundBlue)
{
    backgroundBlue_ = backgroundBlue;
}

const int Options::GetBackgroundBlue() const
{
    return backgroundBlue_;
}

void Options::SetBackgroundAlpha(const int backgroundAlpha)
{
    backgroundAlpha_ = backgroundAlpha;
}

const int Options::GetBackgroundAlpha() const
{
    return backgroundAlpha_;
}




void Options::SetNumSize(const int numSize)
{
    numSize_ = numSize;
}

const int Options::GetNumSize() const
{
    return numSize_;
}

void Options::SetNumRed(const int numRed)
{
    numRed_ = numRed;
}

const int Options::GetNumRed() const
{
    return numRed_;
}

void Options::SetNumGreen(const int numGreen)
{
    numGreen_ = numGreen;
}

const int Options::GetNumGreen() const
{
    return numGreen_;
}

void Options::SetNumBlue(const int numBlue)
{
    numBlue_ = numBlue;
}

const int Options::GetNumBlue() const
{
    return numBlue_;
}

void Options::SetNumAlpha(const int numAlpha)
{
    numAlpha_ = numAlpha;
}

const int Options::GetNumAlpha() const
{
    return numAlpha_;
}



void Options::SetOutlineSize(const int outlineSize)
{
    outlineSize_ = outlineSize;
}

const int Options::GetOutlineSize() const
{
    return outlineSize_;
}

void Options::SetOutlineRed(const int outlineRed)
{
    outlineRed_ = outlineRed;
}

const int Options::GetOutlineRed() const
{
    return outlineRed_;
}

void Options::SetOutlineGreen(const int outlineGreen)
{
    outlineGreen_ = outlineGreen;
}

const int Options::GetOutlineGreen() const
{
    return outlineGreen_;
}

void Options::SetOutlineBlue(const int outlineBlue)
{
    outlineBlue_ = outlineBlue;
}

const int Options::GetOutlineBlue() const
{
    return outlineBlue_;
}

void Options::SetOutlineAlpha(const int outlineAlpha)
{
    outlineAlpha_ = outlineAlpha;
}

const int Options::GetOutlineAlpha() const
{
    return outlineAlpha_;
}