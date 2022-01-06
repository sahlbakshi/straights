#include "user.h"
#include <chrono>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
   int seed;
   if (argc == 2) {
      seed = std::stoi(argv[1]);
   } else {
      seed = std::chrono::system_clock::now().time_since_epoch().count();
   }
   User user{seed};
   user.startGame();
}