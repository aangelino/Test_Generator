#include "mbed.h"

#define DEBUG_PRINT_PULSES 0
DigitalOut led1(LED1);
DigitalOut test_out(D7);
DigitalIn start_in(D8,PullDown);
PwmOut pwm_out_9(D9);
Timer timer;

Serial pc(SERIAL_TX, SERIAL_RX);
int pulses_number;


/*a*/
void callback_thread_100Hz()
{
  int i,j;
  pc.printf("\n\r start thread_100Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif
    test_out.write(1);
    /*5ms*/
    for (j=0;j<10;j++) {wait_us(500);}
    test_out.write(0);
    /*5ms*/
    for (j=0;j<10;j++) {wait_us(500);}
  }
}

/*b*/
void callback_thread_150Hz()
{
  int i,j;
  pc.printf("\n\r start thread_150Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*3.3ms*/
    for (j=0;j<6;j++) {wait_us(500);}
    wait_us(300);
    test_out.write(0);
    /*3.3ms*/
    for (j=0;j<6;j++) {wait_us(500);}
    wait_us(300);
  }
}

/*c*/
void callback_thread_200Hz()
{
  int i,j;
  pc.printf("\n\r start thread_200Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*2.5ms*/
    for (j=0;j<5;j++) {wait_us(500);}
    test_out.write(0);
    /*2.5ms*/
    for (j=0;j<5;j++) {wait_us(500);}
  }
}

/*d*/
void callback_thread_250Hz()
{
  int i,j;
  pc.printf("\n\r start thread_250Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*2ms*/
    for (j=0;j<4;j++) {wait_us(500);}
    test_out.write(0);
    /*2ms*/
    for (j=0;j<4;j++) {wait_us(500);}
  }
}

/*e*/
void callback_thread_300Hz()
{
  int i,j;
  pc.printf("\n\r start thread_300Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*1.65ms*/
    for (j=0;j<3;j++) {wait_us(500);}
    wait_us(150);
    test_out.write(0);
    /*1.65ms*/
    for (j=0;j<3;j++) {wait_us(500);}
    wait_us(150);
  }
}

/*f*/
void callback_thread_350Hz()
{
  int i;
  pc.printf("\n\r start thread_350Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*1.4ms*/
    wait_us(500);
    wait_us(500);
    wait_us(400);
    test_out.write(0);
    /*1.4ms*/
    wait_us(500);
    wait_us(500);
    wait_us(400);
  }
}

/*g*/
void callback_thread_400Hz()
{
  int i;
  pc.printf("\n\r start thread_400Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*1.25ms*/
    wait_us(500);
    wait_us(500);
    wait_us(250);
    test_out.write(0);
    /*1.25ms*/
    wait_us(500);
    wait_us(500);
    wait_us(250);
  }
}

/*h*/
void callback_thread_450Hz()
{
  int i;
  pc.printf("\n\r start thread_450Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*1.11ms*/
    wait_us(500);
    wait_us(500);
    wait_us(110);
    test_out.write(0);
    /*1.11ms*/
    wait_us(500);
    wait_us(500);
    wait_us(110);
  }
}

/*i*/
void callback_thread_500Hz()
{
  int i;
  pc.printf("\n\r start thread_500Hz");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    /*1ms*/
    wait_us(500);
    wait_us(500);
    test_out.write(0);
    /*1ms*/
    wait_us(500);
    wait_us(500);
  }
}


/*l*/
void callback_thread_1KHz()
{
  int i;
  pc.printf("\n start thread_1KHz\n");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    wait_us(500);
    test_out.write(0);
    wait_us(500);
  }
}

/*m*/
void callback_thread_10KHz()
{
  int i;
  pc.printf("\n start thread_10KHz\n");

  for (i=0;i<pulses_number;i++)
  {
#if DEBUG_PRINT_PULSES
    pc.printf("\n\r i:%d",i);
#endif

    test_out.write(1);
    wait_us(50);
    test_out.write(0);
    wait_us(50);
  }
}


// main() runs in its own thread in the OS
int main()
{
  //GPIOA->AFR[0] &= 0xfffffff0;
    //test_out.write(0);
    /*Pwm Settings*/
    //pwm_out_9.period_ms(10);
    //pwm_out_9.write(0);

    /*start directly thread, callback needs to contain argument f(void const *args) */
    //Thread thread_10Hz(callback_thread_10Hz);

    /*Thread instanziation objects*/
    Thread thread_1Hz;
    Thread thread_10Hz;
    Thread thread_100Hz;
    Thread thread_150Hz;
    Thread thread_200Hz;
    Thread thread_250Hz;
    Thread thread_300Hz;
    Thread thread_350Hz;
    Thread thread_400Hz;
    Thread thread_450Hz;
    Thread thread_500Hz;
    Thread thread_1KHz;
    Thread thread_10KHz;

    /*Info system clock*/
    pc.printf("\n\rSystemCoreClock=%d\r\n",SystemCoreClock);

    /*User Interface*/
    pc.printf("\r\n Choose number of pulses \r\n");
    pc.printf("\r\n a. 10       pulses ");
    pc.printf("\r\n b. 100      pulses ");
    pc.printf("\r\n c. 1000     pulses ");
    pc.printf("\r\n d. 10000    pulses ");
    pc.printf("\r\n e. 100000   pulses \r\n");

    switch(pc.getc())
    {
      case 'a': pc.printf("\n\r ---> it will be sent 10 pulses ");
                pulses_number=10;
                break;
      case 'b': pc.printf("\n\r ---> it will be sent 100 pulses ");
                pulses_number=100;
                break;
      case 'c': pc.printf("\n\r ---> it will be sent 1000 pulses ");
                pulses_number=1000;
                break;
      case 'd': pc.printf("\n\r ---> it will be sent 10000 pulses ");
                pulses_number=10000;
                break;
      case 'e': pc.printf("\n\r ---> it will be sent 100000 pulses ");
                pulses_number=100000;
                break;
      default : pc.printf("\n\r Wrong choose");
                break;
    }

    pc.printf("\n\r Choose Frequency/Period \n");

    pc.printf("\n\r a. 100Hz/10ms    ");
    pc.printf("\n\r b. 150Hz/6.66ms  ");
    pc.printf("\n\r c. 200Hz/5ms     ");
    pc.printf("\n\r d. 250Hz/4ms     ");
    pc.printf("\n\r e. 300Hz/3.3ms   ");
    pc.printf("\n\r f. 350Hz/2.8ms   ");
    pc.printf("\n\r g. 400Hz/2.5ms   ");
    pc.printf("\n\r h. 450Hz/2.22ms  ");
    pc.printf("\n\r i. 500Hz/2ms     ");
    pc.printf("\n\r l. 1KHz/1ms      ");
    pc.printf("\n\r m. 10KHz/100us   \n\r");



    switch(pc.getc())
    {
      case 'a': pc.printf("\n\r --> sending train of %d pulses at 100Hz ", pulses_number);
                thread_100Hz.start(callback_thread_100Hz);
                break;
      case 'b': pc.printf("\n\r --> sending train of %d pulses at 150Hz ", pulses_number);
                thread_150Hz.start(callback_thread_150Hz);
                break;
      case 'c': pc.printf("\n\r --> sending train of %d pulses at 200Hz ", pulses_number);
                thread_200Hz.start(callback_thread_200Hz);
                break;
      case 'd': pc.printf("\n\r --> sending train of %d pulses at 250Hz ", pulses_number);
                thread_250Hz.start(callback_thread_250Hz);
                break;
      case 'e': pc.printf("\n\r --> sending train of %d pulses at 300Hz ", pulses_number);
                thread_300Hz.start(callback_thread_300Hz);
                break;
      case 'f': pc.printf("\n\r --> sending train of %d pulses at 350Hz ", pulses_number);
                thread_350Hz.start(callback_thread_350Hz);
                break;
      case 'g': pc.printf("\n\r --> sending train of %d pulses at 400Hz ", pulses_number);
                thread_400Hz.start(callback_thread_400Hz);
                break;
      case 'h': pc.printf("\n\r --> sending train of %d pulses at 450Hz ", pulses_number);
                thread_450Hz.start(callback_thread_450Hz);
                break;
      case 'i': pc.printf("\n\r --> sending train of %d pulses at 500Hz ", pulses_number);
                thread_500Hz.start(callback_thread_500Hz);
                break;
      case 'l': pc.printf("\n\r --> sending train of %d pulses at 1KHz ", pulses_number);
                thread_1KHz.start(callback_thread_1KHz);
                break;
      case 'm': pc.printf("\n\r --> sending train of %d pulses at 10KHz ", pulses_number);
                thread_10KHz.start(callback_thread_10KHz);
                break;

      default : pc.printf("\n\r Wrong choose");
                break;
    }

    while(1)
    {
      /*to main retention, otherwise thread will be died*/
      /*don't leave empty */
      wait(1);
    }

    return 0;
}
