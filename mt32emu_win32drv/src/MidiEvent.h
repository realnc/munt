/* Copyright (c) 2003-2004 Various contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef __MT32WIN32DRV_MIDIEVENT_H__
#define __MT32WIN32DRV_MIDIEVENT_H__

enum MidiEventType {
	ShortMsg,
	SysexData
};

class MidiEvent {
private:
	long long timemarker;
	MidiEventType type;
	MidiEvent *nxtEvent;

public:
	unsigned char *sysexInfo;
	long sysexLen;
	long midiMsg;

	MidiEvent();
	~MidiEvent();

	long long getTime(void);
	MidiEventType getType(void);
	MidiEvent *getNext(void);
	bool isFinal();
	void chainEvent(MidiEvent *newEvent);
	void assignSysex(const unsigned char *Sysex, long len, long long setTime);
	void assignMsg(long Msg, long long setTime);
};

#endif
