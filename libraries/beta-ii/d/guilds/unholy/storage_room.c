#include <std.h>
#include <guild.h>
inherit ROOM;

void
create()
{
    ::create();
    set_short("storage room");

    set_long("storage room ");
    set_properties(([
	"light":2, "night light":2, "no attack":1, "no magic":1, 
	"no bump":1, "no steal":1, "indoors":1, "no teleport":1,
      ]));


}

void reset() {
    ::reset();
        new("/d/guilds/unholy/shroud.c")->move(this_object());
    if (!present("gauntlets", this_object()))
	new("/d/guilds/unholy/gauntlets.c")->move(this_object());
    if (!present("skull", this_object()))
	new("/d/guilds/unholy/bloody_skull.c")->move(this_object());
}
