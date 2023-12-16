#include <tetras.h>

void TETRAS98_MAIN_TWO::go (void)
{
	palette_entry_rgb ("tetras.rgb");
	//palette_100 ();
	dac_100 ();
	//palette_show ();
	dac_show ();
	int tet_ana [2];
	int att_line [2] = {0, 0};
	long counter = 0;
	int i, i2, j, o, o2;
	GRAPH gr;
	//vtext_clear ();
	gr.clear ();
	gr.box (39,  15, 200, 320, 1);
	gr.box (439, 15, 600, 320, 1);
	vga4_bfnt_puts (40,  384, 16, "MIRAGE SOFTWARE", 4);
	vga4_bfnt_puts (440, 384, 16, "Since 1996", 5);
	randomize ();

	int bman [120];
	int bmg [3] = {0, 0};

	for (i = 0; i < 120; i++)
		bman [i] = (random (7) * 4) + 1;
	tet_ana [0] = random (10);
	tet_ana [1] = random (10);

	KEY k;
	player [0] = new TETRAS98_MAIN_TWO1;
	player [1] = new TETRAS98_MAIN_TWO2;
	//mfxddn_bgm_play_mtlib ("X_MAS.MUD");

	player [0]->mv.change (3, 20, bman [bmg [0]], 1, 2);
	player [1]->mv.change (3, 20, bman [bmg [1]], 2, 2);
	player [0]->mv.enter ();
	player [1]->mv.enter ();
	next (bman, bmg [0] + 1, 1, 2);
	next (bman, bmg [1] + 1, 2, 2);

	int bottom [2] = {0, 0};
	int errlv;
	long gage [2] = {0, 0};
	long differ;
	unsigned mus_wait = 0;
	XY w [4];
	int quit = 1;

	for (k.key (); k.t [ES] == 0 && quit; k.key ())
	{
		mus_wait++;
		mus_wait %= 10000;
		//if (mus_wait == 0 && mfxddn_get_playstatus () != 0)
		//	mfxddn_bgm_replay ();
		//mfxddn_bgm_play_mtlib ("X_MAS.MUD");
		bottom [0] = player [0]->search (k);
		bottom [1] = player [1]->search (k);
		if (counter == 65535L)
			counter = 0;
		else
			counter++;
		for (i = 0; i < 2; i++)
		{
			if (player [i]->arrival)
			{
				differ = counter - gage [i] + 65535L;
				differ %= 65536L;
				if (differ >= 500 || bottom [i] == 1)
				{
					errlv = player [i]->mv.move_enable (player [i]->bl, XY (0, -1));
					if (errlv)
						player [i]->mv.move (XY (0, -1), errlv);
					else
					{
						block_data (w, player [i]->mv.bfnt);
						for (j = 0; j < 4; j++)
						{
							w [j].x += player [i]->mv.r.x;
							w [j].y += player [i]->mv.r.y;
							player [i]->bl.blist [w [j].y].t [w [j].x] = 1;
							player [i]->bl.blist [w [j].y].bfnt [w [j].x] = player [i]->mv.bfnt;
						}
						bmg [i]++;
						bmg [i] %= 120;
						next (bman, bmg [i] + 1, i + 1, 2);
						player [i]->mv.change (3, 20, bman [bmg [i]], i + 1, 2);
						if (!(player [i]->mv.move_enable (player [i]->bl, XY(0, 0))))
						{
							player [i]->mv.enter ();
							player [i]->arrival = 0;
						}
						for (o = 0; o < 19; o++)
							if (player [i]->bl.blist [o].all () && player [i]->arrival)
								o2 = 1;
						if (o2 == 1 && player [i]->arrival)
						{
							errlv = erase (&(player [i]->bl), i + 1, 2);
							for (i2 = 0; i2 < 2; i2++)
								if (i2 != i)
									att_line [i2] += errlv;
						}
						o2 = 0;
						if (att_line [i] != 0 && player [i]->arrival)
						{
							attack (att_line [i], tet_ana [i], &(player [i]->bl), i + 1, 2);
							att_line [i] = 0;
						}
					}
					gage [i] = counter;
					bottom [i] = 0;
				}
			}
		}
		if (player [0]->arrival + player [1]->arrival != 2)
			quit = 0;
	}
	//mfxddn_bgm_fadeout (2);
}
