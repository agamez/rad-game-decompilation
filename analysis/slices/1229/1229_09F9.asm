;; fn1229_09F9: 1229:09F9
;;   Called from:
;;     1229:0B8E (in fn1229_0AA8)
;;     1229:0BC3 (in fn1229_0AA8)
;;     1229:0BDF (in fn1229_0AA8)
;;     1229:0BFB (in fn1229_0AA8)
;;     1229:0C17 (in fn1229_0AA8)
fn1229_09F9 proc
	enter	200h,0h
	mov	al,[bp+4h]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	push	0h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0F26h
	cmp	byte ptr [bp+4h],0Ah
	jnc	0A45h

l1229_0A1C:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	mov	di,9F7h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l1229_0A45:
	cmp	byte ptr [bp+4h],64h
	jnc	0A74h

l1229_0A4B:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	mov	di,9F7h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l1229_0A74:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	ret	2h
1229:0A8B                                  01 20 05 54 49            . .TI
1229:0A90 4D 45 3A 06 20 50 55 53 48 3A 06 20 42 4C 4F 57 ME:. PUSH:. BLOW
1229:0AA0 3A 06 20 50 41 53 53 3A                         :. PASS:
