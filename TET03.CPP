#include <tetras.h>

void logo (void)
{
	//char p [48] = {0, 0, 0,  8, 0, 0,  0, 8, 0,  8, 8, 0,  0, 0, 8,  8, 0, 8,  0, 8, 8,	12,12,12,
	//			   8, 8, 8, 15, 0, 0,  0,15, 0, 15,15, 0,  0, 0,15, 15, 0,15,  0,15,15, 15,15,15};
	//graph_start ();
	vgc_start ();
	//palette_init ();
	dac_init ();
	char bak [16] [3];
	for (int i = 0; i < 16; i++)
		for (int t = 0; t < 3; t++)
			bak [i] [t] = Palettes [i] [t];
	MagHeader mag;
	void far *buf; //[6000];
	char far *ptr;
	int y;
	mag_load_pack ("MIRAGE.MAG", &mag, &buf);

	vga4_start (0x0e,640,400);vga_vzoom_off();
	palette_set_all_16 (&mag.palette);
	//palette_set_all_16 (&mag.palette);
	//palette_set_all_16 (p);
	//palette_show ();
	dac_show ();
	ptr = (char *) buf;
	//palette_black ();
	//dac_black ();
	for (y = mag.y1; y <= mag.y2; ++y)
	{
		vga4_pack_put_8 (mag.x1 & ~7, y, buf, mag.xsize);
		buf = FPADD (buf, mag.xsize/2);
	}
	//mfxddn_bgm_play_mtlib ("IFLOGO.MUD");
	//palette_black_in (6);
	//dac_black_in (6);
	mag_free (&mag, buf);
	for (i = 0; i < 90; i++)
		vga_vsync_wait ();
	//palette_black_out (3);
	//dac_black_out (3);
	//graph_clear ();
	vga4_clear ();
	//palette_100 ();
	dac_100 ();
	palette_set_all (bak);
	palette_show ();
}
