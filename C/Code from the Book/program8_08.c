/* Program 8.8 A function to increase your salary that doesn't   */
#include <stdio.h>

long *IncomePlus(long* pPay);          /* Prototype for increase function */

int main(void)
{
  long your_pay = 30000L;             /* Starting salary                 */
  long *pold_pay = &your_pay;         /* Pointer to pay value            */
  long *pnew_pay = NULL;              /* Pointer to hold return value    */

  pnew_pay = IncomePlus(pold_pay);
  printf("\nOld pay = $%ld", *pold_pay);
  printf("   New pay = $%ld\n", *pnew_pay);
  return 0;
}

/* Definition of function to increment pay */
long *IncomePlus(long *pPay)
{
  long pay = 0;                       /* Local variable for the result */

  pay = *pPay + 10000;                /* Increment the value for pay   */
  return &pay;                        /* Return the address            */
}

