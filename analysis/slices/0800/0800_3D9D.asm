;; fn0800_3D9D: 0800:3D9D
;;   Called from:
;;     0800:4423 (in fn0800_4255)
fn0800_3D9D proc
	enter	106h,0h
	call	far 1206h:0066h
	call	far 13E2h:003Bh
	call	far 1AB8h:0F80h
	cmp	byte ptr [53DFh],0h
	jnz	3DBAh

l0800_3DB7:
	call	3CFAh

l0800_3DBA:
	call	far 13E2h:0080h
	call	21E7h
	push	7h
	call	far 1AB8h:1C32h
	push	1h
	push	0h
	push	2h
	call	far 1AB8h:1536h
	call	far 1206h:0066h
	push	140h
	push	1CEh
	mov	di,3D5Ah
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	2h
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1CBAh
	push	2h
	push	2h
	call	far 1AB8h:1342h
	push	2h
	call	far 1AB8h:1C32h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	6Ah
	push	16Dh
	push	203h
	push	1C9h
	call	far 1AB8h:112Eh
	push	79h
	push	19Bh
	call	far 0C74h:06B7h
	push	9Ch
	push	14h
	push	1E0h
	push	16Ah
	push	140h
	push	0B4h
	call	far 1206h:01ACh
	call	far 1206h:0038h

l0800_3E46:
	mov	byte ptr [58E0h],0h
	mov	byte ptr [bp-1h],0FFh
	call	far 1E78h:02FBh
	or	al,al
	jnz	3E64h

l0800_3E58:
	cmp	byte ptr [58E0h],0h
	jnz	3E64h

l0800_3E5F:
	call	far 0C74h:54B1h

l0800_3E64:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3E79h

l0800_3E6D:
	cmp	byte ptr [58E0h],0h
	jnz	3E79h

l0800_3E74:
	call	far 0C74h:54B1h

l0800_3E79:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3E8Eh

l0800_3E82:
	cmp	byte ptr [58E0h],0h
	jnz	3E8Eh

l0800_3E89:
	call	far 0C74h:54F0h

l0800_3E8E:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3EA3h

l0800_3E97:
	cmp	byte ptr [58E0h],0h
	jnz	3EA3h

l0800_3E9E:
	call	far 0C74h:54F0h

l0800_3EA3:
	call	far 1E78h:02FBh
	or	al,al
	jz	3ED2h

l0800_3EAC:
	call	far 1E78h:030Dh
	mov	[bp-1h],al
	cmp	byte ptr [bp-1h],0h
	jnz	3EC2h

l0800_3EBA:
	call	far 1E78h:030Dh
	mov	[bp-1h],al

l0800_3EC2:
	call	far 1E78h:02FBh
	or	al,al
	jz	3ED2h

l0800_3ECB:
	call	far 1E78h:030Dh
	jmp	3EC2h

l0800_3ED2:
	cmp	byte ptr [58E0h],0h
	jz	3EDFh

l0800_3ED9:
	call	1D55h
	mov	[bp-1h],al

l0800_3EDF:
	mov	al,[bp-1h]
	cmp	al,21h
	jnz	3F01h

l0800_3EE6:
	call	far 1206h:0066h
	call	184Ch
	mov	byte ptr [58B2h],0h
	call	2827h
	mov	byte ptr [58B2h],1h
	jmp	415Eh
0800:3EFE                                           E9 33               .3
0800:3F00 02                                              .               

l0800_3F01:
	cmp	al,3Bh
	jnz	3F2Fh

l0800_3F05:
	push	1h
	push	word ptr [541Ch]
	push	word ptr [542Ah]
	mov	di,5438h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	far 0C74h:51AAh
	call	far 1206h:0066h
	call	184Ch
	call	2C0Ch
	jmp	415Eh
0800:3F2C                                     E9 05 02                ... 

l0800_3F2F:
	cmp	al,3Ch
	jz	3F36h

l0800_3F33:
	jmp	3FE3h

l0800_3F36:
	push	2h
	push	word ptr [541Eh]
	push	word ptr [542Ch]
	mov	di,5452h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	11EFh
	push	2h
	push	word ptr [541Eh]
	push	word ptr [542Ch]
	mov	di,5452h
	push	ds
	push	di
	push	0h
	call	19E1h
	push	1h
	push	3h
	call	far 1AB8h:1175h
	mov	ax,[53E4h]
	sub	ax,4h
	push	ax
	mov	ax,[53F2h]
	dec	ax
	push	ax
	mov	ax,[5400h]
	add	ax,4h
	push	ax
	mov	ax,[540Eh]
	add	ax,3h
	push	ax
	call	far 1AB8h:1B3Eh
	cmp	word ptr [5990h],0h
	jnz	3F97h

l0800_3F90:
	cmp	word ptr [598Eh],1h
	jz	3FCCh

l0800_3F97:
	push	1h
	push	word ptr [541Ch]
	push	word ptr [542Ah]
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	mov	di,3D7Fh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5ED6h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,3D83h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	0h
	call	19E1h
	jmp	3FE0h

l0800_3FCC:
	push	1h
	push	word ptr [541Ch]
	push	word ptr [542Ah]
	mov	di,3D85h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_3FE0:
	jmp	4134h

l0800_3FE3:
	cmp	al,3Dh
	jnz	4023h

l0800_3FE7:
	push	3h
	push	word ptr [5420h]
	push	word ptr [542Eh]
	mov	di,546Ch
	push	ds
	push	di
	push	1h
	call	19E1h
	xor	ax,ax
	mov	[598Eh],ax
	mov	[5990h],ax
	call	far 1206h:0066h
	call	149Fh
	call	184Ch
	call	2C0Ch
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	415Eh
0800:4020 E9 11 01                                        ...             

l0800_4023:
	cmp	al,3Eh
	jnz	4065h

l0800_4027:
	cmp	byte ptr [58B0h],0h
	jz	4049h

l0800_402E:
	mov	byte ptr [58B0h],0h
	push	4h
	push	word ptr [5422h]
	push	word ptr [5430h]
	mov	di,5486h
	push	ds
	push	di
	push	1h
	call	19E1h
	jmp	4062h

l0800_4049:
	mov	byte ptr [58B0h],1h
	push	4h
	push	word ptr [5422h]
	push	word ptr [5430h]
	mov	di,5486h
	push	ds
	push	di
	push	0h
	call	19E1h

l0800_4062:
	jmp	4134h

l0800_4065:
	cmp	al,3Fh
	jz	406Ch

l0800_4069:
	jmp	4105h

l0800_406C:
	push	5h
	push	word ptr [5424h]
	push	word ptr [5432h]
	mov	di,54A0h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	far 1206h:0066h
	push	64h
	call	far 1E78h:029Ch
	cmp	byte ptr [0002h],1Eh
	jbe	40F8h

l0800_4093:
	push	2h
	push	0h
	push	2Ah
	push	0h
	call	far 1AB8h:1CBAh
	push	2h
	push	2h
	call	far 1AB8h:1342h
	call	far 1206h:0066h
	push	8h
	push	0h
	call	far 1AB8h:1342h
	mov	di,5ED6h
	push	ds
	push	di
	mov	di,3D91h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	40D9h

l0800_40C8:
	mov	di,3D96h
	push	cs
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l0800_40D9:
	mov	di,5ED6h
	push	ds
	push	di
	call	far 1229h:0DCCh
	cmp	byte ptr [5CB3h],0h
	jnz	40EDh

l0800_40EA:
	call	31B7h

l0800_40ED:
	cmp	byte ptr [5CB3h],0h
	jz	4093h

l0800_40F4:
	jmp	415Eh
0800:40F6                   EB 03                               ..        

l0800_40F8:
	call	2004h
	call	21E7h
	call	far 1206h:0038h
	jmp	4134h

l0800_4105:
	cmp	al,40h
	jnz	4134h

l0800_4109:
	push	6h
	push	word ptr [5426h]
	push	word ptr [5434h]
	mov	di,54BAh
	push	ds
	push	di
	push	1h
	call	19E1h
	push	64h
	call	far 1E78h:029Ch
	call	far 1206h:0066h
	call	391Eh
	call	21E7h
	call	far 1206h:0038h

l0800_4134:
	cmp	byte ptr [bp-1h],41h
	jz	413Dh

l0800_413A:
	jmp	3E46h

l0800_413D:
	push	7h
	push	word ptr [5428h]
	push	word ptr [5436h]
	mov	di,54D4h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	far 0C74h:0A35h
	call	far 1206h:0066h
	call	0000h

l0800_415E:
	leave
	ret
0800:4160 07 52 41 44 2E 44 41 54                         .RAD.DAT
