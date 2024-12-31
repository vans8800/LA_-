#include <stdio.h>

int main() {
  int config1;

  asm volatile ( 
    "li.d $t0, 0x1\n\t"
    "cpucfg %0, $t0\n\t" 
    : "=r"(config1)
   
  );

  printf("Config1 register = 0x%x\n", config1);
  
  return 0;
}
