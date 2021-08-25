TestExpression: Expression.o TestExpression.o 
	g++ Expression.o TestExpression.o  -o TestExpression

Expression.o: Expression.cpp
	g++ -c Expression.cpp

TestExpression.o: TestExpression.cpp
	g++ -c TestExpression.cpp 

clean: 
	rm *.o TestExpression