all: analyze

clean:
	rm -f analyze.exe

analyze: DataWrangle.cpp Indicators.cpp main.cpp
	g++ -std=c++11 -o analyze.exe DataWrangle.cpp Indicators.cpp main.cpp