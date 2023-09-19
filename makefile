CC=g++

OBJS_day1 := day1.o
OBJS_day2 := day2.o
OBJS_day3 := day3.o

day3: ${OBJS_day3}

day2: ${OBJS_day2}

day1: ${OBJS_day1}

${OBJS_day1}: %.o: %.cpp

${OBJS_day2}: %.o: %.cpp

${OBJS_day3}: %.o: %.cpp

clean:
	rm *.o day1
