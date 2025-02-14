#include "scene/2d/dancing_sprite.h"
#include "core/math/math_funcs.h"

void DancingSprite::set_dance_speed(float p_speed) {
    dance_speed = p_speed;
}

float DancingSprite::get_dance_speed() const {
    return dance_speed;
}

void DancingSprite::_notification(int p_what) {
    if (p_what == NOTIFICATION_READY) {
        base_position = get_position();
    }
    if (p_what == NOTIFICATION_PROCESS) {
        float time = Engine::get_singleton()->get_frames_drawn() * 0.01;
        print_line(time);
        Color new_color = Color::from_hsv(fmod(time, 1.0), 0.8, 0.8);
        set_modulate(new_color);
        set_rotation(sin(time * 2) * 0.5);
        set_position(base_position + Vector2(0, sin(time * 3) * 20));
    }
}

void DancingSprite::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_dance_speed", "speed"), &DancingSprite::set_dance_speed);
    ClassDB::bind_method(D_METHOD("get_dance_speed"), &DancingSprite::get_dance_speed);
    
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "dance_speed"), "set_dance_speed", "get_dance_speed");
}

DancingSprite::DancingSprite() {
    set_process(true);
}

DancingSprite::~DancingSprite() {
}
