;; fn1229_0735: 1229:0735
;;   Called from:
;;     1229:0FAE (in fn1229_0DCC)
;;     1229:1012 (in fn1229_0DCC)
;;     1229:106B (in fn1229_0DCC)
;;     1229:10A9 (in fn1229_0DCC)
fn1229_0735 proc
	enter	79Ch,0h
	call	far 133Fh:0137h
	lea	di,[bp+0F964h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,68h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,10h
	push	ax
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,68h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FA64h]
	push	ss
	push	di
	mov	di,6C3h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,6C9h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp+0FC64h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp+0FC64h],0h
	jz	07CFh

l1229_07BD:
	lea	di,[bp+0FC64h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l1229_07CF:
	lea	di,[bp+0F864h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,128h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,10h
	push	ax
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,128h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FA64h]
	push	ss
	push	di
	mov	di,6CDh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,6D3h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0F964h]
	push	ss
	push	di
	mov	di,4FC4h
	push	ds
	push	di
	push	1h
	mov	al,[5CBBh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,1Eh
	sub	ax,dx
	push	ax
	call	far 1EDAh:0A6Bh
	call	far 1EDAh:0AACh
	mov	di,6D5h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp+0FB64h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp+0FB64h],0h
	jz	088Eh

l1229_087C:
	lea	di,[bp+0FB64h]
	push	ss
	push	di
	mov	di,5CBBh
	push	ds
	push	di
	push	1Eh
	call	far 1EDAh:0A39h

l1229_088E:
	mov	di,6D8h
	push	cs
	push	di
	mov	al,[5CDAh]
	push	ax
	call	050Ah
	mov	[5CDAh],al
	mov	di,6E5h
	push	cs
	push	di
	mov	al,[5CDBh]
	push	ax
	call	050Ah
	mov	[5CDBh],al
	mov	di,6F2h
	push	cs
	push	di
	mov	al,[5CDDh]
	push	ax
	call	050Ah
	mov	[5CDDh],al
	mov	di,6FFh
	push	cs
	push	di
	mov	al,[5CDEh]
	push	ax
	call	050Ah
	mov	[5CDEh],al
	mov	di,70Ch
	push	cs
	push	di
	mov	al,[5CDFh]
	push	ax
	call	050Ah
	mov	[5CDFh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	08E5h

l1229_08E0:
	mov	byte ptr [5CDCh],0Ah

l1229_08E5:
	mov	di,719h
	push	cs
	push	di
	mov	al,[5CDCh]
	push	ax
	call	050Ah
	mov	[5CDCh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	0900h

l1229_08FB:
	mov	byte ptr [5CDCh],0Ah

l1229_0900:
	push	0Fh
	call	far 1AB8h:1C32h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,726h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A9h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	call	far 1EDAh:04A9h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:108Ch
	add	sp,4h
	call	far 1EDAh:04A9h
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1185h
	call	far 1EDAh:04A9h
	or	al,al
	jz	09C9h

l1229_0969:
	mov	di,72Eh
	push	cs
	push	di
	lea	di,[bp+0FD66h]
	push	ss
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	byte ptr [bp+0FD8Ch],63h
	mov	byte ptr [bp+0FD8Dh],63h
	mov	byte ptr [bp+0FD8Eh],0Ah
	mov	byte ptr [bp+0FD8Fh],63h
	mov	byte ptr [bp+0FD90h],0h
	mov	byte ptr [bp+0FD91h],0h
	mov	di,4DD6h
	push	ds
	push	di
	lea	di,[bp+0FD92h]
	push	ss
	push	di
	push	1EDh
	call	far 1EDAh:0953h
	mov	byte ptr [bp+0FD6Dh],0h
	lea	di,[bp-80h]
	push	ss
	push	di
	lea	di,[bp+0FD66h]
	push	ss
	push	di
	call	far 1EDAh:108Ch
	add	sp,4h
	call	far 1EDAh:04A9h

l1229_09C9:
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:116Ah
	call	far 1EDAh:04A9h
	sub	ax,2h
	sbb	dx,0h
	mov	[5CB2h],al
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A9h
	call	far 133Fh:0141h
	leave
	ret
1229:09F7                      01 30                             .0
