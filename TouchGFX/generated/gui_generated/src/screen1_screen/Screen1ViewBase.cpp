/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_BACKGROUNDS_800X480_SPOTLIGHTS_ID));
    add(image1);

    image2.setXY(293, 191);
    image2.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_CONTAINERS_SMALL_WIDE_DARK_ID));
    add(image2);

    chargingText.setXY(327, 197);
    chargingText.setColor(touchgfx::Color::getColorFromRGB(214, 173, 36));
    chargingText.setLinespacing(0);
    chargingText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KD3T));
    add(chargingText);

    idleText.setXY(371, 197);
    idleText.setColor(touchgfx::Color::getColorFromRGB(214, 173, 36));
    idleText.setLinespacing(0);
    idleText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_R93R));
    idleText.setVisible(false);
    add(idleText);

    battProgress.setXY(345, 240);
    battProgress.setProgressIndicatorPosition(5, 5, 94, 30);
    battProgress.setRange(0, 100);
    battProgress.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    battProgress.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_IMAGEPROGRESS_STYLED_BATTERIES_BATTERY_LARGE_ID));
    battProgress.setBitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_IMAGEPROGRESS_STYLED_BATTERIES_BATTERY_LARGE_ACTION_ID);
    battProgress.setValue(42);
    battProgress.setAnchorAtZero(true);
    add(battProgress);

    textProgress1.setXY(313, 286);
    textProgress1.setProgressIndicatorPosition(12, 10, 150, 30);
    textProgress1.setRange(0, 100);
    textProgress1.setColor(touchgfx::Color::getColorFromRGB(214, 173, 36));
    textProgress1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TZHV));
    textProgress1.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TEXTPROGRESS_BACKGROUNDS_ROUNDED_LIGHT_ID));
    textProgress1.setValue(42);
    add(textProgress1);

    textArea1.setPosition(176, 240, 106, 63);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IWEA).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1RCL));
    add(textArea1);

    textArea2.setPosition(521, 256, 137, 24);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea2.setLinespacing(0);
    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_5M6Q).getText());
    textArea2.setWildcard(textArea2Buffer);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_63FB));
    add(textArea2);

    textProgress2.setXY(118, 171);
    textProgress2.setProgressIndicatorPosition(12, 10, 150, 30);
    textProgress2.setRange(0, 400);
    textProgress2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textProgress2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0R8C));
    textProgress2.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TEXTPROGRESS_BACKGROUNDS_ROUNDED_LIGHT_ID));
    textProgress2.setValue(60);
    textProgress2.setAlpha(0);
    add(textProgress2);

    textArea3.setXY(299, 373);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea3.setLinespacing(0);
    textArea3Buffer[0] = 0;
    textArea3.setWildcard(textArea3Buffer);
    textArea3.resizeToCurrentText();
    textArea3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IA3T));
    add(textArea3);

    textArea4.setXY(190, 291);
    textArea4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea4.setLinespacing(0);
    textArea4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZJIL));
    add(textArea4);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::handleTickEvent()
{
    //Interaction2
    //When every N tick call virtual function
    //Call bababooey
    bababooey();
}
