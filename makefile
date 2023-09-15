OBJS_day1 :=  day1.o

day1: ${OBJS_day1}

${OBJS_day1}: %.o: %.cpp

clean:
	rm *.o day1
