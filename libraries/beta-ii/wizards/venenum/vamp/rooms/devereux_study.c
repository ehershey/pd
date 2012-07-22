#include <std.h>
#include <venenum.h>
inherit VAULT;

void create() {
    ::create();
    set_short("Study room");
    set_long("This is clearly the study or den, with a large bookcase and meeting desk with several comfortable chairs neatly arranged together. Books, notes, ink quills and other assorted stationary are laid strewn across the desk, while the bookcase appears to be missing several books. There is no dust or mold to be found here and it would appear to be regularly visited. A doorway to the north leads out to the backyard.");
    set_smell("default", "There are few smells here, apart from the faint smell of soil.");
    set_listen("default", "The house is quiet and peaceful.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"bookcase"}) : "This large bookcase holds a great many books on almost any subject you could think of... although several appear to be missing and recently taken.",
	({"desk"}) : "This solid oak desk is expensive and classy. Underneath the desk, curiously, are several small holes drilled into the ground. The smell of earth comes from them.",
	({"book", "books"}) : "There are many many books here on a wide range of topics including toxicology, botany, history, mathmatics, hematopathology, zoology, ars magna, husbandry, paleoecological studies and various disections on art, music and stageworks.",
	({"missing", "missing books"}) : "There is nothing left of these books except patches in the dust where they once were.",
	({"toxicology"}) : "'Dark Elven Toxins and Poisons' by Arthur Power.",
	({"botany"}) : "'Plants and Shrubs of the Daroq Mountains' by Squee the Brave.",
	({"history"}) : "'Praxis' by Xerxes Martin.",
	({"mathmatics"}) : "'Non-linear geometry and it's applications' by Zarta and Ki'rath Blaine.",
	({"hematopathology"}) : "'Hematopathology in the Modern Era' by Marquis De'bray. This book appears to have a small slot carved into it's spine.",
	({"zoology"}) : "'Wild and Tame Species of the Tenebrae region' by Agnus the Stumpy.",
	({"ars magna", "ars", "magna"}) : "'Anagrams- The Great Art' by Odo Tsuustodo.",
	({"husbandry"}) : "'The Horse Screamer' by Alisha Lovejoy.",
	({"paleoecological", "paleoecological studies"}) : "'Paleoecologial Devices' by Maat Moyo.",
	({"slot"}) : "This slot is about the size of a small coin.",
      ]));
    set_exits(([
	"north" : ROOMS"devereux_backyard.c",
	"west" : ROOMS"devereux3.c",
      ]));
}

void init() 

{
    ::init();
    add_action("insert", "insert");
}

int insert(str)

{
    if(str == "coin")
    {
	if (present("vampire_quest_item", this_player()))
	{
	    write("You slot the coin into the book. With a rumble the bookcase slides back, revealing a passageway down.");
	    present("vampire_quest_item", this_player())->move("/d/nopk/standard/void");
	    add_exit(ROOMS"devereux_hidden_room.c", "down");
	    call_out("remove_exit_func", 20);
	    return 1;
	}
    }
}

int remove_exit_func()

{
    write("The bookcase slides closed with a dull thud.");
    this_object()->remove_exit("down");
    return 1;
}
