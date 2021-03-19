
#pragma once

#include <JuceHeader.h>
#include <string>
#include "SimpleFFT.h"
#include "AnalyserComponent.h"
#include "Gain.h"


//==============================================================================
/*
*/
class MainComponent  : public juce::Component, juce::Button::Listener, juce::Slider::Listener
{
public:
    MainComponent();
    ~MainComponent() override;
    
   
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(juce::Button* button);
    void sliderValueChanged(juce::Slider* mGainControlSlider);

private:
    SimpleFFT FFT;
    Gain gain;
    AnalyserComponent SA;

    //testing TextButton that will be created in MainComponent.cpp
    juce::TextButton muteButton;

    juce::Label projectName;
    
    juce::Label gainLabel;
    juce::Slider mGainControlSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
