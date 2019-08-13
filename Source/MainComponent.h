/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class OtherLookAndFeel	: public LookAndFeel_V4
{
public:
	OtherLookAndFeel();
	void drawRotarySlider(Graphics&, int, int, int, int, float, const float, const float, Slider&) override;
};

class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    OtherLookAndFeel otherLookAndFeel;
    Slider dial1;
    Slider dial2;
    TextButton button1;
    TextButton button2;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
