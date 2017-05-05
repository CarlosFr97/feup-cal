/*
 * Print time
 */
// Something like GetTickCount but portable
// It rolls over every ~ 12.1 days (0x100000/24/60/60)
// Use GetMilliSpan to correct for rollover

#include "utils.h"

int GetMilliCount(){

  timeb tb;
  ftime( &tb );
  int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
  return nCount;
}
//---------------------------------------------------------------------------

int GetMilliSpan(int nTimeStart){

  int nSpan = GetMilliCount() - nTimeStart;
  if (nSpan < 0)
	  nSpan += 0x100000 * 1000;
  return nSpan;
}
//---------------------------------------------------------------------------


vector<string> splitString(string rua){
	string buf;
	stringstream ss;
	ss.str(rua);

	vector<string> ret;

	while (ss >> buf)
		ret.push_back(buf);

	return ret;

}

string concatenateStrings(vector<string> vec, int num, int first_pos){
	stringstream ss;
	for(int i = 0; i< num ; i++){
		if(i != num -1)
			ss << vec.at(first_pos + i) << " ";
		else
			ss << vec.at(first_pos + i);
	}

	return ss.str();
}

