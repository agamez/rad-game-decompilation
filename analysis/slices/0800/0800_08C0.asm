;; fn0800_08C0: 0800:08C0
;;   Called from:
;;     0800:279C (in fn0800_2401)
;;     0800:27D5 (in fn0800_2401)
;;     0800:2A83 (in fn0800_2827)
;;     0800:2ABC (in fn0800_2827)
;;     0800:303F (in fn0800_2C0C)
;;     0800:3065 (in fn0800_2C0C)
;;     0800:35B2 (in fn0800_31B7)
;;     0800:35D8 (in fn0800_31B7)
fn0800_08C0 proc
	enter	2h,0h
	mov	byte ptr [bp-1h],0h
	cmp	byte ptr [53DBh],0h
	ja	08D1h

l0800_08CF:
	jmp	08E4h

l0800_08D1:
	call	far 0C74h:522Ch
	or	al,al
	jnz	08DCh

l0800_08DA:
	jmp	08E4h

l0800_08DC:
	mov	byte ptr [bp-1h],1h
	dec	byte ptr [53DBh]

l0800_08E4:
	mov	al,[bp-1h]
	leave
	ret
