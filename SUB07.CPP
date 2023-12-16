#include <tetras.h>

void KEYDATA::setup (int a, int b, int c, int d)
{
	data [0] = a;
	data [1] = b;
	data [2] = c;
	data [3] = d;
}

int KEYDATA::operator ==(KEY k)
{
	int i;
	int d = 0;
	for (i = 0; i < 4; i++)
		d += k.t [data [i]];
	if (d == 0)
		return 0;
	return 1;
}

TETRAS98_MAIN_THREE1::TETRAS98_MAIN_THREE1 (void)
{
	keydata [0].setup (KEY_A, KEY_A, KEY_A, KEY_A);
	keydata [1].setup (KEY_D, KEY_D, KEY_D, KEY_D);
	keydata [2].setup (KEY_X, KEY_X, KEY_X, KEY_X);
	keydata [3].setup (KEY_S, KEY_S, KEY_S, KEY_S);
}

TETRAS98_MAIN_THREE2::TETRAS98_MAIN_THREE2 (void)
{
	keydata [0].setup (KEY_L, KEY_L, KEY_L, KEY_L);
	keydata [1].setup (COLON, COLON, COLON, COLON);
	keydata [2].setup (SLASH,SLASH,SLASH,SLASH);
	keydata [3].setup (SEMI_C,SEMI_C,SEMI_C,SEMI_C);
}

TETRAS98_MAIN_THREE3::TETRAS98_MAIN_THREE3 (void)
{
	keydata [0].setup (HIDARI,TEN_4, TEN_4, TEN_4);
	keydata [1].setup (MIGI,  TEN_6, TEN_6, TEN_6);
	keydata [2].setup (SITA,  TEN_2, TEN_2, TEN_2);
	keydata [3].setup (CR,    TEN_5, TEN_5, TEN_5);
}

#pragma warn -pia

int TETRAS98_MAIN_THREE1::search (KEY k)
{
	if (arrival == 0)
		return 0;
	int i, errlv;
	int ret_value = 0;
	long differ;
	if (count == 65535L)
		count = 0;
	else
		count++;
	for (i = 0; i < 4; i++)
		if (keydata [i] == k)
		{
			differ = (long) (count - gage [i] + 65535L);
			differ %= 65536L;
			switch (i)
			{
				case 0:
					if (errlv = mv.move_enable (bl, XY (-1, 0)) && differ >= 35)
					{
						mv.move (XY (-1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 1:
					if (errlv = mv.move_enable (bl, XY (1, 0)) && differ >= 35)
					{
						mv.move (XY (1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 2:
					if (errlv = mv.move_enable (bl, XY (0, -1)) && differ >= 22)
					{
						mv.move (XY (0, -1), errlv);
						gage [i] = count;
					}
					if (errlv == 0 && differ >= 22)
						ret_value = 1;
					break;
				case 3:
					if (errlv = mv.turn_enable (bl) && differ >= 70)
					{
						mv.turn (errlv);
						gage [i] = count;
					}
					break;
				default:
					errlv++;
			}
		}
	return ret_value;
}

int TETRAS98_MAIN_THREE2::search (KEY k)
{
	if (arrival == 0)
		return 0;
	int i, errlv;
	int ret_value = 0;
	long differ;
	if (count == 65535L)
		count = 0;
	else
		count++;
	for (i = 0; i < 4; i++)
		if (keydata [i] == k)
		{
			differ = (long) (count - gage [i] + 65535L);
			differ %= 65536L;
			switch (i)
			{
				case 0:
					if (errlv = mv.move_enable (bl, XY (-1, 0)) && differ >= 35)
					{
						mv.move (XY (-1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 1:
					if (errlv = mv.move_enable (bl, XY (1, 0)) && differ >= 35)
					{
						mv.move (XY (1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 2:
					if (errlv = mv.move_enable (bl, XY (0, -1)) && differ >= 22)
					{
						mv.move (XY (0, -1), errlv);
						gage [i] = count;
					}
					if (errlv == 0 && differ >= 22)
						ret_value = 1;
					break;
				case 3:
					if (errlv = mv.turn_enable (bl) && differ >= 70)
					{
						mv.turn (errlv);
						gage [i] = count;
					}
					break;
				default:
					errlv++;
			}
		}
	return ret_value;
}

int TETRAS98_MAIN_THREE3::search (KEY k)
{
	if (arrival == 0)
		return 0;
	int i, errlv;
	int ret_value = 0;
	long differ;
	if (count == 65535L)
		count = 0;
	else
		count++;
	for (i = 0; i < 4; i++)
		if (keydata [i] == k)
		{
			differ = (long) (count - gage [i] + 65535L);
			differ %= 65536L;
			switch (i)
			{
				case 0:
					if (errlv = mv.move_enable (bl, XY (-1, 0)) && differ >= 35)
					{
						mv.move (XY (-1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 1:
					if (errlv = mv.move_enable (bl, XY (1, 0)) && differ >= 35)
					{
						mv.move (XY (1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 2:
					if (errlv = mv.move_enable (bl, XY (0, -1)) && differ >= 22)
					{
						mv.move (XY (0, -1), errlv);
						gage [i] = count;
					}
					if (errlv == 0 && differ >= 22)
						ret_value = 1;
					break;
				case 3:
					if (errlv = mv.turn_enable (bl) && differ >= 70)
					{
						mv.turn (errlv);
						gage [i] = count;
					}
					break;
				default:
					errlv++;
			}
		}
	return ret_value;
}

#pragma warn +pia
