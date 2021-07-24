#ifndef LOAD_ASSETS_H_
#define LOAD_ASSETS_H_

class LoadAssets
{
public:
    LoadAssets();
    ~LoadAssets();
    void Load();
    const bool AddImage(const std::string& filePath);

private:
    void LoadImage();
    void LoadSound();
};

#endif