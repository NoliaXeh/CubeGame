#include <iostream>
#include "map.hh"
#include "entity.hh"
#include "player.hh"
#include "graphics.hh"
#include <SDL/SDL.h>
#include <cmath>

Player* Player::camera_bind_ = nullptr;

Player::Player(const Vector3& pos)
    : Entity            (pos)
    , hp_               (100)
    , alive_            (true)
    , trace_            (false)
    , map_              (nullptr)
    , name_             ("Player")
    , dir_              (Vector3(1, 0, 0))
    , is_camera_bind_   (false)
{}
Player::Player(const Vector3& pos, const std::string& name)
    : Entity            (pos)
    , hp_               (100)
    , alive_            (true)
    , trace_            (false)
    , map_              (nullptr)
    , name_             (name)
    , dir_              (Vector3(1, 0, 0))
    , is_camera_bind_   (false)
{}
void Player::damage(int amount)
{
    hp_ -= amount;
    if (hp_ < 1)
    {
        hp_ = 0;
        this->kill();
    }
}
void Player::heal(int amount)
{
    if (this->alive())
    {
        hp_ += amount;
        if (hp_ > 100)
            hp_ = 100;
    }
}
int Player::get_hp()
{
    return hp_;
}
void Player::kill()
{
    this->damage(hp_);
}
void Player::revive()
{
    if (this->alive())
        return;
    this->log("Revived");
    alive_ = true;
    hp_ = 100;
}
void Player::update()
{
    //this->log("Player::update() : called");
    double x, y, z;
    this->get_pos().get(x, y, z);
    double ax, ay, az;
    this->get_dir().get(ax, ay, az);
    if (is_camera_bind_)
    {
        graphics::camera::x = x;
        graphics::camera::y = y;
        graphics::camera::z = z;
        graphics::camera::ax = x + ax;
        graphics::camera::ay = y + ay;
        graphics::camera::az = z + az;
    }
    double v = 0;
    double h = 0;
    
    int mx, my;
    const int cx = 320, cy = 240;
    SDL_GetMouseState(&mx, &my);
    
    h = 2.0 * 1 / ( 1.0 +  std::exp((mx - cx) * 0.01)) - 1.0;
    v = 2.0 * 1 / ( 1.0 +  std::exp((my - cy) * 0.01)) - 1.0;
    v *= -0.5;
    h *= 0.5; 
    dir_.spherical_rotate(v, h);
    SDL_PumpEvents();
    const char *keys = SDL_GetKeyboqrdState(0);
    if (0 || keys[SDL_SCANCODE_Z])
        return;

    this->set_pos((this->dir_ * 0.1) + this->get_pos());
    SDL_WarpMouse(cx, cy);
}
void Player::set_map(Map* map)
{
    this->log("Player::set_map() : map changed");
    map_ = map;
}
void Player::render() const
{
    //this->log("Player::render() : called");
}
void Player::trace()
{
    trace_ = true;
    this->log("Trace turned ON");
}
void Player::untrace()
{
    this->log("Trace turned OFF");
    trace_ = false;
}
void Player::log(const std::string& message) const
{
    const std::string reset = "\033[0m";
    const std::string green = "\033[32m";
    const std::string blue = "\033[38;5;117m";
    const std::string yellow = "\033[33m";

    if (trace_)
        std::clog << "[" << green << "LOG" << reset << "]["
                  << blue << "PLAYER" << reset << "] - <"
                  << yellow << name_ << reset << "> - "
                  << message << std::endl;
}
bool Player::alive()
{
    return alive_;
}

void Player::set_dir(const Vector3& dir)
{
    dir_ = dir;
}

const Vector3& Player::get_dir() const
{
    return dir_;
}

Player* Player::get_camera_bind()
{
    return Player::camera_bind_;
}

void Player::bind_camera()
{
    is_camera_bind_ = true;
    camera_bind_ = this;
}

void Player::unbind_camera()
{
    if (is_camera_bind_)
    {
        is_camera_bind_ = false;
        camera_bind_ = nullptr;
    }
}

bool Player::is_camera_bind() const
{
    return is_camera_bind_;
}
