//	/std/living/follow.c
//	from the Nightmare mudlib
//	code for allowing people to follow
//	created by Descartes of Borg 15 february 1993

static private string allowed_to_follow;
static private object *followers;
static private object following;

object *query_followers() { return followers; }
object query_following() { return following; }

void set_following(object f) { following = f; }

int set_followers(object *f) {
  int i;

  if(!f) return 0;
  if(member_array( this_object(), f ) != -1 ) return 0;
  if(following && member_array(following, f) != -1) return 0;
  followers = f;
  for(i=0; i<sizeof(f); i++) {
    if(!f[i]) followers -= ({ f[i] });
    else f[i]->set_following(this_object());
  }
  return 1;
}

int add_follower(object f) {
  if( f == this_object() ) return 0;
  if(followers)
    if( member_array(f, followers) != -1 ) return 0;
  if(!followers) {
    followers = ({ f });
    f->set_following(this_object());
    return 1;
  }
  f->set_following(this_object());
  followers = followers + ({ f });
  return 1;
}

void remove_follower(object ob) {
  if(followers && member_array(ob, followers) == -1) 
    return;
  followers -= ({ ob });
  ob->set_following(0);
}

void clear_followers() {
  int i;

  if(!followers) return;
  for(i=0; i<sizeof(followers); i++) 
    if(followers[i]) followers[i]->set_following(0);
  followers = ({});
}

void move_followers(object room, string dir) {
  object *tmp;
  object to = this_object();

  if (!room || !dir || !stringp(dir) || !strlen(dir)) return;

  tmp = ({});
  foreach (object fol in followers) {
    if (!objectp(fol) || !environment(fol)) continue;
    if (to->query_riding() && fol == to->query_riding()) continue;
    if (!fol->follow(room, dir)) {
      object stalking = fol->query("stalk_abil_info");
      if (objectp(stalking) && stalking != to) {
	tell_object(to, "You have lost "+fol->query_cap_name()+".\n");
	tell_object(fol, to->query_cap_name()+" has ditched you.\n");
      }
      fol->set_following(0);
    }
    else {
      tmp += ({ fol });
    }
  }
  followers = tmp;
}

void follow_allow(string str) { allowed_to_follow = str; }

int can_follow(mixed who) {
  object own;
  if (stringp(who)) return who == allowed_to_follow;
  if (objectp(who)) {
    if (who->query_name() == allowed_to_follow) return 1;
    if ((own = who->query_owner()) && own == this_object()) return 1;
  }
  return 0;
}

int follow(object room, string dir) {
  int ret;
  object tp = this_player();
  object to = this_object();
  if (to->query_rest_type()) return 0;
  if (tp && !to->query_busy() && to->query_property("teleport follow")) {
    object env = environment(tp);
    to->move_player(env, "following "+tp->query_cap_name());
    if (environment(to) != env) to->move(env);
    ret = 1;
  }
  else if (environment(to) != room) ret = 0;
  else ret = command(dir);
  return (ret ? 1 : 0);
}
