// 'sampleio' Class Header
// Author: M.D.Snellgrove
// Date: 17/3/2002
// History:

// Changes by M Snellgrove 25/7/2003
//   Conditional Compilation for OpenAL

// SDL Mixer audio definitions
#include <SDL_mixer.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

// Class header

class sampleio{
  private:
    int numsamples;
    int numsources;
    int numpool;
    Mix_Chunk** sources;
    bool initdone;
	Mix_Chunk** samples;
    int poolcount;
    void psource(int source, int sample, bool loop);
	bool sourceisplaying(Mix_Chunk*);
  public:
    sampleio();
    void init(int, char[][255], int, int);
    void close();
    void update();
    void channel(int, int);
    void loop(int, int);
    void play(int);
    void stop(int);
    void volume(int, double);
};

