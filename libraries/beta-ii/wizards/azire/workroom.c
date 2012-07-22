#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_properties ( ([ "indoors" : 1, "no attack" : 1, "no magic" : 1]) );
    set("short", "%^WHITE%^A%^YELLOW%^z%^WHITE%^i%^YELLOW%^r%^WHITE%^e%^YELLOW%^'%^WHITE%^s %^BOLD%^CYAN%^S%^YELLOW%^t%^CYAN%^a%^YELLOW%^r%^CYAN%^ %^BLUE%^D%^RED%^e%^BLUE%^n%^RESET%^.");
    set("night long", 
"%^BOLD%^BLUE%^Softly %^RESET%^WHITE%^s%^BOLD%^WHITE%^h%^RESET%^WHITE%^i%^BOLD%^WHITE%^n%^RESET%^WHITE%^i%^RESET%^WHITE%^n%^BOLD%^WHITE%^g %^BOLD%^BLUE%^mists form a large cavern, creating "
"%^RESET%^BLUE%^e%^CYAN%^n%^BOLD%^BLUE%^d%^CYAN%^l%^BOLD%^BLUE%^e%^RESET%^CYAN%^s%^BLUE%^s %^BOLD%^CYAN%^p%^WHITE%^a%^CYAN%^tt%^WHITE%^er%^CYAN%^n%^WHITE%^s%^BOLD%^BLUE%^ of %^YELLOW%^light%^BLUE%^ and %^BOLD%^BLACK%^shadow %^BOLD%^BLUE%^within this place. %^CYAN%^C%^WHITE%^r%^CYAN%^y%^WHITE%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l%^WHITE%^ c%^CYAN%^l%^WHITE%^u%^CYAN%^s%^WHITE%^t%^CYAN%^e%^WHITE%^r%^CYAN%^s%^BLUE%^ of all "
"%^RED%^c%^RESET%^ORANGE%^o%^BOLD%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^s sprout from the soft, %^RESET%^WHITE%^w%^BOLD%^WHITE%^h%^RESET%^WHITE%^i%^BOLD%^WHITE%^t%^RESET%^WHITE%^e%^BOLD%^BLUE%^ ground. A sliver of the %^CYAN%^moons %^WHITE%^brilliant%^BLUE%^ face "
"%^BOLD%^BLUE%^shines through a row of large %^GREEN%^w%^YELLOW%^i%^GREEN%^n%^YELLOW%^d%^GREEN%^o%^YELLOW%^w%^GREEN%^s%^BLUE%^, bathing everything in %^WHITE%^silver %^BOLD%^WHITE%^light%^BLUE%^. Many "
"%^BOLD%^BLUE%^shiny objects and large %^RED%^cushions%^BLUE%^ litter the otherwise bare floor.%^RESET%^\n");
    set("day long", "%^RESET%^ORANGE%^G%^BOLD%^YELLOW%^o%^RESET%^ORANGE%^l%^BOLD%^YELLOW%^d%^RESET%^ORANGE%^e%^BOLD%^YELLOW%^n%^RESET%^ORANGE%^ light shifts across the%^WHITE%^ m%^BOLD%^WHITE%^i%^RESET%^WHITE%^s%^BOLD%^WHITE%^t%^RESET%^WHITE%^s%^ORANGE%^ that form this large "
"%^RESET%^ORANGE%^cavern. Large %^BOLD%^CYAN%^c%^BLUE%^r%^CYAN%^y%^BLUE%^s%^CYAN%^t%^BLUE%^a%^CYAN%^l%^BLUE%^ c%^CYAN%^l%^BLUE%^u%^CYAN%^s%^BLUE%^t%^CYAN%^e%^BLUE%^r%^CYAN%^s%^RESET%^ORANGE%^ scatter endless %^BOLD%^RED%^r%^RESET%^ORANGE%^a%^BOLD%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^WHITE%^w%^BOLD%^WHITE%^s %^RESET%^ORANGE%^over the %^YELLOW%^c%^ORANGE%^l%^YELLOW%^o%^ORANGE%^u%^YELLOW%^d%^ORANGE%^l%^YELLOW%^i%^ORANGE%^k%^YELLOW%^e%^ORANGE%^ "
"%^RESET%^ORANGE%^ground. A few %^GREEN%^b%^BOLD%^BLUE%^i%^RESET%^GREEN%^r%^BOLD%^BLUE%^d%^RESET%^GREEN%^s%^ORANGE%^ in flight pass behind a long row of gigantic %^BOLD%^GREEN%^w%^YELLOW%^i%^GREEN%^n%^YELLOW%^d%^GREEN%^o%^YELLOW%^w%^GREEN%^s%^RESET%^ORANGE%^, "
"%^RESET%^ORANGE%^casting quick %^BOLD%^BLACK%^shadows%^RESET%^ORANGE%^ over the many %^BOLD%^YELLOW%^s%^WHITE%^h%^YELLOW%^i%^WHITE%^n%^YELLOW%^y%^RESET%^ORANGE%^ objects and grand %^RED%^cushions that lay "
"%^RESET%^ORANGE%^helter skelter on the otherwise bare floor.%^RESET%^\n");
    set_exits ( ([ "square" : "/d/nopk/tirun/square",
        "hall" : "/d/nopk/standard/adv_main"
      ]) );
    set_items(([ "mists" : "%^BOLD%^BLUE%^The mist %^CYAN%^glows and shifts with a miriad of %^RED%^c%^YELLOW%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r%^BLACK%^s%^BLUE%^,
%^BOLD%^BLUE%^all of which seem soft and subdued, never intruding on the surrounding
%^BOLD%^BLUE%^environment.%^RESET%^",
        "clusters" : "%^BOLD%^CYAN%^Crystals of all sorts seem to sprout straight from the
%^BOLD%^CYAN%^soft white ground. Greedily catching at any %^WHITE%^l%^RESET%^WHITE%^i%^BOLD%^WHITE%^g%^RESET%^WHITE%^h%^BOLD%^WHITE%^t%^CYAN%^, they send softly sparkling
%^BOLD%^CYAN%^light of all %^BOLD%^BLUE%^h%^CYAN%^u%^WHITE%^e%^BLUE%^s %^CYAN%^across the floor.%^RESET%^",
        "ground" : "%^WHITE%^Infinitely soft and %^BOLD%^WHITE%^white%^RESET%^WHITE%^, this could only be made from
the very fabric of the %^CYAN%^clouds.%^RESET%^",
        "windows" : "%^BOLD%^GREEN%^Tall %^YELLOW%^and %^GREEN%^clear, %^YELLOW%^these %^GREEN%^windows %^YELLOW%^would %^GREEN%^suit %^YELLOW%^the %^GREEN%^grandest %^YELLOW%^of
%^GREEN%^all %^YELLOW%^cathedrals. %^GREEN%^The %^YELLOW%^view %^GREEN%^is %^YELLOW%^of %^GREEN%^nothing%^YELLOW%^ but %^GREEN%^endless %^CYAN%^s%^BLUE%^h%^CYAN%^i%^BLUE%^f%^WHITE%^t%^CYAN%^i%^BLUE%^n%^CYAN%^g %^BLUE%^sky.%^RESET%^",
        "objects" : "Set carefully though chaotically around the cavern are
many odd trinkets, most of which sparkle and shine in the light, a tempting
treasure.",
        "cushions" : "%^BOLD%^RED%^Massive cushions dot the cloudy ground, seeming to
%^BOLD%^RED%^spring forth from the floor itself, they look like %^RESET%^WHITE%^moulded %^BOLD%^WHITE%^clouds,%^RED%^ and very
%^BOLD%^RED%^comfortable.%^RESET%^",
        "birds" : "%^BOLD%^GREEN%^Birds %^BLUE%^of %^GREEN%^many %^BLUE%^kinds %^GREEN%^perch %^BLUE%^on %^GREEN%^the %^BLUE%^outside %^GREEN%^of %^BLUE%^the %^GREEN%^tall
%^BOLD%^BLUE%^windows, %^GREEN%^pausing %^BLUE%^at %^GREEN%^this %^BLUE%^refuge %^GREEN%^in %^BLUE%^the %^GREEN%^clouds %^BLUE%^before %^GREEN%^flying %^BLUE%^on %^GREEN%^to %^BLUE%^their
%^BOLD%^GREEN%^destinations.%^RESET%^'"]));
    set_smell("default", "The crisp, delicate scent of ozone and cloud dust
graces this place.");
    set_listen("default", "A soft bird call in the distance is all that breaks
the peaceful silence here.");
}

void reset() {
  ::reset();
  if(!present("bed", this_object()))
    new("/wizards/azire/azirebed.c")->move(this_object());
 if(!present("poster", this_object()))
    new("/wizards/azire/poster.c")->move(this_object());
}
