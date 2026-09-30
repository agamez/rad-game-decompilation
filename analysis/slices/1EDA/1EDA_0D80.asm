;; fn1EDA_0D80: 1EDA:0D80
;;   Called from:
;;     0800:161F (in fn0800_149F)
;;     0800:162F (in fn0800_149F)
;;     0800:1802 (in fn0800_166D)
;;     0800:1812 (in fn0800_166D)
;;     0C74:07D9 (in fn0C74_076B)
;;     0C74:07EC (in fn0C74_076B)
;;     0C74:0829 (in fn0C74_076B)
;;     0C74:083F (in fn0C74_076B)
;;     0C74:085C (in fn0C74_076B)
;;     0C74:0885 (in fn0C74_076B)
;;     0C74:0924 (in fn0C74_076B)
;;     0C74:095B (in fn0C74_076B)
;;     0C74:0A91 (in fn0C74_0A35)
;;     0C74:0AB6 (in fn0C74_0A35)
;;     0C74:0AED (in fn0C74_0A35)
;;     0C74:0B03 (in fn0C74_0A35)
;;     0C74:0B20 (in fn0C74_0A35)
;;     0C74:0B48 (in fn0C74_0A35)
;;     0C74:0BE6 (in fn0C74_0A35)
;;     0C74:0C1D (in fn0C74_0A35)
fn1EDA_0D80 proc
	call	0DCFh
	xor	ax,ax
	mov	bx,sp
	mov	bx,ss:[bx+4h]
	or	bx,bx
	jz	0D93h

l1EDA_0D8F:
	xchg	dx,ax
	div	bx
	xchg	dx,ax

l1EDA_0D93:
	retf	2h
1EDA:0D96                   E8 36 00 93 B8 80 00 B9 20 00       .6...... .
1EDA:0DA0 F6 C6 80 75 0A D1 E3 D1 D2 FE C8 E2 F3 32 C0 80 ...u.........2..
1EDA:0DB0 E6 7F CB E8 19 00 CD 3C 9F 06 CD 0D CD 37 06 82 .......<.....7..
1EDA:0DC0 53 CD 35 E1 CD 35 FD CD 39 D9 CD 3D CB E1 FF    S.5..5..9..=...
