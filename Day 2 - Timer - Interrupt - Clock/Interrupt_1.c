#include <msp430.h> 

int main(void) {
  WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
  
  P1DIR |= BIT0 | BIT6;
  P1OUT &= ~BIT0;
  P1OUT |= BIT6;
  
  P1REN |= BIT3;
  P1OUT |= BIT3;
  
  P1IE |= BIT3;
  P1IES |= BIT3;
  
  P1IFG &= ~BIT3;
  
  
  __bis_SR_register(LPM0_bits + GIE);
  return 0;
}

#pragma vector = PORT1_VECTOR
__interrupt void P1ISR(void) {  
  P1OUT ^= BIT0 | BIT6;
  __delay_cycles(100000);
  P1IFG &= ~BIT3;
}