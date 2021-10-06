#include "Processor.hpp"
#include "Channel.hpp"

#define TEST_DURATION_MINUTES 1

int main() {
    ProcessorFactory channel_factory;
    ChannelManager channel_manager(channel_factory);
    for(int pos = 0 ;pos < 4; pos++)
    {
        channel_manager.CreateChannel();
    }
    for(int pos = 0 ;pos < 4; pos++)
    {
        channel_manager.StartChannel(pos);
    }
    std::this_thread::sleep_for(std::chrono::minutes(TEST_DURATION_MINUTES));

    for(int pos = 0 ;pos < 4; pos++)
    {
        channel_manager.StopChannel(pos);
    }
    return 0;
}