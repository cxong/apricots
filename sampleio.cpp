// Wrapper Library for OpenAL
// Author: M.D.Snellgrove
// Date: 17/3/2002
// History:

// Changes by M Snellgrove 26/7/2003
//   Conditional Compilation using OpenAL

// Changes by Judebert 1/8/2003
//   Portability fix for WIN32 systems

// Changes by M Snellgrove 5/8/2003
//   Code cleanup

#include "sampleio.h"

// SDL_mixer sound routines

// Constructor

sampleio :: sampleio(){
}

// Initialize SDL_mixer
void sampleio :: init(int nsamples, char filenames[][255], int nsources,
                      int npool){
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
	int audio_channels = 2;
	int audio_buffers = 4096;

	numsamples = nsamples;

	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers))
	{
		// failed to init audio
		exit(1);
	}

	sources = new Mix_Chunk*[numsamples];

	for(int i = 0; i < numsamples; i++)
	{
		sources[i] = Mix_LoadWAV(filenames[i]);
	}
}

void sampleio :: play(int sample){
	Mix_PlayChannel(-1, sources[sample], 0);
}

void sampleio :: close(){
	for(int i = 0; i < numsamples; i++)
	{
		Mix_FreeChunk(sources[i]);
	}
}
void sampleio :: update(){}
void sampleio :: channel(int, int){}
void sampleio :: loop(int, int){}
void sampleio :: stop(int){}
void sampleio :: psource(int, int, bool){}
void sampleio :: volume(int, double){}
bool sampleio :: sourceisplaying(Mix_Chunk*){return false;}
