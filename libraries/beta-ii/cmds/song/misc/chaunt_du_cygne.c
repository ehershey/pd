#include <std.h>
inherit SONG;

void create() {
    ::create();
    set_verses(({
	"Comming quickly, true is lore,",
	"Quicker now than e'er before,",
	"Shadows gather, Take my soul;",
	"A sleep eternal, Black as coal."
      }));
    set_type("other");
  set_target_required(1);
    set_song_name("chaunt du cygne");
}

int song() {
  object o=this_player();
    if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 230)
	return 1;
}

void finish() {
    object ob, tp;
    tp = this_object()->query_caster();
    ob = this_object()->query_target();
    if (!ob || !present(ob, environment(ob)) ||
      ob->query_race() == "vampire") {
	message("info", "Nothing happens.", environment(ob));
	return;
    }
    if(!wizardp(tp)) {
	message("info", "Nothing happens.", environment(ob));
	return;
    }
}

