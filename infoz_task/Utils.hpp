#ifndef UTILS_HPP
#define UTILS_HPP

class Utils{
public:
    static float fix2float(short int fixed)
    {
        return (float)fixed / 32767.0;
    }
};

#endif // UTILS_HPP