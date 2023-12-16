#ifndef KEY_H_
#define KEY_H_
#include <machine.h>
#include <pc98.h>

/*英字キー*/
/*const KEY_A      = 29;
const KEY_B      = 45;
const KEY_C      = 43;
const KEY_D      = 31;
const KEY_E      = 18;
const KEY_F      = 32;
const KEY_G      = 33;
const KEY_H      = 34;
const KEY_I      = 23;
const KEY_J      = 35;
const KEY_K      = 36;
const KEY_L      = 37;
const KEY_M      = 47;
const KEY_N      = 46;
const KEY_O      = 24;
const KEY_P      = 25;
const KEY_Q      = 16;
const KEY_R      = 19;
const KEY_S      = 30;
const KEY_T      = 20;
const KEY_U      = 22;
const KEY_V      = 44;
const KEY_W      = 17;
const KEY_X      = 42;
const KEY_Y      = 21;
const KEY_Z      = 41;*/

/*テンキー*/
/*const TEN_0      = 78;
const TEN_1      = 74;
const TEN_2      = 75;
const TEN_3      = 76;
const TEN_4      = 70;
const TEN_5      = 71;
const TEN_6      = 72;
const TEN_7      = 66;
const TEN_8      = 67;
const TEN_9      = 68;
const TEN_SE     = 64;
const TEN_SR     = 65;
const TEN_KA     = 69;
const TEN_PL     = 73;
const TEN_I      = 77;
const TEN_KO     = 79;
const TEN_PI     = 80;*/

/*ファンクションキー*/
/*const F1         = 98;
const F2         = 99;
const F3         = 100;
const F4         = 101;
const F5         = 102;
const F6         = 103;
const F7         = 104;
const F8         = 105;
const F9         = 106;
const F10        = 107;
const VF1        = 82;
const VF2        = 83;
const VF3        = 84;
const VF4        = 85;
const VF5        = 86;*/

/*特殊キー*/
/*const INS        = 56;
const DEL        = 57;
const UP         = 54;
const DOWN       = 55;
const HOME       = 62;
const HELP       = 63;
const CR         = 28;
const SPACE      = 52;
const XFER       = 53;
const NFER       = 81;
const TAB        = 15;
const ES         = 0;
const BS         = 14;

const STOP       = 96;
const COPY       = 97;
const SHIFT      = 112;
const CAPS       = 113;
const KANA       = 114;
const GRPH       = 115;
const CTRL       = 116;*/

/*矢印キー*/
/*const UE         = 58;
const SITA       = 61;
const HIDARI     = 59;
const MIGI       = 60;*/

/*その他*/
/*const KEY_1      = 1;
const KEY_2      = 2;
const KEY_3      = 3;
const KEY_4      = 4;
const KEY_5      = 5;
const KEY_6      = 6;
const KEY_7      = 7;
const KEY_8      = 8;
const KEY_9      = 9;
const KEY_0      = 10;
const BOU        = 11;
const YAMA       = 12;
const YEN        = 13;
const ATTO       = 26;
const HIDARIKAKU = 27;
const SEMI_K     = 38;
const KORON      = 39;
const MIGIKAKU   = 40;
const TOUTEN     = 48;
const KUTEN      = 49;
const SURUSH     = 50;
const NASI       = 51;*/


const ESC = '\033';
const TRUE = 0;
const FALSE = -1;

/*英字キー*/
const KEY_A = 97;
const KEY_B = 98;
const KEY_C = 99;
const KEY_D = 100;
const KEY_E = 101;
const KEY_F = 102;
const KEY_G = 103;
const KEY_H = 104;
const KEY_I = 105;
const KEY_J = 106;
const KEY_K = 107;
const KEY_L = 108;
const KEY_M = 109;
const KEY_N = 110;
const KEY_O = 111;
const KEY_P = 112;
const KEY_Q = 113;
const KEY_R = 114;
const KEY_S = 115;
const KEY_T = 116;
const KEY_U = 117;
const KEY_V = 118;
const KEY_W = 119;
const KEY_X = 120;
const KEY_Y = 121;
const KEY_Z = 122;

/*テンキー*/
const TEN_0 = 78;
const TEN_1 = 74;
const TEN_2 = 75;
const TEN_3 = 76;
const TEN_4 = 70;
const TEN_5 = 71;
const TEN_6 = 72;
const TEN_7 = 66;
const TEN_8 = 67;
const TEN_9 = 68;
const TEN_SE = 64;
const TEN_SR = 65;
const TEN_KA = 69;
const TEN_PL = 73;
const TEN_I = 77;
const TEN_KO = 79;
const TEN_PI = 80;

/*ファンクションキー*/
/*const F1 = 59;
const F2 = 60;
const F3 = 61;
const F4 = 62;
const F5 = 63;
const F6 = 64;
const F7 = 65;
const F8 = 66;
const F9 = 67;
const F10 = 68;
const VF1 = 82;
const VF2 = 83;
const VF3 = 84;
const VF4 = 85;
const VF5 = 86;*/

/*特殊キー*/
const INS = 82;
const DEL = 83;
//const UP = 54;
//const DOWN = 55;
//const HOME = 62;
//const HELP = 63;
const CR = 13;
const SPACE = 32;
const XFER = 53;
const NFER = 81;
const TAB = 9;
const int ES = 27;
const int BS = 8;

//const STOP = 96;
//const COPY = 97;
//const SHIFT = 112;
//const CAPS = 113;
//const KANA = 114;
//const GRPH = 115;
//const CTRL = 116;

/*矢印キー*/
const UE = 72;
const SITA = 80;
const HIDARI = 75;
const MIGI = 77;

/*その他*/
const KEY_1 = 49;
const KEY_2 = 50;
const KEY_3 = 51;
const KEY_4 = 52;
const KEY_5 = 53;
const KEY_6 = 54;
const KEY_7 = 55;
const KEY_8 = 56;
const KEY_9 = 57;
const KEY_0 = 58;
const BOU = 45;
const YAMA = 94;
const YEN = 92;
const ATTO = 64;
const HIDARIKAKU = 91;
const SEMI_C = 59;
const COLON = 58;
const MIGIKAKU = 93;
const TOUTEN = 44;
const KUTEN = 46;
const SLASH = 47;
const NASI = 95;

class KEY
{
	MACHINE         m;
	int             rotate (int a, int b);
	int             save_cbrk;
public:
	unsigned        t [200];
			KEY (void);
	                ~KEY ();
	void            key (int *scan);
	void            key (int *scan, int *shift);
	void            key (void);
	void            keyclear (void);
};
#endif
