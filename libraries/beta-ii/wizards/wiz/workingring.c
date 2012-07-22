#include <std.h>
#include <security.h>
#include <guild.h>
#define GUILDN "darksoul"
#define GSAVEPATH "/d/guilds/data/" GUILDN

inherit ARMOUR;

mapping main = ([]);
mapping member = ([]);
mapping leader = ([]);
mapping council = ([]);

int query_auto_load() {
    if(this_player()->query_guild()!=GUILDN) return 0;
    return 1;
}

void create() {
    ::create();
    restore_object(GSAVEPATH);
    set_name("Darksoul Ring");
    set_type("ring");
    set_short("darksoul ring");
    set_long("This is a ring of the Darksoul guild.");
    set_id(({ "guild ring", "ring", "darksoul ring"}));
    set_limbs(({ "first hand" }));
    set_weight(1);
}

void init() {
    ::init();
    add_action("restore", "restore");
    add_action("add", "add");
    add_action("induct", "induct");
    add_action("reject", "reject");
    add_action("promote", "promote");
    add_action("demote", "demote");
}

int induct(string str) {
    object tp, tpname, ob, obname;

    restore_object(GSAVEPATH);

    if (!str)
        return notify_fail("Induct who?\n");
    tp = this_player();
    tpname = this_player()->query_name();
    ob = present(str, environment(this_player()));
    if (!ob)
        return notify_fail("Induct who?\n");
    if (this_player()->query_guild() != GUILDN && !wizardp(this_player())) {
        write("You arent in this guild.\n");
        this_object()->remove();
    }
    obname = ob->query_name();
    if (!wizardp(this_player()) && member[tpname]) {
        write("You may not induct.\n");
        return 1;
    }
    if(!ob->query_guild()) {
        write("You induct "+ob->query_cap_name()+" into your guild.\n");
        tell_object(ob, "You have been inducted into the "+tp->query_guild()+""
          " by "+tp->query_cap_name()+".");
        ob->set_guild(tp->query_guild());
        seteuid(UID_GUILDSAVE);
        member[obname] = "1";
        save_object(GSAVEPATH);
        write_file("/d/guilds/data/induct", this_player()->query_cap_name()+" added "+ob->query_name()+" to "+tp->query_guild()+"\n");
        seteuid(getuid());
        return 1;
    }
    write("You may not induct those with guild affiliation.\n");
    return 1;
}

int reject(string str) {
    object tp, tpname, ob, obname;

    restore_object(GSAVEPATH);

    if (!str)
        return notify_fail("Reject who?\n");
    tp = this_player();
    tpname = this_player()->query_name();
    ob = present(str, environment(this_player()));
    obname = ob->query_name();
    if (this_player()->query_guild() != GUILDN && !wizardp(this_player())) {
        write("You arent in this guild.\n");
        this_object()->remove();
    }
    if (main[obname])
        return notify_fail("You may not reject that person.\n");

    if(leader[tpname]) {
        if(!ob) return notify_fail("Reject who?\n");
        write("You reject "+ob->query_cap_name()+" from your guild.\n");
        tell_object(ob, "You have been rejected from your guild by"+tp->query_cap_name()+".");
        ob->set_guild();
        seteuid(UID_GUILDSAVE);
        map_delete(leader, obname);
        map_delete(council, obname);
        map_delete(member, obname);
        save_object(GSAVEPATH);
        write_file("/d/guilds/data/reject", this_player()->query_cap_name()+" removed "+ob->query_name()+""
          "from "+tp->query_guild()+"\n\n");
        seteuid(getuid());
        return 1;
    }
    write("You may not reject.\n");
    return 1;
}

int promote(string str) {
    object tp, tpname, ob, obname;

    restore_object(GSAVEPATH);

    if (!str)
       return notify_fail("Promote whom?");

    tp = this_player();
    tpname = this_player()->query_name();
    ob = present(str, environment(this_player()));
    obname = ob->query_name();
    if(this_player()->query_guild()!=GUILDN) {
        write("You arent in this guild.\n");
        this_object()->remove();
    }
    if(!leader[tpname]) return notify_fail("You may not promote.");
    if(!ob) return notify_fail("Promote who?\n");
    if(ob->query_guild()!=this_player()->query_guild()) return notify_fail("They "
          "arent apart of your guild.\n");
    if(member[obname]) {
        write("You promote "+ob->query_cap_name()+" to council position.\n");
        tell_object(ob, "You have been promoted to council position.");
        seteuid(UID_GUILDSAVE);
        map_delete(member, obname);
        council[obname]="1";
        save_object(GSAVEPATH);
        write_file("/d/guilds/data/induct", this_player()->query_cap_name()+" promoted "+ob->query_name()+""
          "in "+tp->query_guild()+" to council\n\n");
        seteuid(getuid());
        return 1;
    }
    if(council[obname]) {
        write("You promote "+ob->query_cap_name()+" to position leader.\n");
        tell_object(ob, "You have been promoted to leader position");
        seteuid(UID_GUILDSAVE);
        map_delete(council, obname);
        leader[obname]="1";
        save_object(GSAVEPATH);
        write_file("/d/guilds/data/induct", this_player()->query_cap_name()+" promoted "+ob->query_name()+""
          "in "+tp->query_guild()+" to leader\n\n");
        seteuid(getuid());
        return 1;
    }
    if(leader[obname]) {
        write("They are already the hightest position\n");
        return 1;
    }
}
int demote(string str) {
    object obname, ob, tp, tpname;

    restore_object(GSAVEPATH);

    if (!str)
         return notify_fail("Demote whom?\n");

    tp = this_player();
    tpname = tp->query_name();
    ob = present(str, environment(this_player()));
    obname = ob->query_name();
    if(this_player()->query_guild()!=GUILDN) {
        write("You arent in this guild.\n");
        this_object()->remove();
    }
    if(!ob) return notify_fail("Demote who?\n");
    if(!leader[tpname]) return notify_fail("You may not demote.\n");
    if(main[obname]) return notify_fail("You may not demote that person.\n");
    if(this_player()->query_guild()!= this_player()->query_guild()) return
        notify_fail("They are "
          "not apart of your guild.");
    if(member[obname]) return notify_fail("They cannot be demoted anymore.\n");
    if(leader[obname]) {
        seteuid(UID_GUILDSAVE);
        map_delete(leader, obname);
        council[obname]="1";
        save_object(GSAVEPATH);
        write_file("/d/guilds/data/induct", this_player()->query_cap_name()+" demoted "+ob->query_name()+""
          "in "+tp->query_guild()+" to council\n\n");
        seteuid(getuid());
        write("You demote "+ob->query_cap_name()+" to council.");
        tell_object(ob, "You have been demoted to council.");
        return 1;
    }
    if(council[obname]) {
        write("You demote "+ob->query_cap_name()+" to member.\n");
        tell_object(ob, "You have been demoted to member.");
        map_delete(council, obname);
        member[obname]="1";
        seteuid(UID_GUILDSAVE);
        save_object(GSAVEPATH);
        write_file("/d/guilds/data/induct", this_player()->query_cap_name()+" demoted "+ob->query_name()+""
          "in "+tp->query_guild()+" to member\n\n");
        seteuid(getuid());
        return 1;
    }
}
int restore(string str) {
    object ob;

    restore_object(GSAVEPATH);

    if(this_player()->query_guild()!=GUILDN) {
        write("You arent in this guild.\n");
        this_object()->remove();
    }
    if(!str) return notify_fail("Restore who?\n");
    ob = present(str, environment(this_player()));
    if(!ob) return notify_fail("Restore who?\n");
    if(ob->query_guild()!= this_player()->query_guild()) return notify_fail("They "
          "are not part of the guild.\n");
    write("You restore "+ob->query_cap_name()+"'s missing ring.\n");
    tell_object(ob, "Your missing ring has been replaced.");
    new("/d/guilds/"+this_player()->query_guild()+"/ring")->move(ob);
    seteuid(UID_GUILDSAVE);
    write_file("/d/guilds/data/induct", this_player()->query_cap_name()+" restored "+ob->query_name()+""
      "in "+this_player()->query_guild()+"\n\n");
    seteuid(getuid());
}

int add(string str) {
    object ob, obname;

    restore_object(GSAVEPATH);

    if(!wizardp(this_player())) return 0;
    if(!str) return notify_fail("Syntax: <add 'new leader'>\nRemember you must be set to the right guild name.\n");
    ob = present(str, environment(this_player()));
    obname = ob->query_name();
    if(!ob) return notify_fail("There arent here.\n");
    write("You set "+ob->query_cap_name()+" as the leader of "+this_player()->query_guild());
    tell_object(ob, "You are now the leader of "+this_player()->query_guild()+".");
    ob->set_guild(this_player()->query_guild());
    leader[obname]="1";
    main[obname]="1";
    seteuid(UID_GUILDSAVE);
    save_object(GSAVEPATH);
    write_file("/d/guilds/data/induct", this_player()->query_cap_name()+" added "+ob->query_name()+""
      "in "+this_player()->query_guild()+"\n\n");
    seteuid(getuid());
    return 1;
}

