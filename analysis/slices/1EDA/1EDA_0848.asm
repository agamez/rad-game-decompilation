;; fn1EDA_0848: 1EDA:0848
;;   Called from:
;;     0800:2C8E (in fn0800_2C0C)
;;     0800:2CC4 (in fn0800_2C0C)
;;     0800:2CDF (in fn0800_2C0C)
;;     0800:2CFA (in fn0800_2C0C)
;;     0800:2D15 (in fn0800_2C0C)
;;     0C74:0409 (in fn0C74_03D4)
;;     133F:00A7 (in fn133F_0056)
;;     133F:00BD (in fn133F_0056)
;;     133F:00D3 (in fn133F_0056)
;;     13E2:01F8 (in fn13E2_0193)
;;     1AB8:00A7 (in fn1AB8_008B)
;;     1AB8:00C5 (in fn1AB8_008B)
fn1EDA_0848 proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	call	07B6h
	jnz	085Fh

l1EDA_0855:
	mov	al,0Dh
	call	07DAh
	mov	al,0Ah
	call	07DAh

l1EDA_085F:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	call	0879h
	pop	bp
	retf	4h
