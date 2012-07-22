#include <std.h>
#include <sakura.h>
inherit ROOM;

string *lines = ({"newbie","auction","clergy","cleric","druid","kataan","monk","dragon","black","blue","red","white","fighter","antipaladin","berserker","paladin","ranger","warrior","mage","necromancer","pyromancer","sorcerer","wizard","rogue","assassin","scout","thief","thug","wanderer","bard","gypsy","jester","swashbuckler","darksoul","DW","ethereal","unholy","scorpio","vorticon","forsaken","illuminati","chosen","dw","aod","acheron","hm","legend","colosseum","gossip","OOC","trivia","elite","demon","angel","lich","vampire","guild","council","shout","tell","emoteto","open","spin"});
string *imprisoned = ({""});

string owner="venenum";

void create() {
    ::create();
    set_short("Venenum's Dungeon");
    set_long("This is the end of the road for evildoers. This dungeons is where Venenum stores his latest meal. If you are here, you have been bad and may not be released until Venenum or another admin is satisfied that you are not guilty. \n\n Here, Venenum may imprison, release, silence or emancipate people.");
    set_smell("default", "The smell of death is here.");
    set_listen("default", "Only the rattling of chains can be heard here.");
    set_properties(([
	"light" : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no_teleport" : 1,
	"no gate" : 1,
	"no_gate" : 1,
	"no magic" : 1,
	"no_magic" : 1,
	"no attack" : 1,
	"no_attack" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"out" : "/wizards/venenum/workroom.c",
      ]));
    set_pre_exit_functions( ({"out"}), ({"check_canescape"}) );
}

void init() 

{
    ::init();
    add_action("imprison", "imprison");
    add_action("release", "release");
    add_action("silence", "silence");
    add_action("emancipate", "emancipate");
    add_action("catch_talk", "", 1);

}

int imprison(string str) {

    if (this_player()->query_name() != owner) {write("DENIED."); return 1;}
    write("You imprison "+find_player(str)->query_cap_name()+".");
    find_player(str)->move(this_object());
    find_player(str)->set_primary_start("/wizards/venenum/workroom/dungeon");
    return 1;
}

int release(string str) {

    if (this_player()->query_name() != owner) {write("DENIED."); return 1;}
    write("You release "+find_player(str)->query_cap_name()+".");
    find_player(str)->move("/d/nopk/tirun/square");
    find_player(str)->set_primary_start("/d/nopk/tirun/square");
    return 1;
}

int silence(string str)
{
    if (this_player()->query_name() != owner) {write("DENIED."); return 1;}
    write("You silence "+find_player(str)->query_cap_name()+".");
    find_player(str)->set_paralyzed(10000, "You have been silenced for being a doodyhead.");
    return 1;
}

int emancipate(string str)
{
    if (this_player()->query_name() != owner) {write("DENIED."); return 1;}
    write("You emancipate "+find_player(str)->query_cap_name()+".");
    find_player(str)->set_paralyzed(0, "", "You can move again. Now be good.");
    return 1;
}

int catch_talk(string str)
{
    str = query_verb();
    if(this_player()->query_level() < 200) 
    {          
	if(member_array(str, lines) != -1)
	{
	    write("You may not talk on that line.");
	    return 1;
	}
    }
}

int check_canescape()
{
    if (this_player()->query_level() < 200) {write("The guards refuse to release you.");}
    else {write("You walk free of the dungeon."); return 1;}
}
