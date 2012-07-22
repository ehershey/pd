inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "spear", "crude spear", "wooden spear" }));
   set_name("spear");
   set_short("a crude wooden spear");
   set_long("A very sharp branch from a jungle tree. It makes a crude, but usable, spear.");
   set_weight(8);
   set_curr_value("gold", 3);
   set_wc(6);
   set_ac(1);
   set_type("projectile");
}
