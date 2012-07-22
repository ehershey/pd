#include <std.h>


inherit ROOM;


void create() {
    ::create();
     set_name("%^BOLD%^%^BLACK%^The Treasury of the D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s.%^RESET%^");
     set_short("Treasury of the Dark Souls");
     set_long("%^BOLD%^%^BLACK%^The Treasury of the D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s.\n
%^BOLD%^%^BLACK%^It looks as if a %^RED%^ma%^RESET%^%^RED%^s%^BOLD%^%^RED%^s%^RESET%^%^RED%^ac%^BOLD%^%^RED%^re %^BLACK%^has gone on in this room.  Severed heads and limbs
%^BOLD%^%^BLACK%^lie scattered, stiff with rigormortis.  The stench of death and decay blankets
%^BOLD%^%^BLACK%^the area causing large %^WHITE%^hordes of flies %^BLACK%^to swarm upon the pools of sticky blood
%^BOLD%^%^BLACK%^and rotting flesh.  An over-sized coffin lined in %^YELLOW%^t%^BLACK%^or%^YELLOW%^n g%^YELLOW%^o%^BLACK%^ld%^YELLOW%^en %^YELLOW%^sil%^BLACK%^k lays in a
%^BOLD%^%^BLACK%^nook at the back of the room.  A %^BLUE%^scroll %^BLACK%^hangs above the coffin with a warning
%^BOLD%^%^BLACK%^written in %^RED%^blood%^BLACK%^ upon it.  <read scroll>\n");
    set_properties((["indoors"     : 1,
                     "light"       : 1,
                     "night light" : 0 ]));
    set_smell("The scent of death lies heavily in the air."); ----------->don't want them visible, only if u type smell, listen
    set_listen("Echoes of death cries can be faintly heard.");------------^
    set_items( ([({"bodies","heads"}):"A large maggot crawls out of an eye socket!",
({"limbs"}):"The hewn body parts of would be thieves.  Guess they learned their lesson...muahahaha!"]));



<read scroll> gives "%^BOLD%^%^RED%^Let the bodies of these would be thieves remain as a
%^BOLD%^%^RED%^warning to those who would attempt to rob the %^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s%^RED%^.  To try...
%^BOLD%^%^RED%^is to sign your death warrent.  (list treasury commands)%^RESET%^