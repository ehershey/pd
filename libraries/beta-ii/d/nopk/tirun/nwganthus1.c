#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Northwest Ganthus Circle.");
    set_long(
      "Ganthus Road is a lightly-traveled road that circles around the heart of "
      "Tirun.  Because it leads through a rich neighborhood the road is as well "
      "guarded as the market.  The stones underfoot are well kept and the road "
      "is clean.  Large houses line the road to the north, east, and west.  ");
    set_night_long(
      "Ganthus Road is deserted and peaceful at night.  To the north, east, and west, "
      "the shadows coalesce into buildings.  The stones underfoot are hard to "
      "make out in the darkness.  The road leads off into the darkness to the "
      "northeast and south.  ");
    set_exits(([
	"south"  : ROOMS"nganthus",
	"northeast"  : ROOMS"nwganthus2",
        "enter wanderer hall" : ROOMS"wand/wanderer_join.c",
      ]) );
add_exit_alias("enter wanderer hall", "wanderer hall");
add_exit_alias("enter wanderer hall", "wanderer");
add_exit_alias("enter wanderer hall", "hall");
add_exit_alias("enter wanderer hall", "n");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
      (["road" : "Ganthus Road runs through the heart of Tirun.",
	"houses" : "Large two story brownstone houses."]) );
}
