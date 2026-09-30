;; fn0C74_00DB: 0C74:00DB
;;   Called from:
;;     0C74:0198 (in fn0C74_011E)
;;     0C74:0286 (in fn0C74_020C)
fn0C74_00DB proc
	push	bp
	mov	bp,sp
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	call	far 1AB8h:1B3Eh
	leave
	ret	0Ah
0C74:00FC                                     01 30 00 E2             .0..
0C74:0100 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0C74:0110 00 00 00 00 00 00 00 00 00 00 00 00 00 00       ..............
