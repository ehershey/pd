#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("Bishop Brum Soulstone");
         set_id(({ "dwarf", "bishop", "brum", "brum soulstone", "bishop brum soulstone" }));
         set_short("Bishop Brum Soulstone");
         set_long("The Bishop is the head of this monestary. He is a "
                 "highly respected authority figure in Steel Hammer Village. "
                 "He is a kind soul who would do anything for anybody. Bishop "
                 "Soulstone is one of the Village Elders and there isn't "
		 "much that happens in the Village that he doesn't catch "
		 "wind of.");
         set_race("dwarf");
         set_class("clergy");
         set_subclass("monk");
         set_body_type("dwarf");
         set("aggressive", 0);
         set_gender("female");
         set_level(110);
set_spell_chance(70);
         set_spells(({"supplication bishop", "eagleclaw", "furystrike", "ironskin"}));
    new(ARM"monksrobe.c")->move(this_object());
    command("wear robe");
    new(ARM"sandals.c")->move(this_object());
    command("wear sandals");
}



void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%squest%s", a, b) == 2) {
        this_object()->force_me("say Yes, I do have a quest I need completed! "
	 "You see, although this may be a holy place, there is a great evil "
	 "far below us, waiting to erupt and wage a war. They have already "
	 "taken our sacred White Dragon prisoner, alas I don't know what "
	 "to do.");
        return;
    }
    if(sscanf(str, "%sdragon%s", a, b) == 2) {
        this_object()->force_me("say The White Dragon watches over "
	"the village and now we are extremely vulnerable. Please help "
	"and find the way to the tunnels below!");
        return;
    }
    if(sscanf(str, "%stunnels%s", a, b) == 2) {
        this_object()->force_me("say The tunnels are hidden "
	"deep below the monestary. The evil down there is "
	"too strong. But it is up to you, you must find the way!");
        return;
    }
    if(sscanf(str, "%sway%s", a, b) == 2) {
        this_object()->force_me("say I cannot tell you the way, "
	"it is up to you to find it! That is your first objective, "
	"find the hidden tunnels. All I can tell you is the way "
	"down is within the walls of the monestary. Look "
	"at the painting.\nBishop Soulstone points to the painting "
	"behind his desk.\nsay Good luck, adventurer. May you "
	"have the spirit of the Dragon Lord at your aide.");
        return;
    }
    if(sscanf(str, "%s gives you %s", a, b) == 2) {
        call_out("check_quest", 2, ({ lower_case(a), lower_case(b) }) );
    }
}

void check_quest( string *what ) {
    object tp, ob;
    string who, that;

    who = what[0];
    that = what[1];
    tp = present(who, environment(this_object()));
    ob = present("tablet");
    if(!tp) return;
    if(!ob) {
        tell_object(tp, "Bishop Soulstone shakes his head.");
        return;
    }
    if(!ob->id("stone_book_qo")) {
        tell_object(ob, "%^CYAN%^Bishop Soulstone says:%^RESET%^ Alas, this is not "
	 "the proof I was looking for.");
        force_me("give "+that+" to "+who);
        return;
    }
    tell_room(environment(this_object()), "Bishop Soulstone lights up with "
	"excitement..",
      this_object());
    tell_object(tp, "%^CYAN%^Bishop Soulstone says:%^RESET%^ Thank you, my friend. "
	 "May you always be blessed by the spirit of the Dragon Lord and our "
	 "sacred White Dragon! May you leave here in peace!");
    ob->remove();
    ob = new(ITEMS"tablet.c");
    ob->move(this_object());
    if(!tp->set_quest("stone book", 100, "Rescued the sacred White Dragon"))
        tp->add_exp(5000000));
}
