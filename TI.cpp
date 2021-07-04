#include "TI.h"

void TI::SetActive(const bool active)
{
    active_ = active;
}

const bool TI::GetActive()
{
    return active_;
}

void TI::SetString (const sf::String& string)
{
    string_ = string;
}

void TI::AddToString(const sf::String& string)
{
    string_ += string;
}

const sf::String& TI::GetString() const
{
    return string_;
}

void TI::Backspace()
{
    if (string_.getSize() > 0) string_.erase(string_.getSize() - 1);
}

void TI::ClearString()
{
    string_.clear();
}