//
// code for tracking resistances and weaknesses against various damage types

private mapping _Resistances = ([]);
static private mapping _ResistanceBonuses = ([]);

int *query_all_resistances();
mapping query_resistances();
void set_resistance(int, int);
void add_resistance(int, int);
int query_resistance(int);
int query_base_resistance(int type);
int *query_all_resistance_bonuses();
mapping query_resistance_bonuses();
void set_resistance_bonus(int type, int amt);
void add_resistance_bonus(int type, int amt);
int query_resistance_bonus(int type);

void create() {
  if (!_Resistances)
    _Resistances = ([]);
  if (!_ResistanceBonuses)
    _ResistanceBonuses = ([]);
}


// permanent resistances
int *query_all_resistances() {
  if (!_Resistances) _Resistances = ([]);
  return keys(_Resistances) || ({});
}
mapping query_resistances() {
  if (!_Resistances) _Resistances = ([]);
  return copy(_Resistances) || ([]);
}
void set_resistance(int type, int amt) {
  if (!_Resistances) _Resistances = ([]);
  if (amt == 0)
    map_delete(_Resistances, type);
  else
    _Resistances[type] = amt;
}
void add_resistance(int type, int amt) {
  set_resistance(type, query_resistance(type) + amt);
}
int query_base_resistance(int type) {
  if (!_Resistances) _Resistances = ([]);
  return _Resistances[type] || 0;
}
int query_resistance(int type) {
  return query_base_resistance(type) + query_resistance_bonus(type);
}

// for temporary bonuses
int *query_all_resistance_bonuses() {
  if (!_ResistanceBonuses) _ResistanceBonuses = ([]);
  return keys(_ResistanceBonuses) || ({});
}
mapping query_resistance_bonuses() {
  if (!_ResistanceBonuses) _ResistanceBonuses = ([]);
  return copy(_ResistanceBonuses) || ([]);
}
void set_resistance_bonus(int type, int amt) {
  if (!_ResistanceBonuses) _ResistanceBonuses = ([]);
  if (amt == 0)
    map_delete(_ResistanceBonuses, type);
  else
    _ResistanceBonuses[type] = amt;
}
void add_resistance_bonus(int type, int amt) {
  set_resistance_bonus(type, query_resistance_bonus(type) + amt);
}
int query_resistance_bonus(int type) {
  if (!_ResistanceBonuses) _ResistanceBonuses = ([]);
  return _ResistanceBonuses[type] || 0;
}

