inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "el_knife";
    short = "el_knife";
    long = "el_knife (PS Your guild leaders are lazy!)";
    id = ({"el_knife"});
    type = "blade";
    wield = "You wield the el_knife.";
    unwield = "You unwield the el_knife.";
    guild = "aod";
    playerm = "Biff! Bang!";
    targetm = "Biff! Bang!";
    roomm = "Biff! Bang!";
    return 1;
}
