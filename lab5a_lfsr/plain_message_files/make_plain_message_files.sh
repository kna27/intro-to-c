yes "This is a tiny file." 		| head -n 1 > 1_tiny.txt
yes "This is a small file." 	| head -n 10 > 2_small.txt
yes "This is a medium file." 	| head -n 100 > 3_medium.txt
yes "This is a large file." 	| head -n 1000 > 4_large.txt
yes "This is a huge file." 		| head -n 10000 > 5_huge.txt
yes "This is an enormous file."	| head -n 100000 > 6_enormous.txt

