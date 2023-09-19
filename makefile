CC=g++

OBJS_day1 := day1.o
OBJS_day2 := day2.o

day2: ${OBJS_day2}

day1: ${OBJS_day1}

${OBJS_day1}: %.o: %.cpp

${OBJS_day2}: %.o: %.cpp

clean:
	rm *.o day1
