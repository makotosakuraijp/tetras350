#include <key.h>
#include <time.h>

void KEY::key (void)
{
	unsigned key_0;
	unsigned key_1;
	unsigned key_2;
	unsigned key_3;
	unsigned key_4;
	unsigned key_5;
	unsigned key_6;
	unsigned key_7;
	unsigned key_8;
	unsigned key_9;
	unsigned key_a;
	unsigned key_c;
	unsigned key_d;
	unsigned key_e;

	unsigned long tmp;
	time_t t1 = time (NULL);
	long T = 0;

	switch (m.machine)
	{
		case PC9801:
		//ƒOƒ‹[ƒv  b0      b1      b2      b3      b4      b5      b6      b7
		//
		//   ‚O     ESC     1       2       3       4       5       6       7
		//   ‚P     8       9       0       -       ^       \       BS      TAB
		//   ‚Q     Q       W       E       R       T       Y       U       I
		//   ‚R     O       P       ~       [       ØÀ°Ý    A       S       D
		//   ‚S     F       G       H       J       K       L       ;       :
		//   ‚T     ]       Z       X       C       V       B       N       M
		//   ‚U     ,       .       /       _       ½Íß°½   XFER    ROLLUP  ROLLDOWN
		//   ‚V     INS     DEL     ª      ©      ¨      «      HOMECLR HELP
		//   ‚W     -       /       7       8       9       *       4       5
		//   ‚X     6       +       1       2       3       =       0       ,
		//   ‚`     .       NFER
		//   ‚a
		//   ‚b     [STOP]  [COPY]  [f¥1]   [f¥2]   [f¥3]   [f¥4]   [f¥5]   [f¥6]
		//   ‚c     [f¥7]   [f¥8]   [f¥9]   [f¥10]
		//   ‚d     [SHIFT] [CAPS]  [¶Å]    [GRPH]  [CTRL]

			key_0 = pc98key (4, 0x00);
			key_1 = pc98key (4, 0x01);
			key_2 = pc98key (4, 0x02);
			key_3 = pc98key (4, 0x03);
			key_4 = pc98key (4, 0x04);
			key_5 = pc98key (4, 0x05);
			key_6 = pc98key (4, 0x06);
			key_7 = pc98key (4, 0x07);
			key_8 = pc98key (4, 0x08);
			key_9 = pc98key (4, 0x09);
			key_a = pc98key (4, 0x0a);
			key_c = pc98key (4, 0x0c);
			key_d = pc98key (4, 0x0d);
			key_e = pc98key (4, 0x0e);

			t [ES]         = rotate (key_0, 1);
			t [KEY_1]      = rotate (key_0, 2);
			t [KEY_2]      = rotate (key_0, 3);
			t [KEY_3]      = rotate (key_0, 4);
			t [KEY_4]      = rotate (key_0, 5);
			t [KEY_5]      = rotate (key_0, 6);
			t [KEY_6]      = rotate (key_0, 7);
			t [KEY_7]      = rotate (key_0, 8);

			t [KEY_8]      = rotate (key_1, 1);
			t [KEY_9]      = rotate (key_1, 2);
			t [KEY_0]      = rotate (key_1, 3);
			t [BOU]        = rotate (key_1, 4);
			t [YAMA]       = rotate (key_1, 5);
			t [YEN]        = rotate (key_1, 6);
			t [BS]         = rotate (key_1, 7);
			t [TAB]        = rotate (key_1, 8);

			t [KEY_Q]      = rotate (key_2, 1);
			t [KEY_W]      = rotate (key_2, 2);
			t [KEY_E]      = rotate (key_2, 3);
			t [KEY_R]      = rotate (key_2, 4);
			t [KEY_T]      = rotate (key_2, 5);
			t [KEY_Y]      = rotate (key_2, 6);
			t [KEY_U]      = rotate (key_2, 7);
			t [KEY_I]      = rotate (key_2, 8);

			t [KEY_O]      = rotate (key_3, 1);
			t [KEY_P]      = rotate (key_3, 2);
			t [ATTO]       = rotate (key_3, 3);
			t [HIDARIKAKU] = rotate (key_3, 4);
			t [CR]         = rotate (key_3, 5);
			t [KEY_A]      = rotate (key_3, 6);
			t [KEY_S]      = rotate (key_3, 7);
			t [KEY_D]      = rotate (key_3, 8);

			t [KEY_F]      = rotate (key_4, 1);
			t [KEY_G]      = rotate (key_4, 2);
			t [KEY_H]      = rotate (key_4, 3);
			t [KEY_J]      = rotate (key_4, 4);
			t [KEY_K]      = rotate (key_4, 5);
			t [KEY_L]      = rotate (key_4, 6);
			//t [SEMI_C]     = rotate (key_4, 7);
			//t [COLON]      = rotate (key_4, 8);

			t [MIGIKAKU]   = rotate (key_5, 1);
			t [KEY_Z]      = rotate (key_5, 2);
			t [KEY_X]      = rotate (key_5, 3);
			t [KEY_C]      = rotate (key_5, 4);
			t [KEY_V]      = rotate (key_5, 5);
			t [KEY_B]      = rotate (key_5, 6);
			t [KEY_N]      = rotate (key_5, 7);
			t [KEY_M]      = rotate (key_5, 8);

			t [TOUTEN]     = rotate (key_6, 1);
			t [KUTEN]      = rotate (key_6, 2);
			//t [SLASH]      = rotate (key_6, 3);
			t [NASI]       = rotate (key_6, 4);
			t [SPACE]      = rotate (key_6, 5);
			t [XFER]       = rotate (key_6, 6);
			//t [UP]         = rotate (key_6, 7);
			//t [DOWN]       = rotate (key_6, 8);

			t [INS]        = rotate (key_7, 1);
			t [DEL]        = rotate (key_7, 2);
			t [UE]         = rotate (key_7, 3);
			t [HIDARI]     = rotate (key_7, 4);
			t [MIGI]       = rotate (key_7, 5);
			t [SITA]       = rotate (key_7, 6);
			//t [HOME]       = rotate (key_7, 7);
			//t [HELP]       = rotate (key_7, 8);

			t [TEN_SE]     = rotate (key_8, 1);
			t [TEN_SR]     = rotate (key_8, 2);
			t [TEN_7]      = rotate (key_8, 3);
			t [TEN_8]      = rotate (key_8, 4);
			t [TEN_9]      = rotate (key_8, 5);
			t [TEN_KA]     = rotate (key_8, 6);
			t [TEN_4]      = rotate (key_8, 7);
			t [TEN_5]      = rotate (key_8, 8);

			t [TEN_6]      = rotate (key_9, 1);
			t [TEN_PL]     = rotate (key_9, 2);
			t [TEN_1]      = rotate (key_9, 3);
			t [TEN_2]      = rotate (key_9, 4);
			t [TEN_3]      = rotate (key_9, 5);
			t [TEN_I]      = rotate (key_9, 6);
			t [TEN_0]      = rotate (key_9, 7);
			t [TEN_KO]     = rotate (key_9, 8);

			t [TEN_PI]     = rotate (key_a, 1);
			t [NFER]       = rotate (key_a, 2);

			/*t [STOP]       = rotate (key_c, 1);
			t [COPY]       = rotate (key_c, 2);
			t [F1]         = rotate (key_c, 3);
			t [F2]         = rotate (key_c, 4);
			t [F3]         = rotate (key_c, 5);
			t [F4]         = rotate (key_c, 6);
			t [F5]         = rotate (key_c, 7);
			t [F6]         = rotate (key_c, 8);

			t [F7]         = rotate (key_d, 1);
			t [F8]         = rotate (key_d, 2);
			t [F9]         = rotate (key_d, 3);
			t [F10]        = rotate (key_d, 4);*/

			/*t [SHIFT]      = rotate (key_e, 1);
			t [CAPS]       = rotate (key_e, 2);
			t [KANA]       = rotate (key_e, 3);
			t [GRPH]       = rotate (key_e, 4);
			t [CTRL]       = rotate (key_e, 5);*/
			break;

		case PC_AT:
	//do
	//{
	tmp = vkey_scan ();
	/*unsigned key_0 = pc98key (4, 0x00);
	unsigned key_1 = pc98key (4, 0x01);
	unsigned key_2 = pc98key (4, 0x02);
	unsigned key_3 = pc98key (4, 0x03);
	unsigned key_4 = pc98key (4, 0x04);
	unsigned key_5 = pc98key (4, 0x05);
	unsigned key_6 = pc98key (4, 0x06);
	unsigned key_7 = pc98key (4, 0x07);
	unsigned key_8 = pc98key (4, 0x08);
	unsigned key_9 = pc98key (4, 0x09);
	unsigned key_a = pc98key (4, 0x0a);
	unsigned key_c = pc98key (4, 0x0c);
	unsigned key_d = pc98key (4, 0x0d);
	unsigned key_e = pc98key (4, 0x0e);*/

	t [ES]         = (tmp == 283);//rotate (key_0, 1);
	t [KEY_1]      = (tmp == 61);//rotate (key_0, 2);
	t [BS]         = (tmp == 592);//rotate (key_1, 7);
	t [CR]         = (tmp == 7181);//rotate (key_3, 5);
	t [KEY_A]      = (tmp == 7777);//rotate (key_3, 6);
	t [KEY_S]      = (tmp == 8051);//rotate (key_3, 7);
	t [KEY_D]      = (tmp == 8292);//rotate (key_3, 8);
	t [KEY_L]      = (tmp == 9836);//rotate (key_4, 6);
	t [SEMI_C]     = (tmp == 10043);//rotate (key_4, 7);
	t [COLON]      = (tmp == 10279);//10298);//rotate (key_4, 8);
	t [KEY_X]      = (tmp == 11640);//rotate (key_5, 3);
	t [SLASH]      = (tmp == 13615);//rotate (key_6, 3);
	t [SPACE]      = (tmp == 14624);//rotate (key_6, 5);
	t [HIDARI]     = (tmp == 19424);//rotate (key_7, 4);
	t [MIGI]       = (tmp == 19936);//rotate (key_7, 5);
	t [SITA]       = (tmp == 20704);//rotate (key_7, 6);
	//key [HOME]       = 0;//rotate (key_7, 7);
	// key [HELP]       = rotate (key_7, 8); // obsolete pc98 keyboard.
	//key [TEN_4]      = (tmp == 19200);//rotate (key_8, 7);
	//key [TEN_5]      = (tmp == 19456);//rotate (key_8, 8);
	//key [TEN_6]      = (tmp == 19712);//rotate (key_9, 1);
	//key [TEN_2]      = (tmp == 20480);//rotate (key_9, 4);
	//key [F1]         = (tmp == 15104);//rotate (key_c, 3); // obsolete pc98 keyboard. -> Function 1 key.
	//printf ("%lu\n", tmp);
	//}
	do
	{
	T++;
	tmp = vkey_scan ();
	t [ES]         = t [ES] || (tmp == 283);//rotate (key_0, 1);
	t [KEY_1]      = t [KEY_1] || (tmp == 61);//rotate (key_0, 2);
	t [BS]         = t [BS] || (tmp == 592);//rotate (key_1, 7);
	t [CR]         = t [CR] || (tmp == 7181);//rotate (key_3, 5);
	t [KEY_A]      = t [KEY_A] || (tmp == 7777);//rotate (key_3, 6);
	t [KEY_S]      = t [KEY_S] || (tmp == 8051);//rotate (key_3, 7);
	t [KEY_D]      = t [KEY_D] || (tmp == 8292);//rotate (key_3, 8);
	t [KEY_L]      = t [KEY_L] || (tmp == 9836);//rotate (key_4, 6);
	t [SEMI_C]     = t [SEMI_C] || (tmp == 10043);//rotate (key_4, 7);
	t [COLON]      = t [COLON] || (tmp == 10279);//10298);//rotate (key_4, 8);
	t [KEY_X]      = t [KEY_X] || (tmp == 11640);//rotate (key_5, 3);
	t [SLASH]      = t [SLASH] || (tmp == 13615);//rotate (key_6, 3);
	t [SPACE]      = t [SPACE] || (tmp == 14624);//rotate (key_6, 5);
	t [HIDARI]     = t [HIDARI] || (tmp == 19424);//rotate (key_7, 4);
	t [MIGI]       = t [MIGI] || (tmp == 19936);//rotate (key_7, 5);
	t [SITA]       = t [SITA] || (tmp == 20704);//rotate (key_7, 6);
	//key [HOME]       = 0;//rotate (key_7, 7);
	// key [HELP]       = rotate (key_7, 8); // obsolete pc98 keyboard.
	//key [TEN_4]      = (tmp == 19200);//rotate (key_8, 7);
	//key [TEN_5]      = (tmp == 19456);//rotate (key_8, 8);
	//key [TEN_6]      = (tmp == 19712);//rotate (key_9, 1);
	//key [TEN_2]      = (tmp == 20480);//rotate (key_9, 4);
	//key [F1]         = key [F1] || (tmp == 15104);//rotate (key_c, 3); // obsolete pc98 keyboard. -> Function 1 key.
	}
	while (T <= 9000);
			break;

		case FMR:
			break;
	}
}
