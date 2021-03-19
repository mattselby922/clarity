/*
  ==============================================================================

    Gain.h
    Created: 17 Mar 2021 13:43pm

  ==============================================================================
*/

#pragma once

class Gain : public juce::AudioProcessor
{
public:

    //==============================================================================
    Gain()
    {
        addParameter(gain = new juce::AudioParameterFloat("gain", // parameterID
            "Gain", // parameter name
            0.0f,   // minimum value
            1.0f,   // maximum value
            0.5f)); // default value
    }

    //==============================================================================
    void prepareToPlay(double, int) override {}
    void releaseResources() override {}

    void processBlock(juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override
    {
        buffer.applyGain(*gain);
    }

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override { return new juce::GenericAudioProcessorEditor(*this); }
    bool hasEditor() const override { return true; }

    //==============================================================================
    const juce::String getName() const override { return "Param Tutorial"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 0; }

    //==============================================================================
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}

    //==============================================================================
    void getStateInformation(juce::MemoryBlock& destData) override
    {
        juce::MemoryOutputStream(destData, true).writeFloat(*gain);
    }

    void setStateInformation(const void* data, int sizeInBytes) override
    {
        *gain = juce::MemoryInputStream(data, static_cast<size_t> (sizeInBytes), false).readFloat();
    }

private:
    //==============================================================================
    juce::AudioParameterFloat* gain;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Gain)
};
