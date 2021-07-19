#include "Options.h"

Options::Options()
{
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

    SetRandomEmptyBoxPlacement(false);
}

Options::~Options()
{}

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



void Options::SetRandomEmptyBoxPlacement(const bool randomEmptyBoxPlacement)
{
    randomEmptyBoxPlacement_ = randomEmptyBoxPlacement;
}

const bool Options::GetRandomEmptyBoxPlacement() const
{
    return randomEmptyBoxPlacement_;
}