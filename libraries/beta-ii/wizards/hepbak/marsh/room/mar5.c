#include <std.h>
#include <marshserver.h>


inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : ROOMS "mar4",
"north" : ROOMS "mar7",
"south" : ROOMS "ele25",
"southwest" : ROOMS "ele24",
    ]) );

}
