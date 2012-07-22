// Coded by Whit

#include <std.h>
inherit WEAPON;

int combine(string str);

void init() {
::init();
add_action("combine", "combine");
}

void create() {
::create();
set_name("A staff");
set_id(({ "staff", "victors staff", }));
set_short("a staff");
set_long("This is a staff that came from Victor.  However it is not whole.  "
"a peice of it is missing.  The peice will go at the end of the staff.  It "
"looks like a type of gem will fit in it.");

set_wc(20);
set_type("staff");

}

int combine(string str) {
if (str != "ruby with staff") {
write("Combine what with what?");
return 1;
}
if (present("shimmering ruby")) {
write("You place the ruby on the end of the staff.");
call_out("start_staff", 2);
return 1;
}
write("Combine what with what?");
return 1;
}

void start_staff() {
write("The staff starts shaking.\n");
call_out("continue_staff", 4);
}

void continue_staff() {
write("Your mind is cluttered with the history of the staff.\n");
write("The scene starts to play about the room.\n");
call_out("con_1", 5);
}

void con_1() {
write("A small man appears from no where.");
write("He takes what appears to be a blue crystal and "
"throws it into a lake.\n");
call_out("con_2", 4);
}

void con_2() {
write("the man says: You will never get it Bordus.\n");
write("A swoosh of color and light.  You see your self standing in front "
"of a silver pedestal.  It is covered in many strange writings.\n");
call_out("con_4", 6);
}

void con_4() {
write("The man that was there once before now stands near the pedistal "
"holding what looks to be a staff.\n");
call_out("con_5", 5);
}

void con_5() {
write("the man says: Behold the power of Victor!\n");
write("The man stabbed the staff into the pedestal.  I bright light "
"fills the room\n");
call_out("con_6", 6);
}

void con_6() {
write("a shallow voice echos throughout the room.\n");
write("the voice says: Behold, Savior, you have "
"saved the forest from doom.  Like it has now shall it happen again.\n");
new("/d/citrin/weapons2/staff.c")->move(this_player());
call_out("con_7", 3);
}

void con_7() {
write("You gain control of your mind once again.");
write("You are back where you started.");
if (present("victors staff", this_player())->remove());
}
