all : read write
read: SharedMemoryRead.c SharedMemory.h
gcc -o read.out SharedMemoryRead.c -lpthread -lrt

write: SharedMemoryWrite.c SharedMemory.h
gcc -o write.out SharedMemoryWrite.c -lpthread -lrt

runread:
./read.out

runwrite:
./write.out

clean:
rm -rf *.out *.o
