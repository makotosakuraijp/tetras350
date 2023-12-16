#include <tetras.h>

TETRAS98_MAIN_ONE1::TETRAS98_MAIN_ONE1 (void)
{
	keydata [0].setup (KEY_A, KEY_L,HIDARI, TEN_4);
	keydata [1].setup (KEY_D, COLON,  MIGI, TEN_6);
	keydata [2].setup (KEY_X, SLASH,  SITA, TEN_2);
	keydata [3].setup (KEY_S,SEMI_C,    CR, TEN_5);
}

#pragma warn -pia
int TETRAS98_MAIN_ONE1::search (KEY k)
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
					if (errlv = mv.move_enable (bl, XY (-1, 0)) && differ >= 40)
					{
						mv.move (XY (-1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 1:
					if (errlv = mv.move_enable (bl, XY (1, 0)) && differ >= 40)
					{
						mv.move (XY (1, 0), errlv);
						gage [i] = count;
					}
					break;
				case 2:
					if (errlv = mv.move_enable (bl, XY (0, -1)) && differ >= 27)
					{
						mv.move (XY (0, -1), errlv);
						gage [i] = count;
					}
					if (errlv == 0 && differ >= 27)
						ret_value = 1;
					break;
				case 3:
					if (errlv = mv.turn_enable (bl) && differ >= 75)
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

void TETRAS98_MAIN_ONE::go (void)
{
	palette_entry_rgb ("tetras.rgb");
	dac_100 ();
	//palette_100 ();
	dac_show ();
	//palette_show ();
	long counter = 0;
	int i, j, o, o2;
	GRAPH gr;
	//vtext_clear ();
	gr.clear ();
	gr.box (39,  15, 200, 320, 1);
	vga4_bfnt_puts (40,  384, 16, "MIRAGE SOFTWARE", 4);
	vga4_bfnt_puts (440, 384, 16, "Since 1996", 5);
	randomize ();

	int bman [120];
	int bmg = 0;

	for (i = 0; i < 120; i++)
		bman [i] = (random (7) * 4) + 1;

	KEY k;
	player = new TETRAS98_MAIN_ONE1;
	//mfxddn_bgm_play_mtlib ("X_MAS.MUD");

	player->mv.change (3, 20, bman [bmg], 1, 2);
	player->mv.enter ();
	next (bman, bmg + 1, 1, 1);

	int bottom = 0;
	int errlv;
	long gage = 0;
	long differ;
	unsigned mus_wait = 0;
	XY w [4];

	for (k.key (); k.t [ES] == 0 && player->arrival; k.key ())
	{
		mus_wait++;
		mus_wait %= 10000;
		//if (mus_wait == 0 && mfxddn_get_playstatus () != 0)
		//	mfxddn_bgm_play_mtlib ("X_MAS.MUD");
		bottom = player->search (k);
		if (counter == 65535L)
			counter = 0;
		else
			counter++;
		if (player->arrival)
		{
			differ = counter - gage + 65535L;
			differ %= 65536L;
			if (differ >= 500 || bottom == 1)
			{
				errlv = player->mv.move_enable (player->bl, XY (0, -1));
				if (errlv)
					player->mv.move (XY (0, -1), errlv);
				else
				{
					block_data (w, player->mv.bfnt);
					for (j = 0; j < 4; j++)
					{
						w [j].x += player->mv.r.x;
						w [j].y += player->mv.r.y;
						player->bl.blist [w [j].y].t [w [j].x] = 1;
						player->bl.blist [w [j].y].bfnt [w [j].x] = player->mv.bfnt;
					}
					bmg++;
					bmg %= 120;
					next (bman, bmg + 1, 1, 2);
					player->mv.change (3, 20, bman [bmg], 1, 2);
					if (!(player->mv.move_enable (player->bl, XY(0, 0))))
					{
						player->mv.enter ();
						player->arrival = 0;
					}
					for (o = 0; o < 19; o++)
						if (player->bl.blist [o].all () && player->arrival)
							o2 = 1;
					if (o2 == 1 && player->arrival)
						erase (&(player->bl), 1, 2);
					o2 = 0;
				}
				gage = counter;
				bottom = 0;
			}
		}
	}
	//mfxddn_bgm_fadeout (2);
}
