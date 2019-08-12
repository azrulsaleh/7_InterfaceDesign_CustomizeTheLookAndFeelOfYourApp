/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (300, 200);

    getLookAndFeel().setColour(Slider::thumbColourId, Colours::red);
    
    dial1.setSliderStyle(Slider::Rotary);
    dial1.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(dial1);
    
    dial2.setSliderStyle(Slider::Rotary);
    dial2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(dial2);
    
    button1.setButtonText("Button 1");
    addAndMakeVisible(button1);
    
    button2.setButtonText("Button 2");
    addAndMakeVisible(button2);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto border = 4;
    auto area = getLocalBounds();
    
    auto dialArea = area.removeFromTop(area.getHeight() / 2);
    dial1.setBounds(dialArea.removeFromLeft(dialArea.getWidth() / 2).reduced(border));
    dial2.setBounds(dialArea.reduced(border));
    
    auto buttonHeight = 30;
    button1.setBounds(area.removeFromTop(buttonHeight).reduced(border));
    button2.setBounds(area.removeFromTop(buttonHeight).reduced(border));
}
