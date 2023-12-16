#ifndef GRAPH_H_
#define GRAPH_H_
#include <machine.h>
#include <master.h>

const _BLACK       = 0x0;
const _BLUE        = 0x1;
const _RED         = 0x2;
const _MAGENTA     = 0x3;
const _GREEN       = 0x4;
const _WATER       = 0x5;
const _YELLOW      = 0x6;
const _WHITE       = 0x7;
const _GRAY        = 0x8;
const _DARKBLUE    = 0x9;
const _DARKRED     = 0xA;
const _DARKMAGENTA = 0xB;
const _DARKGREEN   = 0xC;
const _DARKWATER   = 0xD;
const _DARKYELLOW  = 0xE;
const _DARKGRAY    = 0xF;

class GRAPH
{
	MACHINE         m;
public:
	static int      graph;
	void            at_copypage (int a);//コピー先ページ
	                GRAPH (void);
	                ~GRAPH ();
	void            active (int page);
	void            box (int x1, int y1, int x2, int y2, int color);
	void            box (int x1, int y1, int x2, int y2, int color1, int color2);
	void            circle (int x, int y, int r, int color);
	void            circle (int x, int y, int r, int color1, int color2);
	void            clear (void);
	void            copypage (int to_page);//コピー先ページ
	void            line (int x1, int y1, int x2, int y2, int color);
	void            setcolor (int a);
	void            visual (int page);
};
#endif
