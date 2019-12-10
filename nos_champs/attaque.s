.name "attaq"
.comment ""

		sti r1, %:life, %1
		sti r1, %:life, %1
		ld %20, r3
		ld %-4500, r2
		ld %0, r4

life:	live %0

start:	fork %:base

aff r4
fork %:life
fork %:start

base:	add r2, r3, r2
		sti r1, r2, %:front

front:	live %0
		zjmp %:base
