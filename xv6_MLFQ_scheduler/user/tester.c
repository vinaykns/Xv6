#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define check(exp, msg) if(exp) {} else {\
  printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
  exit();}

//#define DDEBUG 1

#ifdef DDEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

int time_slices[] = {5, 5, 10, 20};

int workload(int n) {
  int i, j = 0;
  for (i = 0; i < n; i++) {
    j += i * j + 1;
  }
  return j;
}

int
main(int argc, char *argv[])
{

  // Push this thread to the bottom
  workload(80000000);

  // int i;

  //for (i = 0; i < 7; i++) {
    int c_pid = fork();
    // Child
    if (c_pid == 0) {
      workload(800000);
      sleep(100);
      exit();
    }
  //}
  int j;
// Wait for child processes to finish..
  for (j = 0; j < 7; j++) {
    wait();
  }

  sleep(300);
  exit();
}
