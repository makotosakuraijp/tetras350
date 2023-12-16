#include <tetras.h>

void STATUS::went (void)
{
	//vtext_clear ();
	//gotoxy (6, 2);
	//printf ("ÇPÇoÇkÇ`ÇxÅ@Å@Å@Å@Å@ÇQÇoÇkÇ`ÇxÅ@Å@Å@Å@Å@ÇRÇoÇkÇ`ÇxÅ@Å@Å@Å@Å@ÇdÇwÇhÇs\n");

	font_entry_bfnt("CHARACT.BFT");
	vga4_bfnt_puts (45, 15, 16, "1Play     2Play     3Play     Exit", 1);
	it.box (0, 7, 639, 39, _BLUE);
	it.box (1, 8, 638, 38, _GREEN);
}

void STATUS_LIST::del (int a)
{
	r [a] -> del ();
}

void STATUS_LIST::go (int a)
{
	r [a] -> go (relist [a]);
}

STATUS_LIST::STATUS_LIST (STATUS *a, STATUS *b, STATUS *c, STATUS *d)
{
	RECORD_LIST::members = 3;
	relist [0].load ("TETRAS.SCR", relist);
	r [0] = a;
	r [1] = b;
	r [2] = c;
	r [3] = d;

	//mfxddn_bgm_play_mtlib ("setup.mud");
	cu = 0;
	a -> went ();
	//it.box (41, 15, 120, 31, _BLUE, _GREEN);
	a -> go (relist [0]);
}

STATUS_LIST::~STATUS_LIST ()
{
	delete r [0];
	delete r [1];
	delete r [2];
	delete r [3];
}

void STATUS_LIST::move (int a)
{
	const f1 [4] = {41,  201, 361, 521}; //ògÇÃç∂í[
	const f2 [4] = {120, 280, 440, 584}; //ògÇÃâEí[
	it.box (f1 [cu], 15, f2 [cu], 31, _BLACK, _BLACK);
	del (cu);
	font_entry_bfnt("CHARACT.BFT");
	vga4_bfnt_puts (45, 15, 16, "1Play     2Play     3Play     Exit", 1);
	cu = (cu + a + 4) % 4;
	it.box (f1 [cu], 16, f2 [cu], 31, _BLUE);
	it.box (f1 [cu]-1, 15, f2 [cu]-1, 30, _GREEN);
	//it.box (f1 [cu], 15, f2 [cu], 31, _BLUE, _GREEN);
	go (cu);
}

void STATUS_LIST::go (void)
{
	TETRAS98_MAIN_ONE   a1;
	TETRAS98_MAIN_TWO   a2;
	TETRAS98_MAIN_THREE a3;
	int quit = 1;
	int r;
	//palette_entry_rgb ("literal.rgb");
	//palette_init ();
	dac_init ();
	//palette_100 ();
	dac_100 ();
	//palette_show ();
	dac_show ();
	move (0);
	RECORD tmp;

	while (quit)
	{
		for (k.key (&r); r != CR; k.key (&r))
		{
			switch (r)
			{
				case HIDARI:
					move (-1);
					vga_vsync_wait ();
					vga_vsync_wait ();
					break;

				case MIGI:
					move (1);
					vga_vsync_wait ();
					vga_vsync_wait ();
					break;
			}
		}

		//mfxddn_bgm_fadeout (1);

		if (cu != 3)
		{
			if (cu == 0)
				a1.go ();
			if (cu == 1)
				a2.go ();
			if (cu == 2)
				a3.go ();
			it.clear ();
			//vtext_clear ();
			//palette_entry_rgb ("literal.rgb");
			//palette_init ();
			dac_init ();
			//palette_100 ();
			dac_100 ();
			//palette_show ();
			dac_show ();
			//gotoxy (6, 2);
			//printf ("ÇPÇoÇkÇ`ÇxÅ@Å@Å@Å@Å@ÇQÇoÇkÇ`ÇxÅ@Å@Å@Å@Å@ÇRÇoÇkÇ`ÇxÅ@Å@Å@Å@Å@ÇdÇwÇhÇs\n");
			it.box (0, 7, 639, 39, _BLUE);
			it.box (1, 8, 638, 38, _GREEN);
			it.box (41, 15, 120, 31, _BLUE, _GREEN);
			//mfxddn_bgm_play_mtlib ("setup.mud");
			r = 0;
			cu = 0;
			move (0);
		}
		else
			quit = 0;
	}

	it.clear ();
	//vtext_clear ();
}

void STATUS1::del (void)
{
	it.box (0, 64, 639, 399, _BLACK, _BLACK); //STATUSÉNÉâÉXÇ≈íËã`çœÇ›ÅB
};

void STATUS1::go (RECORD_LIST p)
{
	font_entry_bfnt("CHARACT.BFT");
	vga4_bfnt_puts (112, 64, 16, "Score   Name       Date", 15);
	vga4_bfnt_puts (48,  80, 16, "-----------------------------", 15);
	vga4_bfnt_puts (48, 256, 16, "-----------------------------", 15);
	
	for (int i = 0; i <= 9; i++)
	{
		sprintf (ch, "%2d:%6ld %-9s %9s", i + 1, p.t [i].point, p.t [i].name, p.t [i].date);
		vga4_bfnt_puts (48, 96 + i * 16, 16, ch, i + 1);
	}
}

void STATUS2::del (void)
{
}

#pragma warn -par
void STATUS2::go (RECORD_LIST p)
{
//pÇÕâΩÇ…Ç‡égÇÌÇ»Ç¢ÅB
}
#pragma warn +par
