#include "ball.h"
#include "wall.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Ball::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_speed"), &Ball::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Ball::set_speed);
    ClassDB::add_property("Ball", PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "-50,50,0.01"), "set_speed", "get_speed");
    
    ClassDB::bind_method(D_METHOD("_on_ball_collision","area"), &Ball::_on_ball_collision);

    ClassDB::bind_method(D_METHOD("calculate","N"), &Ball::calculate);

    ADD_SIGNAL(MethodInfo("ball_hit"));
    ADD_SIGNAL(MethodInfo("wall_hit"));

}

Ball::Ball() {
    // Initialize any variables here.
    set_position(Vector3(21/rand(), 21/rand(), 21/rand()));
    speed = 1.0;
    direction = Vector3(rand(), rand(), rand());
    direction.normalize();
    connect("area_entered", Callable(this, "_on_ball_collision"));
}

Ball::~Ball() {
    // Add your cleanup here.
    disconnect("area_entered", Callable(this, "_on_ball_collision"));
}

void Ball::_process(double delta) {
    if (get_position().x > 21 || get_position().x < -21) {
        set_position(Vector3(0, 5, 0));
    }
    Vector3 new_position = get_global_transform().origin + Vector3(direction.x, direction.y, direction.z) * speed * delta;
    set_position(new_position);
}


void Ball::set_speed(const double p_speed) {
    speed = p_speed;
}

double Ball::get_speed() const {
    return speed;
}

void Ball::_on_ball_collision(const Area3D* area) {
    
    if (area->get_class() == "Wall") {
        UtilityFunctions::print("Collision Wall"); 
        emit_signal("wall_hit");
        Wall* wall = const_cast<Wall*>(reinterpret_cast <const Wall *>(area));
        direction = calculate(wall->get_normal());
        direction.normalize();

    } else if (area->get_class() == "Ball") {
        UtilityFunctions::print("Collision Ball"); 
        emit_signal("ball_hit");
        Vector3 ball_normal = area->get_position() - get_position();
        direction = calculate(ball_normal);
        direction.normalize();

    } else {
        UtilityFunctions::print("HUUUUH"); 
    }
}

Vector3 Ball::calculate(Vector3 N) {
    Vector3 R = direction - 2*N*(N.dot(direction)); 
    return R;
}