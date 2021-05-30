/*
 * Step 1: add the four needed libraries to include
 */
#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>


/*
 * Step 2: Handle the load/unload event
 */
static int hello_modevent(module_t mod __unused, int event, void *arg __unused) {
  int error = 0;

  switch (event) {
  case MOD_LOAD:
    uprintf("Hello, world!\n");
    break;
  case MOD_UNLOAD:
    uprintf("Good-bye, cruel world!\n");
    break;
  default:
    error = EOPNOTSUPP;
    break;
  }

  return (error);
}

/*
 * Step 3: Name the module and the event hander function using moduledata_T
 */
static moduledata_t hello_mod = {
    "hello", // Module Name
    hello_modevent, // Event handler function name
    NULL // Extra data
};

/*
 * Step 4: Declare the module using DECLARE_MODULE macro
 */
DECLARE_MODULE(hello, hello_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
