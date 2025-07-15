#pragma once

#include <stddef.h>

typedef struct ShellCommand {
  const char *command;
  int (*handler)(int argc, char *argv[]);
  const char *help;
  const int nargs = 0;
} sShellCommand;

extern const sShellCommand *const g_shell_commands;
extern const size_t g_num_shell_commands;

typedef struct ShellImpl {
  //! Function to call whenever a character needs to be sent out.
  int (*send_char)(char c);
  const char* prompt;
} sShellImpl;

//! Initializes the demo shell. To be called early at boot.
void shell_boot(const sShellImpl *impl);

//! Call this when a character is received. The character is processed synchronously.
void shell_receive_char(char c);

//! Print help command
int shell_help_handler(int argc, char *argv[]);

//! Writes string to output
void prv_echo_str(const char *str);

//! Prints a line then a newline
void shell_put_line(const char *str);


void shell_set_echo(const bool);
void prv_echo(char c);

