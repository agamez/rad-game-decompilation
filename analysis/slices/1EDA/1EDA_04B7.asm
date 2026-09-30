;; fn1EDA_04B7: 1EDA:04B7
;;   Called from:
;;     13C8:0121 (in fn13C8_0111)
fn1EDA_04B7 proc
	mov	si,sp
	mov	es,ss:[si+2h]
	cmp	dx,es:[di+2h]
	jg	04CAh

l1EDA_04C3:
	jl	04D9h

l1EDA_04C5:
	cmp	ax,es:[di]
	jc	04D9h

l1EDA_04CA:
	cmp	dx,es:[di+6h]
	jl	04D8h

l1EDA_04D0:
	jg	04D9h

l1EDA_04D2:
	cmp	ax,es:[di+4h]
	ja	04D9h

l1EDA_04D8:
	retf

l1EDA_04D9:
	mov	ax,0C9h
	jmp	00E2h
1EDA:04DF                                              05                .
1EDA:04E0 00 02 2B C4 73 09 F7 D8 3B 06 7E 53 72 01 CB B8 ..+.s...;.~Sr...
1EDA:04F0 CA 00 E9 ED FB                                  .....
