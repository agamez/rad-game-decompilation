;;; Segment 11C8 (11C8:0000)

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

;; fn11C8_0092: 11C8:0092
;;   Called from:
;;     11C8:0397 (in fn11C8_0394)
fn11C8_0092 proc
	enter	10Eh,0h
	call	far 1E78h:01C0h
	mov	byte ptr [bp-0Dh],0h
	mov	byte ptr [bp-1h],1h

l11C8_00A3:
	cmp	byte ptr [bp-1h],7h
	jc	00ACh

l11C8_00A9:
	jmp	0229h

l11C8_00AC:
	cmp	byte ptr [bp-0Dh],0h
	jz	00B5h

l11C8_00B2:
	jmp	0229h

l11C8_00B5:
	mov	al,[bp-1h]
	xor	ah,ah
	shl	ax,4h
	add	ax,200h
	mov	[5978h],ax
	xor	ax,ax
	mov	[bp-8h],ax
	mov	byte ptr [bp-0Eh],0h

l11C8_00CC:
	cmp	word ptr [bp-8h],201h
	jnc	00F1h

l11C8_00D3:
	cmp	byte ptr [bp-0Eh],0h
	jnz	00F1h

l11C8_00D9:
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	in	al,dx
	and	al,80h
	or	al,al
	jnz	00ECh

l11C8_00E8:
	mov	byte ptr [bp-0Eh],1h

l11C8_00EC:
	inc	word ptr [bp-8h]
	jmp	00CCh

l11C8_00F1:
	cmp	byte ptr [bp-0Eh],0h
	jnz	00FAh

l11C8_00F7:
	jmp	01EAh

l11C8_00FA:
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	in	al,dx
	mov	[bp-3h],al
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	mov	al,0D3h
	out	dx,al
	mov	word ptr [bp-0Ah],1h
	jmp	011Bh

l11C8_0118:
	inc	word ptr [bp-0Ah]

l11C8_011B:
	cmp	word ptr [bp-0Ah],1000h
	jnz	0118h

l11C8_0122:
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-4h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	mov	al,1h
	out	dx,al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	mov	al,0h
	out	dx,al
	mov	byte ptr [bp-2h],0h

l11C8_0178:
	xor	ax,ax
	mov	[bp-8h],ax
	mov	byte ptr [bp-0Eh],0h

l11C8_0181:
	cmp	word ptr [bp-8h],201h
	jnc	01A6h

l11C8_0188:
	cmp	byte ptr [bp-0Eh],0h
	jnz	01A6h

l11C8_018E:
	mov	ax,[5978h]
	add	ax,0Eh
	mov	dx,ax
	in	al,dx
	and	al,80h
	cmp	al,80h
	jnz	01A1h

l11C8_019D:
	mov	byte ptr [bp-0Eh],1h

l11C8_01A1:
	inc	word ptr [bp-8h]
	jmp	0181h

l11C8_01A6:
	cmp	byte ptr [bp-0Eh],0h
	jz	01BDh

l11C8_01AC:
	mov	ax,[5978h]
	add	ax,0Ah
	mov	dx,ax
	in	al,dx
	cmp	al,0AAh
	jnz	01BDh

l11C8_01B9:
	mov	byte ptr [bp-0Dh],1h

l11C8_01BD:
	inc	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],10h
	jz	01CCh

l11C8_01C6:
	cmp	byte ptr [bp-0Eh],0h
	jz	0178h

l11C8_01CC:
	cmp	byte ptr [bp-0Eh],0h
	jnz	01EAh

l11C8_01D2:
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	mov	al,[bp-3h]
	out	dx,al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	mov	al,[bp-4h]
	out	dx,al

l11C8_01EA:
	cmp	byte ptr [bp-0Dh],0h
	jz	0223h

l11C8_01F0:
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,71h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	push	word ptr [5978h]
	push	3h
	call	0000h
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:086Ch
	mov	byte ptr [5976h],1h
	jmp	0226h

l11C8_0223:
	inc	byte ptr [bp-1h]

l11C8_0226:
	jmp	00A3h

l11C8_0229:
	cmp	byte ptr [bp-0Dh],0h
	jnz	0234h

l11C8_022F:
	mov	byte ptr [5976h],0h

l11C8_0234:
	leave
	ret

;; fn11C8_0236: 11C8:0236
;;   Called from:
;;     11C8:034E (in fn11C8_033B)
;;     11C8:038C (in fn11C8_0354)
fn11C8_0236 proc
	push	bp
	mov	bp,sp
	mov	ax,[5978h]
	add	ax,4h
	mov	dx,ax
	mov	al,4h
	out	dx,al
	mov	ax,[5978h]
	add	ax,5h
	mov	dx,ax
	mov	al,[bp+6h]
	out	dx,al
	mov	ax,[5978h]
	add	ax,4h
	mov	dx,ax
	mov	al,22h
	out	dx,al
	mov	ax,[5978h]
	add	ax,5h
	mov	dx,ax
	mov	al,[bp+6h]
	out	dx,al
	mov	ax,[5978h]
	add	ax,4h
	mov	dx,ax
	mov	al,26h
	out	dx,al
	mov	ax,[5978h]
	add	ax,5h
	mov	dx,ax
	mov	al,[bp+6h]
	out	dx,al
	leave
	retf	2h

;; fn11C8_0282: 11C8:0282
;;   Called from:
;;     11C8:02BC (in fn11C8_02AB)
;;     11C8:02D1 (in fn11C8_02CC)
;;     11C8:02E2 (in fn11C8_02DB)
fn11C8_0282 proc
	push	bp
	mov	bp,sp
	mov	al,[bp+4h]
	mov	dx,388h
	out	dx,al
	mov	cx,6h

l11C8_028F:
	in	al,dx
	loop	028Fh

l11C8_0292:
	leave
	ret	2h

;; fn11C8_0296: 11C8:0296
;;   Called from:
;;     11C8:02C1 (in fn11C8_02AB)
;;     11C8:02D6 (in fn11C8_02CC)
;;     11C8:02E9 (in fn11C8_02DB)
fn11C8_0296 proc
	push	bp
	mov	bp,sp
	mov	al,[bp+4h]
	mov	dx,389h
	out	dx,al
	mov	cx,35h
	dec	dx

l11C8_02A4:
	in	al,dx
	loop	02A4h

l11C8_02A7:
	leave
	ret	2h

;; fn11C8_02AB: 11C8:02AB
;;   Called from:
;;     11C8:03A8 (in fn11C8_0394)
;;     11C8:03CA (in fn11C8_03BB)
fn11C8_02AB proc
	enter	2h,0h
	mov	byte ptr [bp-1h],1h
	jmp	02B8h

l11C8_02B5:
	inc	byte ptr [bp-1h]

l11C8_02B8:
	mov	al,[bp-1h]
	push	ax
	call	0282h
	push	0h
	call	0296h
	cmp	byte ptr [bp-1h],0F5h
	jnz	02B5h

l11C8_02CA:
	leave
	ret

;; fn11C8_02CC: 11C8:02CC
;;   Called from:
;;     11C8:03C7 (in fn11C8_03BB)
fn11C8_02CC proc
	push	bp
	mov	bp,sp
	push	0B0h
	call	0282h
	push	11h
	call	0296h
	leave
	ret

;; fn11C8_02DB: 11C8:02DB
;;   Called from:
;;     11C8:02F7 (in fn11C8_02F0)
;;     11C8:02FE (in fn11C8_02F0)
;;     11C8:0305 (in fn11C8_02F0)
;;     11C8:030C (in fn11C8_02F0)
;;     11C8:0313 (in fn11C8_02F0)
;;     11C8:031A (in fn11C8_02F0)
;;     11C8:0321 (in fn11C8_02F0)
;;     11C8:0328 (in fn11C8_02F0)
;;     11C8:032F (in fn11C8_02F0)
;;     11C8:0336 (in fn11C8_02F0)
;;     11C8:0375 (in fn11C8_0354)
;;     11C8:0387 (in fn11C8_0354)
;;     11C8:03AF (in fn11C8_0394)
fn11C8_02DB proc
	push	bp
	mov	bp,sp
	mov	al,[bp+6h]
	push	ax
	call	0282h
	mov	al,[bp+4h]
	push	ax
	call	0296h
	leave
	ret	4h

;; fn11C8_02F0: 11C8:02F0
;;   Called from:
;;     11C8:03B2 (in fn11C8_0394)
fn11C8_02F0 proc
	push	bp
	mov	bp,sp
	push	20h
	push	1h
	call	02DBh
	push	40h
	push	10h
	call	02DBh
	push	60h
	push	0F0h
	call	02DBh
	push	80h
	push	77h
	call	02DBh
	push	0A0h
	push	98h
	call	02DBh
	push	23h
	push	1h
	call	02DBh
	push	43h
	push	0h
	call	02DBh
	push	63h
	push	0F0h
	call	02DBh
	push	83h
	push	77h
	call	02DBh
	push	0B0h
	push	31h
	call	02DBh
	leave
	ret

;; fn11C8_033B: 11C8:033B
;;   Called from:
;;     0800:03C2 (in fn0800_031B)
;;     0C74:073C (in fn0C74_070D)
;;     0C74:0910 (in fn0C74_076B)
;;     0C74:0BD2 (in fn0C74_0A35)
;;     0C74:2E1B (in fn0C74_2BBD)
;;     0C74:31F1 (in fn0C74_2E5A)
;;     0C74:35D0 (in fn0C74_3236)
;;     0C74:36C9 (in fn0C74_3615)
;;     0C74:3778 (in fn0C74_3615)
;;     0C74:3876 (in fn0C74_37C3)
;;     0C74:3923 (in fn0C74_37C3)
;;     0C74:48B6 (in fn0C74_45CE)
;;     0C74:4916 (in fn0C74_45CE)
;;     0C74:4CCB (in fn0C74_4999)
;;     0C74:4D2D (in fn0C74_4999)
;;     11C8:03B5 (in fn11C8_0394)
fn11C8_033B proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [5976h],0h
	jnz	034Ch

l11C8_0345:
	call	far 1E78h:02F4h
	jmp	0352h

l11C8_034C:
	push	0h
	push	cs
	call	0236h

l11C8_0352:
	leave
	retf

;; fn11C8_0354: 11C8:0354
;;   Called from:
;;     0800:0359 (in fn0800_031B)
;;     0C74:072A (in fn0C74_070D)
;;     0C74:0845 (in fn0C74_076B)
;;     0C74:0B09 (in fn0C74_0A35)
;;     0C74:2D10 (in fn0C74_2BBD)
;;     0C74:31EA (in fn0C74_2E5A)
;;     0C74:35C9 (in fn0C74_3236)
;;     0C74:36C2 (in fn0C74_3615)
;;     0C74:386F (in fn0C74_37C3)
;;     0C74:48AF (in fn0C74_45CE)
;;     0C74:4CC4 (in fn0C74_4999)
fn11C8_0354 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [5976h],0h
	jnz	0368h

l11C8_035E:
	push	word ptr [bp+6h]
	call	far 1E78h:02C7h
	jmp	0390h

l11C8_0368:
	mov	al,[5975h]
	xor	ah,ah
	add	ax,0A0h
	push	ax
	mov	al,[bp+6h]
	push	ax
	call	02DBh
	mov	al,[5975h]
	xor	ah,ah
	add	ax,0B0h
	push	ax
	mov	al,[bp+7h]
	or	al,10h
	push	ax
	call	02DBh
	push	0C8h
	push	cs
	call	0236h

l11C8_0390:
	leave
	retf	2h

;; fn11C8_0394: 11C8:0394
;;   Called from:
;;     0800:42C6 (in fn0800_4255)
fn11C8_0394 proc
	push	bp
	mov	bp,sp
	call	0092h
	cmp	byte ptr [5976h],0h
	jnz	03A3h

l11C8_03A1:
	jmp	03B9h

l11C8_03A3:
	mov	byte ptr [5975h],0h
	call	02ABh
	push	1h
	push	10h
	call	02DBh
	call	02F0h
	push	cs
	call	033Bh

l11C8_03B9:
	leave
	retf

;; fn11C8_03BB: 11C8:03BB
;;   Called from:
;;     0800:0016 (in fn0800_0000)
fn11C8_03BB proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [5976h],0h
	jnz	03C7h

l11C8_03C5:
	jmp	03CDh

l11C8_03C7:
	call	02CCh
	call	02ABh

l11C8_03CD:
	leave
	retf

;; fn11C8_03CF: 11C8:03CF
;;   Called from:
;;     0800:427D (in fn0800_4255)
fn11C8_03CF proc
	push	bp
	mov	bp,sp
	mov	byte ptr [5976h],0h
	leave
	retf
11C8:03D9                            00 00 00 00 00 00 00          .......
