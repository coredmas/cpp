#ifndef CHANNEL_HPP
#define CHANNEL_HPP

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
#include "Processor.hpp"

using namespace std::chrono_literals;

#define RAW_BLOCK_SIZE 2048
#define READY_BLOCK_SIZE 5100
#define STUB_VALUE 7
#define DELAY_FOR_EMULATING_RATE 1000ms

class Channel{

    std::thread thread_;
    std::atomic<bool> stop_;
    int channel_number_;
    ProcessorFactory& factory_;
    std::shared_ptr<Processor> processor_;

public:
    Channel(int channel_number, ProcessorFactory& factory ):channel_number_(channel_number),factory_(factory)
    {
        processor_ = factory_.createProcessor();
    }

    int Start()
    {
        std::cout << "Channel Starting "<< channel_number_ << std::endl;
        stop_ = false;
        thread_ = std::thread(&Channel::Run, this);

        //affinity to core
        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);
        CPU_SET(channel_number_+1, &cpuset);
        int rc = pthread_setaffinity_np(thread_.native_handle(),sizeof(cpu_set_t), &cpuset);
        if (rc != 0) {
            std::cerr << "Error calling pthread_setaffinity_np: " << rc << std::endl;
        }
        std::cout << "Channel Started "<< channel_number_ << std::endl;
        return 0;
    }

    int Stop()
    {
        std::cout << "Channel Stopping " << channel_number_<< std::endl;
        stop_ = true;
        if(thread_.joinable())
        {
            thread_.join();
        }
        std::cout << "Channel Stopped " << channel_number_<< std::endl;
        return 0;
    }

    void Run()
    {
        std::cout << "Channel Thread Running " << std::endl;
        while (!stop_)
        {
            SampleRaw* sample_raw = new SampleRaw();
            sample_raw->channel_ = channel_number_;
            sample_raw->freq_khz_ = CalculateFreq();
            sample_raw->sample_rate_ksmpls_ =  CalculateRate();
            FillBlock(sample_raw->data_,RAW_BLOCK_SIZE);

            if(processor_){
                std::cout << "New SampleRaw for channel " << channel_number_<< std::endl;
                processor_->receiveData(sample_raw);
            }else{
                std::cerr << "processor_ is empty for channel  " << channel_number_ << std::endl;
            }
            //emulate rate
            std::this_thread::sleep_for(DELAY_FOR_EMULATING_RATE);
        }
        std::cout << "Channel Thread Stopping " << channel_number_ << std::endl;
    }
private:
    int CalculateRate(){
        //stub
        return 0;
    }
    int CalculateFreq(){
        //stub
        return 0;
    }
    void FillBlock( short int* data,int size){
        //stub
        memset(data,STUB_VALUE,size*sizeof(short int));
    }
};

class ChannelManager{

    std::vector<std::shared_ptr<Channel>> store_of_channels_;
    int channel_number_;
    ProcessorFactory& factory_;
public:
    ChannelManager(ProcessorFactory& factory):channel_number_(0),factory_(factory){}

    int CreateChannel()
    {
        std::shared_ptr<Channel> newChannel = std::make_shared<Channel>(channel_number_,factory_);
        store_of_channels_.push_back(newChannel);
        return channel_number_++;
    }

    int StartChannel(int channelNumber)
    {
        if(channelNumber > store_of_channels_.size() || store_of_channels_.size() == 0)
        {
            return -1;
        }
        return store_of_channels_.at(channelNumber)->Start();
    }

    int StopChannel(int channelNumber)
    {
        if(channelNumber > store_of_channels_.size() || store_of_channels_.size() == 0)
        {
            return -1;
        }
        return store_of_channels_.at(channelNumber)->Stop();
    }

    std::shared_ptr<Channel> GetChannel(int channelNumber)
    {
        if(channelNumber > store_of_channels_.size() || store_of_channels_.size() == 0)
        {
            return std::shared_ptr<Channel>();
        }
        return store_of_channels_.at(channelNumber);
    }
};

#endif // CHANNEL_HPP