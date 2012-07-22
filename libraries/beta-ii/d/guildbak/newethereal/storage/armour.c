#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ROOM;

void create() {
    ::create();
    set_name("armour storage");
    set_short("armour");
    set_long("This is the armour storage room to Ethereal.  You shouldnt be in here.");
    set_exits((["east":ROOMS"2-1.c"]));
}

void reset() {
    ::reset();
    if(!present("wings", this_object())) {
        new(ARM"wingmail")->move(this_object());
        new(ARM"wingmail")->move(this_object());
    }
    if(!present("mask", this_object())) {
        new(ARM"mask")->move(this_object());
        new(ARM"mask")->move(this_object());
    }
    if(!present("delphian tunic", this_object())) {
        new(ARM"tunic")->move(this_object());
        new(ARM"tunic")->move(this_object());
    }
    if(!present("cape", this_object())) {
        new(ARM"cape")->move(this_object());
        new(ARM"cape")->move(this_object());
    }
    if(!present("tail wrap", this_object())) {
        new(ARM"tailwrap")->move(this_object());
        new(ARM"tailwrap")->move(this_object());
    }
    if(!present("belt", this_object())) {
        new(ARM"belt")->move(this_object());
        new(ARM"belt")->move(this_object());
    }

    if(!present("boots", this_object())) {
        new(ARM"boots")->move(this_object());
        new(ARM"boots")->move(this_object());
        new(ARM"bootl")->move(this_object());
        new(ARM"bootr")->move(this_object());
    }
    if(!present("centaurus", this_object())) {
        new(ARM"el_cent")->move(this_object());
        new(ARM"el_cent")->move(this_object());
    }
    if(!present("carapace", this_object())) {
        new(ARM"el_rak")->move(this_object());
        new(ARM"el_rak")->move(this_object());
    }
    if(!present("blanket", this_object())) {
        new(ARM"hm_cent")->move(this_object());
        new(ARM"hm_cent")->move(this_object());
    }
    if(!present("spithrend", this_object())) {
        new(ARM"hm_rak")->move(this_object());
        new(ARM"hm_rak")->move(this_object());
    }

    if(!present("ironclad", this_object())) {
        new(ARM"hshoes")->move(this_object());
        new(ARM"hshoes")->move(this_object());
    }
    if(!present("husk", this_object())) {
        new(ARM"husk")->move(this_object());
        new(ARM"husk")->move(this_object());
    }
    if(!present("sash", this_object())) {
        new(ARM"sash")->move(this_object());
        new(ARM"sash")->move(this_object());
    }
    if(!present("gauntlet", this_object())) {
        new(ARM"glovel")->move(this_object());
        new(ARM"glover")->move(this_object());
    }
     
}

