/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen4_screen/Screen4ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen4ViewBase::Screen4ViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_LIGHT_THEME_IMAGES_BACKGROUNDS_1024X600_BLURRY_DROPLETS_ID));
    add(image1);

    textArea1.setXY(208, 216);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EOO2));
    add(textArea1);
}

Screen4ViewBase::~Screen4ViewBase()
{

}

void Screen4ViewBase::setupScreen()
{

}

void Screen4ViewBase::handleTickEvent()
{
    //Interaction1
    //When every N tick call virtual function
    //Call prechargeScreen
    prechargeScreen();
}