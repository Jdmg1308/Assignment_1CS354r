
#include "wall.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Wall::_bind_methods() {

    ClassDB::bind_method(D_METHOD("get_normal"), &Wall::get_normal);

    ClassDB::bind_method(D_METHOD("get_normal_x"), &Wall::get_normal_x);
    ClassDB::bind_method(D_METHOD("set_normal_x", "x"), &Wall::set_normal_x);
    ClassDB::bind_method(D_METHOD("get_normal_y"), &Wall::get_normal_y);
    ClassDB::bind_method(D_METHOD("set_normal_y", "y"), &Wall::set_normal_y);
    ClassDB::bind_method(D_METHOD("get_normal_z"), &Wall::get_normal_z);
    ClassDB::bind_method(D_METHOD("set_normal_z", "z"), &Wall::set_normal_z);

    ClassDB::add_property("Wall", PropertyInfo(Variant::FLOAT, "normal_x", PROPERTY_HINT_RANGE, "-1,1,0.01"), "set_normal_x", "get_normal_x");
    ClassDB::add_property("Wall", PropertyInfo(Variant::FLOAT, "normal_y", PROPERTY_HINT_RANGE, "-1,1,0.01"), "set_normal_y", "get_normal_y");
    ClassDB::add_property("Wall", PropertyInfo(Variant::FLOAT, "normal_z", PROPERTY_HINT_RANGE, "-1,1,0.01"), "set_normal_z", "get_normal_z");

}

Wall::Wall() {
    // Initialize any variables here.
    Normal = Vector3(0, 0, 0);
}

Wall::~Wall() {
    // Add your cleanup here.
}

void Wall::_process(double delta) {
    
}

Vector3 Wall::get_normal() {
    return Normal;
}

double Wall::get_normal_x() { return Normal.x; }
void Wall::set_normal_x(const double x) { Normal.x = x; }

double Wall::get_normal_y() { return Normal.y; }
void Wall::set_normal_y(const double y) { Normal.y = y; }

double Wall::get_normal_z() { return Normal.z; }
void Wall::set_normal_z(const double z) { Normal.z = z; }
