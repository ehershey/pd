#include <std.h>
#include <weather.h>
inherit ROOM;
string *rooms;
string *messages;
void weather();
void add_room(string str);
void query_rooms();
void do_weather();

void create() {
    ::create();
    restore_object(WEATHER_SAVE);
    weather();
    set_name("Storm Room");
    set_long("Storm Room");
    set_properties(([ "light":2, "night light":2, "no teleport":1, "no scry":1 ]));
    set_exits(([ "out" : "/wizards/whit/workroom" ]));
}

void init() {
    ::init();
    add_action("add", "add");
    add_action("remove", "remove");
    add_action("list", "list");
    add_action("add_message", "message");
    add_action("test", "test");
    add_action("commands", "commands");
}

int commands() {
    write("<add [filename]> - Adds a room to the daemon\n");
    write("<message [add]> - Adds a message to the daemon\n");
    write("<list> - lists the current rooms\n");
    write("<test> - tests daemon\n");
    write("<commands> - Lists commands\n");
    return 1;
}

int add(string str) {
    if(!str) return 0;
    if(!file_exists(str+".c")) return notify_fail("No such room.\n");
    add_room(str);
    save_object(WEATHER_SAVE);
}

int list() {
    write("Listing rooms:\n");
    query_rooms();
}

int test() { do_weather(); }

void add_room(string str) {
    if(!rooms) restore_object(WEATHER_SAVE);
    rooms += ({ str });
    save_object(WEATHER_SAVE);
}

void add_message(string str) {
    if(!messages) restore_object(WEATHER_SAVE);
    messages += ({ str });
    save_object(WEATHER_SAVE);
}

void query_rooms() {
    int i;
    i = sizeof(rooms);
    while(i--) {
	write(rooms[i]);
    }
}

void do_weather() {
    int i;
    string ob;
    i = sizeof(rooms);
    ob = messages[random(sizeof(messages))];
    while(i--) {
	tell_room(rooms[i], ob);
    }
    weather();
}

void weather() {
    call_out("do_weather", 20);
}

