#ifndef ID_H_
#define ID_H_

//Commonly used "keys" that need to have the same value across the whole program
//Ex: texture keys, music keys
enum
{
    pic_texture_,
};


//Layer group - order in which objects will be rendered (0 = back, 0 < front)
enum
{
    layer_tilemap_,
    layer_main_,
    layer_UI_
};

#endif