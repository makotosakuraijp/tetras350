#include <tetras.h>

TETRAS98::TETRAS98 (void)
{
	super_entry_bfnt ("tet01.bft");
	super_entry_bfnt ("tet02.bft");
	super_entry_bfnt ("tet03.bft");
	super_entry_bfnt ("tet04.bft");
	super_entry_bfnt ("tet05.bft");
	super_entry_bfnt ("tet06.bft");
	super_entry_bfnt ("tet07.bft");
	super_entry_bfnt ("enter.bft");
	super_entry_bfnt ("tet_next.bft");
	text_systemline_hide ();
	_text_cursor_off (); //カーソルを消す。（ＰＣ９８専用版）
	text_clear ();
	key_beep_off ();
	//vsync_start ();
	//musicbuf = new char [MFXDDN_MAXMUDSIZE];
	//mfxddn_bgm_init2 (musicbuf);
	gaiji_entry_bfnt ("CHARACT.BFT");
	logo (); //logo内では、自前でMACHINE変数を用意する。
	title ();
}

TETRAS98::~TETRAS98 ()
{
	delete [] musicbuf;
	key_beep_on ();
	//vsync_end ();
	_text_cursor_on (); //カーソルを戻す。（ＰＣ９８専用版）
	text_systemline_show ();
}

void TETRAS98::go (void)
{
	try
	{
		STATUS_LIST st (new STATUS1 (), new STATUS1 (), new STATUS1 (), new STATUS2 ());
		st.go ();
	}
	catch (xalloc)
	{
		printf ("TETRAS98::go：stでエラー\n");
		exit (9);
	}
}

TETRASat::TETRASat (void)
{
	super_entry_bfnt ("tet01.bft");
	super_entry_bfnt ("tet02.bft");
	super_entry_bfnt ("tet03.bft");
	super_entry_bfnt ("tet04.bft");
	super_entry_bfnt ("tet05.bft");
	super_entry_bfnt ("tet06.bft");
	super_entry_bfnt ("tet07.bft");
	super_entry_bfnt ("enter.bft");
	super_entry_bfnt ("tet_next.bft");
	//vtext_systemline_hide ();
	//_text_cursor_off (); //カーソルを消す。（ＰＣ９８専用版）
	//text_clear ();
	//key_beep_off ();
	//vsync_start ();
	//musicbuf = new char [MFXDDN_MAXMUDSIZE];
	//mfxddn_bgm_init2 (musicbuf);
	//gaiji_entry_bfnt ("CHARACT.BFT");
	logo (); //logo内では、自前でMACHINE変数を用意する。
	title ();
}

TETRASat::~TETRASat ()
{
	//delete [] musicbuf;
	//key_beep_on ();
	//vsync_end ();
	//_text_cursor_on (); //カーソルを戻す。（ＰＣ９８専用版）
	//text_systemline_show ();
}

void TETRASat::go (void)
{
	try
	{
		STATUS_LIST st (new STATUS1 (), new STATUS1 (), new STATUS1 (), new STATUS2 ());
		st.go ();
	}
	catch (xalloc)
	{
		printf ("TETRASat::go：stでエラー\n");
		exit (9);
	}
}
