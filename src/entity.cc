#include "entity.hh"
#include "vector3.hh"
#include "hitbox.hh"

Entity::Entity()
    : pos_(), hitbox_(), model_(), visible_(false)
{}
Entity::Entity(const Vector3& pos)
    : pos_(pos), hitbox_(), model_(), visible_(false)
{}
Entity::Entity(const Vector3& pos, const Hitbox& hitbox)
    : pos_(pos), hitbox_(hitbox), model_(), visible_(false)
{}
Entity::Entity(const Vector3& pos, const Hitbox& hitbox, const Model& model)
    : pos_(pos), hitbox_(hitbox), model_(model), visible_(false)
{}
Entity::Entity(const Vector3& pos, const Hitbox& hitbox, const Model& model,
               bool visible)
    : pos_(pos), hitbox_(hitbox), model_(model), visible_(visible)
{}
Entity::Entity(const Entity& entity)
    : pos_(entity.pos_)
    , hitbox_(entity.hitbox_)
    , model_(entity.model_)
    , visible_(entity.visible_)
{}
Entity& Entity::operator=(const Entity& entity)
{
    pos_ = entity.pos_;
    hitbox_ = entity.hitbox_;
    model_ = entity.model_;
    visible_ = entity.visible_;
    return *this;
}
const Vector3& Entity::get_pos() const
{
    return pos_;
}
const Hitbox& Entity::get_hitbox() const
{
    return hitbox_;
}
void Entity::set_pos(const Vector3& pos)
{
    pos_ = pos;
}
void Entity::set_hitbox(const Hitbox& hitbox)
{
    hitbox_ = hitbox;
}
void Entity::set_model(const Model& model)
{
    model_ = model;
}
void Entity::hide()
{
    visible_ = false;
}
void Entity::show()
{
    visible_ = true;
}
