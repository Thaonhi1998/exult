/*
Code originally written by Max Horn for ScummVM,
minor tweaks by various other people of the ScummVM, Pentagram
and Exult teams.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef COREAUDIOMIDIDRIVER_H_INCLUDED
#define COREAUDIOMIDIDRIVER_H_INCLUDED

#if defined(MACOSX) && !defined(__IPHONEOS__)
#define USE_CORE_AUDIO_MIDI

#include "LowLevelMidiDriver.h"

#include <AudioToolbox/AUGraph.h>
#include <CoreServices/CoreServices.h>

class CoreAudioMidiDriver : public LowLevelMidiDriver {
	AUGraph _auGraph;
	AudioUnit _synth;


	static const MidiDriverDesc desc;
	static MidiDriver *createInstance() {
		return new CoreAudioMidiDriver();
	}

public:
	static const MidiDriverDesc *getDesc() {
		return &desc;
	}

	CoreAudioMidiDriver();

protected:
	int         open() override;
	void        close() override;
	void        send(uint32 message) override;
	void        send_sysex(uint8 status, const uint8 *msg, uint16 length) override;
	void        increaseThreadPriority() override;
	void        yield() override;
};

#endif //MACOSX

#endif //COREAUDIOMIDIDRIVER_H_INCLUDED
