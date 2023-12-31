/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public juce::AudioAppComponent,
    public juce::Button::Listener,
    public juce::Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;

    /** implement Button::Listener */
    void buttonClicked(juce::Button*) override;

    /** implement Slider::Listener */
    void sliderValueChanged(juce::Slider* slider) override;

private:
    //==============================================================================
    // Your private member variables go here...

    juce::TextButton playButton{ "PLAY" };
    juce::TextButton stopButton{ "STOP" };
    juce::TextButton loadButton{ "LOAD" };

    juce::Slider volSlider;
    juce::Slider speedSlider;

    juce::Random rand;

    double phase;
    double dphase;

    juce::AudioFormatManager formatManager;

    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;

    juce::AudioTransportSource transportSource;
    juce::ResamplingAudioSource resampleSource{ &transportSource, false, 2 };

    void loadURL(juce::URL audioURL);

    // https://docs.juce.com/master/classFileChooser.html#ac888983e4abdd8401ba7d6124ae64ff3

    juce::FileChooser fChooser{"Select a file..."};


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
