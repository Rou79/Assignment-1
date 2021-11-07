void main() {
  int LDR;

  ANSELA.RA1 = 1;
  ANSELD=0;
  TRISA.RA1 = 1;
  TRISD=0;
  
  UART1_Init(9600);
  Delay_ms(100);
  
  UART_Write_Text("LDR Readings:");
  UART1_Write(13);
  UART1_Write(10);
  Delay_ms(2000);

  while(1)
  {
  LDR = ADC_Read(1);

  if(LDR > 500)
  {
   UART1_Write_Text("Liminous");
   UART1_Write(13);
   UART1_Write(10);
   Delay_ms(500);
   PORTD = 0xFF;
   }
   else
   {
   UART1_Write_Text("non luminous");
   UART1_Write(13);
   UART1_Write(10);
   Delay_ms(500);
   PORTD = 0x00;
   }
  }
  }
