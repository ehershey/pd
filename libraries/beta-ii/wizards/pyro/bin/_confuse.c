#include <std.h>

inherit DAEMON;

int cmd_confuse(string str) {
  if(str == "off") return notify_fail("wut?\n");
  "/wizards/pyro/bin/_ddg"->cmd_ddg("drop");
  "/wizards/pyro/bin/_mic"->cmd_mic("off");
  "/wizards/pyro/bin/_mic"->cmd_mic("me");
  "/wizards/pyro/bin/_ddg"->cmd_ddg("/wizards/pyro/kitten.c");
  write("Try not to break the illusion.");
  return 1;
}
