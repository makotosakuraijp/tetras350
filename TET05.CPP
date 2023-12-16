#include <tetras.h>

void enter2 (XY a, int bfnt, int player, int mode)
{
	XY k [4];
	block_data (k, bfnt);
	int i;

	for (i = 0; i < 4; i++)
	{
		k [i].x += a.x;
		k [i].y += a.y;
		if (k [i].x >= 0 && k [i].x < 10 && k [i].y <= 18 && k [i].y >= 0)
			put2 (k [i], bfnt, player, mode);
	}
}

void out2 (XY a, int bfnt, int player, int mode)
{
	XY k [4];
	block_data (k, bfnt);
	int i;

	for (i = 0; i < 4; i++)
	{
		k [i].x += a.x;
		k [i].y += a.y;
		if (k [i].x >= 0 && k [i].x < 10 && k [i].y <= 18 && k [i].y >= 0)
			cls2 (k [i], player, mode);
	}
}

void put2 (int y, BLOCK_LIST bl, int player, int mode)
{
	int i;
	for (i = 0; i < 10; i++)
		put2 (XY (i, y), bl.blist [y].bfnt [i], player, mode);
}

void put2 (XY a, int bfnt, int player, int mode)
{
	const col [8] = {1, 4, 3, 2, 5, 6, 13, 8};
	GRAPH it;
	DRAW d;
	int tmp, color, x, y;
	x = d.XY_to_x (a, player, mode);
	y = d.XY_to_y (a);
	if (bfnt != -1)
	{
		tmp = bfnt;
		tmp /= 4;
		color = col [tmp];
		it.box (x + 1, y + 1, x + 14, y + 14, color, color);
		it.line (x, y, x + 15, y, 15);
		it.line (x, y + 1, x, y + 14, 15);
	}
	else
		it.box (x, y, x + 15, y + 15, 0, 0);
}

void cls2 (XY a, int player, int mode)
{
	if (a.y < 0 || a.y > 18 || a.x < 0 || a.x > 9)
		return;
	GRAPH it;
	DRAW d;
	int x = d.XY_to_x (a, player, mode);
	int y = d.XY_to_y (a);
	it.box (x, y, x + 15, y + 15, 0, 0);
}

int erase (BLOCK_LIST *bl, int player, int mode)
{
	const er [4] = {0, 1, 2, 4};
	GRAPH it;
	it.copypage (1);
	it.visual (1);
	it.active (0);

	int howmany = 0;
	int place [4];
	int i, t;

	for (i = 0; i <= 37; i++)
		if (bl->blist [i].all ())
		{
			place [howmany] = i;
			howmany++;
		}

	for (i = 0; i < 10; i++)
		for (t = 0; t < howmany; t++)
			cls2 (XY (i, place [t]), player, mode);

	if (howmany == 0)
		return 0;

	switch (howmany)
	{
		case 1:
			for (i = place [0] + 1; i <= 37; i++)
				bl->blist [i - 1] = bl->blist [i];
			bl->blist [37] = 0;
			break;

		case 2:
			t = place [1] - place [0];
			if (t == 1)
				for (i = place [1] + 1; i <= 37; i++)
					bl->blist [i - 2] = bl->blist [i];
			else
				if (t == 2)
				{
					bl->blist [place [0]] = bl->blist [place [0] + 1];
					for (i = place [0] + 3; i <= 37; i++)
						bl->blist [i - 2] = bl->blist [i];
				}
			else
			{
				bl->blist [place [0]]     = bl->blist [place [0] + 1];
				bl->blist [place [0] + 1] = bl->blist [place [0] + 2];
				for (i = place [0] + 4; i <= 37; i++)
					bl->blist [i - 2] = bl->blist [i];
			}
			bl->blist [36] = 0;
			bl->blist [37] = 0;
			break;

		case 3:
			t = place [2] - place [0];
			if (t == 2)
				for (i = place [2] + 1; i <= 37; i++)
					bl->blist [i - 3] = bl->blist [i];
			else
				if (place [1] - place [0] == 2)
				{
					bl->blist [place [0]] = bl->blist [place [0] + 1];
					for (i = place [0] + 4; i <= 37; i++)
						bl->blist [i - 3] = bl->blist [i];
				}
			else
			{
				bl->blist [place [0]] = bl->blist [place [0] + 2];
				//bl->blist [place [1]] = bl->blist [place [1] + 2];
				for (i = place [0] + 4; i <= 37; i++)
					bl->blist [i - 3] = bl->blist [i];
			}
			bl->blist [35] = 0;
			bl->blist [36] = 0;
			bl->blist [37] = 0;
			break;

		case 4:
			for (i = place [3] + 1; i <= 37; i++)
				bl->blist [i - 4] = bl->blist [i];
			bl->blist [34] = 0;
			bl->blist [35] = 0;
			bl->blist [36] = 0;
			bl->blist [37] = 0;
			break;
	}

	for (i = 0; i < 6; i++)
	{
		delay (30);
		it.visual (0);
		delay (30);
		it.visual (1);
	}

	if (place [0] < 19)
		for (i = place [0]; i < 19; i++)
			put2 (i, *bl, player, mode);

	it.visual (0);

	return er [howmany - 1];
}

void next (int bman [120], int t, int player, int mode)
{
	DRAW d;
	GRAPH it;
	t %= 120;
	int x = d.XY_to_x (XY (10, 18), player, mode) + 1;
	int y = d.XY_to_y (XY (10, 18));
	int bfnt = bman [t];
	bfnt /= 4;
	bfnt += 35;
	it.box (x, y, x + 31, y + 31, 0, 0);
	vga4_super_put (x, y, bfnt);
}

void attack (int lines, int ana, BLOCK_LIST *bl, int player, int mode)
{
	GRAPH it;
	it.copypage (1);
	it.active (0);
	it.visual (1);
	int i, j;
	for (i = 37; i >= lines; i--)
		bl->blist [i] = bl->blist [i - lines];
	for (i = 0; i < lines; i++)
		for (j = 0; j < 10; j++)
		{
			if (j != ana)
			{
				bl->blist [i].t    [j] = 1;
				bl->blist [i].bfnt [j] = 28;
			}
			else
			{
				bl->blist [i].t    [j] = 0;
				bl->blist [i].bfnt [j] = -1;
			}
		}
	for (i = 0; i < 19; i++)
		put2 (i, *bl, player, mode);
	it.visual (0);
}
