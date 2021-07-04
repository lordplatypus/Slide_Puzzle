#include "Options.h"

Options::Options()
{
    SetRowNum(4);
    SetColumnNum(4);
    SetRedNum(255);
    SetGreenNum(255);
    SetBlueNum(255);
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

void Options::SetRedNum(const int redNum)
{
    redNum_ = redNum;
}

const int Options::GetRedNum() const
{
    return redNum_;
}

void Options::SetGreenNum(const int greenNum)
{
    greenNum_ = greenNum;
}

const int Options::GetGreenNum() const
{
    return greenNum_;
}

void Options::SetBlueNum(const int blueNum)
{
    blueNum_ = blueNum;
}

const int Options::GetBlueNum() const
{
    return blueNum_;
}