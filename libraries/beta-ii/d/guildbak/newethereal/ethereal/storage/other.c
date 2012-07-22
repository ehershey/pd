#include <std.h>
#include <guild.h>
#include <ether.h>
inherit ROOM;

void create() {
    ::create();
    set_name("misc storage");
    set_short("misc");
    set_long("This is the misc. storage room to Ethereal.  You shouldnt be in
here.");
    set_exits((["north":ROOMS"2-1.c"]));
}

void reset() {
    ::reset();
    if(!present("ring", this_object())) {
        new(OBJ"ring")->move(this_object());
        new(OBJ"ring")->move(this_object());
    }
    if(!present("sack", this_object())) {
        new(OBJ"sack")->move(this_object());
        new(OBJ"sack")->move(this_object());
    }
    if(!present("bracelet", this_object())) {
        new(OBJ"bracelet")->move(this_object());
        new(OBJ"bracelet")->move(this_object());
    }
    if(!present("clasp", this_object())) {
        new(OBJ"rose")->move(this_object());
        new(OBJ"rose")->move(this_object());
    }
    if (!present("arms",this_object())) {
	new(OBJ"coa")->move(this_object());
        new(OBJ"coa")->move(this_object());
    }

}

