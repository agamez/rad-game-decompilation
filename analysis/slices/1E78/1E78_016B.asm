;; fn1E78_016B: 1E78:016B
;;   Called from:
;;     0800:0011 (in fn0800_0000)
;;     0800:2CAE (in fn0800_2C0C)
;;     0C74:03F3 (in fn0C74_03D4)
;;     13E2:01B8 (in fn13E2_0193)
;;     1E78:0169 (in fn1E78_0143)
fn1E78_016B proc
	mov	bx,sp
	mov	ax,ss:[bx+4h]
	call	0097h
	call	00E5h
	mov	al,[0B8B8h]
	mov	[0B8AEh],al
	retf	2h
1E78:0180 8B DC 36 8A 57 0A 36 8A 77 08 36 8A 4F 06 36 8A ..6.W.6.w.6.O.6.
1E78:0190 6F 04 3A D1 77 27 3A F5 77 23 FE CA 78 1F FE CE o.:.w':.w#..x...
1E78:01A0 78 1B FE C9 3A 0E B6 B8 77 13 FE CD 3A 2E B7 B8 x...:...w...:...
1E78:01B0 77 0B 89 16 B0 B8 89 0E B2 B8 E8 40 03 CA 08 00 w..........@....
