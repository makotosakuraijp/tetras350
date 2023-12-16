#include <tetras.h>

TETRAS98_MAIN_TWO1::TETRAS98_MAIN_TWO1 (void)
{
	keydata [0].setup (KEY_A, KEY_A, KEY_L, KEY_L);
	keydata [1].setup (KEY_D, KEY_D, COLON, COLON);
	keydata [2].setup (KEY_X, KEY_X, SLASH, SLASH);
	keydata [3].setup (KEY_S, KEY_S,SEMI_C,SEMI_C);
}

TETRAS98_MAIN_TWO2::TETRAS98_MAIN_TWO2 (void)
{
	keydata [0].setup (HIDARI, HIDARI, TEN_4, TEN_4);
	keydata [1].setup (MIGI,   MIGI,   TEN_6, TEN_6);
	keydata [2].setup (SITA,   SITA,   TEN_2, TEN_2);
	keydata [3].setup (UE,     UE,     CR,    TEN_5);
}

#pragma warn -pia

int TETRAS98_MAIN_TWO1::search (KEY k)
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
					if (errlv = mv.move_enable (bl, XY (-1, 0)) && differ >= 37)
					{
						mv.move (XY (-1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 1:
					if (errlv = mv.move_enable (bl, XY (1, 0)) && differ >= 37)
					{
						mv.move (XY (1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 2:
					if (errlv = mv.move_enable (bl, XY (0, -1)) && differ >= 24)
					{
						mv.move (XY (0, -1), errlv);
						gage [i] = count;
					}
					if (errlv == 0 && differ >= 24)
						ret_value = 1;
					break;
				case 3:
					if (errlv = mv.turn_enable (bl) && differ >= 72)
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

int TETRAS98_MAIN_TWO2::search (KEY k)
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
					if (errlv = mv.move_enable (bl, XY (-1, 0)) && differ >= 37)
					{
						mv.move (XY (-1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 1:
					if (errlv = mv.move_enable (bl, XY (1, 0)) && differ >= 37)
					{
						mv.move (XY (1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 2:
					if (errlv = mv.move_enable (bl, XY (0, -1)) && differ >= 24)
					{
						mv.move (XY (0, -1), errlv);
						gage [i] = count;
					}
					if (errlv == 0 && differ >= 24)
						ret_value = 1;
					break;
				case 3:
					if (errlv = mv.turn_enable (bl) && differ >= 72)
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
