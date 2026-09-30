;; fn11C8_0000: 11C8:0000
;;   Called from:
;;     11C8:020D (in fn11C8_0092)
fn11C8_0000 proc
	enter	204h,0h
	mov	byte ptr [bp+0FEFEh],0h
	mov	al,[bp+4h]
	mov	[bp+0FEFDh],al
	mov	al,1h
	cmp	al,[bp+0FEFDh]
	ja	005Ah

l11C8_0018:
	mov	[bp-1h],al
	jmp	0020h

l11C8_001D:
	inc	byte ptr [bp-1h]

l11C8_0020:
	lea	di,[bp+0FDFCh]
	push	ss
	push	di
	mov	ax,[bp+6h]
	and	ax,0Fh
	mov	di,ax
	mov	al,[di+4DC4h]
	push	ax
	call	far 1EDAh:0B4Fh
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	0FFh
	push	1h
	call	far 1EDAh:0B7Ch
	mov	ax,[bp+6h]
	shr	ax,4h
	mov	[bp+6h],ax
	mov	al,[bp-1h]
	cmp	al,[bp+0FEFDh]
	jnz	001Dh

l11C8_005A:
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	ret	4h
11C8:0071    20 53 6F 75 6E 64 20 42 6C 61 73 74 65 72 20   Sound Blaster 
11C8:0080 64 82 74 65 63 74 82 65 20 61 75 20 70 6F 72 74 d.tect.e au port
11C8:0090 20 24                                            $
