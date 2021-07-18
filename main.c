#include <stdio.h>
#include "m-lib/m-array.h"

ARRAY_DEF(aint, int)
#define M_OPL_aint_t() ARRAY_OPLIST(aint, M_DEFAULT_OPLIST)

int main(void)
{
  M_LET( (a, 1, 2, 3), aint_t) {
    printf("a=");
    aint_out_str(stdout, a);
    printf("\n");
  }
  return 0;
}
