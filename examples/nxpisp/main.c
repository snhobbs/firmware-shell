#include "shell/shell.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

int console_putc(char c) {
  printf("%c", c);
  return 1;
}

char console_getc(void) {
  uint8_t cr;
  return getc(stdin);
}


int main(void) {
  sShellImpl shell_impl = {
    .send_char = console_putc,
  };
  shell_boot(&shell_impl);
  
  char c;
  while (true) {
    c = console_getc();
    shell_receive_char(c);
  }
}
