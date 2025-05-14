/*Copyright 2025
Tyler McGurrin*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <argp.h>
#include "xpakd.h"
#include "util.h"

int debug_enable = false;
int verbose_enable = false;

char *package;

const char *argp_program_version =
  "XPM-RD-00006";
const char *argp_program_bug_address =
  "<https://github.com/PKM74/xpm/issues>";

/* Program documentation. */
static char doc[] =
  "A Simple Package Manager for GNU/Linux or Busybox/Linux if thats your thing.";

/* A description of the arguments we accept. */
static char args_doc[] = "";

/* The options we understand. */
static struct argp_option options[] = {
  {"verbose",  'v', 0,      0,  "Produce verbose output" },
  {"debug",  'd', 0,      0,  "Produce debug output" },
  {"quiet",    'q', 0,      0,  "Don't produce any output" },
  {"silent",   's', 0,      OPTION_ALIAS },
  {"output",   'o', "FILE", 0, "Output to FILE instead of standard output" },
  {"install",  'i', "PACKAGE", 0, "Install Packages"},
  { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
  char *args[0];                /* arg1 & arg2 */
  int silent, verbose, install;
  char *output_file;
};

/* Parse a single option. */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *arguments = state->input;

  switch (key)
    {
    case 'd':
      debug_enable = true;
      break;
    case 'q': case 's':
      arguments->silent = 1;
      break;
    case 'v':
      arguments->verbose = 1;
      verbose_enable = true;
      break;
    case 'o':
      arguments->output_file = arg;
      break;
    case 'i':
      printf("Continue With Install? [y/n] ");
      char response;
      scanf(" %c", &response);
      if (response == 'y' || response == 'Y') {
        package = arg;
        printf("Starting Install...\n");
        install(package);

      } else if (response == 'n' || response == 'N') {

        printf("Exiting...\n");
        exit(0);
        
      } else {

        printf("Invalid input. Please enter 'y' or 'n'.\n");

      }
      break;

    case ARGP_KEY_ARG:
      if (state->arg_num >= 100)
        /* Too many arguments. */
        argp_usage (state);

      arguments->args[state->arg_num] = arg;

      break;

    case ARGP_KEY_END:
      if (state->arg_num < 0)
        /* Not enough arguments. */
        argp_usage (state);
      break;

    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt, args_doc, doc };

int main (int argc, char **argv) {
  struct arguments arguments;

  /* Default values. */
  arguments.silent = 0;
  arguments.verbose = 0;
  arguments.output_file = "-";
  arguments.install = 0;

  /* Parse our arguments; every option seen by parse_opt will
    be reflected in arguments. */
  argp_parse (&argp, argc, argv, 0, 0, &arguments);

  // debug_print("ARG1 = %s\nARG2 = %s\nOUTPUT_FILE = %s\n"
  //           "VERBOSE = %s\nSILENT = %s\n",
  //           arguments.args[0], arguments.args[1],
  //           arguments.output_file,
  //           arguments.verbose ? "yes" : "no",
  //           arguments.silent ? "yes" : "no");

  exit (0);
}