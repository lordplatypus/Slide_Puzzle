#include "Counter.h"
#include "LP.h"

Counter::Counter(const int startNum, const int min, const int max, const sf::Vector2f& position)
{
    SetPosition(position);
    // numText_.setPosition(position);
    // UpdateText();
    num_ = startNum;
    min_ = min;
    max_ = max;

    numText_ = LP::SetText(std::to_string(num_), position);
}

Counter::~Counter()
{}

void Counter::Draw(Camera& camera) const
{
    camera.Draw(numText_);
}


void Counter::Increment(const int incrementAmount)
{
    num_ += incrementAmount;
    if (num_ > max_) num_ = max_;
    UpdateText();
}

void Counter::Decrement(const int decrementAmount)
{
    num_ -= decrementAmount;
    if (num_ < min_) num_ = min_;
    UpdateText();
}


void Counter::SetActive(const bool active)
{
    active_ = active;

    if (!active_) numText_.setFillColor(sf::Color(255, 255, 255, 100));
    else numText_.setFillColor(sf::Color(255, 255, 255, 255));
}

bool Counter::GetActive() const
{
    return active_;
}

void Counter::SetPosition(const sf::Vector2f& position)
{
    position_ = position;
    numText_.setPosition(position_);
}

const sf::Vector2f& Counter::GetPosition() const
{
    return position_;
}

void Counter::SetNum(const int num)
{
    num_ = num;
    UpdateText();
}

int Counter::GetNum() const
{
    return num_;
}

void Counter::SetMin(const int min)
{
    min_ = min;
}

int Counter::GetMin() const
{
    return min_;
}

void Counter::SetMax(const int max)
{
    max_ = max;
}

int Counter::GetMax() const
{
    return max_;
}


void Counter::Action()
{}


void Counter::UpdateText()
{
    numText_.setString(std::to_string(num_));
}