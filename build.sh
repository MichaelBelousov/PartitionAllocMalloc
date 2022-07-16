g++ -std=c++11 -o pa_malloc.so -shared -fPIC -ldl pa_malloc.cpp AddressSpaceRandomization.cpp  Assertions.cpp  PageAllocator.cpp  PartitionAlloc.cpp
