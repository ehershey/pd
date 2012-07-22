#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "This path ends at the river.  The water sparkles "
      "under the light from the torch.  Looking up, the "
      "bridge can be seen."
     
    );
    set_items(([
      "path" : "It leads you right up to the river.",
      "river" : "It looks to be quite wide.  You can't "
                "see across it.",
      "water" : "It sparkles in such a way, it makes your "
                "mouth feel dry.",
      "light" : "It is very dim.",
      "torch" : "A wooden torch, not very valuable.",
      "up" : "A bridge crossing the river can be seen "
             "up above.",
      "bridge" : "It is a wooden bridge, it creaks when "
                 "someone crosses it.",
  
    ]));
    set_listen("default", "Water from the river, calms your nerves.");
    set_exits( ([
"northwest" : HIVE "hve9",
    ])  );
}
int get() { return 0; }
int init()
{
 ::init();
 add_action("goDrink", "drink");
}
int goDrink(string str)
{
 if (str!="water") return 0;
 if (this_player()->query_disable())
   {
    write("You cant drink that fast.");
    return 1;
   }
 this_player()->set_disable();
/* this_player()->add_mp(100);
 this_player()->add_sp(100);
 this_player()->add_hp(100);
*/
  this_player()->heal(100);
 write("The pure stream water refreshes you.");
 return 1;
}
void reset() {
 ::reset();
   if (!present("torch", this_object())){
     new( ITEMS "torch" )->move(this_object());
     if (!present("raknid")) 
      new(MOB"rpick")->move(this_object());
     if (!present("raknid")) 
      new(MOB"rshovel")->move(this_object());
    }
}
