#pragma once
#include "map.hh"
#include "entity.hh"
#include "vector3.hh"

class Player : Entity
{
public:
    Player(const Vector3& pos);
    Player(const Vector3& pos, const std::string& name);
    Player(const Player& p) = default;
    Player& operator=(const Player& p) = default;
    void damage(int amount);
    void heal(int amount);
    void kill();
    void revive();
    void update() override;
    void set_map(Map* map);
    void render() const override;
    bool alive();
    int get_hp();
    void trace();
    void untrace();
    const std::string& get_name();
    void set_dir(const Vector3& dir);
    const Vector3& get_dir() const;
    static Player* get_camera_bind();
    bool is_camera_bind() const;
    void bind_camera();
    void unbind_camera();
private:
    void log(const std::string& str) const;
    int hp_;
    bool alive_;
    bool trace_;
    Map* map_;
    std::string name_;
    Vector3 dir_;
    bool is_camera_bind_;
    static Player* camera_bind_;
};
