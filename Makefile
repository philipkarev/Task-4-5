a:tokenaizer.o main.o
	wg++ -fno-elide-constructors -std=c++11  tokenaizer.o main.o

main.o:main.cpp tokenaizer.h
	wg++ -fno-elide-constructors -std=c++11  main.cpp -c

tokenaizer.o:tokenaizer.cpp tokenaizer.h
	wg++ -fno-elide-constructors -std=c++11  tokenaizer.cpp -c

