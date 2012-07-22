#include <std.h>
#include <wedding.h>
inherit ROOM;


void init() {
  ::init();
        add_action ("lay_down","lie");
}

void create() {
::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 1, "no
attack" : 1,
"no bump" : 1]) );
    set_short("%^BOLD%^%^BLUE%^The Wedding Glade%^RESET%^");
    set_long( "%^BOLD%^%^BLUE%^The Wedding Glade%^RESET%^\n"
"This is a wide clearing with towering pines rising up "
"majestically around it. The entrance of the clearing contains "
"cushions for those who have been fighting a little hard and "
"need something soft to sit on. Two pavilions are set on "
"either side of the entrance. The one on the right is set aside for the groom "
"and the one on the left is for the bride. There is chattering coming from the "
"bridal pavilion and laughter from the groom's. A cake is set up next to the "
"groom's pavilion and a feast is being prepared elsewhere. There is an alter "
"made of alabaster and marble in the center of the clearing with an aisle leading "
"up to it. Birds and small animals call and play around the clearing, as if "
"knowing they are safe. Bards play harps and bells to welcome visitors.  The "
"grass is green and lush, inviting one to lay down and enjoy the warmth.  The "
"aisle separates out the two columns of benches which is covered in a red "
"velvetlike cloth."); 
    set_items(([
        "glade" : "This is a glade where peace reigns.  It has been set aside for peaceful gatherings such as weddings and funerals.",
"benches" : "Perhaps you take a pillow and have a seat to wait for the wedding to begin.",
        "cake" : "The cake is three-tiered and has a magical fountain of white w ine flowing through it.",
        "alter" :  "The alter is made of alabaster and marble.  It contains bas-reliefs of all the immortals.  Some of whom seem to be mugging for the artist."]));
    set_exits( (["out" : "/d/tirun/square",]) );
}
int lay_down(string str) {
if(!str) {
        notify_fail("lie on what?\n");

        return 0;

    }
    if(str != "down") {
        notify_fail("You can't lie there!\n");
        return 0;
    }
  else {
    if(this_player()->query_stats("dexterity") < 1){
   say(this_player()->query_cap_name()+" sits down on a wide bench made "
"for this occasion.");
    notify_fail("You sit down on a wide bench made for this occassion.\n");
       return 0;}

  }
}

void reset() {
 ::reset();
  if (!present("priestess", this_object()))
    new(MOBS"priestess" )->move(this_object());
}
