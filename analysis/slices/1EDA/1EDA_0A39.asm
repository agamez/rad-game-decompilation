;; fn1EDA_0A39: 1EDA:0A39
;;   Called from:
;;     0800:0258 (in fn0800_01FE)
;;     0800:066B (in fn0800_0619)
;;     0800:067E (in fn0800_0619)
;;     0800:06AA (in fn0800_0619)
;;     0800:06D6 (in fn0800_0619)
;;     0800:0ABF (in fn0800_0AA1)
;;     0800:0AEB (in fn0800_0AA1)
;;     0800:0B60 (in fn0800_0B42)
;;     0800:0B8C (in fn0800_0B42)
;;     0800:0D32 (in fn0800_0D20)
;;     0800:0D97 (in fn0800_0D20)
;;     0800:102D (in fn0800_0D20)
;;     0800:1198 (in fn0800_0D20)
;;     0800:11CF (in fn0800_0D20)
;;     0800:1231 (in fn0800_11EF)
;;     0800:12F1 (in fn0800_11EF)
;;     0800:19F3 (in fn0800_19E1)
;;     0800:1AF1 (in fn0800_19E1)
;;     0800:2611 (in fn0800_2401)
;;     0800:2932 (in fn0800_2827)
;;     0800:2DD0 (in fn0800_2C0C)
;;     0800:31D9 (in fn0800_31B7)
;;     0800:322C (in fn0800_31B7)
;;     0800:323D (in fn0800_31B7)
;;     0800:40D4 (in fn0800_3D9D)
;;     0C43:00C9 (in fn0C43_00B9)
;;     0C74:0012 (in fn0C74_0000)
;;     0C74:0073 (in fn0C74_004B)
;;     0C74:013B (in fn0C74_011E)
;;     0C74:0167 (in fn0C74_011E)
;;     0C74:0229 (in fn0C74_020C)
;;     0C74:0255 (in fn0C74_020C)
;;     11C8:0068 (in fn11C8_0000)
;;     1229:0052 (in fn1229_0040)
;;     1229:026D (in fn1229_0040)
;;     1229:0385 (in fn1229_0040)
;;     1229:03B4 (in fn1229_039D)
;;     1229:03C7 (in fn1229_039D)
;;     1229:051C (in fn1229_050A)
;;     1229:05B7 (in fn1229_050A)
;;     1229:0694 (in fn1229_061B)
;;     1229:07B1 (in fn1229_0735)
;;     1229:07CA (in fn1229_0735)
;;     1229:0870 (in fn1229_0735)
;;     1229:0889 (in fn1229_0735)
;;     1229:0976 (in fn1229_0735)
;;     1229:0A40 (in fn1229_09F9)
;;     1229:0A6F (in fn1229_09F9)
;;     1229:0A82 (in fn1229_09F9)
;;     1229:0C3C (in fn1229_0AA8)
;;     1229:0DBE (in fn1229_0CCE)
;;     1229:0DDE (in fn1229_0DCC)
;;     1229:0E03 (in fn1229_0DCC)
;;     1229:113A (in fn1229_0DCC)
;;     1229:114B (in fn1229_0DCC)
;;     133F:015D (in fn133F_014B)
;;     133F:02F1 (in fn133F_02DF)
;;     133F:0329 (in fn133F_02DF)
;;     133F:0349 (in fn133F_02DF)
;;     133F:0364 (in fn133F_0352)
;;     133F:04F0 (in fn133F_04DE)
;;     13C1:005E (in fn13C1_0036)
;;     13E2:01A5 (in fn13E2_0193)
;;     1AB8:002B (in fn1AB8_0000)
;;     1AB8:029B (in fn1AB8_027E)
;;     1AB8:02B6 (in fn1AB8_027E)
;;     1AB8:02D1 (in fn1AB8_027E)
;;     1AB8:030B (in fn1AB8_027E)
;;     1AB8:0345 (in fn1AB8_027E)
;;     1AB8:0360 (in fn1AB8_027E)
;;     1AB8:037B (in fn1AB8_027E)
;;     1AB8:0396 (in fn1AB8_027E)
;;     1AB8:03D0 (in fn1AB8_027E)
;;     1AB8:03EB (in fn1AB8_027E)
;;     1AB8:0406 (in fn1AB8_027E)
;;     1AB8:0421 (in fn1AB8_027E)
;;     1AB8:043C (in fn1AB8_027E)
;;     1AB8:0476 (in fn1AB8_027E)
;;     1AB8:0490 (in fn1AB8_027E)
;;     1AB8:04AA (in fn1AB8_027E)
;;     1AB8:04E8 (in fn1AB8_027E)
;;     1AB8:089D (in fn1AB8_0887)
;;     1AB8:08B1 (in fn1AB8_0887)
;;     1AB8:0991 (in fn1AB8_097B)
;;     1AB8:09C6 (in fn1AB8_097B)
;;     1AB8:0BC4 (in fn1AB8_0BAE)
;;     1AB8:0D00 (in fn1AB8_0BAE)
;;     1AB8:0D4D (in fn1AB8_0BAE)
;;     1AB8:14A8 (in fn1AB8_1492)
;;     1AB8:1631 (in fn1AB8_1536)
;;     1AB8:1799 (in fn1AB8_1783)
;;     1EDA:0BC6 (in fn1EDA_0B7C)
;;     1EDA:0C1C (in fn1EDA_0BD0)
fn1EDA_0A39 proc
	cld
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+0Ah]
	les	di,ss:[bx+6h]
	mov	cx,ss:[bx+4h]
	lodsb
	cmp	al,cl
	jbe	0A51h

l1EDA_0A4F:
	mov	al,cl

l1EDA_0A51:
	stosb
	mov	cl,al
	xor	ch,ch
	rep movsb
	mov	ds,dx
	retf	0Ah
1EDA:0A5D                                        8B DC 36              ..6
1EDA:0A60 C4 7F 04 26 8A 05 32 E4 CA 04 00                ...&..2....
