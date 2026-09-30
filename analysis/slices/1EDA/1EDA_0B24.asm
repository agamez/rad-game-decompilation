;; fn1EDA_0B24: 1EDA:0B24
;;   Called from:
;;     0800:064A (in fn0800_0619)
;;     0800:12A7 (in fn0800_11EF)
;;     0800:1300 (in fn0800_11EF)
;;     0800:259C (in fn0800_2401)
;;     0800:2863 (in fn0800_2827)
;;     0800:2C37 (in fn0800_2C0C)
;;     0800:2C57 (in fn0800_2C0C)
;;     0800:2D5E (in fn0800_2C0C)
;;     0800:2D98 (in fn0800_2C0C)
;;     0800:2E12 (in fn0800_2C0C)
;;     0800:2E67 (in fn0800_2C0C)
;;     0800:2EB3 (in fn0800_2C0C)
;;     0800:30A8 (in fn0800_2C0C)
;;     0800:40C1 (in fn0800_3D9D)
;;     1229:045A (in fn1229_039D)
;;     1229:046B (in fn1229_039D)
;;     1229:06A3 (in fn1229_061B)
;;     1229:1119 (in fn1229_0DCC)
;;     1AB8:0613 (in fn1AB8_05D3)
;;     1AB8:0677 (in fn1AB8_05D3)
;;     1AB8:06F6 (in fn1AB8_06CA)
;;     1AB8:078D (in fn1AB8_06CA)
fn1EDA_0B24 proc
	cld
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+8h]
	les	di,ss:[bx+4h]
	lodsb
	mov	ah,es:[di]
	inc	di
	mov	cl,al
	cmp	cl,ah
	jbe	0B3Eh

l1EDA_0B3C:
	mov	cl,ah

l1EDA_0B3E:
	or	cl,cl
	jz	0B48h

l1EDA_0B42:
	xor	ch,ch
	rep cmpsb
	jnz	0B4Ah

l1EDA_0B48:
	cmp	al,ah

l1EDA_0B4A:
	mov	ds,dx
	retf	8h
