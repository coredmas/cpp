#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <functional>
#include <chrono>
#include <list>
#include <memory.h>

#include "Sample.hpp"
#include "Utils.hpp"

class PostProcessor
{
public:
    virtual ~PostProcessor(){}
    virtual void postProcess(SampleReady* sample_ready){
        delete sample_ready;
    }
};

class Processor
{
    short int freq_khz_;
    short int sample_rate_ksmpls_;
    std::list<float> store_of_floats_;
    std::unique_ptr<PostProcessor> post_processor_;
public:
    Processor(std::unique_ptr<PostProcessor> post_processor):post_processor_(std::move(post_processor)),freq_khz_(0),sample_rate_ksmpls_(0)
    {}
    virtual ~Processor(){}
    virtual void receiveData(SampleRaw* sample) {

        if(freq_khz_ == 0 && sample_rate_ksmpls_ == 0)
        {
            freq_khz_ = sample->freq_khz_;
            sample_rate_ksmpls_ = sample->sample_rate_ksmpls_;
        }
        if(freq_khz_ != sample->freq_khz_ || sample_rate_ksmpls_ != sample->sample_rate_ksmpls_)
        {
            freq_khz_ = sample->freq_khz_;
            sample_rate_ksmpls_ = sample->sample_rate_ksmpls_;
            store_of_floats_.clear();
        }
        for(int pos = 0; pos < RAW_BLOCK_SIZE; pos++)
        {
            store_of_floats_.push_back(Utils::fix2float(sample->data_[pos]));
            if(store_of_floats_.size() == READY_BLOCK_SIZE)
            {
                auto sample_ready = createSampleReady(sample->channel_,store_of_floats_);
                std::cout << "New SampleReady " << std::endl;
                post_processor_->postProcess(sample_ready);
                store_of_floats_.clear();
            }
        }
    }
private:
    SampleReady* createSampleReady(int channel_number,std::list<float>& store_of_floats)
    {
        SampleReady* sample_ready = new SampleReady();
        sample_ready->channel_ = channel_number;
        sample_ready->freq_khz_ = freq_khz_;
        sample_ready->sample_rate_ksmpls_ = sample_rate_ksmpls_;
        for(int pos = 0; pos < READY_BLOCK_SIZE; pos++)
        {
            sample_ready->data_[pos] = store_of_floats.front();
            store_of_floats.pop_front();
        }
    }
};

class ProcessorFactory  {
public:
    virtual ~ProcessorFactory() {}
    virtual  std::shared_ptr<Processor> createProcessor()
    {
        std::unique_ptr<PostProcessor> post_processor{new PostProcessor()};
        return std::shared_ptr<Processor>{new Processor(std::move(post_processor))};
    }
};

#endif // PROCESSOR_HPP