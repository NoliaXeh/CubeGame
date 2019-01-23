#pragma once
#include "vector3.hh"
#include "hitbox.hh"

class Entity
{
public:
    Entity();
    Entity(const Vector& pos);
    Entity(const Vector& pos, const Hitbox& hitbox);
    Entity(const Vector& pos, const Hitbox& hitbox, const Model& model);
    Entity(const Vector& pos, const Hitbox& hitbox, const Model& model,
           bool visible);
    ~Entity() = default;
    Entity(const Entity& entity);
    Entity& operator=(const Entity& entity);
    void render() const = 0;
    const Vector3& get_pos() const;
    const Hitbox& get_hitbox() const;
    void set_pos(const Vetcor3& pos);
    void set_hitbox(const Hitbox3& hitbox);
    void set_model(const Model& model);
    void update() = 0;
    void hide();
    void show();
protected:
private:
    Vector3 pos_;
    Hitbox hitbox_;
    Model model_;
    bool visible_;
};
