// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set_short("Southern wall along the Daroq Mountains Pass");
    set_long( "Rocks of all shapes and sizes litter the mountains and the path making the "
                "footing treacherous in places.  A bird's nest in a nearby tree looks like it has "
                "weathered with age.  The crunching of the gravel underfoot echo off into the "
                "mountains.  The Tak'dar Mountain Pass cuts through the tall mountain range."
                "A small cave entrance rests in the mountain walls here."); 

    set_night_long("Rocks of all shapes and sizes litter the mountains and the path making the "
                      "footing treacherous in places.  A bird's nest in a nearby tree looks like it has "
                      "weathered with age.  The crunching of the gravel underfoot echo off into the "
                      "darkness.  The Tak'dar Mountain Pass cuts through the tall mountain range in pitch "
                      "blackness. A small cave entrance rests in the mountain walls here."); 
  set_exits( ([ 

"northwest": ROOMS"tirunmts_323.c",
"north": ROOMS"tirunmts_324.c",
"cave" : "/d/nopk/trollcaves/room/cave1",
  ]) );
}