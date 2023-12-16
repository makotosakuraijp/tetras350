#include <tetras.h>

void title (void)
{
	KEY k;
	char bak [16] [3];
	for (int i = 0; i < 16; i++)
		for (int t = 0; t < 3; t++)
			bak [i] [t] = Palettes [i] [t];
	MagHeader mag;
	void far *buf;
	char far *ptr;
	int y;
	int err;

	printf("%d\n", err=mag_load_pack ("tetras.mag", &mag, &buf));

	vga4_start (0x0e,640,400);vga_vzoom_off();
	palette_set_all_16 (&mag.palette);
	//palette_show ();
	dac_show ();
	ptr = (char *) buf;
	for (y = mag.y1; y <= mag.y2; ++y)
	{
		vga4_pack_put_8 (mag.x1 & ~7, y, buf, mag.xsize);
		buf = FPADD (buf, mag.xsize / 2);
	}
	mag_free (&mag, buf);

	//mfxddn_bgm_play ("UEHR.MUD");
	//mfxddn_bgm_play_mtlib ("UEHR.MUD");
	for (k.key (); k.t [SPACE] == 0; k.key ()){}
	//mfxddn_bgm_fadeout (2);

	palette_set_all (bak);
}
