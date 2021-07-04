#ifndef OPTIONS_H_
#define OPTIONS_H_

class Options
{
public:
    Options();
    ~Options();

    void SetRowNum(const int rowNum);
    const int GetRowNum() const;
    void SetColumnNum(const int columnNum);
    const int GetColumnNum() const;
    void SetRedNum(const int redNum);
    const int GetRedNum() const;
    void SetGreenNum(const int greenNum);
    const int GetGreenNum() const;
    void SetBlueNum(const int blueNum);
    const int GetBlueNum() const;

private:
    int rowNum_{0};
    int columnNum_{0};
    int redNum_{0};
    int greenNum_{0};
    int blueNum_{0};
};

#endif