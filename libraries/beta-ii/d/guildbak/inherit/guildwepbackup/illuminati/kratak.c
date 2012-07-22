inherit "/d/guilds/inherit/weapon.c";

void create() {
    ::create();
}
void set_weapon()
{
    name = "dagger";
    short = "%^BOLD%^BLACK%^Kra'Tak Dagger%^RESET%^";
    long = "Kra'Tak daggers are made for the less... honourably minded members of the Illuminati. A high quality dagger.";
    id = ({"dagger", "knife", "kra'tak"});
    type = "blade";
    wield = "You wield the Kra'Tak.";
    unwield = "You unwield the Kra'Tak.";
    guild = "illuminati";
    playerm = "%^BOLD%^BLACK%^Your dagger %^RED%^slices%^BLACK%^ "+ob->query_cap_name()+" deeply.%^RESET%^";
    targetm = "%^BOLD%^BLACK%^"+this_player()->query_cap_name()+"'s dagger %^RED%^slices%^%^BLACK%^ you deeply.%^RESET%^";
    roomm = "%^BOLD%^BLACK%^"+this_player()->query_cap_name()+"'s dagger %^RED%^slices%^BLACK%^ "+ob->query_cap_name()+" deeply.%^RESET%^";
    return 1;
}
