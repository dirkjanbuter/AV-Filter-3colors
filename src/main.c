#include "main.h"

static int _w = 0;
static int _h = 0;
static int _framecount = 0;

static int _s = 0;
static int _sizebytes = 0;
static unsigned char *_oi;

void tricolors()
{
	int i;

	for(i = 0; i < _sizebytes; i+=4) {
		_oi[i] = (int)(_oi[i]/64)*64;
		_oi[i+1] = (int)(_oi[i+1]/64)*64;
		_oi[i+2] = (int)(_oi[i+2]/64)*64;
		_oi[i+3] = 0xff;//(int)(_oi[i+3]/64)*64;
	}
}


int filterstep(unsigned char *buffer, int w, int h, unsigned color, char *text, int64_t framecount)
{
    _w = w;
    _h = h;
    _framecount = framecount;

    _s = _w * _h;
    _sizebytes = _s * 4;

    _oi = buffer;

    tricolors();

    return 1;
}
