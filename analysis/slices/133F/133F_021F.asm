;; fn133F_021F: 133F:021F
;;   Called from:
;;     133F:05E4 (in fn133F_0528)
;;     133F:060B (in fn133F_0528)
;;     133F:0632 (in fn133F_0528)
;;     133F:0659 (in fn133F_0528)
;;     133F:07F7 (in fn133F_0528)
fn133F_021F proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	cmp	ax,[6CC8h]
	jle	0252h

l133F_022B:
	mov	ax,[bp+8h]
	cmp	ax,[6CCCh]
	jge	0252h

l133F_0234:
	mov	ax,[bp+6h]
	cmp	ax,[6CCAh]
	jle	0252h

l133F_023D:
	mov	ax,[bp+6h]
	cmp	ax,[6CCEh]
	jge	0252h

l133F_0246:
	mov	ax,[bp+8h]
	mov	[6CC4h],ax
	mov	ax,[bp+6h]
	mov	[6CC6h],ax

l133F_0252:
	leave
	retf	4h
