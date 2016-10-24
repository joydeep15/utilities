gcc autoKick.c
read a
while [ $a -gt 0 ]
do
	./a.out
	a=$(( $a - 1))
	sleep 20 
done
