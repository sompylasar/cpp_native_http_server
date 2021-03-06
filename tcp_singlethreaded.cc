// A simple single-threaded TCP server.

/*
# To test:
telnet localhost 8080
*/

#include <thread>

#include "posix_tcp_server.h"

const int kPort = 8080;

int main() {
  Socket s(kPort);
  while (true) {
    Connection c(s.Accept());
    try {
      c.BlockingWrite("BAZINGA\n");
      std::this_thread::sleep_for(std::chrono::seconds(10));
      c.BlockingWrite("DONE\n");
    } catch (NetworkException&) {
    }
  }
}
