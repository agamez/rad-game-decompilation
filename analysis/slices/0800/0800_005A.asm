;; fn0800_005A: 0800:005A
;;   Called from:
;;     0800:04F3 (in fn0800_04E3)
;;     0800:0629 (in fn0800_0619)
;;     0800:0793 (in fn0800_0768)
;;     0800:0B01 (in fn0800_0AA1)
;;     0800:0BA2 (in fn0800_0B42)
;;     0800:25D1 (in fn0800_2401)
;;     0800:28F2 (in fn0800_2827)
;;     0800:2D4A (in fn0800_2C0C)
;;     0800:2F78 (in fn0800_2C0C)
;;     0800:33D6 (in fn0800_31B7)
;;     0800:3AC9 (in fn0800_391E)
fn0800_005A proc
	push	bp
	mov	bp,sp
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1B3Eh
	leave
	ret	8h
0800:007B                                  50 53 51 52 56            PSQRV
0800:0080 57 1E 06 55 89 E5 B8 14 20 8E D8 83 06 E2 53 37 W..U.... .....S7
0800:0090 81 3E E2 53 E8 03 72 1F 31 C0 A3 E2 53 83 3E DA .>.S..r.1...S.>.
0800:00A0 58 00 7F 09 7C 11 83 3E D8 58 00 76 0A 83 2E D8 X...|..>.X.v....
0800:00B0 58 01 83 1E DA 58 00 C9 07 1F 5F 5E 5A 59 5B 58 X....X...._^ZY[X
0800:00C0 CF                                              .
