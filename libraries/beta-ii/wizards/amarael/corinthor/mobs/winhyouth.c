#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("half-elf");
        set_id( ({"halfelf", "half-elf", "youth", "half-elven youth", "halfelven youth"}) );
        set_short("Half-elven youth");
        set_long("By the shorter hair and less pointed ears, it would seem that this is a young half-elf, rather than a full elf.");
        set_race("half-elf");
        set_gender("male");
        set_body_type("half-elf");
        set_level(random(5)+5);
        new(ELFARMOUR"blkshirt.c")->move(this_object());
           command("wear shirt");
}
