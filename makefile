
password: PasswordDriver.o PasswordManager.o
	g++ -o password PasswordDriver.o PasswordManager.o

PasswordDriver.o: PasswordDriver.cpp
	g++ -c -std=c++11 PasswordDriver.cpp

PasswordManager.o: PasswordManager.cpp PasswordManager.h
	g++ -c -std=c++11 PasswordManager.cpp
