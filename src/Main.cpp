#include <enet/enet.h>
#include <iostream>

int main() {
  std::cout << "Hello world\n";
  enet_initialize();
  atexit(enet_deinitialize);
  return 0;
}
