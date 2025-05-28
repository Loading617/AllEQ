#ifndef _AllEQ_AllEQ_h
#define _AllEQ_AllEQ_h

class AllEQ {
public:
    void SetBandGains(int bassGain, int midGain, int trebleGain);
    void ProcessAudio(float* input, float* output, int frameCount);
};

#endif
