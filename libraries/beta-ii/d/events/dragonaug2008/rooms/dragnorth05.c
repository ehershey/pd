#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1   ]));
    set_short("Dragon Lands North");
    set_day_long("The mountain-top path has been trampled firmly into place, there is not a bump or shrub near it to be seen. The mountain ridge below extends off to the east and the south along with the path, which bends off the side of the ridge to the northwest into a smoothly rounded edge. The mountain ridge also extends to the west, but it is too rocky to traverse. The mountain ridge drops off steeply to the southeast. The view to the northwest is magnificent, overlooking the beach and ocean below. Far along the mountain to the southeast there seems to be an intricate path along the ridges of the mountain, which twist and dodge between great gaping chasms.");
    set_night_long("The mountain-top path has been trampled firmly into place, there is not a bump or shrub near it to be seen. The mountain ridge below extends off to the east and the south along with the path, which smoothly drops off the ridge to the northwest into the darkness below. The mountain ridge to the west is covered with dark colossal shapes which seem to impede passage. The mountain ridge drops off steeply to the southeast into darkness. The view to the northwest in the night sky is magnificent yet daunting, overlooking the dark path below. Far along the mountain to the southeast the moonlight mountain ridges twist and dodge between great gaping chasms.");
    set_exits( ([
	"northwest" : DRAG_ROOMS"dragnorth04.c",
	"east" : DRAG_ROOMS"dragnorth06.c",
	"south" : DRAG_ROOMS"dragnorth08.c",
	"pathing_mob_fly" : DRAG_ROOMS"dragnorth04.c",
      ]) );
    set_items( ([
      "path" : "It is below you.",
      ]) );
    add_invis_exit("pathing_mob_fly");
    add_pre_exit_function("pathing_mob_fly", "mob_path_fly");
}

int mob_path_fly() {
    if(!this_player()->is_player() && !this_player()->query_flying_mob()) return 0;
    if (!this_player()->force_me("fly")) {
	write("You take a flying leap of faith off the northwest side of the mountain ridge.");
	message("info", this_player()->query_cap_name()+" runs off the side of the cliff flapping "+this_player()->query_possessive()+" arms.", environment(this_player()), this_player());
	write("%^RED%^You break your face.%^RESET%^");
	this_player()->add_hp(-50);
	return 1;
    }
    return 0;
}

void drag_fly(object ob) {
    ob->force_me("fly");
}

void reset() {
    object newMob;
    ::reset();
    if(sizeof(children(DRAG_MOBS"flydrag.c")) < 5) {
	newMob = new(DRAG_MOBS"flydrag.c");
	newMob->move(this_object());
	//call_out((: newMob->force_me :), 1, "fly");
	call_out((:drag_fly:), 1, newMob);
    }
}
