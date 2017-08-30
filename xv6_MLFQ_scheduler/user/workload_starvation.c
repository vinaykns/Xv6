#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define ITERATIONS 500
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
   // struct pstat st;
    //check(getpinfo(&st) == 0, "getpinfo");

  // Push this thread to the bottom

  // workload(800000)
  int i;
  // int pid_p = getpid();
  

  for (i = 0; i < ITERATIONS; i++)
  {
    workload(800000);
  }
   
/*  int rc = fork();
  if (rc == 0) {
    int j;
    int pid_c = getpid();
    printf(1, "child pid :%d\n",pid_c);
    
    for(j = 0; j < ITERATIONS; j++) {
      workload(80000);
    }
      } else if (rc > 0) {
    // parent
    // print 
    printf(1, "parent pid :%d\n", pid_p); 
    for (i = 0; i < ITERATIONS; i++)
    {
      workload(80000);
    }
       wait();
   } else {
    // fork error
  } 
    
  // getpid();
   
  */
 /* for (i = 0; i < 7; i++) {
    //int c_pid = fork();
    // Child
    if (c_pid == 0) {
      workload(80000000);
      sleep(100);
      exit();
    }   
  }

  sleep(300);

*/
  /* check(getpinfo(&st) == 0, "getpinfo");

  int j, k;
  for (j = 0; j < NPROC; j++) {
    if (st.inuse[j]) {
      printf(1, " %d > %d \n", st.ticks[j][2], time_slices[2]);
      if (st.ticks[j][2] > time_slices[2] && st.ticks[j][2] % time_slices[2] ==
0) {
        count++;
      }
    
      DEBUG_PRINT((1, "pid: %d\n", st.pid[j]));
      for (k = 0; k < 4; k++) {
        DEBUG_PRINT((1, "\t level %d ticks used %d\n", k, st.ticks[j][k]));
      }
    }
  }

  // Wait for child processes to finish..
  for (j = 0; j < 6; j++) {
    wait();
  }

  if (count) {
    printf(1, "TEST PASSED");
  } else {
    printf(1, "TEST FAILED");
  }
*/
  exit();
}
