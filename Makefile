all: processes memory file_system input_output race_prio ipc

processes: processes.cpp tinbes.o
	c++ processes.cpp tinbes.o -o processes

memory: memory.cpp tinbes.o
	c++ memory.cpp tinbes.o -o memory

file_system: file_system.cpp tinbes.o
	c++ file_system.cpp tinbes.o -o file_system

input_output: input_output.cpp
	c++ input_output.cpp -l wiringPi -o input_output

tinbes.o: tinbes.cpp tinbes.h
	c++ -o tinbes.o -c tinbes.cpp

race_prio: race_prio.c
	cc race_prio.c -l pthread -o race_prio

ipc: send_signal catch_signal send_message receive_message

send_signal: send_signal.c
	cc send_signal.c -o send_signal

catch_signal: catch_signal.c
	cc catch_signal.c -o catch_signal

send_message: send_message.c
	cc send_message.c -o send_message

receive_message: receive_message.c
	cc receive_message.c -o receive_message

clean: 
	rm tinbes.o processes memory file_system input_output race_prio send_signal catch_signal send_message receive_message
