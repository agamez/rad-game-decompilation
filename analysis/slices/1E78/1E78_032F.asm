;; fn1E78_032F: 1E78:032F
;;   Called from:
;;     1E78:000B (in fn1E78_0000)
;;     1E78:001E (in fn1E78_0000)
fn1E78_032F proc
	mov	bx,sp
	push	ds
	lds	di,ss:[bx+4h]
	mov	word ptr [di+2h],0D7B0h
	mov	word ptr [di+4h],80h
	lea	ax,[di+80h]
	mov	[di+0Ch],ax
	mov	[di+0Eh],ds
	mov	word ptr [di+10h],35Ah
	mov	[di+12h],cs
	mov	byte ptr [di+30h],0h
	pop	ds
	retf	4h
1E78:035A                               8B DC 1E 36 C5 7F           ...6..
1E78:0360 04 B8 92 03 BB 70 04 8B CB 81 7D 02 B1 D7 74 0A .....p....}...t.
1E78:0370 C7 45 02 B2 D7 B8 3F 04 8B D8 89 45 14 8C 4D 16 .E....?....E..M.
1E78:0380 89 5D 18 8C 4D 1A 89 4D 1C 8C 4D 1E 33 C0 1F CA .]..M..M..M.3...
1E78:0390 04 00 55 8B EC C4 7E 06 26 8B 55 04 4A 4A 26 8B ..U...~.&.U.JJ&.
1E78:03A0 75 08 26 C4 7D 0C 33 DB C6 06 B9 B8 00 0E E8 5C u.&.}.3........\
1E78:03B0 FF B9 01 00 3C 08 74 34 3C 13 74 30 3C 04 74 44 ....<.t4<.t0<.tD
1E78:03C0 49 3C 1B 74 27 3C 01 74 23 3C 06 74 37 3C 1A 74 I<.t'<.t#<.t7<.t
1E78:03D0 46 3C 0D 74 4F 3C 20 72 CF 3B DA 74 CB 26 88 01 F<.tO< r.;.t.&..
1E78:03E0 43 E8 98 00 3B DE 76 C0 8B F3 EB BC 0B DB 74 B8 C...;.v.......t.
1E78:03F0 B0 08 E8 87 00 B0 20 E8 82 00 B0 08 E8 7D 00 4B ...... ......}.K
1E78:0400 E2 EA EB A4 3B DE 74 A0 26 8A 01 3C 20 72 99 E8 ....;.t.&..< r..
1E78:0410 6A 00 43 E2 EF EB 91 80 3E A9 B8 00 74 8A 26 88 j.C.....>...t.&.
1E78:0420 01 43 EB 0A E8 4E 00 26 C7 01 0D 0A 43 43 C4 7E .C...N.&....CC.~
1E78:0430 06 33 C0 26 89 45 08 26 89 5D 0A 5D CA 04 00 8B .3.&.E.&.].]....
1E78:0440 DC 36 C4 7F 04 26 8B 4D 08 26 29 4D 08 E3 19 26 .6...&.M.&)M...&
1E78:0450 C4 7D 0C 80 3E AA B8 00 75 0B 26 8A 05 E8 1C 00 .}..>...u.&.....
1E78:0460 47 E2 F7 EB 03 E8 9C 00 E8 D8 FC 33 C0 CA 04 00 G..........3....
1E78:0470 33 C0 CA 04 00                                  3....
