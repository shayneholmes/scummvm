/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "startrek/room.h"

#define HOTSPOT_EYES     0x20
#define HOTSPOT_MUSHROOM 0x21
#define HOTSPOT_FERN     0x22
#define HOTSPOT_LIGHT_1  0x23
#define HOTSPOT_LIGHT_2  0x24
#define HOTSPOT_LIGHT_3  0x25

namespace StarTrek {

extern const RoomAction feather4ActionList[] = {
	{ {ACTION_TICK, 1, 0, 0},                            &Room::feather4Tick1 },
	{ {ACTION_USE, OBJECT_ICOMM, 0xff, 0},               &Room::feather4UseCommunicator },
	{ {ACTION_USE, OBJECT_IPHASERS, 0xff, 0},            &Room::feather4UsePhaser },
	{ {ACTION_USE, OBJECT_IPHASERK, 0xff, 0},            &Room::feather4UsePhaser },
	{ {ACTION_USE, OBJECT_ISTRICOR, HOTSPOT_LIGHT_1, 0}, &Room::feather4UseSTricorderOnLight },
	{ {ACTION_USE, OBJECT_ISTRICOR, HOTSPOT_LIGHT_2, 0}, &Room::feather4UseSTricorderOnLight },
	{ {ACTION_USE, OBJECT_ISTRICOR, HOTSPOT_LIGHT_3, 0}, &Room::feather4UseSTricorderOnLight },
	{ {ACTION_USE, OBJECT_ISTRICOR, HOTSPOT_MUSHROOM, 0}, &Room::feather4UseSTricorderOnMushroom },
	{ {ACTION_USE, OBJECT_ISTRICOR, HOTSPOT_FERN, 0},    &Room::feather4UseSTricorderOnFern },
	{ {ACTION_USE, OBJECT_ISTRICOR, 0xff, 0},            &Room::feather4UseSTricorderAnywhere },
	{ {ACTION_USE, OBJECT_IMTRICOR, HOTSPOT_LIGHT_1, 0}, &Room::feather4UseMTricorderOnLight },
	{ {ACTION_USE, OBJECT_IMTRICOR, HOTSPOT_LIGHT_2, 0}, &Room::feather4UseMTricorderOnLight },
	{ {ACTION_USE, OBJECT_IMTRICOR, HOTSPOT_LIGHT_3, 0}, &Room::feather4UseMTricorderOnLight },
	{ {ACTION_USE, OBJECT_IMTRICOR, HOTSPOT_MUSHROOM, 0}, &Room::feather4UseMTricorderOnMushroom },
	{ {ACTION_USE, OBJECT_IMTRICOR, 0xff, 0},            &Room::feather4UseMTricorderAnywhere },
	{ {ACTION_USE, OBJECT_IMEDKIT, 0xff, 0},             &Room::feather4UseMedkitAnywhere },
	{ {ACTION_TALK, OBJECT_MCCOY, 0, 0},     &Room::feather4TalkToMccoy },
	{ {ACTION_TALK, OBJECT_SPOCK, 0, 0},     &Room::feather4TalkToSpock },
	{ {ACTION_TALK, OBJECT_REDSHIRT, 0, 0},  &Room::feather4TalkToRedshirt },
	{ {ACTION_LOOK, HOTSPOT_EYES, 0, 0},     &Room::feather4LookAtEyes },
	{ {ACTION_LOOK, 0xff, 0, 0},             &Room::feather4LookAnywhere },
	{ {ACTION_LOOK, HOTSPOT_MUSHROOM, 0, 0}, &Room::feather4LookAtMushroom },
	{ {ACTION_LOOK, HOTSPOT_FERN, 0, 0},     &Room::feather4LookAtFern },
	{ {ACTION_LOOK, HOTSPOT_LIGHT_1, 0, 0},  &Room::feather4LookAtLight },
	{ {ACTION_LOOK, HOTSPOT_LIGHT_2, 0, 0},  &Room::feather4LookAtLight },
	{ {ACTION_LOOK, HOTSPOT_LIGHT_3, 0, 0},  &Room::feather4LookAtLight },
	{ {ACTION_LOOK, OBJECT_KIRK, 0, 0},      &Room::feather4LookAtKirk },
	{ {ACTION_LOOK, OBJECT_SPOCK, 0, 0},     &Room::feather4LookAtSpock },
	{ {ACTION_LOOK, OBJECT_MCCOY, 0, 0},     &Room::feather4LookAtMccoy },
	{ {ACTION_LOOK, OBJECT_REDSHIRT, 0, 0},  &Room::feather4LookAtRedshirt },
};

extern const int feather4NumActions = ARRAYSIZE(feather4ActionList);


void Room::feather4Tick1() {
	playVoc("FEA4LOOP");
	playMidiMusicTracks(27);
}

void Room::feather4UseCommunicator() {
	showText(TX_SPEAKER_MCCOY, TX_FEA4_005); // BUGFIX: Original played wrong audio file (TX_FEA4N008)
}

void Room::feather4UsePhaser() {
	showText(TX_SPEAKER_SPOCK, TX_FEA4_011);
}

void Room::feather4UseSTricorderOnLight() {
	spockScan(DIR_W, TX_FEA4_010);
}

void Room::feather4UseSTricorderOnMushroom() {
	spockScan(DIR_W, TX_FEA4_012);
}

void Room::feather4UseSTricorderOnFern() {
	spockScan(DIR_W, TX_FEA4_009);
}

void Room::feather4UseSTricorderAnywhere() {
	spockScan(DIR_W, TX_FEA4_008);
}

void Room::feather4UseMTricorderOnLight() {
	mccoyScan(DIR_W, TX_FEA4_001);
}

void Room::feather4UseMTricorderOnMushroom() {
	mccoyScan(DIR_W, TX_FEA4_003);
}

void Room::feather4UseMTricorderAnywhere() {
	mccoyScan(DIR_W, TX_FEA4_006);
}

void Room::feather4UseMedkitAnywhere() {
	showText(TX_SPEAKER_MCCOY, TX_FEA4_002);
}

void Room::feather4TalkToMccoy() {
	showText(TX_SPEAKER_MCCOY, TX_FEA4_004);
}

void Room::feather4TalkToSpock() {
	showText(TX_SPEAKER_SPOCK, TX_FEA4_007);
}

void Room::feather4TalkToRedshirt() {
	showText(TX_SPEAKER_STRAGEY, TX_FEA4_013);
}

void Room::feather4LookAtEyes() {
	showText(TX_FEA4N003);
}

void Room::feather4LookAnywhere() {
	showText(TX_FEA4N008);
}

void Room::feather4LookAtMushroom() {
	showText(TX_FEA4N001);
}

void Room::feather4LookAtFern() {
	showText(TX_FEA4N000);
}

void Room::feather4LookAtLight() {
	showText(TX_FEA4N002);
}

void Room::feather4LookAtKirk() {
	showText(TX_FEA4N004);
}

void Room::feather4LookAtSpock() {
	showText(TX_FEA4N007);
}

void Room::feather4LookAtMccoy() {
	showText(TX_FEA4N006);
}

void Room::feather4LookAtRedshirt() {
	showText(TX_FEA4N005);
}

}
