#include "shell/shell.h"

#include <cstdio>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <strings.h>
#include <array>

#ifndef SHELL_RX_BUFFER_SIZE
#define SHELL_RX_BUFFER_SIZE (256)
#endif

#if 0
#ifndef SHELL_PROMPT
#ifdef NO_SHELL_PROMPT
#define SHELL_PROMPT ""
#else
#define SHELL_PROMPT "shell> "
#endif
#endif
#endif

#ifndef SHELL_MAX_ARGS
#define SHELL_MAX_ARGS (16)
#endif

//#define SHELL_RX_BUFFER_SIZE (256)
//#define SHELL_PROMPT "shell> "

#define SHELL_FOR_EACH_COMMAND(command) \
  for (const sShellCommand *command = g_shell_commands; \
    command < &g_shell_commands[g_num_shell_commands]; \
    ++command)

namespace Shell {
static bool echo = false;
}

bool shell_get_echo(void) {
  return Shell::echo;
}

void shell_set_echo(const bool mode) {
  Shell::echo = mode;
}

static struct ShellContext {
  int (*send_char)(char c);
  const char* shell_prompt;
  size_t rx_size;
  std::array<char, SHELL_RX_BUFFER_SIZE> rx_buffer{'\0'};
} s_shell;

static bool prv_booted(void) {
  return s_shell.send_char != NULL;
}

static void prv_send_char(char c) {
  if (!prv_booted()) {
    return;
  }
  s_shell.send_char(c);
}

void prv_echo(char c) {
  if ('\n' == c) {
    prv_send_char('\r');
    prv_send_char('\n');
  } else if ('\b' == c) {
    prv_send_char('\b');
    prv_send_char(' ');
    prv_send_char('\b');
  } else {
    prv_send_char(c);
  }
}

static char prv_last_char(void) {
  return s_shell.rx_buffer[s_shell.rx_size == 0 ? 0 : s_shell.rx_size - 1];
}

static bool prv_is_rx_buffer_full(void) {
  return s_shell.rx_size >= s_shell.rx_buffer.size();
}

static bool prv_is_rx_buffer_empty(void) {
  return s_shell.rx_size <= 0;
}

static void prv_reset_rx_buffer(void) {
  s_shell.rx_buffer[0] = '\0';
  s_shell.rx_buffer[1] = '\0';
  s_shell.rx_size = 0;
}

void prv_echo_str(const char *str) {
  for (const char *c = str; *c != '\0'; ++c) {
    prv_echo(*c);
  }
}

static void prv_send_prompt(void) {
  prv_echo_str(s_shell.shell_prompt);
}

static const sShellCommand *prv_find_command(const char *name) {
  SHELL_FOR_EACH_COMMAND(command) {
#ifdef SHELL_USE_STRCASECMP
	if (strcasecmp(command->command, name) == 0) {
#else
    if (strcmp(command->command, name) == 0) {
#endif
      return command;
    }

  }
  return NULL;
}

static void prv_process(void) {
  if (prv_last_char() != '\n' && !prv_is_rx_buffer_full()) {
    return;
  }

  char *argv[SHELL_MAX_ARGS] = {0};
  int argc = 0;

  char *next_arg = NULL;
  for (size_t i = 0; i < s_shell.rx_size && argc < SHELL_MAX_ARGS; ++i) {
    char *const c = &s_shell.rx_buffer[i];
    if (*c == ' ' || *c == '\n' || i == s_shell.rx_size - 1) {
      *c = '\0';
      if (next_arg) {
        argv[argc++] = next_arg;
        next_arg = NULL;
      }
    } else if (!next_arg) {
      next_arg = c;
    }
  }

  if (s_shell.rx_size == SHELL_RX_BUFFER_SIZE) {
    prv_echo('\n');
  }

  if (argc >= 1) {
    const sShellCommand *command = prv_find_command(argv[0]);
    if (!command) {
      prv_echo_str("Unknown command: ");
      prv_echo_str(argv[0]);
      prv_echo('\n');
      prv_echo_str("Type 'help' to list all commands\n");
    } else {
      if (argc <= command->nargs) {
          prv_echo_str("1, Not enough arguments\n");
      } else {
    	  command->handler(argc, argv);
      }
    }
  }
  prv_reset_rx_buffer();
  prv_send_prompt();
}

void shell_boot(const sShellImpl *impl) {
  s_shell.send_char = impl->send_char;
  s_shell.shell_prompt = impl->prompt;
  prv_reset_rx_buffer();
}

void shell_receive_char(char c) {
  if (c == '\r' || prv_is_rx_buffer_full() || !prv_booted()) {
    return;
  }

  if (shell_get_echo()) {
    prv_echo(c);
  }

  if (c == '\b' && !prv_is_rx_buffer_empty()) {
    s_shell.rx_buffer[--s_shell.rx_size] = '\0';
    return;
  }

  s_shell.rx_buffer[s_shell.rx_size++] = c;

  prv_process();
}

void shell_put_line(const char *str) {
  prv_echo_str(str);
  prv_echo('\n');
}


int shell_help_handler(int argc, char *argv[]) {
  SHELL_FOR_EACH_COMMAND(command) {
    prv_echo_str(command->command);
    prv_echo_str(": ");
    prv_echo_str(command->help);
    prv_echo('\n');
  }
  return 0;
}
