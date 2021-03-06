/*
  This file is part of the DSP-Crowd project
  https://www.dsp-crowd.com

  Author(s):
      - Johannes Natter, office@dsp-crowd.com

  File created on 02.06.2017

  Copyright (C) 2017 Authors and www.dsp-crowd.com

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef IRENC_H
#define IRENC_H

#include <string>
#include <vector>

class IrEnc {

public:
	IrEnc();
	virtual ~IrEnc();

	int exec(int argc, char *argv[]);

private:
	int init();
	void parseChar(char c);
	void addCode(int len);
	void sendSignal();

	std::string strData;
	bool strDataIsSet;

	int hdrMark;
	int hdrSpace;
	int bitMark;
	int bitOneSpace;
	int bitZeroSpace;
	int tailMark;
	int tailSpace;
	bool bitSwap;
#if TARGET_PI
	int gpio;
#endif

	/* FSM */
	bool firstNibble;
	int byte;
	std::vector<int> codes;
};

#endif

