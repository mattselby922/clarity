
#include <JuceHeader.h>
#include <string>
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //Set size of window: setSize(int newWidth, int newHeight)
    setSize(600, 500);
 
    //displaying project name
    addAndMakeVisible(projectName);
    projectName.setFont(juce::Font(30.0f, juce::Font::bold));
    projectName.setText("CLARITY", juce::dontSendNotification);
    projectName.setColour(juce::Label::textColourId, juce::Colours::black);
    projectName.setJustificationType(juce::Justification::left);

    //displaying FFT
    addAndMakeVisible(FFT);

    //displaying Spectrum Analyzer
    addAndMakeVisible(SA);

    //displaying GainSlider
    addAndMakeVisible(mGainControlSlider);
    mGainControlSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    mGainControlSlider.setColour(juce::Slider::thumbColourId, juce::Colour::fromRGB(96, 45, 50));
    mGainControlSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 50);
    mGainControlSlider.addListener(this);
 

    //gainLabel window
    addAndMakeVisible(gainLabel);
    gainLabel.setFont(juce::Font(16.0f, juce::Font::bold));
    gainLabel.attachToComponent(&mGainControlSlider, false);
    gainLabel.setJustificationType(juce::Justification::centred);
    gainLabel.setText("Gain", juce::dontSendNotification);
    
    //creating mute button
    addAndMakeVisible(muteButton);
    muteButton.setButtonText("Mute");
    muteButton.addListener(this);
 
}

MainComponent::~MainComponent()
{
   muteButton.removeListener(this);
   mGainControlSlider.removeListener(this);
}

void MainComponent::paint (juce::Graphics& g)
{
    //fills with nice navy blue
    //g.fillAll(juce::Colour(21, 36, 49));
    
    //coral gradient fill
    g.setGradientFill(juce::ColourGradient(juce::Colours::coral, 300, 300, juce::Colours::lightcoral, 300, 300, true));
    g.fillAll();
}

//on window resize:
void MainComponent::resized()
{
    //sets border to 20px
    const int border = 20;

    juce::Rectangle<int> area = getLocalBounds();
    
    //Positioning projectName
    projectName.setBounds(area.removeFromTop(area.getHeight() / 20));

    //Positioning mGainControlSlider
    juce::Rectangle<int> mGainControlSliderArea = area.removeFromBottom(area.getHeight() / 5);
    mGainControlSlider.setBounds(mGainControlSliderArea.removeFromLeft(area.getWidth() / 5).reduced(border));

    //Positioning muteButton
    juce::Rectangle<int> muteButtonArea = area.removeFromBottom(area.getHeight() / 5);
    muteButton.setBounds(muteButtonArea.removeFromRight(area.getWidth() / 5).reduced(border));

    //Positioning FFT Spectrogram
    juce::Rectangle<int> FFTArea = area.removeFromBottom(area.getHeight() / 4);
    FFT.setBounds(FFTArea.removeFromLeft(area.getWidth() / 3).reduced(border));
    FFT.setBounds(FFTArea.removeFromRight(area.getWidth() / 3).reduced(border));

    //Positioning Analyser
    juce::Rectangle<int> AnalyserArea = area.removeFromBottom(area.getHeight() / 3);
    SA.setBounds(AnalyserArea.removeFromLeft(area.getWidth() / 3).reduced(border));
    SA.setBounds(AnalyserArea.removeFromRight(area.getWidth() / 3).reduced(border));
   
    
    //testing flexbox object on fft spectrogram
    /*juce::FlexBox FFTFlexBox;
    FFTFlexBox.flexWrap = juce::FlexBox::Wrap::wrap;
    FFTFlexBox.justifyContent = juce::FlexBox::JustifyContent::center;
    FFTFlexBox.alignContent = juce::FlexBox::AlignContent::center;
    FFTFlexBox.items.add(juce::FlexItem(FFT));  //adding spectrogram to flexbox
    FFTFlexBox.performLayout(getLocalBounds().toFloat());
    
    //this is probably unecessary, idk what it does
    juce::FlexItem main((float)getWidth() / 2.0f, (float)getHeight(), FFT);
    */
}

void MainComponent::buttonClicked(juce::Button* button)
{
    if (button == &muteButton)
    {
        
        //juce::AudioChannelSet::mono();
    }

}

void MainComponent::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &mGainControlSlider)
    {
        //mGainControlSlider.setValue(1.0 / mGainControlSlider.getValue(), juce::dontSendNotification);
    }
}
