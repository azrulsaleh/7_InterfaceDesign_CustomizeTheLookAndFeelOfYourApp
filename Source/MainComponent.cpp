/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

OtherLookAndFeel::OtherLookAndFeel()
{
	setColour(Slider::thumbColourId, Colours::red);
}

void OtherLookAndFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
	auto radius = jmin(width / 2, height / 2) - 4.0f;
	auto centreX = x + (width * 0.5f);
	auto centreY = y + (height * 0.5f);
	auto rx = centreX - radius;
	auto ry = centreY - radius;
	auto rw = radius * 2.0f;
	auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
	
	g.setColour(Colours::grey);
	g.fillEllipse(rx, ry, rw, rw);
	g.setColour(Colours::red);
	g.drawEllipse(rx, ry, rw, rw, 1.0f);

	Path p;
	//auto pointerLength = radius * 0.33f;
	auto pointerLength = radius * 0.6f;
	//auto pointerThickness = 2.0f;
	auto pointerThickness = 5.0f;
	p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
	//p.addRoundedRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength, 100);
	//p.addArrow(Line<float>(pointerThickness * 0.5f, radius, -pointerThickness * 0.5f, -radius), 5, 20, 20);
	p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
	g.setColour(Colours::red);
	g.fillPath(p);
}

void OtherLookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour, bool isMouseOverButton, bool isButtonDown)
{
	auto buttonArea = button.getLocalBounds();
	//auto edge = 4;
	//g.setColour(Colours::darkgrey.withAlpha(0.5f));
	int edge;
	if (isMouseOverButton == 1)
	{
		edge = 4;
		g.setColour(Colours::red);
	}
	else
	{
		edge = 5;
		g.setColour(Colours::indianred);
	}
	buttonArea.removeFromLeft(edge);
	buttonArea.removeFromTop(edge);
	g.fillRect(buttonArea);

	auto offset = isButtonDown ? -edge / 2 : -edge;
	buttonArea.translate(offset, offset);
	g.setColour(backgroundColour);
	/*if (isMouseOverButton == 1)
	{
		g.setColour(Colours::red);
	}
	else
	{
		g.setColour(Colours::indianred);
	}*/
	g.fillRect(buttonArea);
}

void OtherLookAndFeel::drawButtonText(Graphics& g, TextButton& button, bool isMouseOverButton, bool isButtonDown)
{
	auto font = getTextButtonFont(button, button.getHeight());
	g.setFont(font);
	g.setColour(button.findColour(button.getToggleState() ? TextButton::textColourOnId : TextButton::textColourOffId)
					  .withMultipliedAlpha(button.isEnabled() ? 1.0f : 0.5f));
	auto yIndent = jmin(4, button.proportionOfHeight(0.3f));
	auto cornerSize = jmin(button.getHeight(), button.getWidth()) / 2;
	auto fontHeight = roundToInt(font.getHeight() * 0.6f);
	auto leftIndent = jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
	auto rightIndent = jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
	auto textWidth = button.getWidth() - leftIndent - rightIndent;
	auto edge = 4;
	auto offset = isButtonDown ? edge / 2 : 0;
	if (textWidth > 0)
		g.drawFittedText(button.getButtonText(), 
						 leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2, 
						 Justification::centred, 2);
}

//==============================================================================
MainComponent::MainComponent()
{
    setSize (300, 200);

    //otherLookAndFeel.setColour(Slider::thumbColourId, Colours::red);
    //dial1.setLookAndFeel(&otherLookAndFeel);
	setLookAndFeel(&otherLookAndFeel);

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
	setLookAndFeel(nullptr);
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
