#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linenoise.h>
#include <string>
#include <curses.h>
#include <unistd.h>


void completion(const char *buf, linenoiseCompletions *lc) {
  if (buf[0] == 'h') {
    linenoiseAddCompletion(lc,"hello");
    linenoiseAddCompletion(lc,"hello there");
  }
}


const char *hints(const char *buf, int *color, int *bold) {
  static const std::string hintString = " World, I'm your wild girl";

  if (!strcasecmp(buf,"hello")) {
    *color = 35;
    *bold = 0;
    return hintString.c_str();
  }

  return NULL;
}


int old_main(int argc, char* argv[])
{
  char *line;
  char *prgname = argv[0];

  /* Parse options, with --multiline we enable multi line editing. */
  while(argc > 1) {
    argc--;
    argv++;
    if (!strcmp(*argv,"--multiline")) {
      linenoiseSetMultiLine(1);
      printf("Multi-line mode enabled.\n");
    } else if (!strcmp(*argv,"--keycodes")) {
      linenoisePrintKeyCodes();
      exit(0);
    } else {
      fprintf(stderr, "Usage: %s [--multiline] [--keycodes]\n", prgname);
      exit(1);
    }
  }

  /* Set the completion callback. This will be called every time the
   * user uses the <tab> key. */
  linenoiseSetCompletionCallback(completion);
  linenoiseSetHintsCallback(hints);

  /* Load history from file. The history file is just a plain text file
   * where entries are separated by newlines. */
  linenoiseHistoryLoad("history.txt"); /* Load the history at startup */

  /* Now this is the main loop of the typical linenoise-based application.
   * The call to linenoise() will block as long as the user types something
   * and presses enter.
   *
   * The typed string is returned as a malloc() allocated string by
   * linenoise, so the user needs to free() it. */
  while((line = linenoise("hello> ")) != NULL) {
    /* Do something with the string. */
    if (line[0] != '\0' && line[0] != '/') {
      printf("echo: '%s'\n", line);
      linenoiseHistoryAdd(line); /* Add to the history. */
      linenoiseHistorySave("history.txt"); /* Save the history on disk. */
    } else if (!strncmp(line,"/historylen",11)) {
      /* The "/historylen" command will change the history len. */
      int len = atoi(line+11);
      linenoiseHistorySetMaxLen(len);
    } else if (line[0] == '/') {
      printf("Unreconized command: %s\n", line);
    }
    free(line);
  }
  return 0;
}


int main(int argc, char* argv[])
{
  // set up for game mode
  initscr();
  noecho();
  curs_set(FALSE);

  // state variables
  int max_x=0;
  int max_y=0;

  int x=0;
  int y=0;

  int next_x=0;
  int direction = 1;


  while(1){
    // blank out screen for new frame
    clear();
    // initialize state variables
    getmaxyx(stdscr, max_y, max_x);

    //  print out ball
    mvprintw(y,x,"o");
    refresh();

    // pause
    usleep(30000);

    // compute next frame
    next_x = x + direction;

    // if we reached a wall, reverse the direction
    if(next_x >= max_x || next_x < 0)
      direction *= -1;

    // update the position
    x += direction;
  }

  sleep(1);

  // restore screen to previous state
  endwin();
}
