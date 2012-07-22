#include <daemons.h>
// Coded by Whit
#include <std.h>
#include <guild.h>

inherit ROOM;
mapping leader, council;
string *leaders, *councils;
int i;
object ob;
void init() {
    ::init();
}
void create() {
    ::create();
    restore_object("/d/guilds/save/blackforce");
    set_short("Scorpio Hall");
    set_properties( (["light" : 3, "night light" : 2, "indoors" :
	1, "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1]) );
    set_long("This is the heart of the Scorpio guild.  "
      "The dark glow that illuminates the darkness comes from a "
      "small sphere floating above the middle of the room. There "
      "seems to be a very hidden and secret force that runs through "
      "here. The is a small table that runs along the wall that "
      "has many strange vials on top of it. The distortion from the "
      "sphere makes the room seem as though it is spinning. There is "
      "a large board in the middle of the room that members of the "
      "guild can post about evil plots or anything that may come to "
      "mind.");
    set_exits(([
	"hall" : ROOMS"meeting",
	"up" : ROOMS"blackforce/entrance.c",
	"south" : ROOMS"blackforce/treasury.c",
	"east" : ROOMS"blackforce/meeting.c",
      ]) );
    set_items(([
	"picture" : "It is the pircture of the current guild master "
	"Mochaprincess.",
	"sphere" : "It gives off a dark and mystical force.",
	"table" : "Many vials of poisons lay upon the table.",
      ]));

    ob = new(BBOARD);
    ob->set_location(ROOMS"blackforce/hall.c");
    ob->set_id(({ "board", "scorpio board" }));
    ob->set_board_id("scorpio");
    ob->set_edit_ok(GUILD_D->post_able("scorpio"));
    ob->set_max_posts(99);
    ob->set_short("the Scorpio Board of evil plots");
    ob->set_long("The Scorpio");
}

