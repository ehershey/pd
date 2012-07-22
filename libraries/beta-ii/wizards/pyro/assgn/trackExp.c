

/** Variables for the Exp/hour tracker *****************/
//will be stored in the form ({ ({timeAdded, exp}), ..., ({timeAdded, exp}) })
static mixed xpList = ({ });
static int xpGainedInSampleTime = 0;
static int sampleSize = 60*5;
/*******************************************************/


/** Prototypes for the Exp/hour tracker ****************/
void add_exp(int exp);
void remanage_exp_rate();
void get_exp_rate();
int get_exp_per_second();
int get_exp_per_minute();
int get_exp_per_hour();
/*******************************************************/


/** Functions for the Exp/hour tracker *****************/

void create() {
  xpList = ({ });
  xpGainedInSampleTime = 0;
}

//should be called whenever a player receives exp that should
//contribute to the xp/hour tracker
void add_to_exp_rate(int exp) {
  xpList += ({ ({time(), exp}) });
  xpGainedInSampleTime += exp;
  remanage_exp_rate();
}

//should be called whenever xp is added to the xpList
void remanage_exp_rate() {
 int minTime = time() - sampleSize;
  int i;
  if(minTime < 0) minTime = 0;

  //chop off the members of the array that were added too long ago
  for(i = 0; i < sizeof(xpList); i++) {
    if(xpList[i][0] >= minTime) break;
    xpGainedInSampleTime -= xpList[i][1];
  }
  xpList = xpList[i..<1];
}

float get_exp_rate() {
  remanage_exp_rate();
 return (xpGainedInSampleTime/(sampleSize*1.0));
}

int get_exp_per_second() {
  return to_int(get_exp_rate());
}

int get_exp_per_hour() {
  return to_int(get_exp_rate() * 60 * 60);
}

int get_exp_per_minute() {
  return to_int(get_exp_rate() * 60);
}

int query_exp_rate_sample_size() { return sampleSize; }
void set_exp_rate_sample_size(int size) { sampleSize = size; }

void clear_exp_rate_buffer() {
  xpList = ({ });
  xpGainedInSampleTime = 0;
}

/*******************************************************/
