/**************************************************************************/
/*  audio_stream_player.cpp                                               */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "audio_awesome.h"

#include "core/config/engine.h"
#include "core/math/audio_frame.h"
#include "servers/audio_server.h"

void AudioAwesome::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_ENTER_TREE: {
			print_line("NOTIFICATION_ENTER_TREE");
		} break;

		case NOTIFICATION_INTERNAL_PROCESS: {
			print_line("NOTIFICATION_INTERNAL_PROCESS");
		} break;

		case NOTIFICATION_EXIT_TREE: {
			print_line("NOTIFICATION_EXIT_TREE");
			emit_signal(SNAME("exit_tree"));
		} break;

		case NOTIFICATION_PREDELETE: {
			print_line("NOTIFICATION_PREDELETE");
		} break;

		case NOTIFICATION_PAUSED: {
			print_line("NOTIFICATION_PAUSED");
		} break;

		case NOTIFICATION_UNPAUSED: {
			print_line("NOTIFICATION_UNPAUSED");
		} break;
	}
}

void AudioAwesome::set_volume_db(float p_volume) {
	print_line("set_volume_db " + rtos(p_volume));
    volume_db = p_volume;
}

float AudioAwesome::get_volume_db() const {
	print_line("get_volume_db returns " + rtos(volume_db));
	return volume_db;
}

void AudioAwesome::set_pitch_scale(float p_pitch_scale) {
	print_line("set_pitch_scale " + rtos(p_pitch_scale));
    pitch_scale = p_pitch_scale;
}

float AudioAwesome::get_pitch_scale() const {
	print_line("get_volume_db returns " + rtos(pitch_scale));
	return pitch_scale;
}


void AudioAwesome::play(float p_from_pos) {
    print_line("play from position: " + rtos(p_from_pos));
}

void AudioAwesome::stop() {
    print_line("stop");
}

bool AudioAwesome::is_playing() const {
	print_line("is_playing returns false");
	return false;
}

void AudioAwesome::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_volume_db", "volume_db"), &AudioAwesome::set_volume_db);
	ClassDB::bind_method(D_METHOD("get_volume_db"), &AudioAwesome::get_volume_db);

	ClassDB::bind_method(D_METHOD("set_pitch_scale", "pitch_scale"), &AudioAwesome::set_pitch_scale);
	ClassDB::bind_method(D_METHOD("get_pitch_scale"), &AudioAwesome::get_pitch_scale);

	ClassDB::bind_method(D_METHOD("play", "from_position"), &AudioAwesome::play, DEFVAL(0.0));
	ClassDB::bind_method(D_METHOD("stop"), &AudioAwesome::stop);
	ClassDB::bind_method(D_METHOD("is_playing"), &AudioAwesome::is_playing);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "volume_db", PROPERTY_HINT_RANGE, "-80,24,suffix:dB"), "set_volume_db", "get_volume_db");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pitch_scale", PROPERTY_HINT_RANGE, "0.01,4,0.01,or_greater"), "set_pitch_scale", "get_pitch_scale");

	ADD_SIGNAL(MethodInfo("exit_tree"));
}

AudioAwesome::AudioAwesome() {
    print_line("AudioAwesome::AudioAwesome() Object Created");
}

AudioAwesome::~AudioAwesome() {
    print_line("AudioAwesome::~AudioAwesome() Object Destroyed");
}
