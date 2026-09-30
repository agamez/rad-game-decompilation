;; fn1AB8_180A: 1AB8:180A
;;   Called from:
;;     1AB8:1AA9 (in fn1AB8_1AA6)
fn1AB8_180A proc
	cmp	byte ptr [0B8A3h],0FFh
	jnz	1848h

l1AB8_1811:
	cmp	byte ptr [fn0800_3850],0A5h
	jnz	181Eh

l1AB8_1818:
	mov	byte ptr [0B8A3h],0h
	ret

l1AB8_181E:
	mov	ah,0Fh
	int	10h
	mov	[0B8A3h],al
	mov	ax,40h
	mov	es,ax
	mov	bx,10h
	mov	al,es:[bx]
	mov	[0B8A4h],al
	cmp	byte ptr [0B89Ch],5h
	jz	1848h

l1AB8_183A:
	cmp	byte ptr [0B89Ch],7h
	jz	1848h

l1AB8_1841:
	and	al,0CFh
	or	al,20h
	mov	es:[bx],al

l1AB8_1848:
	ret
1AB8:1849                            55 8B EC BE 06 00 FF          U......
1AB8:1850 1E 20 B8 5D CB                                  . .].
