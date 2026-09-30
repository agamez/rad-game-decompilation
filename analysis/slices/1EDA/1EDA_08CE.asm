;; fn1EDA_08CE: 1EDA:08CE
;;   Called from:
;;     0800:2C89 (in fn0800_2C0C)
;;     0800:2CBF (in fn0800_2C0C)
;;     0800:2CDA (in fn0800_2C0C)
;;     0800:2CF5 (in fn0800_2C0C)
;;     0800:2D10 (in fn0800_2C0C)
;;     0C74:0404 (in fn0C74_03D4)
;;     11C8:01FC (in fn11C8_0092)
;;     11C8:0212 (in fn11C8_0092)
;;     133F:008D (in fn133F_0056)
;;     133F:00A2 (in fn133F_0056)
;;     133F:00B8 (in fn133F_0056)
;;     133F:00CE (in fn133F_0056)
;;     13E2:01F3 (in fn13E2_0193)
;;     1AB8:00A2 (in fn1AB8_008B)
;;     1AB8:00C0 (in fn1AB8_008B)
fn1EDA_08CE proc
	push	bp
	mov	bp,sp
	push	ds
	les	di,[bp+0Ch]
	push	es
	push	di
	call	07B6h
	jnz	0901h

l1EDA_08DC:
	lds	si,[bp+8h]
	mov	cx,[bp+6h]
	cld
	lodsb
	xor	ah,ah
	sub	cx,ax
	jle	08F6h

l1EDA_08EA:
	mov	al,20h
	call	07DAh
	loop	08EAh

l1EDA_08F1:
	mov	al,[si-1h]
	xor	ah,ah

l1EDA_08F6:
	mov	cx,ax
	jcxz	0901h

l1EDA_08FA:
	cld
	lodsb
	call	07DAh
	loop	08FAh

l1EDA_0901:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	pop	ds
	pop	bp
	retf	6h
1EDA:090C                                     B1 03 EB 0A             ....
1EDA:0910 B1 02 EB 06 B1 01 EB 02                         ........
