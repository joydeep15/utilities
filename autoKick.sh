gcc autoKick.c
a=20;
while [ $a -gt 0 ]
do
	./a.out
	a=$(( $a - 1))
	sleep 20 
done
