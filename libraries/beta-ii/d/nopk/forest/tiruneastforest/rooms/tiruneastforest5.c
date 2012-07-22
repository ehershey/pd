/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest4.c", "east" : ROOMS "tiruneastforest6.c",
    /* "north" : "/d/nopk/standard/outlands/brig_pub" */
]));
}


