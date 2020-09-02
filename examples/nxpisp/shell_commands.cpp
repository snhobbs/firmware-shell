#include "isp_error_codes.h"
#include "shell/shell.h"

#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static inline bool CheckArgLength(const int argc, const int length_low, const int length_high) {
  if (argc <= length_low) {
    shell_put_line("> FAIL,too few arguments,1");
    return false;
  } else if (argc > length_high + 1) {
    shell_put_line("> FAIL,too many arguments,1");
    return false;
  }
  return true;
}

namespace cli {
int cmd_syncronize(int argc, char *argv[]) {
  shell_put_line("syncronized");
  return 0;
}

int cmd_printerror(int argc, char *argv[]) {
  if (!CheckArgLength(argc, 1, 1)) {
    return 0;
  }
  const int code = std::atoi(argv[1]);
  if (code < Isp::return_codes.size() && code > 0) {
    shell_put_line(Isp::return_codes[code]);
  } else {
    shell_put_line("> FAIL,Unknown code,2");
  }
  return 0;
}
}  //  namespace cli

static const sShellCommand s_shell_commands[] = {
  {"?", cli::cmd_syncronize, "Required for compatability with NXP ISP loader"},
  {"lookup_error", cli::cmd_printerror, "Print name of error code"},
  {"help", shell_help_handler, "Lists all commands"},
};

const sShellCommand *const g_shell_commands = s_shell_commands;
const size_t g_num_shell_commands = ARRAY_SIZE(s_shell_commands);
