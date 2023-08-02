#ifndef AUDIOX_H
#define AUDIOX_H

#include "core/object/ref_counted.h"

class AudioX : public RefCounted {
    GDCLASS(AudioX, RefCounted);

    int count;

protected:
    static void _bind_methods();

public:
    void add(int p_value);
    void reset();
    int get_total() const;

    AudioX();
    ~AudioX();
};

#endif // AUDIOX_H