#ifndef AUDIO_AWESOME_H
#define AUDIO_AWESOME_H

#include "core/templates/safe_refcount.h"
#include "scene/main/node.h"

class AudioAwesome : public Node {
	GDCLASS(AudioAwesome, Node);

private:
	float pitch_scale = 1.0;
	float volume_db = 0.0;

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	void set_volume_db(float p_volume);
	float get_volume_db() const;

	void set_pitch_scale(float p_pitch_scale);
	float get_pitch_scale() const;

	void play(float p_from_pos = 0.0);
	void stop();
	bool is_playing() const;

	AudioAwesome();
	~AudioAwesome();
};

#endif // AUDIO_AWESOME_H
