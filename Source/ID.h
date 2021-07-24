#ifndef ID_H_
#define ID_H_

//Commonly used "keys" that need to have the same value across the whole program
//Ex: texture keys, music keys, render layer keys
//Texture Keys
enum
{
    image_texture_,
    test_texture_,
};

//Font Keys
enum
{
    main_font
};


//Layer group - order in which objects will be rendered (0 = back, 0 < front)
enum
{
    layer_tilemap_,
    layer_main_,
    layer_particle,
    layer_UI_
};

#endif