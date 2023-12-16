#include <conio.h>
#include <ctype.h>
#include <dos.h>     //FP.SEG
#include <except.h>
#include <graph.h>
#include <key.h>
#include <machine.h>
//#include <mfxddn.h>
#include <process.h> //異常終了の時などに使用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warn -inl
#pragma warn -sig

const ACT_LIMIT = 30;

class TETRAS
{
public:
	virtual void            go (void) = 0;
};

class TETRAS98:public TETRAS
{
public:
	char                    *musicbuf;
	void                    go (void);
	                        TETRAS98 (void);
	                        ~TETRAS98 ();
};

class TETRASat:public TETRAS
{
public:
	//char                    *musicbuf;
	void                    go (void);
	                        TETRASat (void);
	                        ~TETRASat ();
};

class RECORD
{
public:
	long                    point;
	char                    name [9];
	char                    date [9];
	static long             comp (RECORD s1, RECORD s2);
	                        RECORD (void);
};

class RECORD_LIST
{
	RECORD                  tmp [11];
public:
	static int              members;
	RECORD                  t [10];
	void                    load (char *filename, RECORD_LIST *a);
	void                    save (char *filename);
	void                    save (char *filename, RECORD_LIST *a);
};

class STATUS
{
protected:
	GRAPH                   it; //派生クラスからも使用可能。
public:
	void                    went (void);
	virtual void            del (void) = 0;
	virtual void            go (RECORD_LIST p) = 0;
};

class STATUS_LIST
{
	STATUS                  *r [4];
	GRAPH                   it;
	KEY                     k;
	void                    del (int a);
	void                    go (int a);
public:
	                        STATUS_LIST (STATUS *a, STATUS *b, STATUS *c, STATUS *d);
	                        ~STATUS_LIST ();
	RECORD_LIST             relist [4];
	int                     cu;
	void                    move (int a);
	void                    go (void);
};

class STATUS1:public STATUS
{
	char                    ch [80];
public:
	void                    del (void);
	void                    go (RECORD_LIST p);
};

class STATUS2:public STATUS
{
public:
	void                    del (void);
	void                    go (RECORD_LIST p);
};

class XY
{
public:
	int                     x;
	int                     y;
	                        XY (void);
	                        XY (int a, int b);
	void                    operator =(XY a);
};

class BLOCK
{
public:
	int                     t [10]; //ブロックの属性。番兵は作らない
	int                     bfnt [10];
	int                     all (void);
	                        BLOCK (void);
	void                    operator =(int a);
};

class BLOCK_LIST
{
public:
	BLOCK                   blist [38]; //見えている部分１９＋予備１９
};

class DRAW
{
public:
	int                     XY_to_x (XY a, int player, int mode);
	int                     XY_to_y (XY a);
	void                    enter (XY a, int bfnt, int player, int mode);
	void                    in (int x, int y, int bfnt);
	void                    in (XY a, int bfnt, int player, int mode);
	void                    out (int x, int y, int bfnt);
	void                    out (XY a, int bfnt, int player, int mode);
};

class MOVER //動くブロック
{
	DRAW                    it;
public:
	XY                      r; //左上の理論座標
	int                     bfnt;
	int                     type;
	int                     player;
	int                     mode;
	                        MOVER (void);
	void                    enter (void);
	void                    in (void);
	void                    out (void);
	void                    change (int _x, int _y, int _bfnt, int _player, int _mode);
	int                     can_put (BLOCK_LIST a, MOVER b);
	int                     turn_enable (BLOCK_LIST a);
	void                    turn (int errlv);
	int                     move_enable (BLOCK_LIST a, XY b);
	void                    move (XY a, int errlv);
};


class NEXT
{
public:
};

class KEYDATA
{
	int                     data [4]; //最大４つまで登録可能。
public:
	void                    setup (int a, int b, int c, int d);
	int                     operator ==(KEY k);
};

class TETRAS_MAIN
{
public:
	virtual int             search (KEY k);
	                        TETRAS_MAIN (void);
	RECORD                  rec;
	MOVER                   mv;
	BLOCK_LIST              bl;
	long                    count;
	int                     lv;
	KEYDATA                 keydata [4];
	unsigned                gage [4];
	int                     arrival;
};

class TETRAS98_MAIN_ONE
{
public:
	KEY                     k;
	DRAW                    it;
	TETRAS_MAIN             *player;
	void                    go (void);
};

class TETRAS98_MAIN_TWO
{
public:
	KEY                     k;
	DRAW                    it;
	TETRAS_MAIN             *player [2];
	void                    go (void);
};

class TETRAS98_MAIN_THREE
{
public:
	KEY                     k;
	DRAW                    it;
	TETRAS_MAIN             *player [3];
	void                    go (void);
};

class TETRAS98_MAIN_ONE1:public TETRAS_MAIN
{
public:
	                        TETRAS98_MAIN_ONE1 (void);
	int                     search (KEY k);
};

class TETRAS98_MAIN_TWO1:public TETRAS_MAIN
{
public:
	                        TETRAS98_MAIN_TWO1 (void);
	int                     search (KEY k);
};

class TETRAS98_MAIN_TWO2:public TETRAS_MAIN
{
public:
	                        TETRAS98_MAIN_TWO2 (void);
	int                     search (KEY k);
};

class TETRAS98_MAIN_THREE1:public TETRAS_MAIN
{
public:
	                        TETRAS98_MAIN_THREE1 (void);
	int                     search (KEY k);
};

class TETRAS98_MAIN_THREE2:public TETRAS_MAIN
{
public:
	                        TETRAS98_MAIN_THREE2 (void);
	int                     search (KEY k);
};

class TETRAS98_MAIN_THREE3:public TETRAS_MAIN
{
public:
	                        TETRAS98_MAIN_THREE3 (void);
	int                     search (KEY k);
};

//void *operator new (size_t size);
//void  operator delete (void *p);
char *strcat (char *dest, const char src); //strcatの一文字版
void block_data (XY a [4], int bfnt);
void logo (void);
void title (void);
void enter2 (XY a, int bfnt, int player, int mode);
void out2 (XY a, int bfnt, int player, int mode);
void put2 (XY a, int bfnt, int player, int mode);
void put2 (int y, BLOCK_LIST bl, int player, int mode);
void cls2 (XY a, int player, int mode);
int erase (BLOCK_LIST *bl, int player, int mode);
void next (int bman [120], int t, int player, int mode);
void attack (int lines, int ana, BLOCK_LIST *bl, int player, int mode);
