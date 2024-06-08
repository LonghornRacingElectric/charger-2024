/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen2ViewBase::Screen2ViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(-138, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_LIGHT_THEME_IMAGES_BACKGROUNDS_1024X600_BLURRY_DROPLETS_ID));
    add(image1);

    textArea1.setXY(223, 216);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MENF));
    add(textArea1);
}

Screen2ViewBase::~Screen2ViewBase()
{

}

void Screen2ViewBase::setupScreen()
{

}

void Screen2ViewBase::handleTickEvent()
{
    //Interaction1
    //When every N tick call virtual function
    //Call plugScreen
    plugScreen();
}
