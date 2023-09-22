#ifndef WALL_H
#define WALL_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class Wall : public Area3D {
    GDCLASS(Wall, Area3D)


private:
    Vector3 Normal;

protected:
    static void _bind_methods();

public:
    Wall();
    ~Wall();

    void _process(double delta) override;

    Vector3 get_normal();

    double get_normal_x();
    void set_normal_x(const double x);

    double get_normal_y();
    void set_normal_y(const double y);

    double get_normal_z();
    void set_normal_z(const double z);
};

}

#endif