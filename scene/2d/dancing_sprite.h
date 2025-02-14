#ifndef DANCING_SPRITE_H
#define DANCING_SPRITE_H

#include "scene/2d/sprite_2d.h"

class DancingSprite : public Sprite2D {
    GDCLASS(DancingSprite, Sprite2D);

    float dance_speed = 1.0;
    Vector2 base_position;

protected:
    static void _bind_methods();
    void _notification(int p_what);

public:
    void set_dance_speed(float p_speed);
    float get_dance_speed() const;

    DancingSprite();
    ~DancingSprite();
};

#endif //DANCING_SPRITE_H