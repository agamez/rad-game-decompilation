;; fn0800_04CC: 0800:04CC
;;   Called from:
;;     0800:09DF (in fn0800_09C2)
;;     0800:0A09 (in fn0800_09C2)
;;     0800:19C8 (in fn0800_184C)
;;     0800:2625 (in fn0800_2401)
;;     0800:262D (in fn0800_2401)
;;     0800:2954 (in fn0800_2827)
;;     0800:295C (in fn0800_2827)
;;     0800:2DF2 (in fn0800_2C0C)
;;     0800:2DFA (in fn0800_2C0C)
;;     0800:3398 (in fn0800_31B7)
;;     0800:341D (in fn0800_31B7)
;;     0800:3425 (in fn0800_31B7)
;;     0800:4405 (in fn0800_4255)
fn0800_04CC proc
	enter	2h,0h
	mov	al,[bp+4h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	leave
	ret	2h
