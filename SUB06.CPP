#include <tetras.h>

MOVER::MOVER (void)
{
	change (0, 0, 0, 0, 0);
}

void MOVER::enter (void)
{
	//it.enter (r, bfnt, player, mode);
	enter2 (r, bfnt, player, mode);
}

void MOVER::in (void)
{
	it.in (r, bfnt, player, mode);
}

void MOVER::out (void)
{
	//it.out (r, bfnt, player, mode);
	out2 (r, bfnt, player, mode);
}

void MOVER::change (int _x, int _y, int _bfnt, int _player, int _mode)
{
	r.x = _x;
	r.y = _y;
	bfnt = _bfnt;
	type = (bfnt % 4);
	player = _player;
	mode = _mode;
}

int MOVER::can_put (BLOCK_LIST a, MOVER b)
{
	//オーバーラップするかどうかで、
	//オーバーラップしないと真、
	//オーバーラップすると疑を返す。
	XY k [4];
	block_data (k, b.bfnt);
	int g [4];
	int h [4];
	int i;
	int errlv = 1;
	for (i = 0; i < 4; i++)
	{
		g [i] = k [i].x + b.r.x;
		if (g [i] < 0 || g [i] > 9)
			return 0;
	}
	for (i = 0; i < 4; i++)
	{
		h [i] = k [i].y + b.r.y;
		if (h [i] < 0 || h [i] > 37) //$$Yet 上に出てしまっている場合の処理は後回し
			return 0;
		if (h [i] > 16)
			errlv = 2;
	}
	if (a.blist[h[0]].t[g[0]]==0 && a.blist[h[1]].t[g[1]]==0 && a.blist[h[2]].t[g[2]]==0 && a.blist[h[3]].t[g[3]]==0)
		return errlv;
	else
		return 0;
}

int MOVER::turn_enable (BLOCK_LIST a)
{
	MOVER tmp = (*this);
	tmp.type += 3; //タイプを-1つまり、+3する。
	tmp.type %= 4;
	tmp.bfnt -= type; //typeの変化に従ってbfntも変える。
	tmp.bfnt += tmp.type;
	return (can_put (a, tmp));
}

void MOVER::turn (int errlv)
{
	out (); //今表示されている物を消す。
	MOVER tmp = (*this);
	tmp.type += 3; //タイプを-1つまり、+3する。
	tmp.type %= 4;
	tmp.bfnt -= type; //typeの変化に従ってbfntも変える。
	tmp.bfnt += tmp.type;
		(*this) = tmp;
	//if (errlv == 1)
	//	in ();
	//else
	enter ();
}

int MOVER::move_enable (BLOCK_LIST a, XY b)
{
	MOVER tmp = (*this);
	tmp.r.x += b.x;
	tmp.r.y += b.y;
	return (can_put (a, tmp));
}

void MOVER::move (XY a, int errlv)
{
	out (); //今表示されている物を消す。
	r.x += a.x;
	r.y += a.y;
	//if (errlv == 1)
	//	in ();
	//else
	enter ();
}
