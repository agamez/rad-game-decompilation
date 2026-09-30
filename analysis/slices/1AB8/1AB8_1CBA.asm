;; fn1AB8_1CBA: 1AB8:1CBA
;;   Called from:
;;     0800:3DF1 (in fn0800_3D9D)
;;     0800:409B (in fn0800_3D9D)
;;     0800:439C (in fn0800_4255)
;;     1229:0DF0 (in fn1229_0DCC)
;;     13E2:0063 (in fn13E2_003B)
;;     13E2:00DE (in fn13E2_0080)
;;     13E2:012B (in fn13E2_00FB)
;;     13E2:0174 (in fn13E2_00FB)
fn1AB8_1CBA proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	or	ah,80h
	mov	bx,[bp+0Ah]
	mov	cx,[bp+8h]
	mov	dx,[bp+6h]
	mov	si,1Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	8h
