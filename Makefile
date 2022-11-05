a:tokenaizer.o main.o list.o
	wg++ -fno-elide-constructors -std=c++11  tokenaizer.o list.o main.o

main.o:main.cpp tokenaizer.h list.h
	wg++ -fno-elide-constructors -std=c++11  main.cpp -c

tokenaizer.o:tokenaizer.cpp tokenaizer.h
	wg++ -fno-elide-constructors -std=c++11  tokenaizer.cpp -c

list.o:list.cpp list.h
	wg++ -fno-elide-constructors -std=c++11  list.cpp -c

