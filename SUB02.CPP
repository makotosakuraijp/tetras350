#include <tetras.h>

long RECORD::comp (RECORD s1, RECORD s2)
{
	return (s1.point - s2.point);
}

RECORD::RECORD (void)
{
	point = 10000;
	strcpy (name, "MIRAGE");
	strcpy (date, "96/04/17");
}

int RECORD_LIST::members = 0;

void RECORD_LIST::load (char *filename, RECORD_LIST *a)
{
	if (members <= 0)
		exit (6);

	if (!file_exist (filename))
		save (filename);

	if (!file_ropen (filename))
		exit (3);

	int r; //リードデータ
	int i;
	int k;

	char ***ch; //ch [members] [10] [50]に相当する操作を行う。
	try
	{
		ch = new char **[members];
		for (i = 0; i < members; i++)
		{
			ch [i] = new char *[10];
			for (k = 0; k < 10; k++)
			{
				ch [i] [k] = new char [50];
				strcpy (ch [i] [k], ""); //chの内容を全てきれいにする。
			}
		}
	}
	catch (xalloc)
	{
		//printf ("RECORD_LIST::load：chでエラー\n");
		exit (10);
	}

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
			for (r = -2; r != -1 && r != '\n'; )
			{
				r = file_getc ();

				switch (r)
				{
					case -1: //EOFに達しているとき
						if (strlen (ch [members - 1] [9]) == 0)
							exit (4);
						break;

					case '\n':
					case '\r':
						break;

					default:
						strcat (ch [i] [k], (char) r);
				}
			}

	file_close (); //ここまででファイルからの読み出し作業は終了

	char *p;
	char *q;
	char j [3] [9]; //変換する一歩手前の状態で保存
	int f;

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
		{
			p = ch [i] [k];

			for (f = 0; f <= 2; f++) //３つの要素に分解
			{
				while (isspace (*p) || (*p) == NULL) p++;

				q = p;

				while (!isspace (*q) && (*q) != NULL) q++;

				if (q - p + 1 >= 10)
					exit (7);

				strcpy (j [f], "");

				for ( ; p != q; p++)
					strcat (j [f], *p);
			}

			if (strlen (j [0]) >= 7)
				exit (8);

			a [i].t [k].point = atol (j [0]); //ここで変換
			strcpy (a [i].t [k].name, j [1]);
			strcpy (a [i].t [k].date, j [2]);
		}

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
			delete [] ch [i] [k];

	for (i = 0; i < members; i++)
		delete [] ch [i];
	delete [] ch;
}

void RECORD_LIST::save (char *filename) //デフォルトの値でソコアファイルを作る。
{
	if (file_exist (filename))
		if (!file_delete (filename))
			exit (1);

	if (!file_create (filename))
	{
		//printf ("ファイルが書き込めません。\n");
		//printf ("異常終了します。\n");
		exit (2);
	}

	char ch [50];
	RECORD_LIST q;
	int r; //１０を法としてiに合同な０以上の整数の中で最も小さい物。

	for (int i = 0; i <= 29; i++)
	{
		r = (i % 10);
		sprintf (ch, "%ld %s %s\n", q.t [r].point, q.t [r].name, q.t [r].date);
		file_write (ch, strlen (ch));
	}

	file_close ();
}

void RECORD_LIST::save (char *filename, RECORD_LIST *a)
{
	if (members <= 0)
		exit (6);

	if (file_exist (filename))
		if (!file_delete (filename))
			exit (1);

	if (!file_create (filename))
	{
		//printf ("ファイルが書き込めません。\n");
		//printf ("以上終了します。\n");
		exit (2);
	}

	int i;
	int k;

	char ch [50];//臨時文字列変数

	for (i = 0; i < members; i++)
		for (k = 0; k < 10; k++)
		{
			sprintf (ch, "%ld %s %s\n", a [i].t [k].point, a [i].t [k].name, a [i].t [k].date);
			file_write (ch, strlen (ch));
		}

	file_close ();
}
