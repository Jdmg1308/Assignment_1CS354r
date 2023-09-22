#ifndef BALL_H
#define BALL_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class Ball : public Area3D {
    GDCLASS(Ball, Area3D)


private:
    double speed;
    Vector3 direction;

protected:
    static void _bind_methods();

public:
    Ball();
    ~Ball();

    void _process(double delta) override;
    
    void set_speed(const double p_speed);
    double get_speed() const;

    void _on_ball_collision(const Area3D* area);
    void _get_signal(const Vector3 Normal);
    Vector3 calculate(Vector3 N);
};

}

#endif