.name		"_xXx_TUEUR_xXx_"
.comment	"Mouahahah x2"

			st r1, r2
			st r1, r3

defense:	live %0
			fork %:defense
			live %0
			zjmp %:defense

maj:		sti r1, %:defense, %1
			sti r1, %:defense, %9
			zjmp %:maj

loop_on:	ld %0, r2
			aff r2


dupl:		fork %:maj
			fork %:defense
			zjmp %:att

loop:	zjmp %:dupl

att:	st r2, r1
		sti r1, -200, %0
		sti r1, -180, %0
		sti r1, -160, %0
		sti r1, -140, %0
		sti r1, -120, %0
		sti r1, -100, %0
		sti r1, -80, %0
		sti r1, -60, %0
		sti r1, 4, %0
		sti r1, 12, %0
		sti r1, 20, %0
		sti r1, 200, %0
		sti r1, 180, %0
		sti r1, 160, %0
		sti r1, 140, %0
		sti r1, 120, %0
		sti r1, 100, %0
		#zjmp %:dupl

attn:	st r3, r1
		fork %:reins
		fork %:reins
		zjmp %:att


reins:	st r3, r1
		sti r1, %:defense, %1
		sti r1, %:defense, %9
		zjmp %:reins




