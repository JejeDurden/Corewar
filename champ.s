.name "Pov merde"
.comment "Je veux plus vous voir"

coucou: ld %9,r5
sti r1, %5, %3
live: live %0
live2: ld %-8,r6
ld %9,r7
sti r6, %-12, %0
sti r7, %-21, %0
fork %11
add r2, r2, r2
zjmp %:live
add r1, r2, r3
fork %:coucou
