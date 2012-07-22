// Arena - Seeker Sun Feb  4 11:07:21 PST 2001
#include <std.h>
#include <daemons.h>
//#define BROKEN
#define NUM_ARENA_ROOMS 9
#define ANN_MSG "%^BOLD%^%^BLUE%^Colosseum info: %^RESET%^"
#define VICTORY 1
#define LOSER   2
#define ENTER   3
inherit ROOM;
object *arena;
object *query_arena();
mapping top;
mapping vitals;
void create()
{
    ::create();
    set_short("The Colosseum.");
    set_long("%^RESET%^%^CYAN%^The Tirun Colosseum.%^RESET%^\n"
      "This chamber has a flight of stairs leading down.  The room vibrates with the "
      "noise of cheering and battling.  The fighting area of the Colosseum is below "

      "the ground to take up less space in town and to hide this barbarous past time.\n\n"
      "You can enter the Colosseum to fight by typing <enter>.");
    set_exits( ([ 
        "north" : "/d/nopk/tirun/adv_hall",
        "out"  : "/d/nopk/tirun/square2",
      ]) );
    set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "indoors"     : 1,
        "no steal"    : 1 ]) );
    arena = ({});
    top   = ([]);
    vitals = ([]);
    seteuid("BetSave");
    if (file_size("/d/arena/top.o")!=-1)
        restore_object("/d/arena/top.o");
    seteuid(getuid());
    set_no_clean(1);
}

void init()
{
    ::init();
    if(this_player()->query_hp() < 1) this_player()->move("/d/tirun/square2");
#ifdef BROKEN 
    if (!wizardp(this_player()) && this_player()->query_name() != "wizzy") {
        write("%^RESET%^%^CYAN%^The janitor says: You cant come in here! The arena's going under repairs right now. Come back another day.");
        write("The janitor pushes you out.");
        this_player()->move("/d/tirun/square2");
        return;
    }
#endif
    add_action("enter_arena", "enter");
}

void announce(string str, int type)
{
    object *ann=({});
    ann += arena + ({ this_object() });
    switch(type)
    {
    case VICTORY: message("colosseum", ANN_MSG
          +""+str+"", ann); break;
    case LOSER: message("colosseum", ANN_MSG+""
          +"%^RESET%^%^CYAN%^"+str+"%^RESET%^", ann); break;
    case ENTER: message("colosseum", ANN_MSG+""
          +"%^RESET%^%^GREEN%^"+str+"%^RESET%^", ann); break;
    default: message("colosseum", ANN_MSG+""+str, ann); break;
    }

}

int enter_arena()
{
    int i=random(NUM_ARENA_ROOMS);
    i++;
    if (i>NUM_ARENA_ROOMS) i=NUM_ARENA_ROOMS;
    if(this_player()->query_disable())
        return notify_fail("You are too busy to enter.\n");
    arena += ({ this_player() });
    if (!this_player()->query_can_arena()) {
        write("You must quit before you can arena.");
        return 1;
    }
    if(this_player()->query_mounted()) this_player()->force_me("buck "+this_player()->query_mounted()->query_name());
    // used to be:
    //  this_player()->set_arena( (: this_player(), "arena_die" :) );
    this_player()->set_arena(1);
    /* Nesoo: Saving vitals to restore them once out.
        This is to prevent using the arena to heal. */
    vitals[this_player()] = ({
        this_player()->query_hp(),
        this_player()->query_sp(),
        this_player()->query_mp() });
    this_player()->set_hp(this_player()->query_max_hp());
    this_player()->set_sp(this_player()->query_max_sp());
    this_player()->set_mp(this_player()->query_max_mp());

    /* -------------------------------------------- */
    
    this_player()->move_player("/d/arena/arena"+i, "into the arena");
    CHAT_D->do_colosseum_line("%^BOLD%^%^BLUE%^Colosseum info: %^RESET%^"+this_player()->query_cap_name()+" has entered the colosseum.");
    announce(this_player()->query_cap_name()+" has entered the colosseum.",
      ENTER);

    return 1;
}

void arena_die(object ob)
{
    if (member_array(ob, arena)==-1)
        return;
    if (strsrch(file_name(environment(ob)), "/d/arena") == -1) {
        ob->set_arena(0);
        arena -= ({ ob });
        ob->die();
    }
    announce(ob->query_cap_name()+" has been killed in the Colosseum.", LOSER);
    message("info", "%^BOLD%^%^RED%^You have been slaughtered... Try again.%^RESET%^", ob);
    CHAT_D->do_colosseum_line("%^BOLD%^%^BLUE%^Colosseum info: %^RESET%^%^CYAN%^"+ob->query_cap_name()+" has been killed.%^RESET%^");
    ob->cease_all_attacks();
    ob->set_arena(0);
    if(ob->query_riding())
        ob->query_riding()->die(0);
    ob->remove_effect("bane");
    ob->fix_vital_bonus();
    ob->set_hp(10);
    ob->set_sp(10);
    ob->set_mp(10);
    ob->stop_hunting();
    ob->add_poisoning(-9999);
    ob->set_bleeding(0);
    ob->move("/d/arena/looser.c");
    ob->set_paralyzed(5, "You need a moment to recover.", "You're ready to go.");
    call_out("fheal", 3);
    arena -= ({ ob });
    arena = filter(arena, (: $1 :) ); // remove null objects

    if (sizeof(arena)==1)
    {
        if (arena[0]) {
            announce(arena[0]->query_cap_name()+" is victorious in the Colosseum.",VICTORY);
            message("info", "%^BOLD%^%^WHITE%^You are victorious... Good Job.%^RESET%^", arena[0]);
            CHAT_D->do_colosseum_line("%^BOLD%^%^BLUE%^Colosseum info: %^WHITE%^"+arena[0]->query_cap_name()+" is victorious.");
            arena[0]->cease_all_attacks();
            arena[0]->set_arena(0);
            if(arena[0]->query_riding())
                arena[0]->query_riding()->move("/d/arena/winner.c");
            arena[0]->stop_hunting();
            arena[0]->add_poisoning(-9999);
            arena[0]->add_sp(arena[0]->query_max_sp()-arena[0]->query_sp());
            arena[0]->add_mp(arena[0]->query_max_mp()-arena[0]->query_mp());
            arena[0]->add_hp(arena[0]->query_max_hp()-arena[0]->query_hp());
            //   arena[0]->fix_vital_bonus();
            arena[0]->move("/d/arena/winner");
            arena -= ({ arena[0] });
        }
    }
}

object *query_arena() { return arena; }

int add_points(string name, int x, int alive)
{
    int a=0,d=0;
    if (alive) a = x; else d = x;
    if (!top[name]) {
        top[name] = ([ "alive" : a, "dead" : d ]);
        seteuid("BetSave");
        save_object("/d/arena/top.o");
        seteuid(getuid());
        return 1;
    }
    a = top[name]["alive"];
    d = top[name]["dead"];
    if (alive) a++;
    else d++;
    top[name] = ([ "alive" : a, "dead" : d ]); 
    seteuid("BetSave");
    save_object("/d/arena/top.o");
    seteuid(getuid());
    return 1;
}

int cmd_top()
{

}

int fheal() {
    if( !vitals[this_player()] )
    {
        this_player()->set_hp(random(this_player()->query_max_hp() / 2) + 1);
        this_player()->set_sp(random(this_player()->query_max_sp() / 2) + 1);
        this_player()->set_mp(random(this_player()->query_max_mp() / 2) + 1);
    }
    else
    {
        this_player()->set_hp(vitals[this_player()][0]);
        this_player()->set_sp(vitals[this_player()][1]);
        this_player()->set_mp(vitals[this_player()][2]);
    }
    write("%^BOLD%^GREEN%^Your life force is restored%^RESET%^.");
    return 1;
}

mapping query_top() { return top; }
