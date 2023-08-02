#include "audiox.h"

void AudioX::add(int p_value) {
    print_line("AudioX: Adding " + itos(p_value));
    count += p_value;
}

void AudioX::reset() {
    count = 0;
}

int AudioX::get_total() const {
    return count;
}

void AudioX::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add", "value"), &AudioX::add);
    ClassDB::bind_method(D_METHOD("reset"), &AudioX::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &AudioX::get_total);
}

AudioX::AudioX() {
    count = 0;
    print_line("AudioX: Created");
}

AudioX::~AudioX() {
    print_line("AudioX: Destroyed");
}