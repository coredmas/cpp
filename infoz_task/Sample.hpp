#ifndef SAMPLE_HPP
#define SAMPLE_HPP

#define RAW_BLOCK_SIZE 2048
#define READY_BLOCK_SIZE 5100
struct SampleRaw{
    int channel_;
    short int freq_khz_;
    short int sample_rate_ksmpls_;
    short int data_[RAW_BLOCK_SIZE];
};

struct SampleReady{
    int channel_;
    short int freq_khz_;
    short int sample_rate_ksmpls_;
    float data_[READY_BLOCK_SIZE];
};
#endif // SAMPLE_HPP