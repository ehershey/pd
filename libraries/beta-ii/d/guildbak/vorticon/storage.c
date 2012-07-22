#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no magic", 1);
    set_property("no attack", 1);
    set_property("no castle", 1);
    set_property("no steal", 1);
    set_property("no teleport", 1);
    set_property("no scry", 1);
    set_short("Vorticon Guild Storage");
    set_long("Vorticon Guild Storage Area. You shouldn't be here so unless you an Imm 
or Admin Bug it!!!");
    set_exits((["south": VORTICON "shop.c"]));
}

void reset() {
    int i;
    ::reset();
    if (!present("sphere")) {
        for (i=0; i<4; i++) {
            new(VORTICON "mysticsphere.c")->move(this_object());
        }
    }
/*
	if (!present("blade")) {
		for (i=0; i<4; i++) {
			new(VORTICON "icedblade.c")->move(this_object());
		}
	}
	if (!present("leggings")) {
		for (i=0; i<4; i++) {
			new(VORTICON "ssleg-rak.c")->move(this_object());
		}
	}
*/
	if (!present("sack")) {
		for (i=0; i<4; i++) {
			new(VORTICON "vortsack.c")->move(this_object());
		}
	}

	/*
        if (!present("necklace")) {
                for (i=0; i<2; i++) {
                new(VORTICON "bnecklace.c")->move(this_object());
                }
        }
        if (!present("talon")) {
                for (i=0; i<4; i++) {
                new(VORTICON "talon.c")->move(this_object());
                }
        }
        if (!present("dagger")) {
                for (i=0; i<4; i++) {
                new(VORTICON "dagger.c")->move(this_object());
                }
        }
    */
}
