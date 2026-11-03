all:
	gcc -Wall -pthread sync_car.c sync_car-runner.c -o sync_car

clean:
	rm -f sync_car

.PHONY: all clean
