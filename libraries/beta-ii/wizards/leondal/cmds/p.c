#include <std.h>

int main(string arg) {
  string FILE;
  FILE="/cmds/creator/_people.c";
  return call_other((object)FILE,"cmd_people",(string)arg);
}
